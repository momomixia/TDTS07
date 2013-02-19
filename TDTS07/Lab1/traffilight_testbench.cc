#include "controller.h"
#include "sensor.h"
#include "monitor.h"
#include "input_gen.h"
#include <systemc.h>

int sc_main(int argc, char **argv)
{

  assert(argc == 4); //Check so that argc is of certain length
  sc_time sim_time( atof(argv[1]), SC_SEC);
  char *infile = argv[2];
  char *outfile = argv[3];

  // Create channels, signals
  sc_signal<bool> car_signal_WE;
  sc_signal<bool> car_signal_EW;
  sc_signal<bool> car_signal_NS;
  sc_signal<bool> car_signal_SN;

  sc_signal<bool> WE_sensor_to_controller;
  sc_signal<bool> EW_sensor_to_controller;
  sc_signal<bool> NS_sensor_to_controller;
  sc_signal<bool> SN_sensor_to_controller;

  sc_signal<bool> control_light_WE;
  sc_signal<bool> control_light_EW;
  sc_signal<bool> control_light_NS;
  sc_signal<bool> control_light_SN;

  // Create modules
  sensor sensorWE("SensorWE");
  sensor sensorEW("SensorEW");
  sensor sensorNS("SensorNS");
  sensor sensorSN("SensorSN");

  controller control("Controller");
  Monitor monitor("Monitor", outfile);
  generator inputgen("Input_Generator", infile);

  //Connect modules
  sensorWE(car_signal_WE, WE_sensor_to_controller);
  sensorEW(car_signal_EW, EW_sensor_to_controller);
  sensorNS(car_signal_NS, NS_sensor_to_controller);
  sensorSN(car_signal_SN, SN_sensor_to_controller);

  control(WE_sensor_to_controller, EW_sensor_to_controller, NS_sensor_to_controller, SN_sensor_to_controller,
	  control_light_WE, control_light_EW, control_light_NS, control_light_SN);

  inputgen(car_signal_WE, car_signal_EW, car_signal_NS, car_signal_SN);

  monitor(control_light_WE, control_light_EW, control_light_NS, control_light_SN);
 
  sc_start(sim_time);

  return 0;
 
}
