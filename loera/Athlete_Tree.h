//
//  Athlete_Tree.h
//  olympicStats

//  A balanced tree implementation for holding Athletes

//  Created by Matt Loera on 2/23/22.
//

#ifndef Athlete_Tree_h
#define Athlete_Tree_h
class Biathlete;
class Node
{
public:
  Node(const Biathlete&);
  Node(const Biathlete&,Node* left,Node* right);
  ~Node();

  bool isLeaf()const;
  Biathlete& getValue();
  Node* getLeft();
  Node* getRight();
  //return 0 for match
  //negative number for less than
  //positive number for greater than
  int matchKey(const std::string&)const;
  //sets Left node
  int setLeft(Node*);
  //sets Right node
  int setRight(Node*);

private:
  Biathlete* data;
  Node* left;
  Node* right;
};

class Athlete_Tree
{
public:
Athlete_Tree();
~Athlete_Tree();
  int insert(const Biathlete& data);
  int searchName(std::string key,Biathlete*& result);
  int displayInorder()const;
  int remove(std::string key);
  

private:
Node* root;

void deleteAll(Node*);
int insert(const Biathlete&,Node*&);
int searchName(std::string,Biathlete*&,Node*);
int displayInorder(Node*)const; 
Node* remove(std::string,Node*&,bool&);
  
};

#endif /* Athlete_Tree_h */
