#include <iostream>
#include <ctime>
#include <string>

using namespace std;

void print_time(int watch) {
  int hour, min, sec;

  hour = watch / 60 / 60;
  min = watch / 60;
  sec = watch % 60;

  if (hour < 10)
    cout << '0';
  cout << hour << ':';

  if (min < 10)
    cout << '0';
  cout << min << ':';

  if (sec < 10)
    cout << '0';
  cout << sec << endl;
}

int main() {
  int clock = time(NULL);
  int clock_test = clock;

  int stopwatch = 0;

  while (1) {
    clock = time(NULL);
    if (clock != clock_test) {
      clock_test = clock;
      stopwatch++;

      print_time(stopwatch);
    }
  }

  return 0;
}
