#ifndef SONGIFY_H
#define SONGIFY_H
#include "AlbumArray.h"
#include <string>
#include <iostream>

using namespace std;

class Songify
{
public:
    Songify();
    ~Songify();

    bool addAlbum(const string &artist, const string &title);
    bool addSong(const string &title, Song *song);

    bool removeAlbum(const string &artist, const string &title);
    bool removeSong(const string &artist, const string &albumTitle, const string& songTitle);

    bool downloadAlbum(const string &artist, const string &title, Album **album);
    bool streamSong(const string &artist, const string &albumTitle, const string &songTitle, Song **song);

    void printAlbums() const;
    void printSongs() const;
private:
    AlbumArray *albumArray;
};

#endif