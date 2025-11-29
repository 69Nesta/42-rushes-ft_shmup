class GameStateManager
{
private:
	int		score;
	int		lives;
	bool	gameOver;
public:
	GameStateManager(/* args */);
	~GameStateManager();

	void	rest();
	void	add_score();
	void	loseLife();
	void	setGameOver();

};

GameStateManager::GameStateManager(/* args */)
{
}

GameStateManager::~GameStateManager()
{
}
