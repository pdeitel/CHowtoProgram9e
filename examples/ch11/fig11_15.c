// Fig. 11.15: fig11_15.c
// Transaction-processing program reads a random-access file sequentially, 
// updates data already written to the file, creates new data to 
// be placed in the file, and deletes data previously in the file.
#include <stdio.h>

// clientData structure definition               
struct clientData {                              
   unsigned int acctNum; // account number
   char lastName[15]; // account last name     
   char firstName[10]; // account first name   
   double balance; // account balance            
}; 

// prototypes
unsigned int enterChoice(void);
void textFile(FILE *readPtr);
void updateRecord(FILE *fPtr);
void newRecord(FILE *fPtr);
void deleteRecord(FILE *fPtr);

int main(void)
{ 
   FILE *cfPtr; // accounts.dat file pointer

   // fopen opens the file; exits if file cannot be opened
   if ((cfPtr = fopen("accounts.dat", "rb+")) == NULL) {
      puts("File could not be opened.");
   } 
   else { 
      unsigned int choice; // user's choice

      // enable user to specify action
      while ((choice = enterChoice()) != 5) { 
         switch (choice) { 
            // create text file from record file
            case 1:
               textFile(cfPtr);
               break;
            // update record
            case 2:
               updateRecord(cfPtr);
               break;
            // create record
            case 3:
               newRecord(cfPtr);
               break;
            // delete existing record
            case 4:
               deleteRecord(cfPtr);
               break;
            // display message if user does not select valid choice
            default:
               puts("Incorrect choice");
               break;
         } 
      } 

      fclose(cfPtr); // fclose closes the file
   } 
} 

// create formatted text file for printing 
void textFile(FILE *readPtr)
{ 
   FILE *writePtr; // accounts.txt file pointer

   // fopen opens the file; exits if file cannot be opened
   if ((writePtr = fopen("accounts.txt", "w")) == NULL) {
      puts("File could not be opened.");
   } 
   else { 
      rewind(readPtr); // sets pointer to beginning of file
      fprintf(writePtr, "%-6s%-16s%-11s%10s\n", 
         "Acct", "Last Name", "First Name","Balance");

      // copy all records from random-access file into text file
      while (!feof(readPtr)) { 
         // create clientData with default information
         struct clientData client = {0, "", "", 0.0};
         int result = 
            fread(&client, sizeof(struct clientData), 1, readPtr);

         // write single record to text file
         if (result != 0 && client.acctNum != 0) {
            fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n",
               client.acctNum, client.lastName,         
               client.firstName, client.balance);      
         } 
      } 

      fclose(writePtr); // fclose closes the file
   } 
}

// update balance in record
void updateRecord(FILE *fPtr)
{ 
   // obtain number of account to update
   printf("%s", "Enter account to update (1 - 100): ");
   unsigned int account; // account number
   scanf("%d", &account);

   // move file pointer to correct record in file              
   fseek(fPtr, (account - 1) * sizeof(struct clientData), 
      SEEK_SET);                                              

   // create clientData with no information
   struct clientData client = {0, "", "", 0.0};

   // read record from file
   fread(&client, sizeof(struct clientData), 1, fPtr);

   // display error if account does not exist
   if (client.acctNum == 0) {
      printf("Account #%d has no information.\n", account);
   } 
   else { // update record
      printf("%-6d%-16s%-11s%10.2f\n\n", 
         client.acctNum, client.lastName, 
         client.firstName, client.balance);
      
      // request transaction amount from user 
      printf("%s", "Enter charge (+) or payment (-): ");
      double transaction; // transaction amount
      scanf("%lf", &transaction);
      client.balance += transaction; // update record balance
      
      printf("%-6d%-16s%-11s%10.2f\n", 
         client.acctNum, client.lastName, 
         client.firstName, client.balance);
      
      // move file pointer to correct record in file              
      fseek(fPtr, (account - 1) * sizeof(struct clientData), 
         SEEK_SET);                                              

      // write updated record over old record in file         
      fwrite(&client, sizeof(struct clientData), 1, fPtr);
   } 
}

// delete an existing record
void deleteRecord(FILE *fPtr)
{ 
   // obtain number of account to delete
   printf("%s", "Enter account number to delete (1 - 100): ");
   unsigned int accountNum; // account number
   scanf("%d", &accountNum);

   // move file pointer to correct record in file                 
   fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), 
      SEEK_SET);                                                 

   struct clientData client; // stores record read from file

   // read record from file                               
   fread(&client, sizeof(struct clientData), 1, fPtr);

   // display error if record does not exist
   if (client.acctNum == 0) {
      printf("Account %d does not exist.\n", accountNum);
   } 
   else { // delete record
      // move file pointer to correct record in file                 
      fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), 
         SEEK_SET);                                                 

      struct clientData blankClient = { 0, "", "", 0 }; // blank client

      // replace existing record with blank record   
      fwrite(&blankClient,                          
         sizeof(struct clientData), 1, fPtr);     
   } 
} 

// create and insert record
void newRecord(FILE *fPtr)
{ 
   // obtain number of account to create
   printf("%s", "Enter new account number (1 - 100): ");
   unsigned int accountNum; // account number
   scanf("%d", &accountNum);

   // move file pointer to correct record in file                 
   fseek(fPtr, (accountNum - 1) * sizeof(struct clientData), 
      SEEK_SET);                                                 

   // create clientData with default information
   struct clientData client = { 0, "", "", 0.0 };

   // read record from file                               
   fread(&client, sizeof(struct clientData), 1, fPtr);

   // display error if account already exists
   if (client.acctNum != 0) {
      printf("Account #%d already contains information.\n",
         client.acctNum);
   } 
   else { // create record
      // user enters last name, first name and balance
      printf("%s", "Enter lastname, firstname, balance\n? ");
      scanf("%14s%9s%lf", &client.lastName, &client.firstName, 
         &client.balance);

      client.acctNum = accountNum;
      
      // move file pointer to correct record in file   
      fseek(fPtr, (client.acctNum - 1) *            
         sizeof(struct clientData), SEEK_SET);      

      // insert record in file                       
      fwrite(&client,                               
         sizeof(struct clientData), 1, fPtr);     
   } 
} 

// enable user to input menu choice
unsigned int enterChoice(void)
{ 
   // display available options
   printf("%s", "\nEnter your choice\n"
      "1 - store a formatted text file of accounts called\n"
      "    \"accounts.txt\" for printing\n"
      "2 - update an account\n"
      "3 - add a new account\n"
      "4 - delete an account\n"
      "5 - end program\n? ");

   unsigned int menuChoice; // variable to store user's choice
   scanf("%u", &menuChoice); // receive choice from user
   return menuChoice;
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