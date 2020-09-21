// fig07_13.c
// Using operator sizeof to determine standard data type sizes.
#include <stdio.h>

int main(void) {
   char c = '\0';           
   short s = 0;         
   int i = 0;       
   long l = 0;         
   long long ll = 0;         
   float f = 0.0F;        
   double d = 0.0;         
   long double ld = 0.0;   
   int array[20] = {0}; // create array of 20 int elements
   int *ptr = array; // create pointer to array

   printf("    sizeof c = %2zu\t       sizeof(char) = %2zu\n", 
      sizeof c, sizeof(char));
   printf("    sizeof s = %2zu\t      sizeof(short) = %2zu\n", 
      sizeof s, sizeof(short));
   printf("    sizeof i = %2zu\t        sizeof(int) = %2zu\n", 
      sizeof i, sizeof(int));
   printf("    sizeof l = %2zu\t       sizeof(long) = %2zu\n", 
      sizeof l, sizeof(long));
   printf("   sizeof ll = %2zu\t  sizeof(long long) = %2zu\n", 
      sizeof ll, sizeof(long long));
   printf("    sizeof f = %2zu\t      sizeof(float) = %2zu\n", 
      sizeof f, sizeof(float));
   printf("    sizeof d = %2zu\t     sizeof(double) = %2zu\n",
      sizeof d, sizeof(double));
   printf("   sizeof ld = %2zu\tsizeof(long double) = %2zu\n",
      sizeof ld, sizeof(long double));
   printf("sizeof array = %2zu\n  sizeof ptr = %2zu\n", 
      sizeof array, sizeof ptr);
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


