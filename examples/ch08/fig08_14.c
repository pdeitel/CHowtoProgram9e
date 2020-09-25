// fig08_14.c
// Using function strchr
#include <stdio.h>
#include <string.h>

int main(void) {
   const char *string = "This is a test"; // initialize char pointer 
   char character1 = 'a'; // initialize character1
   char character2 = 'z'; // initialize character2
   
   // if character1 was found in string
   if (strchr(string, character1) != NULL) { // can remove "!= NULL"
      printf("\'%c\' was found in \"%s\".\n", character1, string);
   } 
   else { // if character1 was not found
      printf("\'%c\' was not found in \"%s\".\n", character1, string);
   } 

   // if character2 was found in string
   if (strchr(string, character2) != NULL) { // can remove "!= NULL"
      printf("\'%c\' was found in \"%s\".\n", character2, string);
   } 
   else { // if character2 was not found
      printf("\'%c\' was not found in \"%s\".\n", character2, string);
   } 
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
