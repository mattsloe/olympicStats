//
//  input.cpp
//  olympicStats
//
//  Created by Matt Loera on 3/1/22.
//
#include <iostream>
#include "input.h"
#include <string>
int getIntInput(const std::string& prompt)
{
  using namespace std;
  int input;
  bool flag = false;
  do{
    if(!cin){
      cin.clear();
      cin.ignore(100,'\n');
    }
    string str;
    cout << prompt;
    getline(cin,str);
    try{
      input = stoi(str);
      flag = false;
    }
    catch(...){
      cout << "Invalid input.\n";
      flag = true;
    }
  }while(flag);
  
  return input;
}

void getStringInput(const std::string& prompt, std::string& inString)
{
  using namespace std;
  if(!cin){
    cin.clear();
    cin.ignore(100,'\n');
  }
  cout << prompt;
  getline(cin,inString);
}
