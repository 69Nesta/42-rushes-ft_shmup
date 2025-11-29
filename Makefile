TARGET = ft_shmup

CXX = c++
#CXXFLAGS = -Wall -Wextra -std=gnu++2b -I includes -g3
CXXFLAGS = -std=gnu++2b -I includes -g3
DEPFLAGS = -MMD -MP

SRCDIR = src
OBJDIR = .obj

SOURCES = main.cpp \
		engine/Engine.cpp \
		engine/GameClock.cpp \
		engine/InputHandler.cpp \
		managers/GameStateManager.cpp \
		screens/Screen.cpp \
		screens/ScreenManager.cpp \
		screens/ScreenLobby.cpp \
		screens/ScreenGame.cpp

OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))
DEPS = $(OBJECTS:.o=.d)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -lncurses -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

test: all
	@echo
	@echo
	@valgrind ./$(TARGET)

.PHONY: all clean fclean re