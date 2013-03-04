#include "input_gen.h"
#include <cassert>

generator::generator(sc_module_name name,char *datafile)
  : sc_module(name)
{
  assert(datafile != 0); //not null
  in = new ifstream(datafile); //open file
  assert (*in); // ok?!
  SC_THREAD(generate_output);
  
  WE_car.initialize(false);
  EW_car.initialize(false);
  NS_car.initialize(false);
  SN_car.initialize(false);

}
generator::~generator()
{ delete in; }

void generator::generate_output()
{
  double t;
  char from;
  while(!((*in).eof()))
    {
      *in >> from >> t;
      wait(t, SC_SEC);
      if(from == 'W')
	{
	  WE_car = true;
	  wait(55 , SC_MS);
	  WE_car = false;
	  wait(SC_ZERO_TIME);
	}else if(from == 'E')
	{
	  EW_car = true;
	  wait(55 , SC_MS);
	  EW_car = false;
	  wait(SC_ZERO_TIME);
	}else if(from == 'N')
	{
	  NS_car = true;
	  wait(55 , SC_MS);
	  NS_car = false;
	  wait(SC_ZERO_TIME);
	}else if(from == 'S')
	{
	  SN_car = true;
	  wait(55 , SC_MS);
	  SN_car = false;
	  wait(SC_ZERO_TIME);
	}else
	{
	  break;
      }
    }
}
