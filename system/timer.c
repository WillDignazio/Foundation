/* Programable Interval Timer Driver 
** Author: Will Dignazio 
** Description: 
**	Driver for the programmable interval timer that can control the 
** frequency of which interrupt events occur. This driver can also be 
** used to generate system beeps at specific pitch frequencies. 
*/

#include <foundation/system.h>
#include <foundation/sysio.h>
#include <foundation/stdio.h>

unsigned int timer_ticks = 0; 
unsigned int phase = 18;		// Really 18.222, but this will do.  

/* Easy method to change the timekeeping pace. */
void timer_phase(int hz)
{ 
	int divisor = 1193180 / hz; 	// Calc divisor 
	outb(0x43, 0x36); 				// Set our command byte to 0x36
	outb(0x40, divisor & 0xFF);		// Set low byte of divisor 
	outb(0x40, divisor >> 8); 		// Set high byte of divisor 
	phase = hz; 
}

/* Handles the Timer, increments the timer_ticks variable every time 
** the timer fires. By default the timer fires 18.222 times per second. 
** However this will be changed when timer_phase is called, it will 
** then be changed to the hertz argument of the method. 
*/
void timer_handler(struct regs *r)
{ 
	/* Increment ticks */
	timer_ticks++; 

	/*Test loop to display loop increment */
	if (timer_ticks % phase == 0)
	{ 
	} 
} 

/* Sets up the system clock by installing the timer handler to IRQ0 */
void timer_install()
{ 
	/* Installs timer_handler() to IRQ0 */
	irq_install_handler(0, timer_handler); 	// See irq.c for func def
}

/* 	Makes the system wait the alloted ticks */
void wait(int ticks)
{ 
	unsigned long eticks;
	eticks = timer_ticks + ticks; 
	while(timer_ticks < ticks); 
	timer_ticks = 0; 
}
