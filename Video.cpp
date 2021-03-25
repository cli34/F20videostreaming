/*
  Video.cpp
  Definition file for Video class
*/

#include "Video.hpp"



// video title
std::string Video::title() const 
{
    return videoTitle;
}

// video length in hours
int Video::hours() const
{
    //return lengthHours; // previous way
    return videoDuration.Hours(); // refractored way
}

// video length in minutes
int Video::Minutes() const 
{
    //return lengthMinutes; // previos way
    return videoDuration.Minutes(); // refractored way
}

int Video::episodes() const
{
    return numEpisodes;
}

int Video::type() const
{
    return videoType;
}

Video::Video()
{

}

Video::Video(const std::string& title, int type, int hours, int minutes, int episodes)
{
    videoTitle = title; 
    setLength(hours, minutes);
    videoType = type; 
    numEpisodes = episodes;
}

MOVIE::MOVIE()
{

}

MOVIE::MOVIE(const std::string& title, int type, int hours, int minutes, int episodes)
{
    videoTitle = title; 
    setLength(hours, minutes);
    videoType = type; 
    numEpisodes = 0;
}
void MOVIE::setLength(int hours, int minutes) 
{
    //this->lengthHours = hours;        // previous way
    //this->lengthMinutes = minutes;    // previous way
    Duration newVidDuration(hours, minutes);
    videoDuration = newVidDuration;     // refractored way
}
int MOVIE::type() const
{
    return 0; 
}
void MOVIE::getNumberOfStreams(int& streamCount, int& viewings)
{
    streamCount += viewings * (this->hours() ? this->hours() : 1);
}
void MOVIE::getStreamType(std::ostream &output) const
{
    output << "MOVIE";
}
int MOVIE::episodes() const
{
    return 0;
}
std::string MOVIE::title() const 
{
    return videoTitle;
}

TVSHOW::TVSHOW()
{

}

TVSHOW::TVSHOW(const std::string& title, int type, int hours, int minutes, int episodes)
{
    videoTitle = title; 
    setLength(hours, minutes);
    numEpisodes = episodes; 
    videoType = type; 
}
int TVSHOW::episodes() const
{
    return numEpisodes;
}
void TVSHOW::setLength(int hours, int minutes) 
{
    Duration newVidDuration(hours, minutes);
    videoDuration = newVidDuration;
}
int TVSHOW::type() const
{
    return 1; 
}
void TVSHOW::getNumberOfStreams(int& streamCount, int& viewings)
{
    streamCount += viewings;
}
void TVSHOW::getStreamType(std::ostream &output) const
{
    output << "TVSHOW";
}
std::string TVSHOW::title() const 
{
    return videoTitle;
}

ORIGINAL::ORIGINAL()
{
    
}

ORIGINAL::ORIGINAL(const std::string& title, int type, int hours, int minutes, int episodes)
{
    videoTitle = title; 
    setLength(hours, minutes);
    numEpisodes = episodes; 
    videoType = type; 
}
int ORIGINAL::episodes() const
{
    return numEpisodes;
}
void ORIGINAL::setLength(int hours, int minutes) 
{
    Duration newVidDuration(hours, minutes);
    videoDuration = newVidDuration;
}
int ORIGINAL::type() const
{
    return 2; 
}
void ORIGINAL::getNumberOfOriginals(int &streamCount, int &originals, int &viewings)
{
    // for TV shows, the stream count is just the number of streams
    originals += viewings;
    streamCount += viewings;
}
void ORIGINAL::getStreamType(std::ostream &output) const
{
    output << "ORIGINAL";
}

std::string ORIGINAL::title() const 
{
    return videoTitle;
}
