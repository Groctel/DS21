# ==============================================================================
# INTERNAL USE VARIABLES
# ==============================================================================

# Directories
# ------------------------------------------------------------------------------

makedir = .
bin     = $(makedir)/bin
src     = $(makedir)/src
tst     = $(makedir)/tests

CXXFLAGS = -std=c++20 -g -Wall -Wextra -Wpedantic -Wfloat-equal -I$(src)

gtest      = /usr/include/gtest/
gtestlibs  = /usr/lib/libgtest.so
gtestflags = -I$(gtest) $(gtestlibs) -I$(tst)

.PHONY: \
	all \
	clean \
	cleanbuild \
	directories \
	full \
	run \
	test

all: directories $(bin)/practicas

clean:
	-@rm $(bin)/*
	-@find . -name "*.o" -exec rm {} +

cleanbuild: clean all

directories:
	@mkdir -p $(bin)

full: all test run

run: all
	@$(bin)/practicas

test: $(bin)/tests
	@$(bin)/tests --gtest_color=yes

$(bin)/practica: $(src)/practica.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^ $(libs)

$(bin)/tests: $(makedir)/tests.cpp \
		$(tst)/jugador_test.hpp $(src)/jugador.o \
		$(tst)/filtro_test.hpp \
			$(src)/filtro_mayus.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(gtestflags)

$(src)/filtro_mayus.o: $(src)/filtro_mayus.cpp $(src)/filtro_mayus.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(src)/jugador.o: $(src)/jugador.cpp $(src)/jugador.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
