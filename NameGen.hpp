/**
  NameGen.hpp
  Name generating object meant to be portable between projects

  @author Willis Hand
  @version 1.0
  @copyright 2017 Willis Hand
*/
#ifndef _NAMEGEN
#define _NAMEGEN

#include <stdlib.h>
#include <time.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class NameGen {
 public:
    NameGen();
    string genFirst();
    string genLast();
    string genFull();
    string genPlace();
    string genTeam(bool withPlace);

 private:
    vector<string> firstBank; //<! vector<std::string> containing first names
    vector<string> lastBank; //<! vector<std::string> containing last names
    vector<string> placeBank; //<! vector<std::string> containing place names
    vector<string> teamBank; //<! vector<std::string> containing team names
};
#endif
