#include <iostream>
#include <cstdlib>
#include "llque.h"

//default constructor
//sets front and rear to NULL
//outputs message to let user know that the constructor was activated
LLQue::LLQue(){
  front = NULL;
  rear = NULL;
  std::cout << "Linked List Queue created" << std::endl;
}

//destructor
//calls the function MakeEmpty()
LLQue::~LLQue(){
  MakeEmpty();
}

//while front != NULL, tempPtr will be assigned front, while front will be assigned the next node, then tempPtr will be deleted
//after the while loop, rear is assigned NULL
void LLQue::MakeEmpty(){
  printf("\nEmptying the queue...\n");
  NodeType* tempPtr;
  while(front != NULL){
    tempPtr = front;
    front = front->next;
    delete tempPtr;
  }
  rear = NULL;
  printf("Process Complete.\n");
}

//creates a node using tempPtr, and if this is the first node inserted, both front and rear will be assigned to it
//else if it is the following nodes, the rear->next will point to tempPtr, and rear will be assigned tempPtr
//@param value: user inputted value
void LLQue::Enqueue(int value){
  NodeType* tempPtr = new NodeType();
  tempPtr->info = value;
  tempPtr->next = NULL;

  if(front == NULL){ //first node inserted
    front = tempPtr;
    rear = tempPtr;
  } else {
    rear->next = tempPtr;
    rear = tempPtr;
  }
}

//checks to see if the queue is empty
//if not, value will be assigned the contents of front, and front will be assigned the next Node, then it will be deleted
//rear will be assigned NULL, if this is the last remaining node
//returns -999, if the queue is empty; main driver in the program will read this value and output a message
int LLQue::Dequeue(){
  if(IsEmpty()) std::cout << "Queue is Empty" << std::endl;
  else{
    NodeType* tempPtr = front;
    int value = front->info;
    front = front->next;

    if(front == NULL) rear = NULL;

    delete tempPtr;
    return value;
  }
  return -999;
}

//returns true if both front and rear are NULL
bool LLQue::IsEmpty() const{
  return (front == NULL & rear == NULL);
}

//attempts to create a new node, but if the heap is full, a bad allocation exception will be displayed
bool LLQue::IsFull() const{
  NodeType* location;
  try {
    location = new NodeType;
    delete location;
    return false;
  } catch(std::bad_alloc exception){
    return true;
  }
}

//displays the queue
//assigns tempPtr front, and loops through the queue until it reaches a NULL value
void LLQue::DisplayQueue() const{
  if(IsEmpty()) std::cout << "Queue is Empty" << std::endl;
  else{
    printf("\nDisplaying queue...\n");
    std::cout << "Queue: |";
    NodeType* tempPtr = front;
    while(tempPtr != NULL){
      std::cout << tempPtr->info << "|";
      tempPtr = tempPtr->next;
    }
  }
  std::cout << std::endl;
}
