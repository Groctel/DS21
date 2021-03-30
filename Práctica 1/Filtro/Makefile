# ==============================================================================
# INTERNAL USE VARIABLES
# ==============================================================================

# Directories
# ------------------------------------------------------------------------------

makedir = .
bin     = $(makedir)/bin
flt     = $(makedir)/filtros
src     = $(makedir)/src
tst     = $(makedir)/tests

includes = -I$(src) -I$(flt)
CXXFLAGS = -std=c++20 -g -Wall -Wextra -Wpedantic -Wfloat-equal $(includes)

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
	$(CXX) $(CXXFLAGS) -o $@ $^

$(bin)/tests: $(makedir)/tests.cpp \
		$(tst)/gestor_filtros_test.hpp $(src)/gestor_filtros.o \
		$(tst)/filtro_test.hpp \
			$(flt)/filtro_colores.o \
			$(flt)/filtro_mayus.o \
		$(tst)/jugador_test.hpp $(src)/jugador.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(gtestflags)

$(flt)/filtro_colores.o: $(flt)/filtro_colores.cpp $(flt)/filtro_colores.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(flt)/filtro_mayus.o: $(flt)/filtro_mayus.cpp $(flt)/filtro_mayus.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(src)/gestor_filtros.o: $(src)/gestor_filtros.cpp $(src)/gestor_filtros.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(src)/jugador.o: $(src)/jugador.cpp $(src)/jugador.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
