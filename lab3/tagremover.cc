#include <iostream>
#include <fstream>
#include "tagremover.h"
#include <regex>

using namespace std;

Tagremover::Tagremover(istream& in) : instream(in){


}

void Tagremover::print(ostream& out) {
  string change;
  string line;

  cout << "change file to change, type stop to type directly into program" << endl;
  string testfile;
  instream >> testfile;
  if(testfile != "stop"){
  ifstream test (testfile);
  cout << "Read from file complete" << endl;

  while (getline(test, line)) change += line + "\n";
  }else{
  while (getline(instream, line)) change += line + "\n";
  }
  change = regex_replace(change, regex("<[^<>$]*>"), "");
  change = regex_replace(change, regex("&lt;"), "<");
  change = regex_replace(change, regex("&gt;"), ">");
  change = regex_replace(change, regex("&nbsp;"), " ");
  change = regex_replace(change, regex("&amp;"), "&");

  out << change;
}
