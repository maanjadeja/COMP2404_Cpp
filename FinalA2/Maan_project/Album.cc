#include "Album.h"

Album::Album(const string &artist, const string &title)
{
    this->artist = artist;
    this->title = title;
    songArray = new SongArray();
}

Album::Album(Album &album)
{
    this->artist = album.artist;
    this->title = album.title;
    songArray = new SongArray();
    // deep copy
    for (int i = 0; i < album.songArray->size(); i++)
    {
        Song *song;
        album.getSong(i, &song);

        songArray->add(new Song(*song));
    }
}

Album::~Album()
{
    delete songArray;
}

string Album::getArtist() const
{
    return artist;
}

string Album::getTitle() const
{
    return title;
}

bool Album::matches(const string &artist, const string &title) const
{
    return (this->artist == artist && this->title == title);
}

bool Album::lessThan(Album &album)
{
    if (this->artist < album.artist)
        return true;
    else if (this->artist == album.artist)
    {
        if (this->title < album.title)
            return true;
        else
            return false;
    }
    else
        return false;
}

bool Album::addSong(Song *song)
{
    if (artist == song->getArtist())
    {
        return songArray->add(song);
    }
    return false;
}

bool Album::addSong(int index, Song *song)
{
    if (song->getArtist() == artist)
    {
        return songArray->add(index, song);
    }
    else
        return false;
}

bool Album::getSong(const string &title, Song **song)
{
    return songArray->get(artist, title, song);
}

bool Album::getSong(int index, Song **song)
{
    return songArray->get(index, song);
}

bool Album::removeSong(const string &title, Song **song)
{
    return songArray->remove(artist, title, song);
}

bool Album::removeSong(int index, Song **song)
{
    return songArray->remove(index, song);
}

void Album::print() const
{
    cout << "Album Title: " << title << endl;
    cout << "Album Artist: " << artist << endl;
    songArray->print();
}

void Album::printShort() const
{
    cout << "Album Title: " << title << endl;
    cout << "Album Artist: " << artist << endl;
}
