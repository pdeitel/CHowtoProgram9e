// fig06_05.c
// Analyzing a student poll.
#include <stdio.h>
#define RESPONSES_SIZE 20 // define array sizes
#define FREQUENCY_SIZE 6

// function main begins program execution
int main(void) {
   // place the survey responses in the responses array
   int responses[RESPONSES_SIZE] = 
      {1, 2, 5, 4, 3, 5, 2, 1, 3, 1, 4, 3, 3, 3, 2, 3, 3, 2, 2, 5};

   // initialize frequency counters to 0
   int frequency[FREQUENCY_SIZE] = {0};
   
   // for each answer, select the value of an element of the array
   // responses and use that value as a subscript into the array   
   // frequency to determine the element to increment
   for (size_t answer = 0; answer < RESPONSES_SIZE; ++answer) {
      ++frequency[responses[answer]];
   } 

   // display results
   printf("%s%12s\n", "Rating", "Frequency");

   // output the frequencies in a tabular format
   for (size_t rating = 1; rating < FREQUENCY_SIZE; ++rating) {
      printf("%6zu%12d\n", rating, frequency[rating]);
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

