#include <iostream>

enum scale {ounces, kilograms};

class ZooAnimal  
{
private:
  const char *name;
  int cageNumber;
  int weightDate;
  int weight;
  ZooAnimal *mother;
public:
  ZooAnimal(const char*, int, int, int);
  inline ~ZooAnimal();
  
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
  // be automatically converted in an operation like this: "int + ZooAnimal"
  operator int();
};

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

int main ()
{
  const char* name = "Bozo";
  ZooAnimal bozo(name, 408, 1027, 400);

  bozo.reptName();
  //std::cout << "This animal's name is " << bozo.reptName() << std::endl;

  // For some reason, this function does some crazy stuff. I'm going
  // to keep it commented out for now
  // bozo.Destroy ();
}

