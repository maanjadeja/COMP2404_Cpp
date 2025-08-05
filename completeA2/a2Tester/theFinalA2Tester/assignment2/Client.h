#ifndef CLIENT_H
#define CLIENT_H
#include "AlbumArray.h"
#include "Songify.h"
#include <string>
#include <iostream>

using namespace std;

class Client
{
public:
    Client();
    ~Client();

    bool download(Songify *songify, const string &artist, const string &title);
    bool stream(Songify *songify, const string &artist, const string &albumTitle, const string &songTitle);
    bool playLocal(const string &artist, const string &albumTitle, const string &songTitle) const;
    void printAlbums() const;
    void printSongs() const;

private:
    AlbumArray *albumArray;
};

#endif