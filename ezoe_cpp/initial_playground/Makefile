gcc_options = -std=c++17 -Wall --pedantic-errors

all: program

program : main.cpp all.h all.h.gch
	g++ $(gcc_options) -include all.h $< -o $@

all.h.gch : all.h
	g++ $(gcc_options) -x c++-header -o $@ $<

run : all
	./program

clean :
	rm -f ./program
	rm -f ./all.h.gch

.PHONY : all run clean
