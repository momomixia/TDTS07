#ifndef MONITOR_H
#define MONITOR_H

#include <systemc.h>
#include <fstream>
using std::ofstream;

SC_MODULE(Monitor) {
  //Values of the lights from controller
  sc_in<bool> WE_green_light;
  sc_in<bool> EW_green_light;
  sc_in<bool> NS_green_light;
  sc_in<bool> SN_green_light;
  

  SC_HAS_PROCESS(Monitor);
  Monitor(sc_module_name name, char *outfile);
  ~Monitor();
  void monitor_method();
  ofstream *out;
};
#endif

