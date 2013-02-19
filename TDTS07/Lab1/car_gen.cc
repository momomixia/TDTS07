#include <cassert>
#include <iostream>
#include <fstream>
using std::ofstream;

int main(int argc, char **argv){
  assert(argc == 2);
  char *outfile = argv[1];
  ofstream *out;
  out = new ofstream(outfile);
  assert(*out);

  for (int i=0 ; i < 10  ; i++)
    {
      *out << "W " << "1" << "\n";
    }
 
  *out << "N " << "1" << "\n";
 
  for (int i=0 ; i < 10  ; i++)
    {
      *out << "W " << "1" << "\n";
    }
  delete  out;
  return 0;
}
