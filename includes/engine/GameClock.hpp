#pragma once
#include <chrono>

class GameClock
{
	using Clock = std::chrono::steady_clock;
    using TimePoint = std::chrono::time_point<Clock>;
    using Duration = std::chrono::duration<double>;

private:
	TimePoint	start_time;
	TimePoint	frame_start_time;
	TimePoint	previus_frame_time;
	TimePoint	frame_end_time;
	Duration	delta_time;
	Duration	fixed_times_step;
	Duration	target_frame_time;
	Duration	accumulated_time;

	bool		is_paused;
	uint64_t	frame_count;
public:
	GameClock();
	~GameClock();

	void	set_start_frame();
	void	set_end_frame();

	void	set_target_fps(double fps);


	void	pause();
	void	resume();
	bool	is_game_paused();

	double	get_delta_time();
	double	calculate_fps();
};

