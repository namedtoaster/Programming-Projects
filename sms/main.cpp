#include <iostream>
#include <string.h>

using namespace std;

#include "Store.h"
#include "Main.h"

int main() {
  Store sto;
  //clrscr(); TODO <-- find out what this does and implement it
  // manually
  string option, name, company, copies, unit_price;
  while(option[0] != 'e') {
    cout << "\n----------->Enter your choice:<------------\n";
    cout << "I for insert\n";
    cout << "D for delete\n";
    cout << "S for search\n";
    cout << "U for update\n";
    cout << "P for print items in database\n";
    cout << "E for exit\n";

    getline(cin, option);
    char opt = tolower(option[0]);
	
    switch (opt) {

    case 'i':
      cout << "Enter Name of Item, Company, Number of copies and Unit price per line:\n";
      getline(cin, name);
      getline(cin, company);
      getline(cin, copies);
      getline(cin, unit_price);
      sto.insertItem( name, company, stoi(copies),stof(unit_price));
      
      break;
    
    case 'd':
      cout << "Enter Name of Item:\n";
      getline(cin, name);      
      sto.deleteItem(name);
      
      break;
      
    case 's':
      cout << "Enter Name of Item:\n";
      getline(cin, name);
      
      itemEntry *test;
      test = sto.search( name );
      
      if( test != NULL) {
	cout<<"---------------->Searching Result<---------------------" <<endl;
	cout << "Item found\n" <<"Name of the Item:" << test->name << endl;
	cout <<"Company name:"<< test->company << endl;
	cout <<"Number of copies available:"<< test->copies << endl;
	cout <<"Unit price:"<<test->unit_price << endl;
      }
      else
	cout << "Item not found\n";
      
      break;
    case 'u':
      cout << "Enter details for update...\n";
      cout << "Enter name: "; getline(cin, name);
      cout << "Enter total new entry: "; getline(cin, copies);
      cout << "Enter new price: "; getline(cin, unit_price);
      sto.updateItem(name, stoi(copies), stof(unit_price));
      
      break;

    case 'p':
      sto.printItems();

      break;
    case 'e':
      exit(0);
      
      break;
    }
  }
	    
    return 0;
}
