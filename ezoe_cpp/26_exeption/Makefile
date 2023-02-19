gcc_options = -std=c++17 -Wall --pedantic-errors

run : all
	./playground
	./program

all: program playground

playground : playground.cpp all.h all.h.gch
	g++ $(gcc_options) -include all.h $< -o $@

program : main.cpp all.h all.h.gch
	g++ $(gcc_options) -include all.h $< -o $@

all.h.gch : all.h
	g++ $(gcc_options) -x c++-header -o $@ $<

clean :
	rm -f ./program
	rm -f ./all.h.gch

.PHONY : all run clean
