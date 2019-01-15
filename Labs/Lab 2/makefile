objects = main.o countLetters.o outputLetters.o

main: $(objects)
	g++ -g -o main $(objects)

main.o: main.cpp
	g++ -c main.cpp

countLetters.o: countLetters.cpp countLetters.hpp
	g++ -c countLetters.cpp

outputLetters.o: outputLetters.cpp outputLetters.hpp
	g++ -c outputLetters.cpp

.PHONY : clean
clean:
	rm main $(objects)