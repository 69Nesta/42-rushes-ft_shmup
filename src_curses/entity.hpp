#ifndef ENTITY_HPP
# define ENTITY_HPP


class Entity
{
	public:
		Entity 			init_enemy();
		Entity 			init_player();
		Entity 			init_projectile();
		unsigned int	get_lines();
		unsigned int	get_cols();
		void			decrement_entity_lines();
		void			increment_entity_lines();
        void            increment_entity_cols();
        void            decrement_entity_cols();
        void            check_collision(Entity a, Entity b);
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

		Projectile(unsigned int cols, unsigned int lines, int direction);
        ~Projectile();

};

class Player: public Entity {
	private:
		char	ship;
		unsigned int	cols;
		unsigned int	lines;

	public:
		Projectile	shoot(Player);

		Player(unsigned int cols, unsigned int lines) {
			this->cols = cols;
			this->lines = lines;
			this->ship = '>';
		}
        void player_get_hit(bool hit, gamestate::health health);
};

class Ennemy: public Entity {
		
		private:
			char	ship;
			unsigned int	cols;
			unsigned int	lines;

		public:
			Projectile shoot(Ennemy);

			Ennemy(unsigned int cols, unsigned int lines) {
				this->cols = cols;
				this->lines = lines;
				this->ship = '<';
			}
            void ennemy_get_hit(bool hit, gamestate::score score);
};


#endif
