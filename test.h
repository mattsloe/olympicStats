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
  Athlete* athPtr;
  athPtr = new Biathlete();
  std::cout << *athPtr;
}
#endif /* test_h */
