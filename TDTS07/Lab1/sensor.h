
#ifndef SENSOR_H
#define SENSOR_H

#include <systemc.h>

SC_MODULE(sensor){
  sc_in<bool> in_car;
  sc_out<bool> car;
  sc_event new_car;
  bool car_signal;

  SC_HAS_PROCESS(sensor);
  sensor(sc_module_name name);
  void new_car_pulse();
  void set_info();
};

#endif
