#include "screens/Background.hpp"
#include <cmath>

Background::Background(int width, int height, float speed):
    width(width),
    height(height),
    speed(speed),
    scroll_offset(0.0f)
{
    std::srand((unsigned)std::time(nullptr));
    if (has_colors())
    {
        start_color();
        init_pair(2, COLOR_WHITE, COLOR_BLACK);
        init_pair(3, COLOR_CYAN, COLOR_BLACK);
    }
    generate();
}

void Background::resize(int w, int h)
{
    if (w == width && h == height) return;
    width = w;
    height = h;
    generate();
}

void Background::generate()
{
    buffer.clear();
    if (width <= 0 || height <= 0) return;

    buffer.reserve(height);
    for (int y = 0; y < height; ++y)
    {
        std::string line(width, ' ');
        for (int x = 0; x < width; ++x)
        {
            int r = std::rand() % 1000;
            if (r < 8)
                line[x] = '.';
            else if (r < 10)
                line[x] = '`';
            else if (r < 12)
                line[x] = '*';
            else
                line[x] = ' ';
        }
        buffer.push_back(std::move(line));
    }
    scroll_offset = 0.0f;
}

void Background::update(float delta_time)
{
    if (width <= 0) return;
    scroll_offset += speed * delta_time;
    if (scroll_offset > (float)width) scroll_offset = std::fmod(scroll_offset, (float)width);
}

void Background::render(WINDOW* window)
{
    if (!window || width <= 0 || height <= 0) return;

    int off = static_cast<int>(scroll_offset) % width;
    bool use_color = has_colors();

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            char ch = buffer[y][(x + off) % width];

            if (ch == ' ')
            {
                mvwaddch(window, y, x, ' ');
                continue;
            }

            attr_t attrs = A_NORMAL;
            short pair = 0;
            if (ch == '*') {
                attrs = A_BOLD;
                pair = 2;
            } else if (ch == '.') {
                attrs = A_DIM;
                pair = 2;
            } else if (ch == '`') {
                attrs = A_NORMAL;
                pair = 3;
            } else {
                attrs = A_NORMAL;
                pair = 4;
            }

            if (use_color && pair != 0)
                wattron(window, COLOR_PAIR(pair));
            if (attrs != A_NORMAL)
                wattron(window, attrs);

            mvwaddch(window, y, x, ch);

            if (attrs != A_NORMAL)
                wattroff(window, attrs);
            if (use_color && pair != 0)
                wattroff(window, COLOR_PAIR(pair));
        }
    }
}
