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

// Checks for new cars
void sensor::new_car_pulse()
{
  for(;;){// Kommer bil?
    wait(50, SC_MS);
    if (in_car){      
      new_car.notify();
    }
  }
}

// Sensitive to new_car, inverts the signal 
// for car and puts it on output
void sensor::set_info()
{
  car_signal = !car_signal;
  car = car_signal;

}
