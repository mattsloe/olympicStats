//
//  test.h
//  olympicStats
//
//  Created by Matt Loera on 2/23/22.
//

#ifndef test_h
#define test_h
#include "Sport.h"
#include "input.h"
void testSport()
{
  Sport* sportPtr;
  sportPtr = new Monobob();
  (*sportPtr).display();
  delete sportPtr;
  sportPtr = new Biathalon();
  (*sportPtr).display();
  delete sportPtr;
  sportPtr = new Figure_Skating();
  (*sportPtr).display();
  delete sportPtr;
  
}

void testBiathalon()
{
  Biathalon b;
  //add some athletes
    //Biathlete(Athlete,int hitrate,int rank)
  b.addAthlete(Biathlete(Athlete("First Last","Country",20),10,10));
  b.addAthlete(Biathlete(Athlete("Matt L","USA",30),50,5));
  b.addAthlete(Biathlete(Athlete("Ash Coon","NM",31),80,1));
  //display the dataset
  std::cout << "Displaying the dataset...\n";
  b.display();
  //add another athlete
  std::cout << "Add another athlete\n";
  b.addAthlete(Biathlete());
  b.display();
  //remove an athlete by name
  std::cout << "Remove an athlete by name\n";
  std::string str;
  getStringInput("Which to remove? ",str);
  if(b.removeByName(str)) std::cout << "removed\n";
  else std::cout << "no match\n";
  b.display();
  //search by name
  std::cout << "Search by Name\n";
  getStringInput("Which to find? ",str);
  
}
void testSkater()
{
  std::list<Skater> l;
  l.push_back(Skater(Athlete("Name","C",20),1,2,3,4));
  Skater m;
  l.push_back(m);
}
void testSkating()
{
  Figure_Skating s;
  //add some athletes
    //Skater(const Athlete&,int,int,int,int);
  s.addAthlete(Skater(Athlete("Athlete 1","USA",28),5,4,3,2));
  s.addAthlete(Skater(Athlete("First Last","Lat",25),3,4,5,6));
  s.addAthlete(Skater(Athlete("Pom Poko","JP",29),3,3,3,3));
  //display the dataset
  std::cout << "Displaying the dataset...\n";
  s.display();
  //add another athlete
  std::cout << "Add another athlete\n";
  Skater newAthlete;
  s.addAthlete(newAthlete);
  s.display();
  //remove athlete by name
//  std::cout << "Remove an athlete by name\n";
//  std::string str;
//  getStringInput("Which to remove? ",str);
//  if(s.removeByName(str)) std::cout << "removed\n";
//  else std::cout << "no match\n";
//  s.display();
  //search by rank
  std::cout << "Search by rank\n";
  if(!s.showAthlete(getIntInput("Which rank? ")))
    std::cout << "not found :(\n";
}

void testSledding()
{
  Monobob s;
  //add some athletes
    // Sledder(const Athlete&,const string&,int);
  s.addAthlete(Sledder(Athlete("Athlete 1","USA",28),"results",3));
  s.addAthlete(Sledder(Athlete("First Last","Lat",25),"past results here",6));
  s.addAthlete(Sledder(Athlete("Pom Poko","JP",29),"some results",4));
  //display the dataset
  std::cout << "Displaying the dataset...\n";
  s.display();
  //add another athlete
  std::cout << "Add another athlete\n";
  s.addAthlete(Sledder());
  s.display();
  //remove athlete by name
  std::cout << "Remove an athlete by name\n";
  std::string str;
  getStringInput("Which to remove? ",str);
  if(s.removeByName(str)) std::cout << "removed\n";
  else std::cout << "no match\n";
  s.display();
  //search by rank
  std::cout << "Search by rank\n";
  if(!s.showAthlete(getIntInput("Which rank? ")))
    std::cout << "not found :(\n";
  
}

void testAthlete()
{
  Athlete* athPtr1;
  Athlete* athPtr2;
  std::string isEqual, isLessthan;
  athPtr1 = new Skater("Name","A Nation",6);
  athPtr2 = new Skater("Name","A Nation",6);
  std::cout << *athPtr1 << *athPtr2;
  
  if(*athPtr1 == *athPtr2){isEqual = ""; //test == operator
  }else{ isEqual = "not ";}
  
  if(*athPtr1 < *athPtr2){ isLessthan = "";}
  else{isLessthan = "not ";}
  
  std::cout << "Athlete 1 and Athlete 2 are " << isEqual << "equal.\n";
  std::cout << "Athlete 1 is " << isLessthan << "less than Athlete 2.\n";
  
}

void testSub1()
{
  using namespace std;
  Athlete* a1p;
  Athlete* a2p;
  string isEqual, isLessthan;
  cout<< "Testing stream insertion (<<), equality (==), and less than (<) operators\n";
  //Test Athlete
  cout << "First testing a generic athlete.\n";
  cout << "First Athlete.\n";
  a1p = new Athlete();
  cout << "Second Athlete.\n";
  a2p = new Athlete();
  cout << *a1p << *a2p;
  cout << "Comparison based on name\n";
  cout << "athlete1 == athlete2 :";
  if(*a1p == *a2p) cout << "true" << endl;
  else cout << "false" << endl;
  
  cout << "athlete1 < athlete2 :";
  if(*a1p < *a2p) cout << "true" << endl;
  else cout << "false" << endl;
  
  delete a1p;
  delete a2p;
  
  //Test Skater
  cout << "Testing an olympic figure skater.\n";
  cout << "First Skater.\n";
  a1p = new Skater();
  cout << "Second Skater.\n";
  a2p = new Skater();
  
  Skater& s1 = *((Skater*)a1p); Skater& s2 = *((Skater*)a2p);
  cout << s1 << s2;
  cout << "Comparison based on Mean event total\n";
  cout << "skater1 == skater2 :";
  if(s1 == s2) cout << "true" << endl;
  else cout << "false" << endl;
  
  cout << "skater1 < skater2 :";
  if(s1 < s2) cout << "true" << endl;
  else cout << "false" << endl;
  
  delete a1p; delete a2p;
  //Test Sledder
  cout << "Testing an olympic monobob athlete.\n";
  cout << "First Sledder.\n";
  a1p = new Sledder();
  cout << "Second Sledder.\n";
  a2p = new Sledder();
  Sledder& sl1 = *((Sledder*)a1p);Sledder& sl2 = *((Sledder*)a2p);
  
  cout << sl1 << sl2;
  cout << "Comparison based on rank\n";
  cout << "sledder1 == sledder2 :";
  if(sl1 == sl2) cout << "true" << endl;
  else cout << "false" << endl;
  
  cout << "sledder1 < sledder2 :";
  if(sl1 < sl2) cout << "true" << endl;
  else cout << "false" << endl;
  
  delete a1p; delete a2p;
  //Test Biathlete
  cout << "Testing an olympic biathlete.\n";
  cout << "First Athlete.\n";
  a1p = new Biathlete();
  cout << "Second Athlete.\n";
  a2p = new Biathlete();
  Biathlete& b1 = *((Biathlete*)a1p);
  Biathlete& b2 = *((Biathlete*)a2p);
  cout << b1 << b2;
  cout << "Comparison based on rank.\n";
  cout << "biathlete1 == biathlete2 :";
  if(b1 == b2) cout << "true" << endl;
  else cout << "false" << endl;
  
  cout << "biathlete1 < biathlete2 :";
  if(b1 < b2) cout << "true" << endl;
  else cout << "false" << endl;

  delete a1p; delete a2p;
}
#endif /* test_h */
