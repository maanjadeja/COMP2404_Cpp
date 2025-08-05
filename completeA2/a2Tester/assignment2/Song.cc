#include "Song.h"

Song::Song(const string &artist, const string &title, const string &content)
{
    this->artist = artist;
    this->title = title;
    this->content = content;
}

Song::Song(Song &song)
{
    this->artist = song.artist;
    this->title = song.title;
    this->content = song.content;
}

string Song::getArtist() const
{
    return this->artist;
}

string Song::getTitle() const
{
    return this->title;
}

bool Song::matches(const string &artist, const string &title) const
{
    return (this->artist == artist && this->title == title);
}

void Song::print() const
{
    cout << "Song Artist: " << this->artist << endl;
    cout << "Song Title: " << this->title << endl;
}

void Song::play() const
{
    print();
    cout << "Content " << this->content << endl;
}