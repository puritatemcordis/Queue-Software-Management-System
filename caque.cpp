#include <iostream>
#include <cstdlib>
#include "caque.h"

//default constructor
//sets the size of the queue to 500, while assigning -1 to front and rear
//dynamically creates space in the heap for the queue
//outputs message to let user know that the constructor was activated
CAQue::CAQue(){
  maxQue = 5;
  front = -1;
  rear = -1;
  queue = new int[maxQue];
  std::cout << "Cirular Array Queue created" << std::endl;
}

//constructor
//sets the size of the queue to user input, while assigning -1 to front and rear
//dynamically creates space in the heap for the queue
//outputs message to let user know that the constructor was activated
//@param max: user input size of the array
CAQue::CAQue(int max){
  maxQue = max + 1;
  front = -1;
  rear = -1;
  queue = new int[maxQue];
  std::cout << "Circular Array Queue created" << std::endl;
}

//destructor
CAQue::~CAQue(){
    delete [] queue;
}

//assigns the private variables, front and rear, to -1
void CAQue::MakeEmpty(){
  printf("\nEmptying the queue...\n");
  front = -1;
  rear = -1;
  printf("Process Complete.\n");
}

//inserts the user defined value, which will be inserted into the front/rear, if it is the first element, or the rear for any of the following elements
//@param value: user inputted numerical value
void CAQue::Enqueue(int value){
  if(IsFull()) std::cout << "Queue is Full" << std::endl;
  else{
    if(front == -1) front = 0; //first element inserted
    rear = (rear + 1) % maxQue;
    queue[rear] = value;
  }
}

//assigns the value of the front of the queue to the variable value
//if the front is equal to the rear, then assign -1 to front and rear
//else increment the front, which will dequeue the value
//returns -999, if the queue is empty; main driver in the program will read this value and output a message
int CAQue::Dequeue(){
  if(IsEmpty()) std::cout << "Queue is Empty" << std::endl;
  else{
    int value = queue[front];
    if (front == rear){
      front = - 1;
      rear = -1;
    } else front = (front + 1) % maxQue;

    return value;
  }
  return -999;
}

//if both front and rear are -1, then the queue is empty
bool CAQue::IsEmpty() const{
  if(front == -1 && rear == -1) return true;
  return false;
}

//if both the front and next spot in rear are equal, then the queue is full
bool CAQue::IsFull() const{
  if ((rear+1)% maxQue == front) return true;
  return false;
}

//displays the queue
//if the front is less than the rear, then print the front to the rear meaning the queue has never been filled to the end
//else the front, which is in front of the rear, is printed first then the rear;
void CAQue::DisplayQueue() const{
  if(IsEmpty()) std::cout << "Queue is Empty" << std::endl;
  else{
    printf("\nDisplaying queue...\n");
    std::cout << "Queue:    |";
    if (front <= rear){
      for(int i = front; i <= rear; i++) std::cout << queue[i] << "|";
      std::cout << std::endl << "Position: |";
      for(int i = front; i <= rear; i++) std::cout << i << "|";
    } else {
      int i = front;
      while(i < maxQue){
        std::cout << queue[i] << "|";
        i++;
      }
      i = 0;
      while(i <= rear){
        std::cout << queue[i] << "|";
        i++;
      }
      std::cout << std::endl << "Position: |";
      i = front;
      while(i < maxQue){
        std::cout << i << "|";
        i++;
      }
      i = 0;
      while (i <= rear){
        std::cout << i << "|";
        i++;
      }
    }
  }
  std::cout << std::endl;
}
