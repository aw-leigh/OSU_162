objects = main.o countLetters.o outputLetters.o appendTxt.o

LetterCounter: $(objects)
	g++ -g -o LetterCounter $(objects)

main.o: main.cpp
	g++ -c main.cpp

countLetters.o: countLetters.cpp countLetters.hpp
	g++ -c countLetters.cpp

outputLetters.o: outputLetters.cpp outputLetters.hpp
	g++ -c outputLetters.cpp

appendTxt.o: appendTxt.cpp appendTxt.hpp
	g++ -c appendTxt.cpp

.PHONY : clean
clean:
	rm LetterCounter $(objects)