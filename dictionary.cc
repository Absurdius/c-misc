#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib> //used bc atoi.
#include "word.h"
#include "dictionary.h"
#include <unordered_set>

using namespace std;

/*
 operator==(string a, string b)
 {

 }
 */

Dictionary::Dictionary()
{
	ifstream wordsfile ("words.txt");
	//make lost of empty vectors and put them in words_by_length
//	for(int k = 0; k != 26; ++k)
//	{
//		words_by_length[k] = vector<Word>
//	}

	string line;
	string theWord;
	int theWordLength;
	string vecSizeChar;
	int vecSize;
	/*
	while (wordsfile)
	{
		theWord = wordsfile >> string;
		theWordLength = theWord.size();
		vecSize = wordsfile >> int;
		vector<string> trigs(vecSize);
		for(int i=0; i != vecSize; ++i)
			{
				// insert trigrams one by one.
				int ref = ((theWord.size() + 3) + (4 * i));
				trigs.push_back(line.substr(ref, 3));
			}
	}
	*/


	while(getline(wordsfile, line))
	{
		theWord = line.substr(0, line.find(" "));
		theWordLength = theWord.size();
		//vecSize = stoi(line.substr(theWord.size(), 1));
		vecSize = theWordLength - 2;
		vector<string> trigs(vecSize);
		for(int i=0; i != vecSize; ++i)
			{
				// insert trigrams one by one.
				int ref = ((theWord.size() + 3) + (4 * i));
				trigs.push_back(line.substr(ref, 3));
			}
		words_by_length[theWordLength].push_back(Word(theWord, trigs));
	}


	wordsfile.close();
}

bool Dictionary::contains(const string& word) const {
	int size = word.size();
	/*
	if(find(words_by_length[size].begin(), words_by_length[size].end(), word) != words_by_length[size].end()){
		return true;
	}else{
		return false;
	}*/
	vector<Word> strings = words_by_length[size];
	for(Word s: strings)
	{
		string wrdd = s.get_word();
		if(wrdd.compare(word) == 0){return true;}
	}
	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	cout << "Before add";
	add_trigram_suggestion(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

vector<string> Dictionary::add_trigram_suggestion(vector<string> sugg, const string& word) const{
	unsigned int size = word.size()-2;
	vector<string> trigrams;
	for(unsigned int i = 0; i != size; ++i)
	{
	trigrams.push_back(word.substr(i, 3));
	}
	for(Word w: words_by_length[word.size()]){
		if(size/2 <= w.Word::get_matches(trigrams)){
				sugg.push_back(w.get_word());
		}
	}
	for(Word w: words_by_length[word.size()+1]){
		if(size/2 <= w.Word::get_matches(trigrams)){
				sugg.push_back(w.get_word());
		}
	}
	for(Word w: words_by_length[word.size()-1]){
		if(size/2 <= w.Word::get_matches(trigrams)){
				sugg.push_back(w.get_word());
		}
	}
	return sugg;
}

vector<string> Dictionary::rank_suggestions(vector<string> sugg, const string& word) const{
	vector<pair<int, string>> score;

	for(unsigned int s=0; s != sugg.size(); ++s)
	{
		vector<vector<unsigned int>> d(26, vector<unsigned int>(26));
		d[0][0] = 0;

		for(unsigned int i = 1; i <= 26; ++i) d[i][0] = i;
	for(unsigned int i = 1; i <= 26; ++i) d[0][i] = i;

	for(unsigned int i = 1; i <= 26; ++i){
	for(unsigned int j = 1; j <= 26; ++j){
										d[i][j] = min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (word[i - 1] == sugg.at(s)[j - 1] ? 0 : 1) });
										}
									}
		score.push_back(make_pair(d[26][26], word));
	}
	sort(score.begin(), score.end());
	vector<string> sortedsugg;
	for(pair<int, string> p: score)
	{
		sortedsugg.push_back(p.second);
	}



	return sortedsugg;
}

vector<string> Dictionary::trim_suggestions(vector<string> sugg) const{
vector<string> trimmed;
for(int i = 0; i !=5; ++i){
	trimmed.push_back(sugg.at(i));
}
return trimmed;
}
