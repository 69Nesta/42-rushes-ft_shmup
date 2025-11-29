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
		void		decrement_entity_lines();
		void		increment_entity_lines();
		
	private:

		unsigned int cols;		//COLS
		unsigned int lines;		//LINES

};

class Projectile : public Entity {

	private:
		char		 ship;
		unsigned int cols;
		unsigned int lines;
		int			 direction;
	
	public :

		
		Projectile(unsigned int cols, unsigned int lines, int direction) {
			this->cols = cols;
			this->lines = lines;
			this->direction = direction;
			this->ship = '-';
		}
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
};


#endif
