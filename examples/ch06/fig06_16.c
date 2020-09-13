// fig06_16.c
// Initializing multidimensional arrays.
#include <stdio.h>

void printArray(int a[][3]); // function prototype

// function main begins program execution
int main(void) {
   int array1[2][3] = {{1, 2, 3}, {4, 5, 6}};
   puts("Values in array1 by row are:");
   printArray(array1);

   int array2[2][3] = {{1, 2, 3}, {4, 5}};       
   puts("Values in array2 by row are:");
   printArray(array2);

   int array3[2][3] = {{1, 2}, {4}};         
   puts("Values in array3 by row are:");
   printArray(array3);
} 

// function to output array with two rows and three columns
void printArray(int a[][3]) {
   // loop through rows                                    
   for (size_t i = 0; i <= 1; ++i) {                        
      // output column values                              
      for (size_t j = 0; j <= 2; ++j) {                      
         printf("%d ", a[i][j]);                        
      }                                    
                                                              
      printf("\n"); // start new line of output          
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

