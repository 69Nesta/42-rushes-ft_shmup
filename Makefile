TARGET = ft_shmup

CXX = c++
CXXFLAGS = -Wall -Wextra -std=gnu++2b -I includes
DEPFLAGS = -MMD -MP

SRCDIR = src
OBJDIR = .obj

SOURCES = main.cpp \
		classes/Engine.cpp \
		classes/Window.cpp \
		classes/LobbyScreen.cpp \
		classes/GameScreen.cpp 

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