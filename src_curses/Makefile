TARGET = ft_shmup

CXX = c++
CXXFLAGS = -Wall -Wextra -std=gnu++2b -I includes 
DEPFLAGS = -MMD -MP

SRCDIR = .
OBJDIR = .obj

SOURCES = main.cpp frame.cpp

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

.PHONY: all clean fclean re
