#include "Clock.hpp"
#include <iostream>


Clock::Clock()
{
	clock_t begin = clock();
    
    int i;
    for( i=0; i<1000000000; i++ ) {
    
    }
    clock_t end = clock();
    unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;
    std::cout << "Finished in" << millis << "ms" << std::endl;        
}

Clock::~Clock()
{

}