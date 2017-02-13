#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include "word.h"

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
	std::vector<std::string> add_trigram_suggestion(std::vector<std::string> sugg, const std::string& word) const;
	std::vector<std::string> rank_suggestions(std::vector<std::string> sugg, const std::string& word) const;
	std::vector<std::string> trim_suggestions(std::vector<std::string> sugg) const;
private:
	//std::vector<std::vector<Word>> words_by_length;
	std::vector<Word> words_by_length[26];
};

#endif
