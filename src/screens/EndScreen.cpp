#include "screens/EndScreen.hpp"
#include <string>
#include <sstream>

EndScreen::EndScreen(IScreenManager& screen_manager, GameStateManager &game_state, bool& is_running):
	Screen(screen_manager, ScreenType::END), game_state(game_state), is_running(is_running)
{
	this->window = subwin(stdscr, LINES, COLS, 0, 0);
}

EndScreen::~EndScreen()
{

	if (this->window)
	{
		delwin(this->window);
		this->window = NULL;
	}
}

void	EndScreen::update(float delta_time)
{
    (void)delta_time;
}

void	EndScreen::render(void)
{}

std::string game_over_msg = "   _________    __  _________   ____ _    ____________ \n"
"  / ____/   |  /  |/  / ____/  / __ \\ |  / / ____/ __ \\\n"
" / / __/ /| | / /|_/ / __/    / / / / | / / __/ / /_/ /\n"
"/ /_/ / ___ |/ /  / / /___   / /_/ /| |/ / /___/ _, _/ \n"
"\\____/_/  |_/_/  /_/_____/   \\____/ |___/_____/_/ |_|  \n";

void	EndScreen::resize()
{
    erase();
    // utiliser le message multi-lignes game_over_msg
    std::ostringstream	score;
    score << "SCORE: " << this->game_state.get_score();

    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);

    // découpe game_over_msg en lignes et affiche chaque ligne centrée
    std::istringstream iss(game_over_msg);
    std::string line;
    int y = LINES / 5 * 2;
    while (std::getline(iss, line))
    {
        int x = (COLS - static_cast<int>(line.length())) / 2;
        if (x < 0) x = 0;
        mvwprintw(this->window, y++, x, "%s", line.c_str());
    }

    // affiche le score juste en dessous du bloc du message
    mvwprintw(this->window, y + 1, (COLS / 2) - score.str().length() / 2, "%s", score.str().c_str());
    box(this->window, ACS_VLINE, ACS_HLINE);
    wbkgd(this->window, COLOR_PAIR(1));
    wrefresh(this->window);
}

void	EndScreen::handle_input(InputHandler& input)
{
	if (input.key_is_pressed(' '))
		is_running = false;
	if (input.key_is_pressed(410))
		this->resize();
}

void	EndScreen::initialize(void)
{
	this->resize();
}
