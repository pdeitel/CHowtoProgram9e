// weather.c
/* Accessing an OpenWeatherMap web service via libcurl and parsing the
   results using cJSON.

   ---------------------------------------
   libcurl functions used in this example:
   ---------------------------------------
   - curl_easy_init: Creates and initializes a CURL object, which we'll
     use to invoke a web service.

   - curl_easy_setopt: Used to set options, such as the URL of the web
     service to invoke.

   - curl_easy_perform: Used to invoke the web service.

   - curl_easy_cleanup: Releases the CURL object's resources allocated 
     by curl_easy_init.

   -------------------------------------
   cJSON functions used in this example:
   -------------------------------------
   - cJSON_Parse: Reads a string and converts it into a data structure 
     that cJSON uses to access the data in a JSON object.

   - cJSON_GetObjectItemCaseSensitive: Locates a key in the JSON object
     and returns the corresponding value.

   - cJSON_IsString: Returns true if a cJSON object contains a string.

   - cJSON_IsObject:  Returns true if a cJSON object contains a 
     JavaScript object.

   - cJSON_ArrayForEach: A preprocessor macro that creates a C for loop
     for iterating through a JSON array.
*/
#include "cJSON.h"
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define URL_LENGTH 2048 // max URL length is 2048 characters

/* This application receives two commandline arguments. The first is the
   city for which you'd like to get the current weather, such as

      Boston,MA,USA

   If the city contains a space, enclose it in quotes as in

      "Los Angeles,CA,USA"

   The second command-line argument is your OpenWeatherMap API key, which
   you must obtain by signing up at 
   
      https://openweathermap.org/home/sign_up

   Once you sign up and confirm your account, you'll received your API 
   key via email. */
int main(int argc, char *argv[]) {
   /* If there are not three command-line arguments, terminate. The
      first command line argument is the application name. The other 
      two are the city and API key. */
   if (argc != 3) {
      printf("Usage: weather city api_key");
      exit(1);
   }
   
   /* curl is a tool for transfering data over a network connection.
      libcurl is a library for interacting with curl from a C program.
      The libcurl function curl_easy_init must be called first. It creates 
      and initializes a CURL object and returns a pointer to it. That 
      pointer must be passed as an argument to each subsequent libcurl  
      function call. When you're done with this CURL object, you must 
      call curl_easy_cleanup to release its resources. */
   CURL *curl = curl_easy_init(); 
   
   /* Open the file in which the JSON response returned by OpenWeatherMap
      will be stored. */
   char *weatherReportFile = "weatherreport.json";
   FILE *outputFile = fopen(weatherReportFile, "w");
   
   /* The URL for OpenWeatherMap's web service that returns the current
      weather for a city has the format

      https://api.openweathermap.org/data/2.5/weather?q=CITY&units=metric&appid=YOUR_API_KEY

      where CITY and YOUR_API_KEY are this program's command-line 
      arguments. These are passed as arguments to the web service via
      the URL. The following statements assemble this URL into a 
      character array. */
   char *apiURL = "https://api.openweathermap.org/data/2.5/weather?q=";
   char queryURL[URL_LENGTH];
   sprintf(queryURL, 
      "%s%s&units=metric&appid=%s", apiURL, argv[1], argv[2]);
//   printf("URL: %s\n", queryURL);
   
   /* Before using curl to perform a task you must set its options via 
      libcurl function curl_easy_setopt. The function takes three 
      arguments:
      
      - A CURL pointer.
      
      - A CURLOPT constant that specifies the curl option to set.
        You can see the complete list of constants at:
        https://curl.se/libcurl/c/curl_easy_setopt.html
        
      - The value to set for the specific curl option. */
   
   /* When CURLOPT_URL is the second argument, the third argument is the 
      URL curl will access--in this case, to call an OpenWeatherMap 
      web service. */
   curl_easy_setopt(curl, CURLOPT_URL, queryURL);
   
   /* When CURLOPT_WRITEDATA is the second argument, the third argument
      is a pointer to the file in which curl will write the returned 
      data--in this case, to call an OpenWeatherMap */
   curl_easy_setopt(curl, CURLOPT_WRITEDATA, outputFile);
   
   /* Once the CURL object is configured, you can execute its task by
      calling libcurl function curl_easy_perform. This uses the URL we 
      constructed to make a request to OpenWeatherMap--as if you had 
      entered that URL in your web browser's address bar. This "invokes"
      the web service, and OpenWeatherMap returns a response, based on 
      the arguments provided in the URL we configured above. This will 
      write the results into the file weatherreport.json as configured 
      above. curl_easy_perform returns an int indicating whether the 
      request was successful (CURLE_OK) or an error occurred. For a 
      complete list of error codes see: 
      https://curl.se/libcurl/c/libcurl-errors.html */
   int result = curl_easy_perform(curl);

   // close the output file
   fclose(outputFile); 
   
   /* libcurl function curl_easy_cleanup releases the CURL object's
      resources that were allocated by curl_easy_init. */
   curl_easy_cleanup(curl); 
   
   /* check whether the request was successful and, if not, display
      and error message and terminate. */
   if (result != CURLE_OK) {
      printf("An error occurred: %s\n", curl_easy_strerror(result));
      exit(1);
   }
      
   // open the weatherReportFile to read the JSON weather report 
   FILE *inputFile = fopen(weatherReportFile, "r");

   /* Seek to the end of the file so we can determine the total number
      of characters then create an array large enough to store the
      entire file as a string. The subsequent ftell call returns the 
      file-position pointer's location. */
   fseek(inputFile, 0L, SEEK_END);
   long count = ftell(inputFile);

   /* Use the file's character count to create a variable-length array 
      that can store the entire file as a string. Visual C++ users should
      replace this statement with 
      
         char *json = malloc(sizeof(char) * (count + 1));

      The preceding statement uses dynamic memory allocation to create 
      the array then returns a pointer to it. If this pointer is NULL, 
      the memory was not allocated and you should terminate the program.
      We discuss malloc and dynamic memory allocation in Section 12.3. */
   char json[count + 1];

   // Move the file-position pointer to the beginning of the file.
   fseek(inputFile, 0L, SEEK_SET);  

   // Read the entire contents of the file into the json array.
   fread(json, sizeof(char), count, inputFile);

   // Close the file.
   fclose(inputFile);

   /* SAMPLE JSON RESPONSE: 
      {
        "coord": {
          "lon": -71.06,
          "lat": 42.36
        },
        "weather": [
          {
            "id": 803,
            "main": "Clouds",
            "description": "broken clouds",
            "icon": "04d"
          }
        ],
        "base": "stations",
        "main": {
          "temp": 0.55,
          "feels_like": -5.59,
          "temp_min": 0,
          "temp_max": 1.11,
          "pressure": 1016,
          "humidity": 88
        },
        "visibility": 10000,
        "wind": {
          "speed": 5.7,
          "deg": 340
        },
        "clouds": {
          "all": 75
        },
        "dt": 1609772661,
        "sys": {
          "type": 1,
          "id": 3486,
          "country": "US",
          "sunrise": 1609762409,
          "sunset": 1609795488
        },
        "timezone": -18000,
        "id": 4930956,
        "name": "Boston",
        "cod": 200
      }
   */

   /* Use the cJSON library's cJSON_Parse function to convert the json
      string into a data structure that cJSON uses to extract data from
      the JSON response. You can then use other cJSON functions to 
      request specific items from the JSON. cJSON_Parse returns NULL
      if it's unable to parse the JSON response. */
   cJSON *parsedJson = cJSON_Parse(json); // parse the JSON

   if (parsedJson != NULL) {
      /* Use cJSON's cJSON_GetObjectItemCaseSensitive function to extract
         the value for the key "name" in the JSON. In the sample JSON 
         above, that key-value pair is

            "name": "Boston"

         so this call would return a cJSON object containing "Boston". 
         cJSON_GetObjectItemCaseSensitive looks for the key using a case
         sensitive comparison. */
      const cJSON *cityName = 
         cJSON_GetObjectItemCaseSensitive(parsedJson, "name");

      /* cJSON provides many functions with names that start with "cJSON_Is" 
         that you can use to confirm the type of a value. cJSON_IsString 
         receives a pointer to a cJSON object and returns true if the 
         value it stores is a string. In this case, the cJSON struct 
         object returned by cJSON_GetObjectItemCaseSensitive will contain
         that string in its valuestring member. We confirm that 
         cityName->valuestring is not NULL before printing it. */
      if (cJSON_IsString(cityName) && (cityName->valuestring != NULL)) {
         printf("%s Weather\n", cityName->valuestring);
      }

      /* In the sample JSON shown earlier, the "main" object 

           "main": {
             "temp": 0.55,
             "feels_like": -5.59,
             "temp_min": 0,
             "temp_max": 1.11,
             "pressure": 1016,
             "humidity": 88
           },

         contains several data items we'd like to display in our weather  
         report. The following call to cJSON_GetObjectItemCaseSensitive 
         gets the "main" object, which is itself a JSON object containing 
         other key-value pairs. We can then use this object to extract 
         thedata items we'd like to display. */
      const cJSON *mainData = 
         cJSON_GetObjectItemCaseSensitive(parsedJson, "main");

      /* cJSON function cJSON_IsObject returns true if it's argument
         represents a JSON object (curly braces containing zero or
         more key-value pairs). */
      if (cJSON_IsObject(mainData)) {
         /* For this example, the next four statements use the function
         cJSON_GetObjectItemCaseSensitive to extract from the "main" 
         JSON object the temp, feels_like, pressure and humidity. */
         const cJSON *tempCurrent = 
            cJSON_GetObjectItemCaseSensitive(mainData, "temp");
         const cJSON *feelsLike = 
            cJSON_GetObjectItemCaseSensitive(mainData, "feels_like");
         const cJSON *pressure = 
            cJSON_GetObjectItemCaseSensitive(mainData, "pressure");
         const cJSON *humidity = 
            cJSON_GetObjectItemCaseSensitive(mainData, "humidity");

         /* Display four data items we just extracted. As you saw in the
            "main" object's JSON above, these four values are numeric, so
            we access each cJSON object's valuedouble member to get the 
            numeric value for display. The cJSON object contains valueint
            and valuedouble members and sets BOTH when it parses any 
            numeric value. Of course, when it converts floating-point 
            values to int, the floating-point part is truncated. */
         printf("Temperature: %.1f C\n", tempCurrent->valuedouble); 
         printf(" Feels like: %.1f C\n", feelsLike->valuedouble); 
         printf("   Pressure: %.0f hPa\n", pressure->valuedouble); 
         printf("   Humidity: %.0f%%\n", humidity->valuedouble); 
      }

      /* Next, we get the city's "weather" object

           "weather": [
             {
               "id": 803,
               "main": "Clouds",
               "description": "broken clouds",
               "icon": "04d"
             }
           ],         

         which contains an array of JSON objects. Some OpenWeatherMap web
         services return weather forecasts for multiple days, in which 
         case this array would contain multiple JSON objects. For the 
         city's current weather, this array contains one JSON object from
         which we'll extract the "description" to display. */
      const cJSON *weather = 
         cJSON_GetObjectItemCaseSensitive(parsedJson, "weather");

      /* day is a pointer to a cJSON object that's used in the 
         next statement. */
      const cJSON *day = NULL; 

      /* cJSON macro cJSON_ArrayForEach generates a C for loop that
         iterates through cJSON's underlying JSON array representation.
         Though we know there is only one item in the JSON array in this
         example, we show you cJSON_ArrayForEach so that if you use one 
         of OpenWeatherMap's web services that returns multiple results,
         you can iterate through them. The macro's arguments are: 
         
         - a pointer to a cJSON object in which the loop will store an
           element of the JSON array during each iteraton of the loop. 
           
         - a pointer to a cJSON object representing the JSON array. */
      cJSON_ArrayForEach(day, weather) { 

         /* use cJSON function cJSON_GetObjectItemCaseSensitive to get 
            the value for the "description" key. */
         cJSON *description = 
            cJSON_GetObjectItemCaseSensitive(day, "description");

         /* use cJSON function cJSON_IsString to confirm that the 
            "description" is a string. If it's not NULL, display it. */
         if (cJSON_IsString(description) && 
             (description->valuestring != NULL)) {
            printf(" Conditions: %s\n", description->valuestring);
         }
      }
   }
   
   /* cJSON functon cJSON_Delete releases all the memory resources cJSON
      used to create its data structure representing the JSON response. */
   cJSON_Delete(parsedJson); 
}




/**************************************************************************
 * (C) Copyright 1992-2021 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/

