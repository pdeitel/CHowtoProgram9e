// anscombe_macos.c
// Simple linear regression with Anscombe's Quartet and the GNU Scientific
// Library, and plotting with gnuplot.
#include <gsl/gsl_fit.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAMPLES 11
#define DATASETS 4
#define SIZE 80

/* Use the GNU Scientific Library's gsl_fit_linear function to perform
   simple lineary regression on the x-y data samples in the x and y 
   arguments. Store the y-intercept and slope in the variables that the
   intercept and slope parameters point to. */
void performRegression(double x[], double y[], 
   double *intercept, double *slope) {

   /* Required arguments to function gsl_fit_linear. 
      In this example, we do not use the results gsl_fit_linear stores 
      in these variables. */ 
   double cov00 = 0.0; 
   double cov01 = 0.0;
   double cov11 = 0.0;
   double chi_squared = 0.0;

   /* The GNU Scientific Library's gsl_fit_linear function performs simple
      linear regression to find the straight line that best fits the 
      provided data samples. The function's parameters are as follows:

      - x is an array of x-coordinates for the data samples.

      - xstride is the increment between elements in the x array. For the 
        value 1, gsl_fit_linear uses every element from the beginning of the
        array up to the number of elements specified by the parameter n.

      - y is an array of y-coordinates for the data samples.

      - ystride is the increment between elements in the y array. For the 
        value 1, gsl_fit_linear uses every element from the beginning of the
        array up to the number of elements specified by the parameter n.

      - n is the number of x-y coordinate pairs to use in the regression.
      
       -c0 is a pointer to the variable in which gsl_fit_linear will store 
        the y-intercept of the linear regression line.

      - c1 is a pointer to the variable in which gsl_fit_linear will store
        the slope of the linear regression line.

      - gsl_fit_linear's last four arguments are pointers of type double 
        that are used to store additional information. We do not use these
        in this example, but they are required to call the function. 
        For details on these parameters, visit:
           https://www.gnu.org/software/gsl/doc/html/lls.html
   */
   gsl_fit_linear(x, 1, y, 1, SAMPLES, intercept, slope,
      &cov00, &cov01, &cov11, &chi_squared);
}

// read Anscombe's Quartet CSV data into program 
void readAnscombesQuartetData(double x1[], double y1[], 
   double x2[], double y2[], double x3[], double y3[], 
   double x4[], double y4[]) {

   FILE *file = NULL;
   
   // open the CSV-format text file anscombe.csv for reading
   if ((file = fopen("anscombe.csv" , "r")) == NULL) { 
      printf("Unable to open anscombe.csv"); 
      exit(0); 
   } 
   
   puts("Loading Anscombe's Quartet Data");
   char line[SIZE] = ""; // used to store each line read from anscombe.csv

   /* The first line of the CSV file contains column heads that identify the
      columns x1, y1, x2, y2, x3, y3, x4 and y4. The following fgets call
      reads that line of text. We do not use the column heads in this 
      example, so we simply ignore them. */
   fgets(line, SIZE, file); 

   /* The Anscombe's Quartet data items are double values. For each  
      remaining line in the file, we use the C function strtok to tokenize 
      the line's eight columns. We pass each token to C function atof to
      convert it to a double, then store it in the appropriate array. */
   for (size_t i = 0; i < SAMPLES; ++i) {
      fgets(line, SIZE, file); // read next line

      x1[i] = atof(strtok(line, ",\n")); // convert x1
      y1[i] = atof(strtok(NULL, ",\n")); // convert y1
      x2[i] = atof(strtok(NULL, ",\n")); // convert x2
      y2[i] = atof(strtok(NULL, ",\n")); // convert y2
      x3[i] = atof(strtok(NULL, ",\n")); // convert x3
      y3[i] = atof(strtok(NULL, ",\n")); // convert y3
      x4[i] = atof(strtok(NULL, ",\n")); // convert x4
      y4[i] = atof(strtok(NULL, ",\n")); // convert y4
   }

   puts("Loaded Anscombe's Quartet Data");
}

int main(void) {
   /* The following arrays will store the slopes and intercepts calculated
      by gsl_fit_linear. We ignore each array's element 0 so the array
      subscript (1 through 4) matches the dataset number. */
   double slopes[DATASETS + 1] = {0.0}; 
   double intercepts[DATASETS + 1] = {0.0}; 

   // We load the Anscombe's Quartet data samples into the following arrays.
   double x1[SAMPLES] = {0};
   double y1[SAMPLES] = {0};
   double x2[SAMPLES] = {0};
   double y2[SAMPLES] = {0};
   double x3[SAMPLES] = {0};
   double y3[SAMPLES] = {0};
   double x4[SAMPLES] = {0};
   double y4[SAMPLES] = {0};

   /* Call readAnscombesQuartetData to load the datasets into the 
      arrays defined above. */
   readAnscombesQuartetData(x1, y1, x2, y2, x3, y3, x4, y4);

   /* Call performRegression for each dataset. This function calls 
      gsl_fit_linear to perform the simple linear regression and store the 
      resulting y-intercept and slope values. */
   performRegression(x1, y1, &intercepts[1], &slopes[1]);
   performRegression(x2, y2, &intercepts[2], &slopes[2]);
   performRegression(x3, y3, &intercepts[3], &slopes[3]);
   performRegression(x4, y4, &intercepts[4], &slopes[4]);

   printf("%7s  %9s  %7s\n", "Dataset", "Intercept", "Slope");

   /* For each dataset, display the dataset number and the dataset's 
      y-intercept and slope values calculated by gsl_fit_linear. */
   for (int i = 1; i <= DATASETS; ++i) { 
      printf("%7d  %9.5f  %7.5f\n", i, intercepts[i], slopes[i]);
   }

   /* The rest of this program sends gnuplot commands to the gnuplot 
      application. You can send commands from one application to another 
      via an operating system capability known as a pipe. In particular,
      a pipe enables output from one running application to be passed to 
      another. In macOS and Linux, you "open a pipe" using the nonstandard 
      popen function (short for "pipe open") from the <stdio.h> header. In 
      Windows, the function's name is _popen. The popen and _popen functions
      each receive two arguments. The first is a command for the operating 
      system to execute and the second is a file-open mode. Similar to file
      I/O, popen and _popen enable bytes to be written to or read from
      another application. This following function call launches the gnuplot
      application and opens a pipe to it through which we can write ("w"), 
      enabling this application to send bytes to gnuplot. */
   FILE *pipe = popen("gnuplot" , "w"); 
   
   // Ensure that the pipe opened successfully; if not, terminate.
   if (pipe == NULL) { 
      printf("Unable to open gnuplot\n"); 
      exit(0); 
   } 
   
   /* Once you open the pipe, you can use standard file-processing  
      functions, such as fprintf, to send text commands to gnuplot through 
      the pipe. You simply use the pipe's FILE pointer as the output 
      destination for each command. */

   /* gnuplot can read data from a text file, such as anscombe.csv, and plot
      the data. gnuplot's "set datafile separator" command specifies the
      separator character used to separate the columns in each data row. 
      In this example, we use CSV data, so the separator is a comma. 
      Each gnuplot command you send through the pipe should end with a 
      newline character, which tells gnuplot to execute that command. */
   fprintf(pipe, "set datafile separator ','\n");

   /* gnuplot's "set terminal" command specifies the output file format
      and configuration. The command's arguments

         png size 1600,900 font ',30'

      indicate that we will output plots as PNG format images that are 1600
      pixels wide and 900 pixels tall, using gnuplot's default font in 30pt 
      size to label the plots. You could specify a custom font before the 
      comma in ',30'. */
   fprintf(pipe, "set terminal png size 1600,900 font ',30'\n");

   /* gnuplot's "set pointsize" command sets the size of the points (dots)
      displayed on the plot. The default pointsize is 1. */
   fprintf(pipe, "set pointsize 5\n");

   /* gnuplot's "set nokey" command indicates that the plot should 
      not have a key describing the meaning of various plot elements. */
   fprintf(pipe, "set nokey\n");

   /* gnuplot's "set xrange" command sets the x-axis range. In this example,
      we set every plot's x-axis range from 2 through 20 so all the plots
      have identical x-axes. */
   fprintf(pipe, "set xrange [2:20]\n");

   /* gnuplot's "set yrange" command sets the y-axis range. In this example,
      we set every plot's y-axis range from 2 through 14 so all the plots
      have identical y-axes. Setting both the x- and y-axes identically
      for all four plots ensures that all the dots and regression lines
      are plotted using the same scale. This will enable you to see that 
      the regression lines appear to be identical. */
   fprintf(pipe, "set yrange [2:14] \n");

   // The following loop produces the four plots
   for (int i = 1; i <= DATASETS; ++i) {
      // gnuplot's "set title" command sets the title above the plot
      fprintf(pipe, "set title 'Dataset %d'\n", i);

      /* gnuplot's "set output" command sets the PNG image's filename
         in which the plot will be stored. */
      fprintf(pipe, "set output 'dataset%d.png'\n", i);

      /* gnuplot's "plot" command creates a plot. The following is a sample
         plot command sent to gnuplot when the fprintf below executes:

            plot 'anscombe.csv' using 1:2 with points pointtype 7, 0.5*x+3.0 linewidth 3 linecolor rgb 'red'

         The following are the plot command's arguments:

         'anscombe.csv' 
            The file containing the data to plot.

         using %d:%d 
           Specifies the start and end column numbers to plot. We substitute
           integer values for the two %d specifiers. For example, 0:1 
           indicates that the x-y coordinates for the plot are in columns 0 
           and 1 of anscombes.csv.

         with points 
           Gnuplot will display individual x-y data points.

         pointtype 7, 
           Points are displayed using gnuplot point type 7 (circular dots).

         %f*x+%f
           This is the calculation mx + b that is used to calculate the 
           regression line's points. The first %f is replaced with the 
           slope (m) and the second %f is replaced with the intercept (b).

         linewidth 3
           Specifies the regression line's thickness should be 3pt.

         linecolor rgb 'red' 
           Specifies that lines should be displayed in red.

         Note that the two strings in the fprintf below are concatenated
         by the compiler because they are separated only by whitespace.
      */
      fprintf(pipe, "plot 'anscombe.csv' using %d:%d with points "
         "pointtype 7, %f*x+%f linewidth 3 linecolor rgb 'red'\n", 
         i * 2 - 1, i * 2, slopes[i], intercepts[i]);
   }

   // Close the pipe to terminate the connection to gnuplot. 
   fclose(pipe); 
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
 **************************************************************************/
