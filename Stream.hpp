/*
  Stream.hpp

  Include file for Stream class
*/

#ifndef RENTAL_H
#define RENTAL_H

#include "Video.hpp"

class Stream {
public:

    // constructor
    Stream();
    Stream(const Video&, int);

    Stream(const MOVIE&, int);
    Stream(const TVSHOW&, int);
    Stream(const ORIGINAL&, int);
    bool getIsMovie() const;
    bool getIsTV() const;
    bool getIsOriginal() const;

    // number of times watched
    int viewings() const;

    // video rented
    Video video() const;
    MOVIE movie() const;
    TVSHOW tvshow() const;
    ORIGINAL original() const;

private:
    Video streamingVideo;
    MOVIE streamingMovie;
    TVSHOW streamingTvshow;
    ORIGINAL streamingOriginal;
    bool isMovie;
    bool isTV;
    bool isOriginal;
    int numViewed;
};

#endif
