/**
  NameGen.cpp
  Name generating object meant to be portable between projects

  @author Willis Hand
  @version 2.0
  @copyright 2017 Willis Hand
*/
#include "NameGen.hpp"

vector<string> NameGen::firstBank;
vector<string> NameGen::lastBank;
vector<string> NameGen::placeBank;
vector<string> NameGen::teamBank;

NameGen::NameGen() {
  path1 = "./nameGen/res/first.txt";
  path2 = "./nameGen/res/last.txt";
  path3 = "./nameGen/res/team.txt";
  path4 = "./nameGen/res/place.txt";
  populate();
}

NameGen::NameGen(string inDirectory){
  path1 = inDirectory + "first.txt";
  path2 = inDirectory + "last.txt";
  path3 = inDirectory + "team.txt";
  path4 = inDirectory + "place.txt";
  populate();
}

void NameGen::populate(){
  if(firstBank.size() > 0){
    //printf("Already loaded\n");
    return;
  }
  ifstream inFile1(path1);
  ifstream inFile2(path2);
  ifstream inFile3(path3);
  ifstream inFile4(path4);
  string temp;

  if (inFile1.is_open()) {
      while (getline(inFile1, temp)) {
      firstBank.push_back(temp);
    }
      inFile1.close();
    } else {
      printf("Unable to open input file\n");
    }

  if (inFile2.is_open()) {
      while (getline(inFile2, temp)) {
      lastBank.push_back(temp);
    }
      inFile2.close();
    } else {
      printf("Unable to open input file\n");
    }

  if (inFile3.is_open()) {
      while (getline(inFile3, temp)) {
      teamBank.push_back(temp);
    }
      inFile3.close();
    } else {
      printf("Unable to open input file\n");
    }

  if (inFile4.is_open()) {
      while (getline(inFile4, temp)) {
      placeBank.push_back(temp);
    }
      inFile4.close();
    } else {
      printf("Unable to open input file\n");
    }

  firstBank.shrink_to_fit();
  lastBank.shrink_to_fit();
  teamBank.shrink_to_fit();
  placeBank.shrink_to_fit();
}

string NameGen::genFirst() {
  int temp = rand() % firstBank.size();
  return firstBank[temp];
}

string NameGen::genLast() {
  int temp = rand() % firstBank.size();
  return lastBank[temp];
}

string NameGen::genFull() {
  return genFirst() + " " + genLast();
}

string NameGen::genPlace() {
  int temp = rand() % placeBank.size();
  return placeBank[temp];
}

string NameGen::genTeam(bool withPlace) {
  int temp = rand() % teamBank.size();
  string hold = teamBank[temp];
  if (withPlace) {
    return genPlace() + " " + hold;
  } else {
    return hold;
  }
}
