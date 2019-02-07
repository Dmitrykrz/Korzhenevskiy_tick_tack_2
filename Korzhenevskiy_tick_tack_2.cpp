
#include "Korzhenevskiy_tick_tack_2.h"


int Korzhenevskiy_tick_tack_2::number_of_objects{};

Korzhenevskiy_tick_tack_2* Korzhenevskiy_tick_tack_2::registry[Korzhenevskiy_tick_tack_2::len]{};

Korzhenevskiy_tick_tack_2::Korzhenevskiy_tick_tack_2(fptr callback, uint32_t timer) {
	registry[number_of_objects] = (this);
	number_of_objects++;

	_timer = timer;
	this->callback = callback;
	_enabled = false;
	_lastTime = 0;
	counts = 0;

}

Korzhenevskiy_tick_tack_2::~Korzhenevskiy_tick_tack_2() {}

void Korzhenevskiy_tick_tack_2::start() {
	_lastTime = millis();
	_enabled = true;
	}



void Korzhenevskiy_tick_tack_2::stop() {
	_enabled = false;
	}


void Korzhenevskiy_tick_tack_2::tick() {
	if (_enabled) 
	{

		if ((millis() - _lastTime) >= _timer)
		{
			_lastTime = millis();
			counts++;
			callback();
		}
	}



}


void Korzhenevskiy_tick_tack_2::mass_start()
{
	for (int x = 0; x < number_of_objects; x++)
		registry[x]->start();
	
}


void Korzhenevskiy_tick_tack_2::mass_tick()
{
	for (int x = 0; x < number_of_objects; x++)
		registry[x]->tick();

}


void Korzhenevskiy_tick_tack_2::mass_stop()
{
	for (int x = 0; x < number_of_objects; x++)
		registry[x]->stop();

}


void Korzhenevskiy_tick_tack_2::setinterval(int timer) {
	_timer = timer;
}


void Korzhenevskiy_tick_tack_2::restart() {
	_lastTime = millis();

}


void Korzhenevskiy_tick_tack_2::zero_count() {
		counts = 0;
}