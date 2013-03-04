#include "controller.h"
#include<systemc.h>

controller::controller(sc_module_name name)
  : sc_module(name)
{
  SC_THREAD(calc_green);
  //Initializing values for:  
  WE_car = false;
  EW_car = false;
  NS_car = false;
  SN_car = false;
  WE_green.initialize(false);
  EW_green.initialize(false);
  NS_green.initialize(false);
  SN_green.initialize(false);

  SC_METHOD(set_waiting_car_WE);
  dont_initialize();
  sensitive << WE_sensor;

  SC_METHOD(set_waiting_car_EW);
  dont_initialize();
  sensitive << EW_sensor;

  SC_METHOD(set_waiting_car_NS);
  dont_initialize();
  sensitive << NS_sensor;

  SC_METHOD(set_waiting_car_SN);
  dont_initialize();
  sensitive << SN_sensor;
}

//Reacts on events from the sensors
void controller::set_waiting_car_WE()
{
  WE_car = true;
}
void controller::set_waiting_car_EW()
{
  EW_car = true;
}
void controller::set_waiting_car_NS()
{
  NS_car = true;
}
void controller::set_waiting_car_SN()
{
  SN_car = true;
}

void controller::calc_green()
{
  for(;;){
    wait(50, SC_MS); // wait to let simulation time go
    //Check if there are waiting cars from east and west, enable green on appropriate light 
    if(WE_car || EW_car){   
      if(WE_car){
	WE_green = true;
      }
      if(EW_car){
	EW_green = true;
      }
      wait(3, SC_SEC);      // waiting for cars to pass
      if(EW_green) {
	EW_green=false;}    //reset the lights that were green, and remove the corresponding cars
      if(WE_green) {
	WE_green=false;}
      if(EW_green) {
	EW_car = false;}
      if(WE_green) {
	WE_car =  false;}
      wait(50,SC_MS); 
    }
    if(NS_car || SN_car){   //same as above but for north and green
      if(NS_car){
	NS_green = true;
      }
      if(SN_car){
	SN_green = true;
      }
      
      
      wait(3, SC_SEC);
      if(NS_green) {
	NS_green=false;}
      if(SN_green) {
	SN_green=false;}
      if(NS_green) {
	NS_car = false;}
      if(SN_green) {
	SN_car =  false;}

      wait(50, SC_MS);
    }
  } 
}

