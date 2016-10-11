#include "NameGen.hpp"

NameGen::NameGen(){
	ifstream inFile1("./res/first.txt");
	ifstream inFile2("./res/last.txt");
	string temp;
	srand(time(NULL));

	if(inFile1.is_open()){
    	while(getline(inFile1, temp)){
			firstBank.push_back(temp);
		}
    	inFile1.close();
  	}else printf("Unable to open input file\n");
	if(inFile2.is_open()){
    	while(getline(inFile2, temp)){
			lastBank.push_back(temp);
		}
    	inFile2.close();
  	}else printf("Unable to open input file\n");

	firstBank.shrink_to_fit();
	lastBank.shrink_to_fit();
}

string NameGen::genFirst(){
	int temp = rand() % firstBank.size();
	return firstBank[temp];
}

string NameGen::genLast(){
	int temp = rand() % firstBank.size();
	return lastBank[temp];
}

string NameGen::genFull(){
	return genFirst() + " " + genLast();
}

