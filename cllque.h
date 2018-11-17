#ifndef CLLQUE_H
#define CLLQUE_H

struct Node{
  int info;
  Node* next;
};

class CLLQue{
public:
  CLLQue();
  ~CLLQue();
  void MakeEmpty(CLLQue*);
  void Enqueue(CLLQue*, int);
  int Dequeue(CLLQue*);
  bool IsEmpty() const;
  bool IsFull() const;
  void DisplayQueue(CLLQue*) const;

private:
  Node* front;
  Node* rear;

};

#endif
