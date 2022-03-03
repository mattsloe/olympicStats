//
//  Athlete_Tree.cpp
//  olympicStats
//
//  Created by Matt Loera on 2/23/22.
//

#include <iostream>
#include "Athlete_Tree.h"
#include "Athlete.h"

Node::Node(const Biathlete& a): data(new Biathlete(a)),left(nullptr),right(nullptr)
{}

Node::Node(const Biathlete& a,Node* l,Node* r)
:data(new Biathlete(a)),left(l),right(r)
{}

Node::~Node()
{
  delete data;
}

int Node::setLeft(Node* l)
{
  left = l;
  return 1;
}

int Node::setRight(Node* r)
{
  right = r;
  return 1;
}

bool Node::isLeaf()const
{
  if(left || right) return false;
  return true;
}

Biathlete& Node::getValue()
{
  return *data;
}

Node* Node::getLeft()
{
  return left;
}

Node* Node::getRight()
{
  return right;
}

int Node::matchKey(const string& key)const
{
  Athlete& _d = *data;
  if(_d == Athlete(key,key,0))
    return 0;
  else if(_d > Athlete(key,key,0)){
    return -1;
  }
  return 1;
}

Athlete_Tree::Athlete_Tree():root(nullptr)
{}

Athlete_Tree::~Athlete_Tree()
{deleteAll(root);}

int Athlete_Tree::insert(const Biathlete& data)
{
 return insert(data,root);
}

int Athlete_Tree::searchName(std::string key,Biathlete*& result)
{
  if(result) delete result; //sanitize
  return searchName(key,result,root);
}

int Athlete_Tree::searchName(std::string key,Biathlete*& result,Node* root)
{
  if(!root) return 0; //BASE
  int compare = root->matchKey(key);
  if(compare == 0){ //SUCCESS
    result=new Biathlete(root->getValue());
    return 1;
  }
  if(compare < 0){ //SEARCH LOWER
    return searchName(key,result,root->getLeft());
  }
  if(compare > 0){ //SEARCH HIGHER
    return searchName(key,result,root->getRight());
  }
  return -1;
}

int Athlete_Tree::displayInorder()const
{
  return displayInorder(root);
}

int Athlete_Tree::displayInorder(Node* root)const
{
  if(root){
    displayInorder(root->getLeft());
    root->getValue().display();
    std::cout << std::endl;
    displayInorder(root->getRight());
    return 1;
  }
  return 0;
}

int Athlete_Tree::remove(std::string key)
{
  bool flag = false;
  root = remove(key,root,flag);
  return flag;
}

//inorder traversal until flag found
Node* Athlete_Tree::remove(std::string key,Node*& root,bool& flag)
{
  if(root!= nullptr){
    /*special case leaf*/
    if(root->isLeaf() && root->matchKey(key)==0){
      delete root;
      return nullptr;
    }
//left first
    Node * left = root->getLeft();
    root->setLeft(remove(key,left,flag));
//then root
    if(root->matchKey(key)==0){
      flag = true;
      if(root->getRight()){
        Node* right = root->getRight();
        delete root;
        root = right;
      }else{ //root->getLeft() == true
        Node* left = root->getLeft();
        delete root;
        root = left;
      }
    }
//then right
    Node* right = root->getRight();
    root->setRight(remove(key,right,flag));
  }
  return root;
}

void Athlete_Tree::deleteAll(Node* root)
{
  if(root){
    deleteAll(root->getLeft());
    deleteAll(root->getRight());
  }
  delete root;
}

int Athlete_Tree::insert(const Biathlete& data, Node*& root)
{
 if(!root){
    root = new Node(data,nullptr,nullptr);
    return 1;
  }
  if(data < root->getValue()){
    Node* left = root->getLeft();
    if(left){
      return insert(data,left);
    }else{
      left = new Node(data,nullptr,nullptr);
      root->setLeft(left);
      return 1;
    }
  }
  if(!(data < root->getValue()) && !(data == root->getValue())){
    Node* right = root->getRight();
    if(right){
      return insert(data,right);
    }else{
      right = new Node(data,nullptr,nullptr);
      root->setRight(right);
      return 1;
    }
  }
  return -1;
}

