all:	p1 p1v2 p2 p3 p4 p5 p5v2 p6

p1:	p1-ops.cc
	g++ -o p1 p1-ops.cc

p1v2:	p1v2-ops-dyn.cc
	g++ -o p1v2 p1v2-ops-dyn.cc

p2:	p2-expr.cc
	g++ -o p2 p2-expr.cc

p3:	p3-blk.cc
	g++ -o p3 p3-blk.cc

p4:	p4-stdio.cc
	g++ -o p4 p4-stdio.cc

p5:	p5-parr.cc
	g++ -o p5 p5-parr.cc

p5v2:	p5-parp.cc
	g++ -o p5v2 p5-parp.cc

p6:	p6-ref.cc
	g++ -o p6 p6-ref.cc

clean:
	rm -f p1 p2 p2v2 p3 p4 p5 p5v2 p6 *.exe

