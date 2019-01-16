objects = main.o countLetters.o outputLetters.o appendTxt.o

LetterCounter: $(objects)
	g++ -std=c++11 -g -o LetterCounter $(objects)

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

countLetters.o: countLetters.cpp countLetters.hpp
	g++ -std=c++11 -c countLetters.cpp

outputLetters.o: outputLetters.cpp outputLetters.hpp
	g++ -std=c++11 -c outputLetters.cpp

appendTxt.o: appendTxt.cpp appendTxt.hpp
	g++ -std=c++11 -c appendTxt.cpp

.PHONY : zip
zip:
	zip -r Lab2_Wilson_Andrew.zip .

.PHONY : clean
clean:
	rm LetterCounter $(objects)