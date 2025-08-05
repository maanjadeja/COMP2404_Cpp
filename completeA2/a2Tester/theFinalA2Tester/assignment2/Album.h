#ifndef ALBUM_H
#define ALBUM_H
#include "SongArray.h"
#include <string>
#include <iostream>

using namespace std;

class Album
{
public:
    Album(const string &artist, const string &title);
    Album(Album &album);

    ~Album();

    string getArtist() const;
    string getTitle() const;

    bool matches(const string &artist, const string &title) const;
    bool lessThan(Album &album) const;

    bool addSong(Song *song);
    bool addSong(int index, Song *song);

    bool getSong(const string &title, Song **song);
    bool getSong(int index, Song **song);

    bool removeSong(const string &title, Song **song);
    bool removeSong(int index, Song **song);

    void print() const;
    void printShort() const;

private:
    string artist, title;
    SongArray *songArray;
};

#endif