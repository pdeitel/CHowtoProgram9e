// figC_05.c
// Fibonacci calculations performed sequentially
#include <stdio.h>
#include <time.h>

long long int fibonacci(int n); // function prototype

int main(void) {
   puts("Sequential calls to fibonacci(50) and fibonacci(49)");

   // calculate fibonacci value for 50
   time_t startTime1 = time(NULL);
   puts("Calculating fibonacci(50)");
   long long int result1 = fibonacci(50);
   time_t endTime1 = time(NULL);

   printf("fibonacci(50) = %llu\n", result1);
   printf("Calculation time = %f minutes\n\n", 
      difftime(endTime1, startTime1) / 60.0);

   time_t startTime2 = time(NULL);
   puts("Calculating fibonacci(49)");
   long long int result2 = fibonacci(49);
   time_t endTime2 = time(NULL);

   printf("fibonacci(49) = %llu\n", result2);
   printf("Calculation time = %f minutes\n\n", 
      difftime(endTime2, startTime2) / 60.0);

   printf("Total calculation time = %f minutes\n", 
      difftime(endTime2, startTime1) / 60.0);
} 

// Recursively calculates fibonacci numbers
long long int fibonacci(int n) {   
   if (0 == n || 1 == n) { // base case
      return n;                                      
   }                                        
   else { // recursive step                          
      return fibonacci(n - 1) + fibonacci(n - 2);
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
