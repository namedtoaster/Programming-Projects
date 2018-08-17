#include <iostream>
#include <string.h>

struct product {
  int weight;
  double price;
};

struct movie {
  string title;
  int year;
} yours;

void print_movie(movie* x) {
  cout << "Movie title: " << x->title << endl;
  cout << "Movie year: " << x->year << endl;
}

int main() {
  product apple;
  apple.weight = 1, apple.price = .5;
  cout << "Apple weight: " << apple.weight << endl;
  cout << "Apple price: " << apple.price << endl;

  // Struct example. Setting your favorite movie title (and year)
  cout << "Enter the name of your favorite movie: ";
  getline(cin, yours.title);

  string input;
  cout << "Enter the year " << yours.title << " was produced: ";
  getline(cin, input);
  yours.year = stoi(input);

  cout << "Your favorite movie: " << yours.title << endl;
  cout << yours.title << " was produced in " << yours.year << endl;

  // Example of a pointer to a struct
  movie* moviep;
  movie mymovie;

  mymovie.title = "Social Network";
  mymovie.year = 2004;

  // Now initialize the pointer variable
  moviep = &mymovie;

  // Just print the values
  cout << "mymovie.title: " << moviep->title << endl;
  cout << "mymovie.year: " << moviep->year << endl;

  // Now send the pointer to a function and print it there
  print_movie(moviep);
}
