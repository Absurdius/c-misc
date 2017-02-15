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
	while(getline(wordsfile, line))
	{
		theWord = line.substr(0, line.find(" "));
		theWordLength = theWord.size();
		//vecSize = stoi(line.substr(theWord.size(), 1));
		vector<string> trigs;
		for(int i=0; i != theWordLength; ++i)
			{
				// insert trigrams one by one.
				trigs.push_back(line.substr(i, 3));
			}
		words_by_length[theWordLength].push_back(Word(theWord, trigs));
	}


	wordsfile.close();
	cout << "Ready to receive" << endl;
}

bool Dictionary::contains(const string& word) const {
	int size = word.size();
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
	suggestions = add_trigram_suggestion(suggestions, word);
	suggestions = rank_suggestions(suggestions, word);
	suggestions = trim_suggestions(suggestions);
	return suggestions;
}

vector<string> Dictionary::add_trigram_suggestion(vector<string> sugg, const string& word) const{
	unsigned int size = word.size()-2;
	vector<string> trigrams;
	for(unsigned int i = 0; i != size; ++i)
	{
	trigrams.push_back(word.substr(i, 3));
	}
	for(unsigned int i=0; i!=words_by_length[word.size()].size(); ++i){
		if(words_by_length[word.size()].at(i).get_matches(trigrams) > 0){
		}
		if(size/2 <= words_by_length[word.size()].at(i).get_matches(trigrams)){
			//	sugg.push_back(w.get_word());
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
	vector<vector<unsigned int>> d(26, vector<unsigned int>(26));
	int wordsize = word.size();
	int suggwordsize = 0;

	for(unsigned int s=0; s != sugg.size(); ++s)
	{


		d[0][0] = 0;
		suggwordsize = sugg.at(s).size();
		int refi = 0;
		int refj = 0;
		for(int i = 1; i <= wordsize; ++i) d[i][0] = i;
		for(int i = 1; i <= suggwordsize; ++i) d[0][i] = i;
		for(int i = 1; i <= wordsize; ++i){
			for(int j = 1; j <= suggwordsize; ++j){
						d[i][j] = min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (word.at(i - 1) == sugg.at(s).at(j - 1) ? 0 : 1) });
								refi = i;
								refj = j;
										}
									}
		score.push_back(make_pair(d[refi][refj], sugg.at(s)));
	}
	sort(score.begin(), score.end());
	vector<string> sortedsugg;
	for(unsigned int i=0; i != score.size(); ++i)
	{
		sortedsugg.push_back(score[i].second);
	}
	return sortedsugg;
}

vector<string> Dictionary::trim_suggestions(vector<string> sugg) const{
vector<string> trimmed;
int comp = 5;
if(sugg.size() < 5) {comp = sugg.size();}
for(int i = 0; i !=comp; ++i){
	trimmed.push_back(sugg.at(i));
}
return trimmed;
}
