// Fig// fig12_02.c
// A simple stack program
#include <stdio.h>
#include <stdlib.h>

// self-referential structure                      
struct stackNode {                                 
   int data; // define data as an int              
   struct stackNode *nextPtr; // stackNode pointer 
};                                                 

typedef struct stackNode StackNode; // synonym for struct stackNode
typedef StackNode *StackNodePtr; // synonym for StackNode*

// prototypes
void push(StackNodePtr *topPtr, int info);
int pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);
void instructions(void);

int main(void) {
   StackNodePtr stackPtr = NULL; // points to stack top
   int value = 0; // int input by user
 
   instructions(); // display the menu
   printf("%s", "? ");
   int choice = 0; // user's menu choice
   scanf("%d", &choice);

   // while user does not enter 3
   while (choice != 3) { 
      switch (choice) { 
         case 1: // push value onto stack
            printf("%s", "Enter an integer: ");
            scanf("%d", &value);
            push(&stackPtr, value);
            printStack(stackPtr);
            break;
         case 2: // pop value off stack
            // if stack is not empty
            if (!isEmpty(stackPtr)) {
               printf("The popped value is %d.\n", pop(&stackPtr));
            } 

            printStack(stackPtr);
            break;
         default:
            puts("Invalid choice.\n");
            instructions();
            break;
      } 

      printf("%s", "? ");
      scanf("%d", &choice);
   } 

   puts("End of run.");
} 

// display program instructions to user
void instructions(void) {
   puts("Enter choice:\n"
      "1 to push a value on the stack\n"
      "2 to pop a value off the stack\n"
      "3 to end program");
} 

// insert a node at the stack top
void push(StackNodePtr *topPtr, int info) {
   StackNodePtr newPtr = malloc(sizeof(StackNode));

   // insert the node at stack top
   if (newPtr != NULL) {          
      newPtr->data = info;        
      newPtr->nextPtr = *topPtr;  
      *topPtr = newPtr;           
   }                              
   else { // no space available
      printf("%d not inserted. No memory available.\n", info);
   } 
} 

// remove a node from the stack top
int pop(StackNodePtr *topPtr) {
   StackNodePtr tempPtr = *topPtr;
   int popValue = (*topPtr)->data;
   *topPtr = (*topPtr)->nextPtr;  
   free(tempPtr);                 
   return popValue;
} 

// print the stack
void printStack(StackNodePtr currentPtr) {
   if (currentPtr == NULL) { // if stack is empty
      puts("The stack is empty.\n");
   } 
   else { 
      puts("The stack is:");

      while (currentPtr != NULL) { // while not the end of the stack
         printf("%d --> ", currentPtr->data);
         currentPtr = currentPtr->nextPtr;
      } 

      puts("NULL\n");
   } 
} 

// return 1 if the stack is empty, 0 otherwise
int isEmpty(StackNodePtr topPtr) {
   return topPtr == NULL;
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
