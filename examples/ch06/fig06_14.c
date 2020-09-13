// fig06_14.c
// Linear search of an array.
#include <stdio.h>
#define SIZE 100

// function prototype
int linearSearch(const int array[], int key, size_t size); 

// function main begins program execution
int main(void) {
   int a[SIZE] = {0}; // create array a

   // create some data
   for (size_t x = 0; x < SIZE; ++x) { 
      a[x] = 2 * x;
   } 

   printf("Enter integer search key: ");
   int searchKey = 0; // value to locate in array a
   scanf("%d", &searchKey);

   // attempt to locate searchKey in array a 
   int subscript = linearSearch(a, searchKey, SIZE); 

   // display results
   if (subscript != -1) {
      printf("Found value at subscript %d\n", subscript);
   } 
   else {
      puts("Value not found");
   } 
} 

// compare key to every element of array until the location is found 
// or until the end of array is reached; return subscript of element 
// if key is found or -1 if key is not found                              
int linearSearch(const int array[], int key, size_t size) { 
   // loop through array                                    
   for (size_t n = 0; n < size; ++n) {                      
      if (array[n] == key) {                                
         return n; // return location of key                
      }                                                     
   }                                                        
                                                            
   return -1; // key not found                              
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

