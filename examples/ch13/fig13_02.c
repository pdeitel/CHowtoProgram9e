// fig13_02.c 
// The insertion sort algorithm. 
#define SIZE 10
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes 
void insertionSort(int array[], size_t length);
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
   insertionSort(array, SIZE);
   puts("Sorted array:");
   
   for (size_t i = 0; i < SIZE; i++) { // print the array 
      printf("%d  ", array[i]);
   }

   puts("");  
}

// function that sorts the array 
void insertionSort(int array[], size_t length) {
   // loop over length - 1 elements 
   for (size_t i = 1; i < length; i++) {
       size_t moveItem = i; // initialize location to place element 
       int insert = array[i]; // holds element to insert
        
       // search for place to put current element 
       while (moveItem > 0 && array[moveItem - 1] > insert) {
           // shift element right one slot 
           array[moveItem] = array[moveItem - 1];
           --moveItem;
       }
        
       array[moveItem] = insert; // place inserted element 
       printPass(array, length, i, moveItem);
   } 
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
   for (size_t i = 0; i <= pass; i++) {
       printf("%s", "--  ");
   }
    
   puts(""); // add newline 
} 



/**************************************************************************
 * (C) Copyright 1992-2013 by Deitel & Associates, Inc. and               *
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
