#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

//push_back push_front pop_back pop_front back front getValAtLoc

void ULListStr::push_back(const std::string& val)
{
  //add to the back
  //examples: new list, fit in back, does't fit, ....

  if(empty())
  {
    //has already provided code in push front
    push_front(val);
    return;
  }
  else if(tail_->last != 10)
  {
    //fits in the back
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  else
  {
    //doesn't fit
    Item* temp = new Item;
    tail_->next = temp;
    temp->val[0] = val;
    temp->prev = tail_;
    tail_ = temp;
    tail_->next = NULL;

    tail_->last = 1;
    tail_->first = 0;
    
  
  }

  size_++;


}

void ULListStr::push_front(const std::string& val)
{
  //add to the front
  //examples: new list, fit in front, does't fit, ....
  if(empty())
  {
    //new list
    head_ = new Item;
    tail_ = head_;
    head_->val[0] = val;
    //change the values of the first and list
    head_->first = 0;
    head_->last++;
  }
  else if(head_->first != 0)
  {
    //fit in front
    
    head_->first--;
    head_->val[head_->first] = val; 
  }
  else
  {
    //no space at the front
    Item* temp = new Item;
    head_->prev = temp;
    temp->next = head_;
    temp->prev = NULL;

    temp->val[9] = val;
    head_ = temp;
    head_->first = 9;
    head_->last = 10;
  }

  size_++;
}

void ULListStr::pop_back()
{
  //remove from the back
  //example: 2 5 6 7 , 1 _ , empty, 
  if(empty())
  {
    //empty
    return;
  }
  else if(size_ == 1)
  {
    //if there is just one node
    delete head_;
    head_ = NULL;
    tail_ = NULL;
  }
  else if(tail_->last == 1)
  {
    //has one in node and deallocate the node
    Item* temp = tail_;
    tail_ = tail_->prev;
    delete temp;
  }
  else
  {
    //remove from back
    tail_->val[tail_->last - 1] = nullptr;
    tail_->last--;
  }
  //decrease size of size_
  size_--;

}

void ULListStr::pop_front()
{
  //remove from the front
  //example: 2 5 6 7 , _ 1 , empty, 
  if(empty())
  {
    //empty
    return;
  }
  else if(size_ == 1)
  {
    //if there is just one node
    delete head_;
    head_ = NULL;
    tail_ = NULL;
  }
  else if(head_->first == 9)
  {
    //has one in node and deallocate the node
    Item* temp = head_;
    head_ = head_->next;
    delete temp;
  }
  else
  {
    //remove from front
    head_->val[head_->first] = nullptr;
    head_->first++;
  }
  //decrease size of size_
  size_--;
 
}

std::string const & ULListStr::back() const
{
  //const reference to the back element
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  //const reference to the front element
  return head_->val[head_->first];
}


std::string* ULListStr::getValAtLoc(size_t loc) const
{
  //returns pointer to the item at index, loc, 
  // if loc is valid and NULL otherwise
  if(loc >= size_)
  {
    return NULL;
  }

  Item* temp = head_;
  size_t arraylocation = temp->first;

  //use a for loop
  for(size_t i = 0; i < loc; i++)
  {
    //one by one
    arraylocation++;
    if(arraylocation == temp->last)
    {
      //if first equals 10 goes to new node
      temp = temp->next;
      arraylocation = 0;
    }
  }

  return &temp->val[arraylocation];
}


void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
