PROJ = Lab3_Wilson_Andrew
objects = main.o die.o game.o validation.o
BIN = War

$(BIN): $(objects)
	@g++ -g -std=c++11 -o War $(objects)

main.o: main.cpp
	@g++ -std=c++11 -c main.cpp

die.o: die.cpp die.hpp
	@g++ -std=c++11 -c die.cpp

game.o: game.cpp game.hpp
	@g++ -std=c++11 -c game.cpp

validation.o: validation.cpp validation.hpp
	@g++ -std=c++11 -c validation.cpp

.PHONY : valgrind
valgrind:
	@valgrind --leak-check=full --track-origins=yes ./$(BIN)

.PHONY : zip
zip:
	zip $(PROJ).zip *.cpp *.hpp makefile

.PHONY : clean
clean:
	@rm $(BIN) $(objects)