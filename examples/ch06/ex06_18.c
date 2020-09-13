// ex06_18.c
// What does this program do?
#include <stdio.h>
#define SIZE 10

// function prototype
void someFunction(const int b[], size_t start, size_t size); 

// function main begins program execution
int main(void) {
   int a[SIZE] = {8, 3, 1, 2, 6, 0, 9, 7, 4, 5}; // initialize a
  
   puts("Answer is:");
   someFunction(a, 0, SIZE);
   puts("");
} 

// What does this function do?
void someFunction(const int b[], size_t start, size_t size) {
   if (start < size) {
      someFunction(b, start + 1, size);
      printf("%d  ", b[start]);
   } 
} 



/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
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

