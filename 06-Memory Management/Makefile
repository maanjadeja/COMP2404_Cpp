all:	p1 p2 p3 p3v2

p1:	p1-ptr.cc
	g++ -o p1 p1-ptr.cc

p2:	p2-pass.cc
	g++ -o p2 p2-pass.cc

p3:	p3-dynAlloc.cc
	g++ -o p3 p3-dynAlloc.cc

p3v2:	p3-memLeak.cc
	g++ -o p3v2 p3-memLeak.cc

clean:
	rm -f p1 p2 p3
