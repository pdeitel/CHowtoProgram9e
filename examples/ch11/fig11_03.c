// fig11_03.c
// Credit inquiry program
#include <stdbool.h>
#include <stdio.h>

enum Options {ZERO_BALANCE = 1, CREDIT_BALANCE, DEBIT_BALANCE, END};

// determine whether to display a record
bool shouldDisplay(enum Options option, double balance) {
   if ((option == ZERO_BALANCE) && (balance == 0)) {
      return true;
   } 

   if ((option == CREDIT_BALANCE) && (balance < 0)) {
      return true;
   } 

   if ((option == DEBIT_BALANCE) && (balance > 0)) {
      return true;
   } 

   return false;
} 

int main(void) {
   FILE *cfPtr = NULL; // clients.txt file pointer

   // fopen opens the file; exits program if file cannot be opened
   if ((cfPtr = fopen("clients.txt", "r")) == NULL) {
      puts("File could not be opened");
   } 
   else {
      // display request options
      printf("%s", "Enter request\n"
         " 1 - List accounts with zero balances\n"
         " 2 - List accounts with credit balances\n"
         " 3 - List accounts with debit balances\n"
         " 4 - End of run\n? ");
      int request = 0; 
      scanf("%d", &request);

      // display records
      while (request != END) { 
         switch (request) { 
            case ZERO_BALANCE:
               puts("\nAccounts with zero balances:");
               break;
            case CREDIT_BALANCE:
               puts("\nAccounts with credit balances:");
               break;
            case DEBIT_BALANCE:
               puts("\nAccounts with debit balances:");
               break;
         }

         int account = 0;  
         char name[30] = ""; 
         double balance = 0.0; 

         // read account, name and balance from file          
         fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);

         // read file contents (until eof)
         while (!feof(cfPtr)) { 
            // output only if balance is 0
            if (shouldDisplay(request, balance)) {
               printf("%-10d%-13s%7.2f\n", account, name, balance);
            } 

            // read account, name and balance from file
            fscanf(cfPtr, "%d%29s%lf", &account, name, &balance);
         } 

         rewind(cfPtr); // return cfPtr to beginning of file

         printf("%s", "\n? ");
         scanf("%d", &request);
      } 

      puts("End of run.");
      fclose(cfPtr); // close the file
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
