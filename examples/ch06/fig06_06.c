// fig06_06.c
// Displaying a bar chart.
#include <stdio.h>
#define SIZE 5

// function main begins program execution
int main(void) {
   // use initializer list to initialize array n
   int n[SIZE] = {19, 3, 15, 7, 11};

   printf("%s%13s%17s\n", "Element", "Value", "Bar Chart");

   // for each element of array n, output a bar of the bar chart
   for (size_t i = 0; i < SIZE; ++i) {
      printf("%7zu%13d        ", i, n[i]);

      for (int j = 1; j <= n[i]; ++j) { // print one bar
         printf("%c", '*');                             
      }                                                 

      puts(""); // end a bar with a newline
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
