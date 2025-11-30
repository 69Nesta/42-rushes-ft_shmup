#include "managers/BulletsManager.hpp"
#include "screens/IScreenManager.hpp"
#include "managers/EnemysManager.hpp"
#include "entities/Player.hpp"

class CollisionManager
{
private:
	BulletsManager&	bullet_manager;
	EnemysManager&	enemys_manager;
	IScreenManager& screen_manager;
	Player&			player;
public:
	CollisionManager(BulletsManager& bullet_manager, EnemysManager& enemys_manager, Player& player, IScreenManager& screen_manager);
	~CollisionManager();
	
	void	update(WINDOW *window);
};
