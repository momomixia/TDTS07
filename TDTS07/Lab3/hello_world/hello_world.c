#include "appsupport.h"

void main1() {
  int i;  

  start_metric();
   
  for(i=0;i<5;i++) {    
      pr("", i, PR_CPU_ID | PR_DEC | PR_NEWL );
  }

  stop_metric();
  stop_simulation();
}

