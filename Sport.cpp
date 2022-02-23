//
//  Sport.cpp
//  olympicStats
//
//  Created by Matt Loera on 2/23/22.
//

//#include <string>
//#include <vector>
//#include <list>
//#include "Athlete.h"
//#include "Athlete_Tree.h"
#include "Sport.h"

  /*Constructors*/
Sport::Sport()
{}
  
/*Interface*/
//display the name, description, event date for this sport
int Sport::display()const
{
  return 0;
}

string name; //name of the event
string description; //description of the event
string eventDate; //date of the olympic competition for this event


/*class Biathalon*/
//Athlete_Tree athletes;

Biathalon::Biathalon()
{}
  
/*Interface*/
//display the name, description, event date for this sport
int Biathalon::display()const
{
  return 0;
}
//add an athlete to this sport
int Biathalon::addAthlete(const Athlete&)
{
  return 0;
}
//display an athlete to this sport by rank
int Biathalon::showAthlete(int rank)
{
  return 0;
}



/*class Figure_Skating: public Sport*/
//std::vector<Skater> athletes;

Figure_Skating::Figure_Skating()
{}
  
/*Interface*/
//display the name, description, event date for this sport
int Figure_Skating::display()const
{
  return 0;
}
//add an athlete to this sport
int Figure_Skating::addAthlete(const Athlete&)
{
  return 0;
}
//display an athlete to this sport by rank
int Figure_Skating::showAthlete(int rank)
{
  return 0;
}


//class Monobob: public Sport
//std::list<Sledder> athletes;

/*Constructors*/
Monobob::Monobob()
{}

/*Interface*/
//display the name, description, event date for this sport
int Monobob::display()const
{
  return 0;
}
//add an athlete to this sport
int Monobob::addAthlete(const Athlete&)
{
  return 0;
}
//display an athlete to this sport by rank
int Monobob::showAthlete(int rank)
{
  return 0;
}

