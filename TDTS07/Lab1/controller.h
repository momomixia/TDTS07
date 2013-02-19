
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <systemc.h>

SC_MODULE(controller){

  sc_in<bool> WE_sensor;
  sc_in<bool> EW_sensor;
  sc_in<bool> NS_sensor;
  sc_in<bool> SN_sensor;

  sc_out<bool> WE_green;
  sc_out<bool> EW_green;
  sc_out<bool> NS_green;
  sc_out<bool> SN_green;


  bool WE_car;
  bool EW_car;
  bool NS_car;
  bool SN_car;


  SC_HAS_PROCESS(controller);
  controller(sc_module_name name);
  void calc_green();
  void set_waiting_car_NS();
  void set_waiting_car_SN();
  void set_waiting_car_EW();
  void set_waiting_car_WE();
  


};

#endif
