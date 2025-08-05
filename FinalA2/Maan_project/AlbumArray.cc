#include "AlbumArray.h"
#include "defs.h"

AlbumArray::AlbumArray()
{
    albumArray = new Album *[MAX_ARRAY];
    totalAlbums = 0;
}

AlbumArray::~AlbumArray()
{
    // for (int i = 0; i < totalAlbums; i++)
    // {
    //     delete albumArray[i];
    // }

    delete[] albumArray;
    totalAlbums = 0;
}

bool AlbumArray::add(Album *album)
{
    if (totalAlbums < MAX_ARRAY)
    {
        int i;
        for (i = totalAlbums - 1; i >= 0; i--)
        {
            Album *a = albumArray[i];
            if (album->lessThan(*a))
            {
                albumArray[i + 1] = albumArray[i];
            }
            else
            {
                break;
            }
        }
        albumArray[i + 1] = album;
        totalAlbums++;
        return true;
    }
    else
    {
        return false;
    }
}

bool AlbumArray::get(const string &artist, const string &title, Album **album)
{
    for (int i = 0; i < totalAlbums; i++)
    {
        if (albumArray[i]->matches(artist, title))
        {
            *album = albumArray[i];
            return true;
        }
    }
    return false;
}

bool AlbumArray::get(int index, Album **album)
{
    if (index >= 0 && index < totalAlbums)
    {
        *album = albumArray[index];
        return true;
    }
    else
        return false;
}

bool AlbumArray::remove(const string &artist, const string &title, Album **album)
{
    int removedIndex = -1;
    for (int i = 0; i < totalAlbums; i++)
    {
        if (albumArray[i]->matches(artist, title))
        {
            removedIndex = i;
            break;
        }
    }

    if (removedIndex == -1)
        return false;
    else
    {
        for (int i = removedIndex; i < totalAlbums - 1; i++)
        {
            albumArray[i] = albumArray[i + 1];
        }
        totalAlbums--;
        return true;
    }
}

bool AlbumArray::remove(int index, Album **album)
{
    if (index >= 0 && index < totalAlbums)
    {
        for (int i = index; i < totalAlbums - 1; i++)
        {
            albumArray[i] = albumArray[i + 1];
        }
        totalAlbums--;
        return true;
    }
    else
        return false;
}

int AlbumArray::size() { return totalAlbums; }

bool AlbumArray::isFull() { return totalAlbums == MAX_ARRAY; }

void AlbumArray::printShort()
{
    for (int i = 0; i < totalAlbums; i++)
    {
        albumArray[i]->printShort();
    }
}
