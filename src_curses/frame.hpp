#ifndef	FRAME_HPP
#define FRAME_HPP

#include "entity.hpp"
#include <vector>

class Frame
{
	public:

		//WINDOW**	init_frame();
		void	init_frame();
        void        clear_entity_frame(vector<Entity> entity);
		void	    render_entity_frame(vector<Entity> entity);
		//void	    end_game(WINDOW** layer);
		void	    end_game();

	private:

		void	render_entity();	
		

};

#endif

