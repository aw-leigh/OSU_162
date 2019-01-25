PROJ = ZooTycoon
objects = main.o zoo.o animal.o tiger.o penguin.o turtle.o validation.o
BIN = $(PROJ)

$(BIN): $(objects)
	@g++ -g -o $(BIN) $(objects)

main.o: main.cpp
	@g++ -c main.cpp

zoo.o: zoo.cpp zoo.hpp
	@g++ -c zoo.cpp

animal.o: animal.cpp animal.hpp
	@g++ -c animal.cpp

tiger.o: tiger.cpp
	@g++ -c tiger.cpp

penguin.o: penguin.cpp penguin.hpp
	@g++ -c penguin.cpp

turtle.o: turtle.cpp turtle.hpp
	@g++ -c turtle.cpp

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
	@rm $(PROJ) $(objects)