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
#include "input.h"

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
  using namespace std;
  cout << name << ": " << description << endl;
  cout << "Event Date: " << eventDate << endl;
  return 1;
}

void Sport::init()
{
  using namespace std;
  getStringInput("Name: ",name);
  getStringInput("Description: ",description);
  getStringInput("Event Date: ", eventDate);
}

/*class Biathalon*/
//Athlete_Tree athletes;
static string biathName = "Biathalon";
static string biathDesc = "Biathalon description.";
static string biathDate = "Date of the biathalon event.";
Biathalon::Biathalon():Sport(biathName,biathDesc,biathDate)
{init();}
  
/*Interface*/
//display the name, description, event date for this sport
int Biathalon::display()const
{
  Sport::display();
  athletes.displayInorder();
  return 1;
}
//add an athlete to this sport
int Biathalon::addAthlete(const Athlete& toAdd)
{
  athletes.insert(dynamic_cast<const Biathlete&>(toAdd));
  return 1;
}
//display an athlete to this sport by rank
int Biathalon::showAthlete(int rank)
{
  return 0;
}

int Biathalon::removeByName(const std::string& key)
{
  if(athletes.remove(key)) return 1;
 else return 0; 
}

void Biathalon::init()
{

}




/*class Figure_Skating: public Sport*/
//std::vector<Skater> athletes;
static string skateName = "Olympic Figure Skating";
static string skateDesc = "Figure skating description.";
static string skateDate = "Date of the figure skating event.";
Figure_Skating::Figure_Skating():Sport(skateName,skateDesc,skateDate)
{init();}
 Figure_Skating::~Figure_Skating()
{
   athletes.clear();
}
/*Interface*/
//display the name, description, event date for this sport
int Figure_Skating::display()const
{
  Sport::display();
  displaySkaters();
  return 1;
}
//add an athlete to this sport
int Figure_Skating::addAthlete(const Athlete& toAdd)
{
  const Skater& add = (const Skater&)toAdd;
  bool flag = false;
  //case::empty list
  if(athletes.empty()){
    athletes.push_back(add);
    flag = true;
  }
  //iterate throguh list and put in order
  if(!flag){
  for(auto pos = athletes.begin();pos != athletes.end();++pos){
    if(*pos < add){
        if(!flag) athletes.insert(pos,add);
        flag = true;
      break;
    }
  }}
  //case::add at end
  if(!flag){
    athletes.push_back(add);
    flag = true;
  }
  return flag;
}
//display an athlete to this sport by rank
int Figure_Skating::showAthlete(int rank)
{
  if(rank<1 || rank>athletes.size()) return 0;
  athletes[rank-1].display();
  return 1;
}

int Figure_Skating::removeByName(const std::string&)
{
  return 0;
}

void Figure_Skating::init()
{
}

void Figure_Skating::displaySkaters() const
{
  for(Skater const& s:athletes){
    s.display();
  }
}


//class Monobob: public Sport
//std::list<Sledder> athletes;
static string bobName = "Women's Monobob";
static string bobDesc = "Monobob description";
static string bobDate = "Women's Monobob event date!";

/*Constructors*/
Monobob::Monobob():Sport(bobName,bobDesc,bobDate)
{init();}

Monobob::~Monobob()
{athletes.clear();}

/*Interface*/
//display the name, description, event date for this sport
int Monobob::display()const
{
  Sport::display();
  displaySledders();
  return 1;
}
//add an athlete to this sport
int Monobob::addAthlete(const Athlete& toAdd)
{
  const Sledder& add = (const Sledder&)toAdd;
  bool flag = false;
  //case::empty list
  if(athletes.empty()){
    athletes.push_back(add);
    flag = true;
  }
  //iterate throguh list and put in order
  if(!flag){
  for(auto pos = athletes.begin();pos != athletes.end();++pos){
    if(add < *pos){
        if(!flag) athletes.insert(pos,add);
        flag = true;
      break;
    }
  }}
  //case::add at end
  if(!flag){
    athletes.push_back(add);
    flag = true;
  }
  return flag;
}
//display an athlete to this sport by rank
int Monobob::showAthlete(int rank)
{
  if(rank<1 || (unsigned long)rank>athletes.size()) return 0;
  athletes[rank-1].display();
  return 1; 
}

int Monobob::removeByName(const std::string&)
{
  return 0;
}

void Monobob::init()
{

}

void Monobob::displaySledders()const
{
  for(Sledder const& s:athletes){
    s.display();
  }
}

