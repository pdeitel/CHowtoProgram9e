// fig06_04.c
// Computing the sum of the elements of an array.
#include <stdio.h>
#define SIZE 5

// function main begins program execution
int main(void) {
   // use an initializer list to initialize the array
   int a[SIZE] = {1, 2, 3, 4, 5};
   int total = 0; // sum of array
   
   // sum contents of array a         
   for (size_t i = 0; i < SIZE; ++i) {
      total += a[i];                  
   }                                  

   printf("The total of a's values is %d\n", total);
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
