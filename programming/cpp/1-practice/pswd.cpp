#include <iostream>
#include <string>

using namespace std;

int main() {
  string username, pwd;
  string user1 = "Bob", pwd1 = "123abc";
  string user2 = "Joe", pwd2 = "456def";
  string user3 = "Fred", pwd3 = "789ghi";

  cout << "Enter a username and password\n\nUsername: ";
  getline(cin, username);
  cout << "Password: ";
  getline(cin, pwd);

  if (username == user1 || username == user2 || username == user3) {
    if (username == user1 && pwd == pwd1 ||
        username == user2 && pwd == pwd2 ||
        username == user3 && pwd == pwd3)
      cout << "Welcome, " << username << '!' << endl;
    else
      cout << "\nAccess denied!" << endl;
  }
  else
    cout << "Username doesn't exist" << endl;

  return 0;
}
