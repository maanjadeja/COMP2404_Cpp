#observe - Linux is case sensitive. These names should match your filenames exactly

all: test
	
test: test.o SongArray.o Song.o Album.o 
	g++ -o test test.o SongArray.o Song.o Album.o 
	
test.o: test.cc Song.h Album.h
	g++ -c test.cc

SongArray.o:   SongArray.cc SongArray.h
	g++ -c SongArray.cc
	
Album.o:	Album.h Album.cc 
	g++ -c Album.cc 

Song.o:	Song.h Song.cc
	g++ -c Song.cc
	
clean:
	rm -f test *.o
