/*
  Stream.cpp

  Definition file for Stream class
*/

#include "Stream.hpp"

// constructor

Stream::Stream()
{

}

Stream::Stream(const Video& video, int viewings)
{
    streamingVideo = video; 
    numViewed= viewings;
    isMovie = false;
    isTV = false;
    isOriginal = false;
}

Stream::Stream(const MOVIE& movie, int viewings)
{
    streamingMovie = movie; 
    numViewed= viewings;
    isMovie = true;
    isTV = false;
    isOriginal = false;
}

Stream::Stream(const TVSHOW& tvshow, int viewings)
{
    streamingTvshow = tvshow; 
    numViewed= viewings;
    isMovie = false;
    isTV = true;
    isOriginal = false;
}

Stream::Stream(const ORIGINAL& original, int viewings)
{
    streamingOriginal = original; 
    numViewed= viewings;
    isMovie = false;
    isTV = false;
    isOriginal = true;
}

bool Stream::getIsMovie() const{
    return isMovie;
}

bool Stream::getIsTV() const{
    return isTV;
}

bool Stream::getIsOriginal() const{
    return isOriginal;
}

// number of times watched
int Stream::viewings() const 
{
    return numViewed;
}

// video rented
Video Stream::video() const 
{
    return streamingVideo;
}

MOVIE Stream::movie() const 
{
    return streamingMovie;
}

TVSHOW Stream::tvshow() const 
{
    return streamingTvshow;
}

ORIGINAL Stream::original() const 
{
    return streamingOriginal;
}
