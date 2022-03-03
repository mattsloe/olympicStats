//main driver for olympicStats program
//Author: Matt Loera
//
//#include "test.h"
#include "Sport.h"
#include "input.h"
#include <iostream>

void init(Figure_Skating&,Monobob&,Biathalon&);
void mainMenu(Figure_Skating&,Monobob&,Biathalon&);
void skateMenu(Figure_Skating&);
void bobMenu(Monobob&);
void biathMenu(Biathalon&);


int main()
{

  //init
  Figure_Skating f;
  Monobob m;
  Biathalon b;
  init(f,m,b);

  mainMenu(f,m,b);
  return 0;
}

void init(Figure_Skating& f,Monobob& m,Biathalon& b)
{
  f.addAthlete(Skater(Athlete("Figure Skater 1","USA",28),10,4,3,2));
  f.addAthlete(Skater(Athlete("Skaty Skates","Lat",25),12,4,5,6));
  f.addAthlete(Skater(Athlete("Firsty Lastname","JP",29),5,3,3,3));

  b.addAthlete(Biathlete(Athlete("First Last","Country",20),10,10));
  b.addAthlete(Biathlete(Athlete("Matt L","USA",30),50,5));
  b.addAthlete(Biathlete(Athlete("Ash Coon","NM",31),80,1));

  m.addAthlete(Sledder(Athlete("Sledder 1","USA",28),"novice",3));
  m.addAthlete(Sledder(Athlete("First Last","Lat",25),"Olympic pewter",6));
  m.addAthlete(Sledder(Athlete("Ash Coon","JP",29),"Champ Olympic Gold",4));
}

void mainMenu(Figure_Skating& f,Monobob& m, Biathalon& b)
{
  using namespace std;
bool menu=true;
  char choice;
  do{
    //display the menu
    cout << "Choose an Olympic Sport:" << endl;
    cout << "A| Women's Solo Figure Skating" <<endl
         << "B| Women's Monobob" <<endl
         << "C| Women's Biathalon" <<endl;
    getCharInput("D| QUIT\n",choice);
 
    switch(choice){
      case 'a': /*Fig Skate*/
      case 'A':
        skateMenu(f);
        break;
        
      case 'b': /*Monobob*/
      case 'B':
        bobMenu(m);
        break;
        
      case 'c': /*Biathalon*/
      case 'C':
        biathMenu(b);
        break;
        
      case 'd': /*Quit*/
      case 'D':
        menu = false;
        break;
        
      default:
        break;
    }
  }while(menu);
}

void skateMenu(Figure_Skating& f)
{
  using namespace std;
bool menu=true;
  char choice;
  do{
    //display the menu
    cout << "MENU:" << endl;
    cout << "A| Display Skaters" <<endl
         << "B| Add Athlete" <<endl
         << "C| View By Rank" <<endl
         << "D| Remove By Name" <<endl;
    getCharInput("E| QUIT\n",choice);
 
    switch(choice){
      case 'a': /*Display Skaters*/
      case 'A':
        f.display();
        break;
        
      case 'b': /*Add athlete*/
      case 'B':
      { cout << "Add another athlete\n";
        Skater newAthlete;
        f.addAthlete(newAthlete);
      f.display();
      break;}
        
      case 'c': /*View By Rank*/
      case 'C':
        cout << "View a skater by rank.\n";
        if(!f.showAthlete(getIntInput("Which rank? ")))
          cout << "not found\n";
        break;
        
      case 'd': /*Remove By Name*/
      case 'D':
      { cout<< "Remove an athlete by name\n";
        string str;
        getStringInput("Which athlete to remove? ",str);
        if(f.removeByName(str)) cout << "removed\n";
        else cout << "no match\n";
        f.display();
      break;}
        
      case 'e': /*Quit*/
      case 'E':
        menu = false;
        break;
        
      default:
        break;
    }
  }while(menu);
}
void bobMenu(Monobob& f)
{
  using namespace std;
  bool menu=true;
    char choice;
    do{
      //display the menu
      cout << "MENU:" << endl;
      cout << "A| Display Sledders" <<endl
           << "B| Add Athlete" <<endl
           << "C| View By Rank" <<endl
           << "D| Remove By Name" <<endl;
      getCharInput("E| QUIT\n",choice);
   
      switch(choice){
        case 'a': /*Display Sledders*/
        case 'A':
          f.display();
          break;
          
        case 'b': /*Remove By Name*/
        case 'B':
         { cout << "Add another athlete\n";
        Sledder newAthlete;
        f.addAthlete(newAthlete);
         f.display();
      break;} 

          
        case 'c': /*View By Rank*/
        case 'C':
          cout << "View a skater by rank.\n";
          if(!f.showAthlete(getIntInput("Which rank? ")))
          cout << "not found\n";
          break;
          
        case 'd': /*Remove By Name*/
        case 'D':
        { cout<< "Remove an athlete by name\n";
          string str;
          getStringInput("Which athlete to remove? ",str);
          if(f.removeByName(str)) cout << "removed\n";
          else cout << "no match\n";
          f.display();
          break;}
          
        case 'e': /*Quit*/
        case 'E':
          menu = false;
          break;
          
        default:
          break;
      }
    }while(menu);
}
void biathMenu(Biathalon& f)
{
  using namespace std;
bool menu=true;
  char choice;
  do{
    //display the menu
    cout << "MENU:" << endl;
    cout << "A| Display Biathletes" <<endl
         << "B| Add Athlete" <<endl
         << "C| View By Rank" <<endl
         << "D| Remove By Name" <<endl;
    getCharInput("E| QUIT\n",choice);
 
    switch(choice){
      case 'a': /*Display Biathlete*/
      case 'A':
        f.display();
        break;
        
      case 'b': /*Add Biathlete*/
      case 'B':
      { cout << "Add another athlete\n";
        Biathlete newAthlete;
        f.addAthlete(newAthlete);
        f.display();
        break;}
        
        
      case 'c': /*View By Rank*/
      case 'C':
        cout << "View a skater by rank.\n";
        if(!f.showAthlete(getIntInput("Which rank? ")))
          cout << "not found\n";
        break;
        
      case 'd': /*Remove By Name*/
      case 'D':
        { cout<< "Remove an athlete by name\n";
        string str;
        getStringInput("Which athlete to remove? ",str);
        if(f.removeByName(str)) cout << "removed\n";
        else cout << "no match\n";
        f.display();
        break;}

        
      case 'e': /*Quit*/
      case 'E':
        menu = false;
        break;
        
      default:
        break;
    }
  }while(menu);
}

