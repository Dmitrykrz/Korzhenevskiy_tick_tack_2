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
