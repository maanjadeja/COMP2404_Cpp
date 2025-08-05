#include "Client.h"

Client::Client()
{
    albumArray = new AlbumArray();
}

Client::~Client()
{
    delete albumArray;
}

bool Client::download(Songify *songify, const string &artist, const string &title)
{
    if (albumArray->isFull())
        return false;
    else
    {
        Album *album;
        bool res = songify->downloadAlbum(artist, title, &album);

        if (res)
        {
            album = new Album(*album);
            albumArray->add(album);
            return true;
        }
        else
            return false;
    }
}

bool Client::stream(Songify *songify, const string &artist, const string &albumTitle, const string &songTitle)
{
    Song *song;
    bool res = songify->streamSong(artist, albumTitle, songTitle, &song);

    if (res)
    {
        song->play();
        return true;
    }
    else
    {
        return false;
    }
}

bool Client::playLocal(const string &artist, const string &albumTitle, const string &songTitle) const
{
    Album *album;
    bool res = albumArray->get(artist, albumTitle, &album);
    if (res)
    {

        Song *song;
        res = album->getSong(songTitle, &song);
        if (res)
        {
            song->play();
            return true;
        }
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

void Client::printAlbums() const
{
    for (int i = 0; i < albumArray->size(); i++)
    {
        Album *album;
        bool res = albumArray->get(i, &album);
        if (res)
        {
            album->printShort();
        }
    }
}

void Client::printSongs() const
{
    for (int i = 0; i < albumArray->size(); i++)
    {
        Album *album;
        bool res = albumArray->get(i, &album);
        if (res)
        {
            album->print();
        }
    }
}
