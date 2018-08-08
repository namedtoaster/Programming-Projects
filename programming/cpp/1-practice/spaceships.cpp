#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Spaceship {
  string color;
  string name;
  int pos_x;
  int pos_y;
};

bool ships_on_screen(Spaceship ships[], int size) {
  for (int i = 0; i < size; i++) {
    if (ships[i].pos_x < 1024)
      return true;
  }

  return false;
}

void print_ship_coords(Spaceship ships[], int size) {
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0 && ships[i].pos_x <= 1024) {
      cout << ", ";
      cout << "Spaceship " << i << " coords: [" << ships[i].pos_x << ", " << ships[i].pos_y << "]";
    }
  }
  cout << "]" << endl;
}

int main() {
  Spaceship ships[10];

  srand(time(NULL));

  // init spaceships with random x and y coords
  for (int i = 0; i < 10; i++) {
    ships[i].pos_x = rand() % 1024;
    ships[i].pos_y = rand() % 768;
  }

  // print the coords of each spaceship
  print_ship_coords(ships, 10);

  // update the x_pos (add 1 unit) until the spaceship is off screen
  bool on_screen = true;

  while(on_screen) {
    // keep updating the x_pos then checking how many spaceships are on screen
    for (int i = 0; i < 10; i++) {
      ships[i].pos_x++;
    }

    // print the coords of each spaceship
    print_ship_coords(ships, 10);

    // print the coords of the remaining ships
    on_screen =  ships_on_screen(ships, 10);
  }

  return 0;
}
