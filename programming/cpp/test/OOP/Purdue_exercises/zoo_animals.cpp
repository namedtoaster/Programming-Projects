#include <iostream>

class ZooAnimal  
{
private:
  char *name;
  int cageNumber;
  int weightDate;
  int weight;
public:
  ZooAnimal(const char*, int, int, int) {}
  void Destroy (); // destroy function
  const char* reptName ();
  int daysSinceLastWeighed (int today);
};

void ZooAnimal::Destroy ()
{	
  delete [] name;
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

int main ()
{
  const char name[] = "Bozo";
  ZooAnimal bozo(name, 408, 1027, 400);

  //std::cout << "This animal's name is " << bozo.reptName() << std::endl;

  bozo.Destroy ();
}

