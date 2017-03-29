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

    //! Constructor that takes no arguments but requires 4 files in ./res/ : first.txt, last.txt, place.txt, and team.txt
    */
    NameGen();

    //! Member function that returns a random first name from firstBank
    /*!
      \return std::string
    */
    string genFirst();

    //! Member function that returns a random first name from lastBank
    /*!
      \return std::string
    */
    string genLast();

    //! Member function that returns a single string containing "<firstname> <lastname>" pulled from genFirst() and genLast().
    /*!
      \return std::string
    */
    string genFull();

    //! Member function that returns a random place name from placeBank.
    /*!
      \return std::string
    */
    string genPlace();

    //! Member function that has two functionalities based on boolean parameter. If withPlace is FALSE, the string returned will only be an element of teamBank. If withPlace is TRUE, the string will be in the format "<placename> <teamname>" with <placename> pulled from genPlace().
    /*!
      \param withPlace If true, team name will be appended to a place name. If false, only team name is returned.
      \return std::string
    */
    string genTeam(bool withPlace);

 private:
    vector<string> firstBank; //<! vector<std::string> containing first names
    vector<string> lastBank; //<! vector<std::string> containing last names
    vector<string> placeBank; //<! vector<std::string> containing place names
    vector<string> teamBank; //<! vector<std::string> containing team names
};
#endif
