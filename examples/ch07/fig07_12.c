// fig07_12.c
// Applying sizeof to an array name returns 
// the number of bytes in the array.
#include <stdio.h>
#define SIZE 20

size_t getSize(const float *ptr); // prototype

int main(void){
   float array[SIZE]; // create array

   printf("Number of bytes in the array is %zu\n", sizeof(array));
   printf("Number of bytes returned by getSize is %zu\n", getSize(array));
} 

// return size of ptr
size_t getSize(const float *ptr) {
   return sizeof(ptr);
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

