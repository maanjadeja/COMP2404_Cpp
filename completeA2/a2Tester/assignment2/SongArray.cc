#include "SongArray.h"
#include "defs.h"

SongArray::SongArray()
{
    songArray = new Song *[MAX_ARRAY];
    totalSongs = 0;
}

SongArray::~SongArray()
{
    for (int i = 0; i < totalSongs; i++)
    {
        delete songArray[i];
    }

    delete[] songArray;
    totalSongs = 0;
}

bool SongArray::add(Song *song)
{
    if (totalSongs < MAX_ARRAY)
    {
        songArray[totalSongs] = song;
        totalSongs++;
        return true;
    }
    else
    {
        return false;
    }
}

bool SongArray::add(int index, Song *song)
{
    if (index >= 0 && index <= totalSongs && totalSongs < MAX_ARRAY)
    {
        for (int i = totalSongs; i > index; i--)
        {
            songArray[i] = songArray[i - 1];
        }
        songArray[index] = song;
        totalSongs++;
        return true;
    }
    else
    {
        return false;
    }
}

bool SongArray::get(const string &artist, const string &title, Song **song)
{
    for (int i = 0; i < totalSongs; i++)
    {
        Song *s = songArray[i];
        if (s->matches(artist, title))
        {
            *song = s;
            return true;
        }
    }
    return false;
}

bool SongArray::get(int index, Song **song)
{
    if (index >= 0 && index < totalSongs)
    {
        *song = songArray[index];
        return true;
    }
    else
    {
        return false;
    }
}

bool SongArray::remove(const string &artist, const string &title, Song **song)
{
    int removedIndex = -1;
    for (int i = 0; i < totalSongs; i++)
    {
        Song *s = songArray[i];
        if (s->matches(artist, title))
        {
            *song = s;
            removedIndex = i;
            break;
        }
    }

    // not found
    if (removedIndex == -1)
        return false;
    else
    {
        // shift
        for (int i = removedIndex + 1; i < totalSongs; i++)
        {
            songArray[i - 1] = songArray[i];
        }
        totalSongs--;
        return true;
    }
}

bool SongArray::remove(int index, Song **song)
{
    if (index >= 0 && index < totalSongs)
    {
        *song = songArray[index];

        for (int i = index + 1; i < totalSongs; i++)
        {
            songArray[i - 1] = songArray[i];
        }
        totalSongs--;
        return true;
    }
    else
    {
        return false;
    }
}

int SongArray::size() const
{
    return totalSongs;
}

bool SongArray::isFull() const
{
    return totalSongs == MAX_ARRAY;
}

void SongArray::print() const
{
    for (int i = 0; i < totalSongs; i++)
    {
        songArray[i]->print();
    }
}
