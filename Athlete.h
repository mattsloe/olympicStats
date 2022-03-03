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
  Athlete();
  Athlete(const string& name, const string& nationality, int age);
  Athlete(const Athlete&);
  virtual ~Athlete();//manages the char*
  
  virtual int display()const;
  friend std::ostream& operator<<(std::ostream &out, const Athlete &a);
  int operator==(const Athlete &a2); //compares based on value
  int operator<(const Athlete &a2); //compares based on name (for alphabetizing)
  int operator>(const Athlete &a2);
  int operator!=(const Athlete& a2);
  int operator<=(const Athlete& a2);
  int operator>=(const Athlete& a2);
  Athlete& operator=(const Athlete& a2);
 
protected:
  void init();

private:
  char* name; //here's my cstring
  string nationality;
  int age; //validate [0,99]

};

class Skater : public Athlete
{
public:
  Skater();
  Skater(const string& n, const string& nat, int a);
  Skater(const Athlete&,int,int,int,int);
  Skater(const Skater&);
  ~Skater();
  int display()const;
  friend std::ostream& operator<<(std::ostream &out, const Skater &a);
  int operator==(const Skater &a2)const; //compares based on value
  int operator<(const Skater &a2)const; //compares based on rank
 // void operator=(const Skater&a2);//assingment
private:
  int meanEventTotal;
  int meanBV;
  int meanTES;
  int meanPCS;
  
  void init();
  
};

class Sledder : public Athlete
{
public:
  Sledder();
  Sledder(const string& n, const string& nat, int a);
  Sledder(const Athlete&,const string&,int);
  ~Sledder();
  
  int display()const;
  friend std::ostream& operator<<(std::ostream &out, const Sledder &a);
  int operator==(const Sledder &a2)const; //compares based on value
  int operator<(const Sledder &a2)const; //compares based on rank
  //void operator=(const Sledder &a2);
private:
  string pastResults;
  int avgRank;
  void init();
  
};

class Biathlete : public Athlete
{
public:
  Biathlete();
  Biathlete(const string& n, const string& nat, int a);
  Biathlete(const Athlete&,int,int);
  ~Biathlete();
  
  int display()const;
  friend std::ostream& operator<<(std::ostream &out, const Biathlete &a);
  int operator==(const Biathlete &a2)const; //compares based on value
  int operator<(const Biathlete &a2)const; //compares based on rank
private:
  int careerHitRate; //as a percent [0,100]
  int avgSkiRank; //[1,+inf]
  void init();
  
};
#endif /* Athelte_h */
