// fig02_05.c
// Using if statements, relational 
// operators, and equality operators.
#include <stdio.h>

// function main begins program execution
int main(void) {
   printf("Enter two integers, and I will tell you\n");
   printf("the relationships they satisfy: ");

   int number1 = 0; // first number to be read from user
   int number2 = 0; // second number to be read from user
   
   scanf("%d %d", &number1, &number2); // read two integers
   
   if (number1 == number2) {                          
      printf("%d is equal to %d\n", number1, number2);
   } // end if                                        

   if (number1 != number2) {
      printf("%d is not equal to %d\n", number1, number2);
   } // end if

   if (number1 < number2) {
      printf("%d is less than %d\n", number1, number2);
   } // end if

   if (number1 > number2) {
      printf("%d is greater than %d\n", number1, number2);
   } // end if

   if (number1 <= number2) {
      printf("%d is less than or equal to %d\n", number1, number2);
   } // end if

   if (number1 >= number2) {
      printf("%d is greater than or equal to %d\n", number1, number2);
   } // end if
} // end function main



/**************************************************************************
 * (C) Copyright 1992-2015 by Deitel & Associates, Inc. and               *
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
