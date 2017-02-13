#include <string>
#include <vector>
#include "word.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t) {
	wrd = w;
	trigs = t;
}

string Word::get_word() const {
	return wrd;
}

/* Returns how many of the trigrams in t that are present
 in this word's trigram vector */
unsigned int Word::get_matches(const vector<string>& t) const {
	int score = 0;
	int tL = t.size();
	int trigsL = trigs.size();
	for(int i = 0; i != tL; ++i)
	{
		for(int j = 0; j != trigsL; ++j)
		{
			if(trigs[i].compare(t[j]) == 0)
			{
				++score;
			}
		}
	}
	return score;
}
