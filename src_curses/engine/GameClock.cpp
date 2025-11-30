#include "engine/GameClock.hpp"
#include <thread>

using namespace std::chrono;

GameClock::GameClock() :
	start_time(steady_clock::now()),
	frame_start_time(steady_clock::now()),
	previus_frame_time(steady_clock::now()),
	frame_end_time(steady_clock::now()),
	delta_time(0),
	fixed_times_step(duration<double>(1.0 / 60.0)), // Pour la physique
	target_frame_time(duration<double>(1.0 / 60.0)), // 60 FPS
	accumulated_time(0),
	frame_count(0),
	is_paused(false)
{
}

GameClock::~GameClock()
{
}

void GameClock::set_start_frame()
{
	this->frame_start_time = steady_clock::now();
	this->delta_time = this->frame_start_time - this->previus_frame_time;

	if (!this->is_paused)
		this->accumulated_time += this->delta_time;

	this->previus_frame_time = this->frame_start_time;
	this->frame_count++;
}

double GameClock::get_delta_time()
{
	if (this->is_paused)
		return (0.0);
	return (this->delta_time.count());
}

void GameClock::set_end_frame()
{
	this->frame_end_time = steady_clock::now();
	auto frame_duration = this->frame_end_time - this->frame_start_time;

	if (frame_duration < this->target_frame_time && !this->is_paused)
	{
		std::this_thread::sleep_for(this->target_frame_time - frame_duration);
	}
}

void GameClock::set_target_fps(double fps)
{
	if (fps > 0)
	{
		target_frame_time = duration<double>(1.0 / fps);
	}
}

void GameClock::pause()
{
	this->is_paused = true;
}

void GameClock::resume()
{
	this->is_paused = false;
}

bool GameClock::is_game_paused()
{
	return (this->is_paused);
}

double GameClock::calculate_fps()
{
	return delta_time.count() > 0 ? 1.0 / delta_time.count() : 0.0;
}