# Korzhenevskiy_tick_tack_2
Arduino library for timers   
 
# Arduino timer library based on millis()

There are dozens of ticker/timer libraries out there. All of them lack on thing that I needed which is the ability to mass stop/start/update timers without the need to add a line for each timer. So I made such a library with the help of Andrey Krikunov.


# Usage

### Declare the timer
```
Korzhenevskiy_tick_tack_1 timer1(some_function_1, 1000);
Korzhenevskiy_tick_tack_2 timer1(some_function_2, 3000);
```
### Start all timers
```
Korzhenevskiy_tick_tack_2::mass_start();
```
### Add updater to the loop()
```
Korzhenevskiy_tick_tack_2::mass_tick();
```


# List of all functions

```void start(); ``` 
Starts the timer, counts=0

	```void stop();```
 Stops the timer
 
	```void tick();```
 Checks if the time is due, executtes callback functions if needed
 
	```void setinterval(int timer);```
 Sets new interval in ms
 
	```void restart();```
 Restart timer. What it does is basically not letting the timer execute it's function by forcing it to wait again
 
	```void zero_count();```
 Makes the number of executions zero
 
	```static void mass_start();```
 Starts all timers.  This functions calls 	```void start();``` for every timer
 
	```static void mass_tick();```
 Checks all timers. This functions calls 	```void tick();``` for every timer
 
	```static void mass_stop();```
 Checks all timers. This functions calls 	```void stop();``` for every timer
 
	```int counts;```
 Returns the number of executions
 
 ```#define max_number_of_timers 10```
 This parameter in .h file determins the maximum number of timers, default is 10
 
