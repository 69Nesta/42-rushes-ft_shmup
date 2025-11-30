#pragma once

class GameStateManager
{
private:
	int		score;
	int		lives;
	bool	pause;
	bool	gameOver;
public:
	GameStateManager(/* args */);
	~GameStateManager();

	void	rest(void);
	void	add_score(int value = 1);
	int		get_score();
	void	loseLife(void);
	void	setGameOver(void);

};
