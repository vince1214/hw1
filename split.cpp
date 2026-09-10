/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if(in == nullptr)
  {
    //adds the ends of the lists and sets in to nullptr
    evens = nullptr;
    odds = nullptr;
    return;
  }
  
  //temp node??
  Node* temp = in->next;
  if(in->value % 2 == 0)
  {
    //if the number is even
    //current even address equals to the current in address??
    
    evens = in;
    evens->next = nullptr;
    in = nullptr;

    //calls split again but changes the location/address of in
    //to the next number of the list
    //in addition the next number in the even list
    
    split(temp, odds, evens->next);
    
  }
  else if(in->value % 2 == 1)
  {
    //if the number is odd
    //current odd address equals to the current address of in?

    odds = in;
    odds->next = nullptr;
    in = nullptr;

    //calls split again but changes the location/address of in
    //to the next number of the list
    //in addition the next number in the odd list
    split(temp, odds->next, evens);
  }

}

/* If you needed a helper function, write it here */
