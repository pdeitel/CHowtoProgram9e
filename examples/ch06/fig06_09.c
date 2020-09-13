// fig06_09.c
// Static arrays are initialized to zero if not explicitly initialized.
#include <stdio.h>

void staticArrayInit(void); // function prototype
void automaticArrayInit(void); // function prototype

// function main begins program execution
int main(void) {
   puts("First call to each function:");
   staticArrayInit();   
   automaticArrayInit();

   puts("\n\nSecond call to each function:");
   staticArrayInit();   
   automaticArrayInit();
   puts("");
} 
 
// function to demonstrate a static local array
void staticArrayInit(void) {
   // initializes elements to 0 before the function is called
   static int array1[3];

   puts("\nValues on entering staticArrayInit:");

   // output contents of array1
   for (size_t i = 0; i <= 2; ++i) {
      printf("array1[%zu] = %d  ", i, array1[i]);
   } 

   puts("\nValues on exiting staticArrayInit:");

   // modify and output contents of array1
   for (size_t i = 0; i <= 2; ++i) {
      printf("array1[%zu] = %d  ", i, array1[i] += 5);
   } 
} 

// function to demonstrate an automatic local array
void automaticArrayInit(void) {
   // initializes elements each time function is called
   int array2[3] = {1, 2, 3};

   puts("\n\nValues on entering automaticArrayInit:");

   // output contents of array2
   for (size_t i = 0; i <= 2; ++i) {
      printf("array2[%zu] = %d  ", i, array2[i]);
   } 

   puts("\nValues on exiting automaticArrayInit:");

   // modify and output contents of array2
   for (size_t i = 0; i <= 2; ++i) {
      printf("array2[%zu] = %d  ", i, array2[i] += 5);
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

