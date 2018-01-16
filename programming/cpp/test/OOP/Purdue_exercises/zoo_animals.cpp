#include <iostream>

enum scale {ounces, kilograms};


class ZooAnimal  
{
  // The keywords 'friend' and 'class' (in that order) before the
  // class name 'cageAssignment' designates it as a friend of the
  // ZooAnimal class. In this case, cageAssignment is able to access
  // the private and protected values of ZooAnimal
  friend class cageAssignment;
  
public:
  ZooAnimal(const char*, int, int, int);
  ZooAnimal(const char*);
  inline ~ZooAnimal();

  void changeOldestWeightDate(int date);
  void changeWeight (int pounds);
  void changeWeightDate (int today);
  int reptWeight ();
  void reptWeight (scale which);
  inline int reptWeightDate (); 
  const char* reptName ();
  int daysSinceLastWeighed (int today);
  void isMotherOf (ZooAnimal&);

  // This is kinda a weird one. Basically how you can call this is by
  // explicitly calling "int(ZooAnimal)" or "(int)ZooAnimal" or it can
  // be automatically converted in an operation like this: "int +
  // ZooAnimal"
  operator int();

  // Static members require a bit of explanation.
  //
  // Basiclly, there is only one value for static member variables
  // that persist throughout the scope of the class. As opposed to
  // "normal" class members that you can change with each instance of
  // the class. For instance, you can have an object counter that you
  // can initialize at 0 then incrememnt every time an instance is
  // created (you would do that in the constructor).
  //
  // In order to access and therefore even use the static member, you
  // have to declare it (that is done oustside the class - you can do
  // that right below the definition of the class like I've done in
  // this file...int ZooAnimal::oldestWeightDate; ) Once you do that,
  // any member function you define that tries to access it can,
  // static or otherwise.
  //
  // See
  //  https://www.tutorialspoint.com/cplusplus/cpp_static_members.htm
  //  for more info.
  static int oldestWeightDate;
  void reptNutrition();
  
  class nutrition
  {
  private:
    int numberMeals;
    int maxPoundsFed;
    float avgNutrValue;
  public:
    inline nutrition () {
      numberMeals = 4;
      maxPoundsFed = 75;
      avgNutrValue = 38.21;};
    inline float reptMealNutrition () 
    {return numberMeals * avgNutrValue;};
  };

  // Friend functions are those that can access the private and public
  // members of the class they are friends of
  friend ZooAnimal duplicate(ZooAnimal);

  static ZooAnimal* start;
  static ZooAnimal* current;
  static int numAnmls;
    
private:
  const char *name;
  int cageNumber;
  int weightDate;
  int weight;
  ZooAnimal *mother;
  nutrition nutr;
  ZooAnimal* prevAnml;
  ZooAnimal* nextAnml;

  void updateLL();
  // Test function
  void printLL();
};


// Previously I declared the cageAssignment class before the ZooAnimal
// class. I then forward declared the ZooAnimal class - just type
// 'class ZooAnimal' sometime before the cageAssignment class
// definition. This threw an error which basically said it didn't have
// enough info about the ZooAnimal class. Since there isn't really
// anything in the ZooAnimal class that needs to know about the
// cageAssignment class, I just put the cageAssignment class below the
// ZooAnimal class. Problem solved.
//
/// See
/// https://stackoverflow.com/questions/12466055/field-has-incomplete-type-error
/// for more info

class cageAssignment {
public:
    // Test function to test the frienship between cageAssignment and ZooAnimal
  void test(ZooAnimal a) { value = a.weight; }
  
  void changeCage(ZooAnimal&);
  friend int reptCage(ZooAnimal&);
private:
  // A test value to test the friendship between cageAssignment and ZooAnimal
  int value;

  int enclosure;
};





// Static member initialization
int ZooAnimal::oldestWeightDate;
ZooAnimal* ZooAnimal::start = NULL;
ZooAnimal* ZooAnimal::current = NULL;
int ZooAnimal::numAnmls = 0;

// Class member functions

void ZooAnimal::updateLL()
{
  // Modify linked list
  if (start == NULL)
    {
      start = this;
      current = this;

      prevAnml = NULL;
    }
  else
    {
      prevAnml = current;
      nextAnml = NULL;
      
      prevAnml->nextAnml = this;
      current = this;
    }

  // Increase the number of ZooAnimals
  numAnmls++;

  printLL();
}

void ZooAnimal::printLL()
{
  printf("Print the Linked List...\n");
  printf("1: %s\n", ZooAnimal::start->reptName());

  ZooAnimal* temp = start->nextAnml;
  
  for (int x = 1; x < numAnmls; x++)
    {
      printf("%i: %s\n", x + 1, temp->reptName());

      temp = temp->nextAnml;
    }
  printf("\n");
}

void cageAssignment::changeCage(ZooAnimal& changeMe)
{
  changeMe.cageNumber = enclosure;
  enclosure++;
}

void ZooAnimal::reptNutrition()
{
  nutr.reptMealNutrition();
}

void ZooAnimal::changeOldestWeightDate(int date)
{
  oldestWeightDate = date;
}

ZooAnimal::ZooAnimal(const char* n, int a, int b, int c)
{
  name = n;
  cageNumber = a;
  weightDate = b;
  weight = c;

  updateLL();
}

ZooAnimal::ZooAnimal(const char* n)
{
  name = new char;
  
  name = n;

  updateLL();
}

ZooAnimal::~ZooAnimal()
{
  // Not sure why, but when the destructor gets (automatically) called,
  // the compiler complains about an invalid pointer and it spews out
  // the memory map. Look at this in the future
  // delete name;
  // delete mother;
}

ZooAnimal::operator int()
{
  return cageNumber;
}

void ZooAnimal::isMotherOf (ZooAnimal& child)
{
  child.mother = this;
}

// Not really sure what inline does, but it supposedly makes the
// function run faster. Not sure why Purdue decided to just use it for
// this function. Who knows
inline int ZooAnimal::reptWeightDate()
{
  return weightDate;
}

// -------- member function to return the animal's name
const char* ZooAnimal::reptName ()
{
  return name;
}
   
// -------- member function to return the number of days
// -------- since the animal was last weighed
int ZooAnimal::daysSinceLastWeighed(int today)
{
  int startday, thisday;
  thisday = today/100*30 + today - today/100*100;
  startday = weightDate/100*30 + weightDate - weightDate/100*100;
  if (thisday < startday) 
    thisday += 360;
  return (thisday-startday);
}


int reptOldestZooAnimalWeightDate()
{
  return ZooAnimal::oldestWeightDate;
}

int main ()
{
  // Some testing stuff
  /*
    *************************************************************************
    bozo.reptName();
    std::cout << int(bozo) << std::endl;
    
    ZooAnimal test("Bill");
    test.reptName();
    *************************************************************************

    *************************************************************************
    A bit of LL testing

    ZooAnimal bozo("Bozo", 408, 1027, 400);
    std::cout << "Current: " << ZooAnimal::current->reptName() << std::endl;
    std::cout << "Start: " << ZooAnimal::start->reptName() << std::endl;

    ZooAnimal bingo("Bingo", 308, 101, 4);
    std::cout << "Current: " << ZooAnimal::current->reptName() << std::endl;
    std::cout << "Start: " << ZooAnimal::start->reptName() << std::endl;

    ZooAnimal bobo("Bobo", 8, 3101, 54);
    std::cout << "Current: " << ZooAnimal::current->reptName() << std::endl;
    std::cout << "Start: " << ZooAnimal::start->reptName() <<
    std::endl;
    *************************************************************************
  */

  /*ZooAnimal bozo("Bozo", 408, 1027, 400);
  ZooAnimal bobo("Bobo", 8, 3101, 54);*/
  
  ZooAnimal bingo("Bingo", 308, 101, 4);
  ZooAnimal bongo("Bongo", 308, 101, 4);
  ZooAnimal bogo("Bogo", 308, 101, 4);
  ZooAnimal borgo("Borgo", 308, 101, 4);
  ZooAnimal bego("Bego", 308, 101, 4);
}
