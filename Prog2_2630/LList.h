#ifndef _LINKED_LIST
#define _LINKED_LIST

#include "Fruit.h"
#include <iostream>

typedef Fruit InfoType;

class LList
{
public:
   //---------------------------------------------------------------------
   // default constructor for Linked List class
   //---------------------------------------------------------------------
   LList() { list = nullptr; }

   //---------------------------------------------------------------------
   // destructor for Linked List class
   //---------------------------------------------------------------------
   ~LList(); // delete all the nodes

   //---------------------------------------------------------------------
   // Checks if the linked list is empty
   //---------------------------------------------------------------------
   bool IsEmpty() const;

   //---------------------------------------------------------------------
   // Inserts an item into the linked list
   //---------------------------------------------------------------------
   bool Insert(InfoType* x_ptr);

   //---------------------------------------------------------------------
   // Deletes an item from the linked list
   //---------------------------------------------------------------------
   bool Delete(const InfoType& x);

   //---------------------------------------------------------------------
   // destructor for Linked List class
   //---------------------------------------------------------------------
   void Display(ostream& out_stream) const;

private:
   struct Node
   {
      Node(InfoType* x, Node* p = NULL) { infoPtr = x; next = p; }
      ~Node() { delete infoPtr; }
      InfoType* infoPtr;
      Node* next;
   };
   Node* list;
   LList(const LList& copyFrom); // Don't allow!
   LList& operator= (const LList& assignFrom); // Don't allow!
};

#endif