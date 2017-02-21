#include <iostream>
#include <fstream>
#include "tagremover.h"
#include <regex>

using namespace std;

Tagremover::Tagremover(istream& in) : instream(in){


}

void Tagremover::print(ostream& out) {
  string input;
  string line;

  cout << "Input file to change, type stop to type directly into program" << endl;
  string testfile;
  instream >> testfile;
  if(testfile != "stop"){
  ifstream test (testfile);
  cout << "Read from file complete" << endl;

  while (getline(test, line)) input += line + "\n";
  }else{
  while (getline(instream, line)) input += line + "\n";
  }
  input = regex_replace(input, regex("<[^<>$]*>"), "");
  /* input = regex_replace(input, regex("<[^<>$]*>"), ""); */
  input = regex_replace(input, regex("&lt;"), "<");
  input = regex_replace(input, regex("&gt;"), ">");
  input = regex_replace(input, regex("&nbsp;"), " ");
  input = regex_replace(input, regex("&amp;"), "&");

  out << input;
}
