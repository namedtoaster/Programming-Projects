#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void print_array(int arr[], int size) {
  cout << "{";
  for (int i = 0; i < size; i++) {
    if (i != 0)
      cout << ", ";
    cout << arr[i];
  }
  cout << "}\n";
}

bool test_sorted(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    // don't want to access outside of the array
    if (i != size -1) {
      if (arr[i + 1] < arr[i]) {
        return false;
      }
    }
  }

  return true;
}

void swap(int arr[], int first_index, int second_index) {
  int temp = arr[first_index];
  arr[first_index] = arr[second_index];
  arr[second_index] = temp;
}

int find_min_remaining_val(int arr[], int size, int index) {
  int min_index = index;
  for (int i = index + 1; i < size; i++) {
    if (arr[i] < arr[min_index])
      min_index = i;
  }

  return min_index;
}

void sort(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    int index_of_min_val = find_min_remaining_val(arr, size, i);
    if (arr[index_of_min_val] < arr[i])
      swap(arr, index_of_min_val, i);
  }
}

int main() {
  srand(time(NULL));

  // create an array, let's say size 10
  int array[10];

  // initialize array with random values
  for (int i = 0; i < 10; i++)
    array[i] = rand() % 10;

  // test if the array is sorted
  bool is_sorted = test_sorted(array, 10);

  // if the array is not sorted, sort it
  if (!is_sorted) {
    sort(array, 10);
  }

  // print the array
  print_array(array, 10);

  return 0;
}
