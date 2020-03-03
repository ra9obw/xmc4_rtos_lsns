/*
 * main.c
 *
 *  Created on: 2020 Mar 03 07:44:22
 *  Author: fynjy
 */




#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)

/**

 * @brief main() - Application entry point
 *
 * <b>Details of function</b><br>
 * This routine is the application entry point. It is invoked by the device startup code. It is responsible for
 * invoking the APP initialization dispatcher routine - DAVE_Init() and hosting the place-holder for user application
 * code.
 */

void my_usleep(uint32_t dly)
{
	//scaling factor
	dly *= 12;
//	dly /= 10;
	//
	for(; dly > 0; --dly)
	{
		__NOP();
	}
}

int main(void)
{
  DAVE_STATUS_t status;

  status = DAVE_Init();           /* Initialization of DAVE APPs  */

  if(status != DAVE_STATUS_SUCCESS)
  {
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");

    while(1U)
    {

    }
  }

  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
	  my_usleep(500000);
	  DIGITAL_IO_ToggleOutput(&LED_0);
	  my_usleep(500000);
	  DIGITAL_IO_ToggleOutput(&LED_0);
	  DIGITAL_IO_ToggleOutput(&LED_1);
  }
}
