// figC_04.c
// Complex number operations.
#include <complex.h> // for complex type and math functions
#include <stdio.h>

int main(void) {
   double complex a = 3.0 + 2.0 * I; 
   double complex b = 2.7 + 4.9 * I; 

   printf("a is %.1f + %.1fi\n", creal(a), cimag(a));
   printf("b is %.1f + %.1fi\n", creal(b), cimag(b));

   double complex sum = a + b; // perform complex addition
   printf("a + b is: %.1f + %.1fi\n", creal(sum), cimag(sum));

   double complex difference = a - b; // perform complex subtraction
   printf("a - b is: %.1f + %.1fi\n", creal(difference), cimag(difference));

   double complex product = a * b; // perform complex multiplicaton
   printf("a * b is: %.1f + %.1fi\n", creal(product), cimag(product));

   double complex quotient = a / b; // perform complex division
   printf("a / b is: %.1f + %.1fi\n", creal(quotient), cimag(quotient));

   double complex power = cpow(a, 2.0); // perform complex exponentiation
   printf("a ^ b is: %.1f + %.1fi\n", creal(power), cimag(power));
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
