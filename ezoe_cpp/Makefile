gcc_options = -std=c++17 -Wall --pedantic-errors

all: program bmi convert

program : main.cpp all.h all.h.gch
	g++ $(gcc_options) -include all.h $< -o $@

bmi : bmi.cpp all.h all.h.gch
	g++ $(gcc_options) -include all.h $< -o $@

convert : convert.cpp all.h all.h.gch
	g++ $(gcc_options) -include all.h $< -o $@

all.h.gch : all.h
	g++ $(gcc_options) -x c++-header -o $@ $<

run : all
	cat bodymass.txt | ./convert | ./bmi

clean :
	rm -f ./program
	rm -f ./bmi
	rm -f ./convert
	rm -f ./all.h.gch

.PHONY : all run clean
