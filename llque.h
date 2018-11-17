#ifndef LLQUE_H
#define LLQUE_H

struct NodeType{
  int info;
  NodeType* next;
};

class LLQue{
public:
  LLQue();
  ~LLQue();
  void MakeEmpty();
  void Enqueue(int);
  int Dequeue();
  bool IsEmpty() const;
  bool IsFull() const;
  void DisplayQueue() const;

private:
  NodeType* front;
  NodeType* rear;
};

#endif
