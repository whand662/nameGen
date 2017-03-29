/**
  testGen.cpp
  driver to show sample outputs of NameGen

  @author Willis Hand
  @version 1.0
  @copyright 2017 Willis Hand
*/
#include <iostream>
#include "NameGen.hpp"
using std::cout;

int main() {
  NameGen ng = NameGen();
  cout << "First: " << ng.genFirst() << "\n";
  cout << "Last:  " << ng.genLast() << "\n";
  cout << "Full:  " << ng.genFull() << "\n";
  cout << "Place: " << ng.genPlace() << "\n";
  cout << "Team:  " << ng.genTeam(false) << "\n";
  cout << "Team+: " << ng.genTeam(true) << "\n";
}
