// fig09_12.c
// Reading input with integer conversion specifiers
#include <stdio.h>

int main(void) {
   int a = 0; 
   int b = 0; 
   int c = 0; 
   int d = 0; 
   int e = 0; 
   int f = 0; 
   int g = 0; 

   puts("Enter seven integers: ");
   scanf("%d%i%i%i%o%u%x", &a, &b, &c, &d, &e, &f, &g);

   puts("\nThe input displayed as decimal integers is:");
   printf("%d %d %d %d %d %d %d\n", a, b, c, d, e, f, g);
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
