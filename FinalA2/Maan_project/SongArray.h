#ifndef SONGARRAY_H
#define SONGARRAY_H
#include "Song.h"
#include <string>
#include <iostream>

using namespace std;

class SongArray
{
public:
    SongArray();
    ~SongArray();

    bool add(Song *song);
    bool add(int index, Song *song);

    bool get(const string &artist, const string &title, Song **song);
    bool get(int index, Song **song);

    bool remove(const string &artist, const string &title, Song **song);
    bool remove(int index, Song **song);

    int size();

    bool isFull();

    void print();

private:
    Song **songArray;
    int totalSongs;
};

#endif