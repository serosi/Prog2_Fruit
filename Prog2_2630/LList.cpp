#include "LList.h"
#include "LeakWatcher.h"
using namespace std;

//---------------------------------------------------------------------
// destructor for Linked List class
//---------------------------------------------------------------------
LList::~LList() {
   Node* tmp;
   while (list != nullptr) {
      tmp = list;
      list = tmp->next;
      delete tmp;
   }
}

//---------------------------------------------------------------------
// Checks if the linked list is empty
//---------------------------------------------------------------------
bool LList::IsEmpty() const {
   if (list != nullptr) {
      return false;
   }
   else
      return true;
}

//---------------------------------------------------------------------
// Inserts an item into the linked list
//---------------------------------------------------------------------
bool LList::Insert(InfoType* x_ptr) {
   Node* tmp = new Node(x_ptr);
   Node* curr = list;
   Node* prev = nullptr;
   bool inList = false;

   if (curr != nullptr) {
      if (*tmp->infoPtr == *curr->infoPtr) {
         delete x_ptr;
         inList = true; // item already in list
      }
      else if (*tmp->infoPtr < *curr->infoPtr) {
         prev = curr;
         curr = curr->next;
      }
   }

   delete tmp;
   delete curr;
   delete prev;
   if (inList) // return false if item is already in list
      return false;
   else // item was added
      return true;
}

//---------------------------------------------------------------------
// Deletes an item from the linked list
//---------------------------------------------------------------------
bool LList::Delete(const InfoType& x) {
   Node* tmp = nullptr;
   Node* curr = list;
   Node* prev = nullptr;
   
   if (!IsEmpty()) {
      while (curr != nullptr) {
         //if (x == curr->infoPtr)


      }
   }


   delete tmp;
   return true;
}

//---------------------------------------------------------------------
// Displays the entire linked list
//---------------------------------------------------------------------
void LList::Display(ostream& out_stream) const {
   while (list != nullptr && !IsEmpty()) {
      out_stream << list->infoPtr << " ";
      //list = list->next;
   }
}