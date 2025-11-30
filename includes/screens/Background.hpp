#pragma once
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <ncurses.h>

class Background
{
public:
    Background(int width = 0, int height = 0, float speed = 1.0f);
    ~Background() = default;

    void resize(int width, int height);
    void update(float delta_time);
    void render(WINDOW* window);

private:
    void generate();

    int width;
    int height;
    float speed;      // cells per second
    float scroll_offset;     // fractional scroll accumulator
    std::vector<std::string> buffer;
};