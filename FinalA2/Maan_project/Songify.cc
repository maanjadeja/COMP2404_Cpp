#include "Songify.h"

Songify::Songify()
{
    albumArray = new AlbumArray();
}

Songify::~Songify()
{
    delete albumArray;
}

bool Songify::addAlbum(const string &artist, const string &title)
{
    if (albumArray->isFull())
        return false;
    else
    {
        Album *album = new Album(artist, title);
        albumArray->add(album);
        return true;
    }
}

bool Songify::removeAlbum(const string &artist, const string &title)
{
    Album *removedAlbum;
    bool res = albumArray->remove(artist, title, &removedAlbum);

    if (res)
        return true;
    else
    {
        cout << "ERROR: The removal of the album with the artist: " << artist << " and title: " << title << " was unsuccessful" << endl;
        return false;
    }
}

bool Songify::addSong(const string &title, Song *song)
{
    Album *album;
    bool res = albumArray->get(song->getArtist(), title, &album);

    if (res)
    {
        Song *s = new Song(*song);
        res = album->addSong(s);
        if (res)
            return true;
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

bool Songify::removeSong(const string &artist, const string &albumTitle, const string &songTitle)
{
    Album *album;
    bool res = albumArray->get(artist, albumTitle, &album);

    if (res)
    {
        Song *s;
        res = album->removeSong(songTitle, &s);
        return res;
    }
    else
    {
        return false;
    }
}

bool Songify::downloadAlbum(const string &artist, const string &title, Album **album)
{
    bool res = albumArray->get(artist, title, album);
    return res;
}

bool Songify::streamSong(const string &artist, const string &albumTitle, const string &songTitle, Song **song)
{
    Album *album;
    bool res = albumArray->get(artist, albumTitle, &album);
    if (res)
    {
        res = album->getSong(songTitle, song);
        return res;
    }
    else
        return false;
}

void Songify::printAlbums()
{
    albumArray->printShort();
}

void Songify::printSongs()
{
    for (int i = 0; i < albumArray->size(); i++)
    {
        // print album
        Album *album;
        albumArray->get(i, &album);
        album->print();
    }
}