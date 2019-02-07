
#include "Korzhenevskiy_tick_tack_2.h"

// declare functions first .
// it better to declare them here and write the content in the end. 
//Otherwise timer cannot use another timer.
void printMessage1(); 
void printMessage2();
void printMessage3();


// declare timers
// (fuction that timer starts, delay in ms)
Korzhenevskiy_tick_tack_2 timer1(printMessage1, 1000);
Korzhenevskiy_tick_tack_2 timer2(printMessage2, 2001);
Korzhenevskiy_tick_tack_2 timer3(printMessage3, 3001);


void setup() {
	Serial.begin(115200);
	Serial.println("Start");
	
	// start all timers
	Korzhenevskiy_tick_tack_2::mass_start();


}

void loop() {
	// check all timers and execute functions if the time is due
	// mass_tick() must be present in the loop
	Korzhenevskiy_tick_tack_2::mass_tick();

	// example code
	if (timer1.counts > 4) timer1.stop();
	if (timer2.counts > 8) timer2.stop();
	

}

// timer 3 will not work until timer 2 stops
// this happens because timer 2 time is shorter that timer 3
void printMessage1() { Serial.println("timer_function_1"); }
void printMessage2() { Serial.println("timer_function_2"); timer3.restart(); }
void printMessage3() { Serial.println("timer_function_3"); }