#pragma once
#include <ncurses.h>
#include <stdlib.h>

enum ScreenType {
	LOBBY,
	GAME,
	PAUSE,
	GAMEOVER
};

enum ScreenStatus {
	ACTIVE,
	PAUSED,
	HIDDEN
};

class Screen
{
private:
	ScreenStatus	status;
	ScreenType		type;

public:
	Screen(ScreenType type);
	~Screen(void);

	virtual	void	initialize(void) = 0;
	virtual void	update(float delta_time) = 0;
	virtual void	render(void) = 0;
	// virtual void	handleInput(void);

	void			pause(void);
	void			resume(void);

	ScreenStatus	get_status(void);
	ScreenType		get_type(void);
	bool			is_active(void);	
};
