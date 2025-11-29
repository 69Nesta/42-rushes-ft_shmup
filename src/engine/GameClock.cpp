#include "engine/GameClock.hpp"

using namespace std::chrono;

GameClock::GameClock(): 
	start_time(steady_clock::now()),
	frame_start_time(steady_clock::now()),
	previus_frame_time(steady_clock::now()),
	delta_time(0),
	fixed_times_step(0),
	accumulated_time(0),
	frame_count(0),
	is_paused(false)
{
}

GameClock::~GameClock()
{
}

void	GameClock::set_start_frame()
{
	this->frame_start_time = steady_clock::now();
	this->delta_time = this->frame_start_time - this->previus_frame_time;

	if (!this->is_paused)
		this->accumulated_time += this->delta_time;

	this->previus_frame_time = this->frame_start_time;
	this->frame_count++;
}

double	GameClock::get_delta_time()
{
	if (this->is_paused)
		return (0.0);
	return (this->delta_time.count());
}

void	GameClock::set_end_frame() {}

void	GameClock::pause()
{
	this->is_paused = true;
}

void	GameClock::resume()
{
	this->is_paused = false;
}

bool	GameClock::is_game_paused()
{
	return (this->is_paused);
}

double	GameClock::calculate_fps()
{
	return delta_time.count() > 0 ? 1.0 / delta_time.count() : 0.0;
}