/**
  NameGen.hpp
  Name generating object meant to be portable between projects

  @author Willis Hand
  @version 1.2
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

    //! Constructor that takes no arguments but requires 4 files in ./res/ : first.txt, last.txt, place.txt, and team.txt. Use this constructor when using NameGen from its own subdirectory.
    NameGen();

    //! Constructor that requires 4 files in ./res/ : first.txt, last.txt, place.txt, and team.txt. The value of inDirectory doesn't matter, it just signals that the application is being run from inside the nameGen directory so that the NameGen object will use the right file paths to get to the /res directory.
    /*!
      \param inDirectory Regardless of value passed will change filepath from "./nameGen/res/" to "./res/"
    */
    NameGen(bool inDirectory);

    //! Called by constructors to populate the vectors with data from .txt files in res.
    void populate();

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
    string path1, path2, path3, path4;
    static vector<string> firstBank; //<! vector<std::string> containing first names
    static vector<string> lastBank; //<! vector<std::string> containing last names
    static vector<string> placeBank; //<! vector<std::string> containing place names
    static vector<string> teamBank; //<! vector<std::string> containing team names
};
#endif
