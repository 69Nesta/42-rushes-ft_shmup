#pragma once
#include "screens/IScreenManager.hpp"
#include "engine/InputHandler.hpp"
#include <ncurses.h>
#include <stdlib.h>

enum ScreenStatus {
	ACTIVE,
	PAUSED,
	HIDDEN
};

class Screen
{
protected:
	IScreenManager&	screen_manager;
private:
	ScreenStatus	status;
	ScreenType		type;

public:
	Screen(IScreenManager& screen_manager, ScreenType type);
	virtual ~Screen() = default;

	virtual	void	initialize(void) = 0;
	virtual void	update(float delta_time) = 0;
	virtual void	render(void) = 0;
	virtual void	handle_input(InputHandler& input) = 0;

	void			pause(void);
	void			resume(void);

	ScreenStatus	get_status(void);
	ScreenType		get_type(void);
	bool			is_active(void);	
};
