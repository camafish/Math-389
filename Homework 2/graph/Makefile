
graph: myMath.o charLines.o graph.o
	gcc -o graph -lm myMath.o charLines.o graph.o

%.o: %.c
	gcc -c -o $@ $<

graph.o: myMath.h charLines.h

myMath.o: myMath.h

charLines.o: charLines.h
