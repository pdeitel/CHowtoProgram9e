// fig08_11.c
// Using functions strcpy and strncpy
#include <stdio.h>
#include <string.h>
#define SIZE1 25
#define SIZE2 15

int main(void) {
   char x[] = "Happy Birthday to You"; // initialize char array x
   char y[SIZE1] = ""; // create char array y
   char z[SIZE2] = ""; // create char array z
   
   // copy contents of x into y
   printf("%s%s\n%s%s\n", 
      "The string in array x is: ", x,
      "The string in array y is: ", strcpy(y, x));

   strncpy(z, x, SIZE2 - 1); // copy first 14 characters of x into z
   z[SIZE2 - 1] = '\0'; // terminate string in z, because '\0' not copied
   printf("The string in array z is: %s\n", z);
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
