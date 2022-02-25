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
#include <iostream>

/*
string name; //name of the event
string description; //description of the event
string eventDate; //date of the olympic competition for this event
*/
  /*Constructors*/
Sport::Sport()
{init();}

Sport::~Sport()
{}

  
Sport::Sport(const string& _name,const string& _description,const string& _eventDate)
:name(_name),description(_description),eventDate(_eventDate)
{}
/*Interface*/
//display the name, description, event date for this sport
int Sport::display()const
{
  return 0;
}

void Sport::init()
{
  using namespace std;
  cout << "Sport: ";
  getline(cin,name);
  cout << "Description: ";
  getline(cin,description);
  cout << "Event Date: ";
  getline(cin,eventDate);
}






/*class Biathalon*/
//Athlete_Tree athletes;
static string biathName = "Biathalon";
static string biathDesc = "Biathalon description.";
static string biathDate = "Date of the biathalon event.";
Biathalon::Biathalon():Sport(biathName,biathDesc,biathDate)
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
static string skateName = "Olympic Figure Skating";
static string skateDesc = "Figure skating description.";
static string skateDate = "Date of the figure skating event.";
Figure_Skating::Figure_Skating():Sport(skateName,skateDesc,skateDate)
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
static string bobName = "Women's Monobob";
static string bobDesc = "Monobob description";
static string bobDate = "Women's Monobob event date!";

/*Constructors*/
Monobob::Monobob():Sport(bobName,bobDesc,bobDate)
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

