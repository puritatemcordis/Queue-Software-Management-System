#ifndef CAQUE_H
#define CAQUE_H

class CAQue{
public:
  CAQue(); //Default size = 10;
  CAQue(int max); //max: size of the queue
  ~CAQue();
  void MakeEmpty();
  void Enqueue(int value);
  int Dequeue();
  bool IsEmpty() const;
  bool IsFull() const;
  void DisplayQueue() const;

private:
  int *queue; //Dynamic array
  int maxQue;
  int front;
  int rear;
};

#endif
