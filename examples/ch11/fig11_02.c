// fig11_02.c
// Reading and printing a sequential file
#include <stdio.h>

int main(void) {
   FILE *cfPtr = NULL; // cfPtr = clients.txt file pointer

   // fopen opens file; exits program if file cannot be opened 
   if ((cfPtr = fopen("clients.txt", "r")) == NULL) {
      puts("File could not be opened");
   } 
   else { // read account, name and balance from file
      int account = 0; // account number   
      char name[30] = ""; // account name
      double balance = 0.0; // account balance  

      printf("%-10s%-13s%s\n", "Account", "Name", "Balance");
      fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);

      // while not end of file
      while (!feof(cfPtr)) { 
         printf("%-10d%-13s%7.2f\n", account, name, balance);
         fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);
      } 

      fclose(cfPtr); // fclose closes the file   
   } 
} 

 

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