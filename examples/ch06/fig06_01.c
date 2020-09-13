// fig06_01.c
// Initializing the elements of an array to zeros.
#include <stdio.h>

// function main begins program execution
int main(void) {
   int n[5]; // n is an array of five integers
   
   // set elements of array n to 0        
   for (size_t i = 0; i < 5; ++i) {              
      n[i] = 0; // set element at location i to 0
   }                                             
   
   printf("%s%8s\n", "Element", "Value");

   // output contents of array n in tabular format
   for (size_t i = 0; i < 5; ++i) {               
      printf("%7zu%8d\n", i, n[i]);               
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
