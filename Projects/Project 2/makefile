PROJ = Project2_Wilson_Andrew
BIN = ZooTycoon
objects = main.o zoo.o animal.o tiger.o penguin.o turtle.o validation.o

$(BIN): $(objects)
	@g++ -g -std=c++11 -o $(BIN) $(objects)

main.o: main.cpp
	@g++ -std=c++11 -c main.cpp

zoo.o: zoo.cpp zoo.hpp
	@g++ -std=c++11 -c zoo.cpp

animal.o: animal.cpp animal.hpp
	@g++ -std=c++11 -c animal.cpp

tiger.o: tiger.cpp tiger.hpp
	@g++ -std=c++11 -c tiger.cpp

penguin.o: penguin.cpp penguin.hpp
	@g++ -std=c++11 -c penguin.cpp

turtle.o: turtle.cpp turtle.hpp
	@g++ -std=c++11 -c turtle.cpp

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