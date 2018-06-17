#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int find_highest(int arr[], int size) {
  int highest = arr[0];

  for (int i = 1; i < size; i++) {
    if (arr[i] > highest)
      highest = arr[i];
  }
  return highest;
}

int find_lowest(int arr[], int size) {
  int lowest = arr[0];

  for (int i = 1; i < size; i++) {
    if (arr[i] < lowest)
      lowest = arr[i];
  }
  return lowest;
}

double find_average(int arr[], int size) {
  int sum = 0;

  for (int i = 0; i < size; i++)
    sum += arr[i];

  double average = double(sum / size);

  return average;
}

int main() {
  srand(time(NULL));
  // create array
  int array[50];

  // assign random values to array (between 1 and 100)
  for (int i = 0; i < 50; i++) {
    array[i] = rand() % 100;
  }

  // find the highest value and print it
  int highest = find_highest(array, 50);
  cout << "Highest value: " << highest << endl;

  // find the lowest value and print it
  int lowest = find_lowest(array, 50);
  cout << "Lowest value: " << lowest << endl;

  // find the average value then print it
  double average = find_average(array, 50);
  cout << "Average value: " << average << endl;

  // print all values
  cout << "{";
  for (int i = 0; i < 50; i++) {
    if (i != 0)
      cout << ", ";
    cout << array[i];
  }
  cout << "}";
}
