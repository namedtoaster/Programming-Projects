#include <iostream>

enum scale {ounces, kilograms};

class ZooAnimal  
{
public:
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
private:
  const char *name;
  int cageNumber;
  int weightDate;
  int weight;
  ZooAnimal *mother;
  nutrition nutr;
public:
  ZooAnimal(const char*, int, int, int);
  inline ~ZooAnimal();

  void changeOldestWeightDate(int date);
  void changeWeight (int pounds);
  void changeWeightDate (int today);
  int reptWeight ();
  void reptWeight (scale which);
  inline int reptWeightDate (); 
  void Destroy (); // destroy function
  const char* reptName ();
  int daysSinceLastWeighed (int today);
  void isMotherOf (ZooAnimal&);
  // This is kinda a weird one. Basically how you can call this is by
  // explicitly calling "int(ZooAnimal)" or "(int)ZooAnimal" or it can
  // be automatically converted in an operation like this: "int +
  // ZooAnimal"

  operator int();

  // Statc members require a bit of explanation.
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
  float reptNutrition();
};

float ZooAnimal::reptNutrition()
{
  nutr.reptMealNutrition();
}

int ZooAnimal::oldestWeightDate;

void ZooAnimal::changeOldestWeightDate(int date)
{
  oldestWeightDate = date;
}

ZooAnimal::~ZooAnimal()
{
  // Not sure why, but when the destructor gets automatically called,
  // the compiler complains about an invalid pointer and it spews out
  // the memory map. Look at this in the future
  //delete name;
  //delete mother;
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

ZooAnimal::ZooAnimal(const char* n = "Nameless", int a = 9999, int b =
101, int c = 100)
{
  name = n;
  cageNumber = a;
  weightDate = b;
  weight = c;
}

void ZooAnimal::Destroy ()
{	
  delete name;
  name = NULL;
}

// -------- member function to return the animal's name
const char* ZooAnimal::reptName ()
{
  std::cout << name << std::endl;
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
  const char* name = "Bozo";
  ZooAnimal bozo(name, 408, 1027, 400);

  bozo.reptName();
  std::cout << int(bozo) << std::endl;
}

