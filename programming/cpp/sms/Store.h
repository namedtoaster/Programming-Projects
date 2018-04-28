#ifndef __STORE_H_INCLUDED__
#define __STORE_H_INCLUDED__

#include <string.h>

#include "itemEntry.h"
#include "Main.h"

class Store{
public:
  int numItem;
  itemEntry database[MAX];

  Store(){
    numItem = 0;
  }
  void insertItem( std::string itemName, std::string company, int c,float p);
  void deleteItem( std::string itemName);
  itemEntry *search( std::string itemName);
  void updateItem(std::string itemName, int total, float price);
  void printItems();
};

#endif
