CC := g++
FLAGS := -Wall -std=c++11 -g -O

main: main.o pack7bit.o
	${CC} ${FLAGS} -o $@ $^

.PHONY: clean
clean:
	@del *.o
	@del *.exe
	@echo done