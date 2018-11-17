#include <iostream>
#include <cstdlib>
#include "cllque.h"

//default constructor
//sets front and rear to NULL
//outputs message to let user know that the constructor was activated
CLLQue::CLLQue(){
  front = NULL;
  rear = NULL;
  std::cout << "Circular Linked List Queue created" << std::endl;
}

//destructor
//same functionality of MakeEmpty except there are no parameters
CLLQue::~CLLQue(){
  if(IsEmpty()) ;
  else{
    Node* tempPtr = front;
    while(tempPtr->next != front){
      tempPtr = front;
      front = front->next;
      delete tempPtr;
    }
    tempPtr = front;
    delete tempPtr;

    front = NULL;
    rear = NULL;
  }
}

//creates a node with tempPtr and assigns it the front, and until it re-reaches the front,
//tempPtr will hold the current value, while front will move to the next node, then tempPtr will be deleted
//regardless of the condition, tempPtr will be assigned to the original front and it will be deleted
//front and rear will then be assigned NULL
//@param queue: class variable
void CLLQue::MakeEmpty(CLLQue* queue){
  printf("\nEmptying the queue...\n");
  if(IsEmpty()) ;
  else{
    Node* tempPtr = queue->front;
    while(tempPtr->next != queue->front){
      tempPtr = queue->front;
      queue->front = (queue->front)->next;
      delete tempPtr;
    }
    tempPtr = queue->front;
    delete tempPtr;

    queue->front = NULL;
    queue->rear = NULL;
  }
  printf("Process Complete.\n");
}

//creates a node with tempPtr and assigns it the value
//if it is the first element, then front will be assigned tempPtr else, rear->next will be assigned it
//regardless of the condition, rear will be assigned tempPtr, and rear->next will then point to the front
//@param queue: class variable
//@param value: user inputted value
void CLLQue::Enqueue(CLLQue* queue, int value){
  Node* tempPtr = new Node();
  tempPtr->info = value;

  if(front == NULL){ //first element inserted
    queue->front = tempPtr;
  } else {
    (queue->rear)->next = tempPtr;
  }

  queue->rear = tempPtr;
  (queue->rear)->next = queue->front;
}

//checks to see if the queue is empty
//if not, value will be assigned the contents of front; if front and rear and equivalent, it means that there is only one node left thus,
//the node will be deleted and front and rear will be assigned NULL
//else queue->front will be assigned the next node, and rear->next will be assigned to that node to continue the circularity
//then the tempPtr, which held the previous position, will be deleted
//returns -999, if the queue is empty; main driver in the program will read this value and output a message
//@param queue: class variable
int CLLQue::Dequeue(CLLQue* queue){
  if(IsEmpty()) std::cout << "Queue is Empty" << std::endl;
  else{
    int value;

    Node* tempPtr = queue->front;
    value = tempPtr->info;

    if(queue->front == queue->rear){
      delete tempPtr;
      queue->front = NULL;
      queue->rear = NULL;
    } else {
      queue->front = (queue->front)->next;
      (queue->rear)->next = queue->front;
      delete tempPtr;
    }
    return value;
  }
  return -999;
}

//returns true if both front and rear are NULL
bool CLLQue::IsEmpty() const{
  return (front == NULL & rear == NULL);
}

//attempts to create a new node, but if the heap is full, a bad allocation exception will be displayed
bool CLLQue::IsFull() const{
  Node* location;
  try {
    location = new Node;
    delete location;
    return false;
  } catch(std::bad_alloc exception){
    return true;
  }
}

//displays the queue
//assigns tempPtr front, and loops through the queue until it re-reaches front, which then it will output the last node
//@param queue: class variable
void CLLQue::DisplayQueue(CLLQue* queue) const{
  if(IsEmpty()) std::cout << "Queue is empty" << std::endl;
  else{
    printf("\nDisplaying queue...\n");
    std::cout << "Queue: |";
    Node* tempPtr = queue->front;
    while(tempPtr->next != queue->front){
      std::cout << tempPtr->info << "|";
      tempPtr = tempPtr->next;
    }
    std::cout << tempPtr->info << "|" << std::endl;
  }
}
