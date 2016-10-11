#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <time.h> 

using namespace std;

class NameGen{
	public:
		
		NameGen();
		string genFirst();
		string genLast();
		string genFull();
		
	private:
		vector<string> firstBank, lastBank;
};
