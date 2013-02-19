#include "monitor.h"
#include <cassert>

Monitor::Monitor(sc_module_name name, char *outfile)
  : sc_module(name)
{
  assert(outfile != 0);
  out = new ofstream(outfile);
  assert(*out);
  SC_METHOD(monitor_method);
  dont_initialize();
  sensitive << WE_green_light << EW_green_light << NS_green_light << SN_green_light;
}

Monitor::~Monitor()
{ delete out; }

void Monitor::monitor_method()
{ 
  bool  WE = WE_green_light->read();
  *out << "WE green light(" << sc_time_stamp() << ") = " << WE << '\t';
  bool  EW = EW_green_light->read();
  *out << "EW green light(" << sc_time_stamp() << ") = " << EW << '\t';
  bool  NS = NS_green_light->read();
  *out << "NS green light(" << sc_time_stamp() << ") = " << NS << '\t';
  bool  SN = SN_green_light->read();
  *out << "SN green light(" << sc_time_stamp() << ") = " << SN << endl;

}
