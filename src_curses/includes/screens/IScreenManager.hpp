#pragma once
#include "ScreenType.hpp"

class IScreenManager {
public:
    virtual ~IScreenManager() = default;

    virtual void push_screen(ScreenType type) = 0;
    virtual void pop_screen() = 0;
    virtual void change_screen(ScreenType type) = 0;
};