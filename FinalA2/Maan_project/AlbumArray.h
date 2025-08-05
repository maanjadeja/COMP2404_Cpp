#ifndef ALBUMARRAY_H
#define ALBUMARRAY_H
#include "Album.h"
#include <string>
#include <iostream>

using namespace std;

class AlbumArray
{
public:
    AlbumArray();
    ~AlbumArray();

    bool add(Album *album);

    bool get(const string &artist, const string &title, Album **album);
    bool get(int index, Album **album);

    bool remove(const string &artist, const string &title, Album **album);
    bool remove(int index, Album **album);

    int size();
    bool isFull();
    void printShort();

private:
    Album **albumArray;
    int totalAlbums;
};

#endif