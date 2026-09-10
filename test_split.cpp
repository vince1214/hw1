/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{
  Node* start = new Node(1, nullptr);
  Node* current = start;

  for(int i = 2; i < 10; i++)
  {
    current->next = new Node(i, nullptr);
    current = current->next;
  }

  Node* odds = nullptr;
  Node* evens = nullptr;

  split(start, odds, evens);

  std::cout << (start == NULL) << std::endl;

  //prints out both lists
  // for(int i = 1; i<6; i++)
  // {
  //   //prints out: 1, 3, 5, 7, 9
  //   std::cout << odds->value << std::endl;
  //   odds = odds->next;
  // }
  // for(int i = 1; i<5; i++)
  // {
  //   //prints out: 2, 4, 6, 8
  //   std::cout << evens->value << std::endl;
  //   evens = evens->next;
  // }

  //Node* deleting = odds;
  while(odds != nullptr)
  {
    Node* currentnode = odds->next;
    delete odds;
    odds = currentnode;
  }

  //deleting = evens;
  while(evens != nullptr)
  {
    Node* currentnode = evens->next;
    delete evens;
    evens = currentnode;
  }
}
