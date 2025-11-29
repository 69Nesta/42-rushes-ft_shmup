CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++11 -I includes
DEPFLAGS = -MD

SRCDIR = src
OBJDIR = .obj

SOURCES = main.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJDIR)/%.o)
DEPFILES = $(OBJECTS:.o=.d)

TARGET = ft_shmup

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(DEPFLAGS) -c $< -o $@

-include $(OBJECTS:.o=.d)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(TARGET)

.PHONY: all clean fclean