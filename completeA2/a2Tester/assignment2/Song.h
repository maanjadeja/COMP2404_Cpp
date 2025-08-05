#ifndef SONG_H
#define SONG_H
#include <string>
#include <iostream>

using namespace std;

class Song
{
public:
    Song(const string &artist, const string &title, const string &content);
    Song(Song &song);

    string getArtist() const;
    string getTitle() const;

    bool matches(const string &artist, const string &title) const;

    void print() const;
    void play() const;

private:
    string artist, title, content;
};

#endif