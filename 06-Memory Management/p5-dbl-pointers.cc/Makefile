p5:	main.o Date.o Calendar.o
	g++ -o p5 main.o Date.o Calendar.o

main.o:	main.cc Date.h Calendar.h
	g++ -c main.cc

Calendar.o:	Calendar.cc Calendar.h
	g++ -c Calendar.cc

Date.o:	Date.cc Date.h
	g++ -c Date.cc

clean:
	rm -f *.o p5
