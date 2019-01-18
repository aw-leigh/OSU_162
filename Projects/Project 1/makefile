objects = main.o menu.o ant.o validation.o

Ant: $(objects)
	g++ -g -o Ant $(objects)

main.o: main.cpp
	g++ -c main.cpp

menu.o: menu.cpp menu.hpp
	g++ -c menu.cpp

ant.o: ant.cpp ant.hpp
	g++ -c ant.cpp

validation.o: validation.cpp validation.hpp
	g++ -c validation.cpp

.PHONY : clean
clean:
	rm Ant $(objects)