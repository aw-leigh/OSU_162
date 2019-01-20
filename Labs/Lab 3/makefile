objects = main.o die.o game.o validation.o

War: $(objects)
	g++ -g -o War $(objects)

main.o: main.cpp
	g++ -c main.cpp

die.o: die.cpp die.hpp
	g++ -c die.cpp

game.o: game.cpp game.hpp
	g++ -c game.cpp

validation.o: validation.cpp validation.hpp
	g++ -c validation.cpp

.PHONY : clean
clean:
	rm War $(objects)