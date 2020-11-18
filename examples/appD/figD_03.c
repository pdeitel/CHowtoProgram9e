// figD_03.c
// Using bool, true and false.
#include <stdio.h>
#include <stdbool.h> // allows the use of bool, true, and false

bool isEven(int number); // function prototype

int main(void) {
   // loop for 2 inputs
   for (int i = 0; i < 2; ++i) {
      printf("Enter an integer: ");
      int input = 0; // value entered by user
      scanf("%d", &input);

      bool valueIsEven = isEven(input); // determine if input is even

      // determine whether input is even
      if (valueIsEven) {
         printf("%d is even\n\n", input);
      } 
      else {
         printf("%d is odd\n\n", input);
      } 
   } 
} 

// isEven returns true if number is even 
bool isEven(int number) {
   if (number % 2 == 0) { // is number divisible by 2?
      return true;
   } 
   else {
      return false;
   }
} 


 /*************************************************************************
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
