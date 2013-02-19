#include "sensor.h"

sensor::sensor(sc_module_name name)
  :sc_module(name)
{
  SC_THREAD(new_car_pulse);
  car_signal = false;
  car.initialize(false);
  
  SC_METHOD(set_info);
  dont_initialize();
  sensitive << new_car;
}

void sensor::new_car_pulse()
{
  for(;;){// Kommer bil?
    wait(50, SC_MS);
    if (in_car){      
      new_car.notify();
    }
  }
}


void sensor::set_info()
{
  car_signal = !car_signal;
  car = car_signal;

}
