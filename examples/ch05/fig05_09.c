// fig05_09.c
// Recursive factorial function.
#include <stdio.h>

unsigned long long int factorial(int number); 

int main(void) {
   // calculate factorial(i) and display result
   for (int i = 0; i <= 21; ++i) {
      printf("%d! = %llu\n", i, factorial(i));
   } 
} 

// recursive definition of function factorial  
unsigned long long int factorial(int number) { 
   if (number <= 1) { // base case             
      return 1;                                
   }                                           
   else { // recursive step                    
      return (number * factorial(number - 1)); 
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
