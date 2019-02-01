PROJ = Lab4_Wilson_Andrew
BIN = OSUInfoSystem
CXX = g++
CXXFLAGS = -std=c++11 -g
OBJS = main.o university.o building.o person.o student.o instructor.o validation.o
SRCS = main.cpp university.cpp building.cpp person.cpp student.cpp instructor.cpp validation.cpp
DEPS = university.hpp building.hpp person.hpp student.hpp instructor.hpp validation.hpp

$(BIN): $(OBJS)
	@${CXX} ${CXXFLAGS} -o $(BIN) $(OBJS)

${OBJS}: ${SRCS} $(DEPS)
	@${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

.PHONY : valgrind
valgrind:
	@valgrind --leak-check=full --track-origins=yes ./$(BIN)

.PHONY : zip
zip:
	zip $(PROJ).zip *.cpp *.hpp *.pdf makefile

.PHONY : clean
clean:
	@rm $(BIN) $(OBJS)