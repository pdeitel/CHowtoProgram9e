// fig05_02.c
// Finding the maximum of three integers.
#include <stdio.h>

int maximum(int x, int y, int z); // function prototype

int main(void) {
   int number1 = 0; // first integer entered by the user
   int number2 = 0; // second integer entered by the user
   int number3 = 0; // third integer entered by the user

   printf("%s", "Enter three integers: ");
   scanf("%d%d%d", &number1, &number2, &number3);
   
   // number1, number2 and number3 are arguments 
   // to the maximum function call
   printf("Maximum is: %d\n", maximum(number1, number2, number3));
} 

// Function maximum definition
int maximum(int x, int y, int z) {            
   int max = x; // assume x is largest        
                                              
   if (y > max) { // if y is larger than max, 
      max = y; // assign y to max             
   }                                          
                                              
   if (z > max) { // if z is larger than max, 
      max = z; // assign z to max             
   }                                          
                                              
   return max; // max is largest value        
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

