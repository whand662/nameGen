#include "NameGen.hpp"
#include <iostream>

using namespace std;

int main(){
	NameGen ng = NameGen();
	cout << ng.genFirst() << "\n";
	cout << ng.genLast() << "\n";
	cout << ng.genFull() << "\n";
	cout << ng.genPlace() << "\n";
	cout << ng.genTeam(false) << "\n";
	cout << ng.genTeam(true) << "\n";
}
