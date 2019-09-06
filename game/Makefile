CXX=g++
CXXFLAGS=-Wall -MMD
EXEC=pp9k
OBJECTS=main.o game.o player.o human.o computer.o piece.o king.o queen.o rook.o knight.o bishop.o pawn.o empty.o controller.o textdisplay.o
DEPENDS=${OBJECTS:.o=.d}

${EXEC} : ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
