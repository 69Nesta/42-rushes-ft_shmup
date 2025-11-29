#ifndef ENTITY_HPP
# define ENTITY_HPP

#include <vector>
using namespace   std;

class Entity
{
	public:

	    vector<Entity>  init_vec_entity(Entity entity);	
        Entity          init_projectile();
        void            clear_vec(vector<Entity> v);
		Entity 			init_enemy();
		Entity 			init_player();
		unsigned int	get_lines();
		unsigned int	get_cols();
		void			decrement_entity_lines();
		void			increment_entity_lines();
        void            increment_entity_cols();
        void            decrement_entity_cols();
        bool            check_collision(Entity a, Entity b);
		char			get_ship();
		
	private:

		unsigned int cols;		//COLS
		unsigned int lines;		//LINES
		char	     ship;

};

class Projectile : public Entity {

	private:
		char		 ship;
		unsigned int cols;
		unsigned int lines;
		int			 direction;
	
	public :
        Projectile(unsigned int cols, unsigned int lines, int direction)
        {
            this->cols = cols;
            this->lines = lines;
            this->direction = direction;
            this->ship = '-';
        };
//        ~Projectile();

};

class Player: public Entity {
	private:
		char	ship;
		unsigned int	cols;
		unsigned int	lines;

	public:

            Player(unsigned int cols, unsigned int lines)
            {
                this->cols = cols;
                this->lines = lines;
                this->ship = '>';
            };
//            ~Player();
		    Projectile	shoot(Player);
//        void player_get_hit(bool hit, gamestate::health health);
};

class Ennemy: public Entity {
		
		private:
			char	ship;
			unsigned int	cols;
			unsigned int	lines;

		public:
			Projectile shoot(Ennemy);
            Ennemy(unsigned int cols, unsigned int lines)
            {
                this->cols = cols;
                this->lines = lines;
                this->ship = '<';
            };
//                ~Ennemy();
//            void ennemy_get_hit(bool hit, gamestate::score score);
};

#endif
