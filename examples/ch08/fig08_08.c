// fig08_08.c
// Using function getchar.
#include <stdio.h>
#define SIZE 80

int main(void) {
   int c = 0; // variable to hold character input by user
   char sentence[SIZE] = ""; 
   int i = 0; 

   puts("Enter a line of text:"); 

   // use getchar to read each character              
   while ((i < SIZE - 1) && (c = getchar()) != '\n') {
      sentence[i++] = c;                              
   }                                                  

   sentence[i] = '\0'; // terminate string

   puts("\nThe line entered was:");
   puts(sentence); // display sentence
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