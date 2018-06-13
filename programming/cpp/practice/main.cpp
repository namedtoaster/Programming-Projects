#include <iostream>
#include <string>

using namespace std;

int main() {
  int firstAge, secondAge;

  cout << "Give me the age of two people.\nWhat's the age of the first person? ";
  cin >> firstAge;

  cout << "What's the age of the second person? ";
  cin >> secondAge;

  if (firstAge > secondAge)
    cout << "The first person is older" << endl;
  else if (secondAge > firstAge)
    cout << "The second person is older" << endl;

  if (firstAge > 100 && secondAge > 100)
    cout << "Both people are really old" << endl;

  return 0;
}
