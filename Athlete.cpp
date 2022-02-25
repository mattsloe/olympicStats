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


using std::ostream;

int Athlete::display()const
{
  return 0;
}

ostream& operator<<(ostream &out, const Athlete &a)
{
  return out;
}

int operator==(const Athlete &a1,const Athlete &a2); //compares based on value
int operator<(const Athlete &a1,const Athlete &a2); //compares based on name (for alphabetizing)
  

/*class Skater : public Athlete*/
//  int meanEventTotal;
//  int meanBV;
//  int meanTES;
//  int meanPCS;

int Skater::display()const
{
  return 0;
}

std::ostream& operator<<(std::ostream &out, const Skater &a)
{
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

  


/*class Sledder : public Athlete*/
//  string pastResults;
//  int avgRank;
int Sledder::display()const
{
  return 0;
}
std::ostream& operator<<(std::ostream &out, const Sledder &a)
{
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

  


/*class Biathlete : public Athlete*/
//  int careerHitRate; //as a percent [0,100]
//  int avgSkiRank; //[1,+inf]

int Biathlete::display()const
{
  return 0;
}

std::ostream& operator<<(std::ostream &out, const Biathlete &a)
{
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

  
  
