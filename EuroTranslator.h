//11929229 Daniel Song

#ifndef EUROTRANSLATOR_H
#define EUROTRANSLATOR_H

class EuroTranslator
{
	private:
				

	public:
		EuroTranslator();
		~EuroTranslator();
		bool isSpecial(char c);
		void printList(const list<char> &myList);
		void fillList(list<char> &myList, const string &vowels);
		void changeCase(list <char> &myList);
		unsigned short getHash(const list<char> &charList);

};
EuroTranslator::EuroTranslator()
{
}
EuroTranslator::~EuroTranslator()
{
}

bool EuroTranslator::isSpecial(char c)
{
	if (c == 0)
	{
		return false;
	}
	if (c >= 'a' && c <= 'z')
	{
		return false;
	}
	if (c >= 'A' && c <= 'Z')
	{
		return false;
	}
	return true;
}
void EuroTranslator::printList(const list<char> &myList)
{
	list<char>::const_iterator itr;
   	
	for (itr = myList.begin(); itr != myList.end(); itr++ ) 
	{
		cout << *itr;
	}
	cout << '\n';
}

void EuroTranslator::fillList(list<char> &myList, const string &vowels)
{
	for (int i = 0; i<vowels.length(); i++) 
	{
		myList.push_back(vowels[i]);
	}
}

void EuroTranslator::changeCase(list <char> &myList)
{
	int i = 0;
	list<char>::iterator itr;
		
	for (itr = myList.begin(); itr != myList.end(); itr++ )
	{	
		char ch = *itr;
		bool wasUpper = isupper(ch); //check the Uppercase If true, it was uppercase
		ch = tolower(ch);
		list<char>::iterator itrn = itr; // 'itrn' is next character to 'itr'
		++itrn; 
		list<char>::iterator itrnn = itrn; // 'itrnn' is next character to 'itrn'
		++itrnn;
		bool next = (itrn != myList.end());
		++i;

		// Rule 1 : Replace all c with s if followed by the characters e, i or y, otherwise replace with k. 
		if (*itr == 'C' || *itr == 'c') 
		{
			if (next)
			{
				if (*itrn == 'e' || *itrn == 'i' || *itrn == 'y')
				{
					*itr = wasUpper ? 'S' : 's';
				}
				else
				{
					*itr = wasUpper ? 'K' : 'k';
				}
			}
		}

		// Rule 2 : Replace all instances of w with v.
		if (*itr == 'W' || *itr == 'w')
		{
			*itr = wasUpper? 'V' : 'v';
		}

		// Rule 3 : Replace all instances of ph with the character f.
		if (*itr == 'P' || *itr == 'p') 
		{
			if (next)
			{
				if(*itrn == 'h')
				{
					*itr = wasUpper ? 'F' : 'f';
					*itrn = 0;
				}	
			}
		}

		// Rule 4 : Replace all double characters with a single instance of the character. 
		if (next) 
		{	
			bool variable = true;
			while(variable) 
			{
				if (*itr == *itrn)
				{
					*itrn = 0;
				} 
				else 
				{
					variable = false;			
				}
			}
		}

		// Rule 5 : If a word is more than 3 characters long and ends with an e then it can be removed. 
		if (*itr == 'E' || *itr == 'e') 
		{
			if (next)
			{
				if (isSpecial(*itrn) && i >= 3)
				{
					*itr = 0;
				}
			}
		}

		// Rule 6 : Replace all instances of th with z.
		if (*itr == 'T' || *itr == 't')
		{
			if (next)
			{
				if (*itrn == 'h')
				{
					*itr = wasUpper ? 'Z' : 'z';
					*itrn = 0;
				}
			}
		}

		// Rule 7 : Replace all instances of ou with u.
		if (*itr == 'O' || *itr == 'o') 
		{
			if (next)
			{
				if (*itrn  == 'u')
				{
					*itr = wasUpper ? 'U' : 'u';
					*itrn = 0;
				}
			}
		}

		/*
			Rule 8 : Replace all instances of ea with e.
			Rule 9 : If a word ends with ed then replace it with d. 			
		*/
		if (*itr == 'E' || *itr == 'e') 
		{
			if (next)
			{
				if (*itrn == 'a')
				{
					*itrn = 0;
				} 

				else if(*itrn == 'd' && (*itrnn == '.' || *itrnn == ',' || isspace(*itrnn)))  
				{
		        	*itr = wasUpper ? 'D' : 'd';  
		       		*itrn = 0;  
		   		}
			}
		}
	
		if (isSpecial(ch))
		{
			i = 0;
		}	
	}
}

unsigned short EuroTranslator::getHash(const list<char> &charList) 
{ 
   unsigned short shift, hash = 0; 
   list<char>::const_iterator itr; 
   for (itr = charList.begin(); itr != charList.end(); itr++) 
   { 
      hash ^= *itr; 
      shift = (hash & 15); 
      hash = (hash << shift) | (hash >> (16 - shift)); 
   } 
   return hash; 
}
#endif
