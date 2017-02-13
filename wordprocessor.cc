// Words preprocessor
// read the file words
/* IMPORTANT */
/* CREATES THE FILE WORDS.TXT
   DOES NOT CREATE WORD-OBJECS */

   #include <string>
   #include <vector>
   #include <fstream>
   #include <iostream>
   #include <sstream>
   #include <algorithm>

   using namespace std;
bool comparestr(string a, string b)
{
  return (a.string::compare(b) < 0);
}

int main()
{
  ifstream dict ("words");
  if(!dict){cout << "no file called words (only)"; return 1;}

  ofstream dictpp ("words.txt");
  //iterates over the entire ditionary word by word
  string line;
  stringstream wordline;
  while(getline(dict, line))
  {
    //work on the string line aka the word in the Dictionary
    transform(line.begin(), line.end(), line.begin(), ::tolower);
    int nbr_trigrams = line.length() - 2;
    //append number to line;
    wordline << line << " " << nbr_trigrams;
    line = wordline.str();
    line += " ";

    if(nbr_trigrams > 0)
    {
      vector<string> trigrams;
      //iterate from every letter up to the third last one
      for(int i = 0; i != nbr_trigrams; ++i)
      {
        string trigram;
        for(int j = 0; j != 3; ++j)
        {
          trigram += line.at(i+j);
        }
       trigrams.push_back(trigram);
      }
      sort(trigrams.begin(), trigrams.end(), comparestr);
      for(string trigram : trigrams){
        line += trigram;
        line += " ";
      }
    }
    // output line
    cout << line << "\n";
    dictpp << line << "\n";
    wordline.str("");
    wordline.clear();
  }
  cout << "scanned file successfully! " << "\n";
  dictpp.close();
    return 0;
}
