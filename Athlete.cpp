//
//  Athlete.cpp
//  olympicStats
//
//  Created by Matt Loera on 2/23/22.
//

/*class Athlete*/
//char* name; //here's my cstring
//string nationality;
//int age; //validate [0,99]
#include "Athlete.h"
#include <cstring>
#include "input.h"

//const int MAX = 500;//buffer string max length


using std::ostream;
using std::string;
Athlete::Athlete()
{
  using namespace std;
  string buff;
  getStringInput("Name: ",buff);
  getStringInput("Nationality: ",nationality);
  age = getIntInput("Age: ");
  name = new char[buff.length()+1];
  strcpy(name,buff.c_str());
  
}

Athlete::Athlete(const string& n, const string& nat, int a)
:name(new char[n.length()+1]),nationality(),age(a)
{
  strcpy(name,n.c_str());
}

Athlete::Athlete(const Athlete& toCopy)
:Athlete(string(toCopy.name),toCopy.nationality,toCopy.age)
{}

Athlete::~Athlete()
{
  delete[] name;
}
int Athlete::display()const
{
  using namespace std;
  cout << "Name: " << name << " -- ";
  cout << "Age: " << age << endl;
  cout << "Nationality: " << nationality << endl;
  return 1;
  
}

ostream& operator<<(ostream &out, const Athlete &a)
{
  a.display();
  return out;
}

int Athlete::operator==(const Athlete &a2) //compares based on value
{
  return 0;
}
int Athlete::operator<(const Athlete &a2) //compares based on name (for alphabetizing)
{
  return 0;
}
  
/*class Skater : public Athlete*/
//  int meanEventTotal;
//  int meanBV;
//  int meanTES;
//  int meanPCS;
Skater::Skater()
:Athlete()
{init();}

Skater::Skater(const string& n, const string& nat, int a)
:Athlete(n,nat,a)
{init();}

Skater::~Skater()
{}

int Skater::display()const
{
  using namespace std;
  Athlete::display();
  cout << "Mean Event Total: " << meanEventTotal << endl;
  cout << "Mean BV: " << meanBV << endl;
  cout << "Mean TES: " << meanTES << endl;
  cout << "Mean PCS: " << meanPCS << endl;
  return 1;
}

ostream& operator<<(ostream &out, const Skater &a)
{
  a.display();
  return out;
}

int Skater::operator==(const Athlete &a2) //compares based on value
{
  return 0;
}

int Skater::operator<(const Athlete &a2) //compares based on rank
{
  return 0;
}

void Skater::init()
{
  meanEventTotal = getIntInput("Mean event total: ");
  meanBV = getIntInput("Mean BV: ");
  meanTES = getIntInput("Mean TES: ");
  meanPCS = getIntInput("Mean PCS: ");
}

  


/*class Sledder : public Athlete*/
//  string pastResults;
//  int avgRank;
Sledder::Sledder() :Athlete()
{init();}

Sledder::Sledder(const string& n, const string& nat, int a)
:Athlete(n,nat,a)
{init();}

Sledder::~Sledder()
{}

int Sledder::display()const
{
  using namespace std;
  Athlete::display();
  cout << "Average Rank: " << avgRank << endl;
  cout << "Past Results: " << pastResults << endl;
  return 1;
}
ostream& operator<<(ostream &out, const Sledder &a)
{
  a.display();
  return out;
}

int Sledder::operator==(const Athlete &a2) //compares based on value
{
  return 0;
}

int Sledder::operator<(const Athlete &a2) //compares based on rank
{
  return 0;
}

void Sledder::init()
{
  getStringInput("Past results? ",pastResults);
  avgRank = getIntInput("Average Rank? ");
}

  


/*class Biathlete : public Athlete*/
//  int careerHitRate; //as a percent [0,100]
//  int avgSkiRank; //[1,+inf]
Biathlete::Biathlete() :Athlete()
{init();}

Biathlete::Biathlete(const string& n, const string& nat, int a)
:Athlete(n,nat,a)
{init();}

Biathlete::~Biathlete()
{}

int Biathlete::display()const
{
  using namespace std;
  Athlete::display();
  cout << "Carrer Hit Rate: " << careerHitRate << "%\n";
  cout << "Avg Ski Rank: " << avgSkiRank << endl;
  return 1;
}

ostream& operator<<(ostream &out, const Biathlete &a)
{
  a.display();
  return out;
}

int Biathlete::operator==(const Athlete &a2) //compares based on value
{
  return 0;
}

int Biathlete::operator<(const Athlete &a2) //compares based on rank
{
  return 0;
}

void Biathlete::init()
{
  careerHitRate = -1;
  avgSkiRank = -1;
  while(careerHitRate < 0 || careerHitRate >=100){ //validate percent range
    careerHitRate = getIntInput("Career Hit Rate Percent? ");
  }
  while(avgSkiRank < 0){
    avgSkiRank = getIntInput("Avg Ski Rank? ");
  }
}

  
  
