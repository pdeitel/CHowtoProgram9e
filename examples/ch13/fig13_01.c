// fig13_01.c
// The selection sort algorithm. 
#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes 
void selectionSort(int array[], size_t length);
void swap(int array[], size_t first, size_t second);
void printPass(int array[], size_t length, int pass, size_t index);

int main(void) {
   int array[SIZE] = {0}; // declare the array of ints to be sorted 
    
   srand(time(NULL)); // seed the rand function 
    
   for (size_t i = 0; i < SIZE; i++) {
      array[i] = rand() % 90 + 10; // give each element a value 
   }
        
   puts("Unsorted array:");
    
   for (size_t i = 0; i < SIZE; i++) { // print the array 
      printf("%d  ", array[i]);
   }
        
   puts("\n");
   selectionSort(array, SIZE);
   puts("Sorted array:");
    
   for (size_t i = 0; i < SIZE; i++) { // print the array 
      printf("%d  ", array[i]);
   }

   puts("");  
} 

// function that selection sorts the array 
void selectionSort(int array[], size_t length) {
   // loop over length - 1 elements 
   for (size_t i = 0; i < length - 1; i++) {
      size_t smallest = i; // first index of remaining array 
        
      // loop to find index of smallest element 
      for (size_t j = i + 1; j < length; j++) {
         if (array[j] < array[smallest]) {
            smallest = j;
         }
      }
                
      swap(array, i, smallest); // swap smallest element 
      printPass(array, length, i + 1, smallest); // output pass 
   } 
}

// function that swaps two elements in the array 
void swap(int array[], size_t first, size_t second) {
   int temp = array[first];
   array[first] = array[second];
   array[second] = temp;
} 

// function that prints a pass of the algorithm 
void printPass(int array[], size_t length, int pass, size_t index) {
   printf("After pass %2d: ", pass);
    
   // output elements till selected item 
   for (size_t i = 0; i < index; i++) {
      printf("%d  ", array[i]);
   }
        
   printf("%d* ", array[index]); // indicate swap 
    
   // finish outputting array 
   for (size_t i = index + 1; i < length; i++) {
      printf("%d  ", array[i]);
   }
        
   printf("%s", "\n               "); // for alignment 
    
   // indicate amount of array that is sorted 
   for (int i = 0; i < pass; i++) {
      printf("%s", "--  ");
   }
    
   puts(""); // add newline 
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