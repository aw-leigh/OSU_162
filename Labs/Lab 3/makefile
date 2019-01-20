PROJ = War
objects = main.o die.o game.o validation.o
BIN = $(PROJ)

$(BIN): $(objects)
	@g++ -g -o War $(objects)

main.o: main.cpp
	@g++ -c main.cpp

die.o: die.cpp die.hpp
	@g++ -c die.cpp

game.o: game.cpp game.hpp
	@g++ -c game.cpp

validation.o: validation.cpp validation.hpp
	@g++ -c validation.cpp

.PHONY : valgrind
valgrind:
	@valgrind --leak-check=full ./$(BIN)

.PHONY : zip
zip:
	zip $(PROJ).zip *.cpp *.hpp makefile

.PHONY : clean
clean:
	@rm War $(objects)