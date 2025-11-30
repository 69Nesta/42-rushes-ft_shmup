#pragma once

class GameStateManager
{
private:
	int		score;
	int		lives;
public:
	GameStateManager(/* args */);
	~GameStateManager();

	void	rest(void);
	void	add_score(int value = 1);
	void	loseLife(void);
	int		get_score();
};
