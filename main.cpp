//compiler g++ main.cpp caque.cpp caque.h cllque.cpp cllque.h llque.cpp llque.h
#include <iostream>
#include <cstdlib>
#include "caque.h"
#include "llque.h"
#include "cllque.h"

//FUNCTION PROTOTYPES
void ClearScreen();
char Greeting();
void DisplayMenu(int& choice);
void FunctionMenu(int& choice);
void Exit(int& next);

int main(){
  ClearScreen();
  char answer = Greeting();

  while (answer == 'Y'){
    int choice = 0;
    int value;
    int next = 1;

    ClearScreen();
    DisplayMenu(choice);

    if(choice == 1){ //CIRCULAR ARRAY QUEUE
      CAQue caq;

      choice = 0;
      while(next){
        FunctionMenu(choice);

        switch(choice){
          case 1:
            while (true){
              printf("\nTo exit, enter -999.\n");
              printf("Enter value to enqueue into queue: ");
              std::cin >> value;
              if(value == -999) break;
              caq.Enqueue(value);
            }
            break;
          case 2:
            value = caq.Dequeue();
            if(value == -999) break;
            else printf("\nDequeued value: %d\n", value);
            break;
          case 3:
            caq.DisplayQueue();
            break;
          case 4:
            caq.MakeEmpty();
            break;
          case 5:
            Exit(next);
            break;
          default:
            printf("\nError! None of the options selected.\n");
            Exit(next);
          }
        std::cout << std::endl;
      }
    } else if (choice == 2) { //LINKED LIST QUEUE
      LLQue llq;

      choice = 0;
      while(next){
        FunctionMenu(choice);

        switch(choice){
          case 1:
            while (true){
              printf("\nTo exit, enter -999.\n");
              printf("Enter value to enqueue into queue: ");
              std::cin >> value;
              if(value == -999) break;
              llq.Enqueue(value);
            }
            break;
          case 2:
            value = llq.Dequeue();
            if(value == -999) break;
            else printf("\nDequeued value: %d\n", value);
            break;
          case 3:
            llq.DisplayQueue();
            break;
          case 4:
            llq.MakeEmpty();
            break;
          case 5:
            Exit(next);
            break;
          default:
            printf("\nError! None of the options selected.\n");
            Exit(next);
        }
        std::cout << std::endl;
      }
    } else if (choice == 3){ //CIRCULAR LINKED LIST QUEUE
      CLLQue cllq;

      choice = 0;
      while(next){
        FunctionMenu(choice);

        switch(choice){
          case 1:
            while (true){
              printf("\nTo exit, enter -999.\n");
              printf("Enter value to enqueue into queue: ");
              std::cin >> value;
              if(value == -999) break;
              cllq.Enqueue(&cllq, value);
            }
            break;
          case 2:
            value = cllq.Dequeue(&cllq);
            if(value == -999) break;
            else printf("\nDequeued value: %d\n", value);
            break;
          case 3:
            cllq.DisplayQueue(&cllq);
            break;
          case 4:
            cllq.MakeEmpty(&cllq);
            break;
          case 5:
            Exit(next);
            break;
          default:
            printf("\nError! None of the options selected.\n");
            Exit(next);
        }
      std::cout << std::endl;
      }
    } else {
      printf("Error! None of the options selected.\n");
      printf("Exiting program...\n");
    }

    printf("Do you want to restart the Queue Management Software System? (Y/N): ");
    std::cin >> answer;
    answer = toupper(answer); //capitalizes the char inputted by user
  }
  std::cout << "Good bye!" << std::endl;
  return 0;
}


//FUNCTION DEFINITIONS

//Sends 100 newlines to the console, which is equivalent to UNIX command "clear"
//Used to show changes in matrix without stacking each display on top of one another
void ClearScreen(){
  for(int n = 0; n < 10; n++){
    std::cout << "\n\n\n\n\n\n\n\n\n\n";
  }
}

//Displays the menu of different selections of queues
//@param choice: integer, which is pass-by-reference, which the user will input to advance the menu
void DisplayMenu(int& choice){
  printf("Please select one of the following of the menu:\n");
  printf("1) Queue using a Circular Array\n");
  printf("2) Queue using a Linked List\n");
  printf("3) Queue using a Circular Linked List\n");
  printf("Your choice: ");
  std::cin >> choice;
  std::cout << std::endl;
}

//Displays the menu of different actions of the queues
//@param choice: integer, which is pass-by-reference, that the user will input to decide the action
void FunctionMenu(int& choice){
  printf("Please select one of the following of the menu:\n");
  printf("1) Enqueue\n");
  printf("2) Dequeue\n");
  printf("3) Display Queue\n");
  printf("4) Make Empty Queue\n");
  printf("5) Exit\n");
  printf("Your choice: ");
  std::cin >> choice;
}

//Displays an exit message and assigns 0 to next, which will end the while loop
//@param next: integer, which is pass-by-reference, that will be assigned 0, which will break the while loop
void Exit(int& next){
  printf("\nExiting program...");
  next = 0;
}

//Returns char to determine whether the user wants to play game
//Greets player and explains rules of the game
char Greeting(){
  //declaration and initialization of answer to ' '
  char answer = ' ';

  //explains the rules of Conway's Game of Life
  std::cout << "\t\t\t\t\t\t\t\t \"Welcome to the Queue Management Software System\"" << std::endl;
  std::cout << std::endl;

  std::cout << "A queue is an abstract data structure (ADT) that follows the process of FIFO - first-in-first-out." << std::endl;
  std::cout << "However, one of the problems and inefficienties of a queue is the process of DEQUEUING, which" << std::endl;
  std::cout << "removes the first element, but requires the entire queue to be moved up one opisition in an array." << std::endl;
  std::cout << "Thus, DEQUEUE takes O(N) time if the queue has length n." << std::endl;
  std::cout << std::endl;

  std::cout << "This program implements a queue using three different data structures - circular array, linked list, circular linked list." << std::endl;
  std::cout << "As a result, DEQUEUE will take O(1) time, which is constant regardless of the size of the queue." << std::endl;
  std::cout << "The program will display a menu, which lets the user to select one of three different data structures." << std::endl;
  std::cout << "Afterwards, the queue with that data structure will be created, and a menu displaying different methods of the queue will appear." << std::endl;
  std::cout << std::endl;

  //while loop to ensure player either selects Y or N, which determines whether they play or not
  while (answer != 'Y' && answer != 'N'){
    std::cout << "Would you like to continue? (Y/N): ";
    std::cin >> answer;
    answer = toupper(answer); //capitalizes the char inputted by user
  }

  return answer;
}
