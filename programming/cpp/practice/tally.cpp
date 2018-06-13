#include <iostream>

using namespace std;

int main() {
  string poll, opt1, opt2, opt3;

  cout << "Poll: ";
  cin >> poll;

  cout << "Option 1: ";
  cin.ignore();
  cin >> opt1;

  cout << "Option 2: ";
  cin >> opt2;

  cout << "Option 3: ";
  cin >> opt3;

  int input;
  int opt1_count = 0, opt2_count = 0, opt3_count = 0;
  cout << "Vote: ";
  cin >> input;

  while (input != 0) {
    cout << "Vote: ";
    cin >> input;

    if (input == 1)
      opt1_count++;
    else if (input == 2)
      opt2_count++;
    else if (input == 3)
      opt3_count++;
    else if (input != 0)
      cout << "Not an option" << endl;
  }

  cout << "Results\n\n";
  cout << "1. " << opt1 << ": " << opt1_count << endl;
  cout << "2. " << opt2 << ": " << opt2_count << endl;
  cout << "3. " << opt3 << ": " << opt3_count << endl;

  // find max value
  int max_val;
  if (max(opt1_count, opt2_count) == opt1_count)
    max_val = opt1_count;
  else
    max_val = opt2_count;

  if (opt3_count > max_val)
    max_val = opt3_count;

  // print bar graph
  for (int i = max_val; i > 0; i--) {
    cout << i;

    cout << "  ";
    if (opt1_count >= i)
      cout << '*';

    cout << '\t';
    if (opt2_count >= i)
      cout << '*';

    cout << '\t';
    if (opt3_count >= i)
      cout << '*';

    cout << '\n';
  }

  cout << "   1\t2\t3" << endl;

  return 0;
}
