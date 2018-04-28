#include <iostream>
#include <string.h>
#include <locale>

#include "itemEntry.h"
#include "Store.h"

std::string stringToLower(std::string input) {
  std::locale loc;
  std::string temp = "";
  for (std::string::size_type i = 0; i < input.length(); i++) {
    temp += tolower(input[i], loc);
  }

  return temp;
}

void Store::insertItem( std::string itemName, std::string company, int c, float p){
  database[numItem].name.assign(itemName);
  database[numItem].company.assign(company);
  database[numItem].copies = c;
  database[numItem].unit_price = p;
  std::cout << "Item Inserted Successfully.\n";
  ++numItem;
}

void Store::deleteItem( std::string itemName){
  int i;
  for( i = 0; i < numItem; i++){
    if (itemName.compare(database[i].name) != 0) {
      //if( strcmp( itemName, database[i].name) == 0){
      database[i].copies--;
      std::cout << "Item Deleted Successfully.\n";
      return;
    }
  }
  std::cout << "Item not found.\n";
}

itemEntry *Store::search( std::string itemName){
  int i;
  std::string itemToCompare = stringToLower(itemName);
  std::cout << "Item being searched for: " << itemToCompare << std::endl;
  for( i = 0; i < numItem; i++){
    std::cout << "#" << i << ": " << stringToLower(database[i].name) << std::endl;
    if (itemToCompare.compare(stringToLower(database[i].name)) == 0)
      return &database[i];
  }
  return NULL;
}

void Store::updateItem(std::string itemName, int total, float price)
{
  itemEntry *item = search(itemName);
  if(item == NULL)
    {
      std::cout<<"Item not found.\n";
      return;
    }
  item->copies += total;
  item->unit_price = price;
}

void Store::printItems() {
  for (int x = 0; x < numItem; x++){
    std::cout << "Item #" << x << ": " << database[x].name << std::endl;
  }
}
