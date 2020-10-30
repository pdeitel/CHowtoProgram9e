// fig15_01.c
// Using variable-length argument lists
#include <stdarg.h> 
#include <stdio.h>

double average(int i, ...); // ... represents variable arguments

int main(void) {
   double w = 37.5; 
   double x = 22.5; 
   double y = 1.7;  
   double z = 10.2; 

   printf("%s%.1f; %s%.1f; %s%.1f; %s%.1f\n\n",
      "w = ", w, "x = ", x, "y = ", y, "z = ", z);
   printf("%s%.3f\n%s%.3f\n%s%.3f\n",
      "The average of w and x is ", average(2, w, x),
      "The average of w, x, and y is ", average(3, w, x, y),
      "The average of w, x, y, and z is ", average(4, w, x, y, z));
} 

// calculate average
double average(int i, ...) {
   double total = 0; // initialize total
   va_list ap; // stores information needed by va_start and va_end

   va_start(ap, i); // initializes the va_list object

   // process variable-length argument list
   for (int j = 1; j <= i; ++j) {
      total += va_arg(ap, double);
   } 

   va_end(ap); // clean up variable-length argument list
   return total / i; // calculate average
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
