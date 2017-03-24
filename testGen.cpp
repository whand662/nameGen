/**
  testGen.cpp
  driver to show sample outputs of NameGen

  @author Willis Hand
  @version 1.0
  @copyright 2017 Willis Hand
*/
#include <iostream>
#include "NameGen.hpp"Name generating object meant to be portable between projects

using std::cout;

int main() {
  NameGen ng = NameGen();
  cout << ng.genFirst() << "\n";
  cout << ng.genLast() << "\n";
  cout << ng.genFull() << "\n";
  cout << ng.genPlace() << "\n";
  cout << ng.genTeam(false) << "\n";
  cout << ng.genTeam(true) << "\n";
  cout << ng.genTeam(true) << "\n";
  cout << ng.genTeam(true) << "\n";
}
