//
//  Sport.h
//  olympicStats
//  This contains the class interfaces for Sport and it's derivative classes.
//  Including Biathalon, Figure_Skating, and Monobob
//  Created by Matt Loera on 2/23/22.
//

#ifndef Sport_h
#define Sport_h

#include <string>
#include <vector>
#include <list>
#include "Athlete.h"
#include "Athlete_Tree.h"

class Sport
{
public:
  /*Constructors*/
  Sport();
  Sport(const string& name,const string& description,const string& eventDate);
  virtual ~Sport();
  
  /*Interface*/
  //display the name, description, event date for this sport
  virtual int display()const;
  //add an athlete to this sport
  virtual int addAthlete(const Athlete&)=0;
  //display an athlete to this sport by rank
  virtual int showAthlete(int rank)=0;
  //remove an athlete by name
  virtual int removeByName(const std::string&)=0;
  
private:
  string name; //name of the event
  string description; //description of the event
  string eventDate; //date of the olympic competition for this event
  
  void init();
  
};

class Biathalon: public Sport
{
public:
  /*Constructors*/
  Biathalon();
  
  /*Interface*/
  //display the name, description, event date for this sport
  int display()const;
  //add an athlete to this sport
  int addAthlete(const Athlete&);
  //display an athlete to this sport by rank
  int showAthlete(int rank);
  
  int removeByName(const std::string&);
  
private:
  Athlete_Tree athletes;
  
  void init();
  
};

class Figure_Skating: public Sport
{
public:
  /*Constructors*/
  Figure_Skating();
  ~Figure_Skating();
  
  /*Interface*/
  //display the name, description, event date for this sport
  int display()const;
  //add an athlete to this sport
  int addAthlete(const Athlete&);
  //display an athlete to this sport by rank
  int showAthlete(int rank);
  
  int removeByName(const std::string&);
private:
  std::vector<Skater> athletes;
  void init();
  void displaySkaters()const;
  
};

class Monobob: public Sport
{
public:
  /*Constructors*/
  Monobob();
  ~Monobob();
  
  /*Interface*/
  //display the name, description, event date for this sport
  int display()const;
  //add an athlete to this sport
  int addAthlete(const Athlete&);
  //display an athlete to this sport by rank
  int showAthlete(int rank);
  
  int removeByName(const std::string&);
private:
  std::vector<Sledder> athletes;
  void init();
  void displaySledders()const;
};
#endif /* Sport_h */
