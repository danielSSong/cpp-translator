//11929229 Daniel Song

#include <iostream>
#include <list>
#include <ctype.h>
#include <string>
#include <fstream>

using namespace std;

#include "EuroTranslator.h"

int main(int argc, char *argv[])
{
	EuroTranslator *trans  = new EuroTranslator();

	char ch;
	string message;
	list<char> myList;
	  
	cout << "Creating input file stream object..." << endl;
	ifstream fin;

	// check user input the file
	if(!argv[1])
	{
		cout << "Not input the file" << endl;
		return 0;
	}

	cout << "Trying to open " << argv[1] << endl;
	fin.open(argv[1]);

	// check user input right file, if it is right(find the file), the program prints the character by character.
	if(!fin)
	{
	  cout << "File name " << argv[1] << " is not exist" << endl; 
	}
	else 
	{
		cout << "Trying to read characters form the file...\n"   << endl;
		while(!fin.eof())
		{
	  		fin.get(ch);
	  		message += ch;
		}
	}

	trans->fillList(myList, message);
	trans->printList(myList);
	cout << "Hash = " << trans->getHash(myList) << "\n" << endl;
	trans->changeCase(myList);
	trans->printList(myList);
	cout << "Hash = " << trans->getHash(myList) << "\n" << endl;
	trans->getHash(myList);
	fin.close();

	cout << "This is the end of the program" << endl;
	delete trans;
	return 0;
		
}
