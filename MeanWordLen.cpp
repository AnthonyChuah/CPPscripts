// Program reads a text file and calculates the average length of words in the text.
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void gen_word_report(ifstream& instream, ofstream& outstream);
// This reads all the text in the input file and writes to an output file a report.
// Report contains the average length of each word and number of words.

int main()
{
  char filename[80];
  char outfilename[80];
  ifstream fin;
  ofstream fout;
  cout << "Begin reading text file.\n";
  cout << "Which text file do you wish to read?\n";
  cin >> filename;
  fin.open(filename);
  if (fin.fail())
    {
      cout << "Reading input file failed.\n";
      exit(1);
    }
  cout << "What is the name of your report?\n";
  cin >> outfilename;
  fout.open(outfilename);
  if (fout.fail())
    {
      cout << "Reading output file failed.\n";
      exit(1);
    }
  gen_word_report(fin,fout);
  fin.close();
  fout.close();
  cout << "End of generating report.\n";
  return 0;
}

void gen_word_report(ifstream& instream, ofstream& outstream)
{
  int wordcount = 0;
  double totalchars = 0;
  double meanlen = 0;
  char next;
  bool prev_letter = false;
  while (!instream.eof())
    {
      instream.get(next);
      if (isspace(next))
	{
	  if (prev_letter)
	    wordcount++;
	  prev_letter = false;
	  continue;
	}
      else
	{
	  prev_letter = true;
	}
      totalchars++;
    }
  meanlen = totalchars / wordcount;
  outstream << "Word count: " << wordcount << endl;
  outstream << "Mean word length: " << meanlen << endl;
}
