#ifndef INPUT_GEN_H
#define INPUT_GEN_H

#include <systemc.h>
#include <fstream>
using std::ifstream;

SC_MODULE(generator){
  sc_out<bool> WE_car;
  sc_out<bool> EW_car;
  sc_out<bool> NS_car;
  sc_out<bool> SN_car;

  SC_HAS_PROCESS(generator);
  generator(sc_module_name name, char *datafile);
  ~generator();

  void generate_output();
  ifstream *in;


};


#endif
