//
//  Athelete.h
//  olympicStats
//  This contains the interface for the Athelete class and it's derivatives.
//  Including Biathlete, Skater, and Sledder
//  Created by Matt Loera on 2/23/22.
//

#ifndef Athlete_h
#define Athlete_h
#include <string>
#include <iostream>
using std::string;

class Athlete
{
public:
  virtual int display()const;
  friend std::ostream& operator<<(std::ostream &out, const Athlete &a);
  int operator==(const Athlete &a2); //compares based on value
  int operator<(const Athlete &a2); //compares based on name (for alphabetizing)
  

private:
  char* name; //here's my cstring
  string nationality;
  int age; //validate [0,99]
};

class Skater : public Athlete
{
public:
  virtual int display()const;
  friend std::ostream& operator<<(std::ostream &out, const Skater &a);
  int operator==(const Athlete &a2); //compares based on value
  int operator<(const Athlete &a2); //compares based on rank
private:
  int meanEventTotal;
  int meanBV;
  int meanTES;
  int meanPCS;
  
};

class Sledder : public Athlete
{
public:
  virtual int display()const;
  friend std::ostream& operator<<(std::ostream &out, const Sledder &a);
  int operator==(const Athlete &a2); //compares based on value
  int operator<(const Athlete &a2); //compares based on rank
private:
  string pastResults;
  int avgRank;
  
};

class Biathlete : public Athlete
{
public:
  virtual int display()const;
  friend std::ostream& operator<<(std::ostream &out, const Biathlete &a);
  int operator==(const Athlete &a2); //compares based on value
  int operator<(const Athlete &a2); //compares based on rank
private:
  int careerHitRate; //as a percent [0,100]
  int avgSkiRank; //[1,+inf]
  
  
};
#endif /* Athelte_h */
