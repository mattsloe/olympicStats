//
//  test.h
//  olympicStats
//
//  Created by Matt Loera on 2/23/22.
//

#ifndef test_h
#define test_h
#include "Sport.h"
void testSport()
{
  Sport* sportPtr;
  sportPtr = new Monobob();
  delete sportPtr;
  sportPtr = new Biathalon();
  delete sportPtr;
  sportPtr = new Figure_Skating();
  delete sportPtr;
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
