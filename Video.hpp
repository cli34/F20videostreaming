/*
  Video.hpp
  Include file for Video class
  
  Perfect fundamentals, 
*/

#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <vector>
#include <string>
#include "Duration.hpp"

class Video
  {
    public:

      Video();
      Video(const std::string& title, int type, int hours, int minutes, int episodes);
      // video title
      int type() const;
      int episodes() const;
      
      std::string title() const;
      // length of video in hours
      virtual int hours() const;
      // length of video in minutes
      virtual int Minutes() const;

      

      

      // set video length
      void setLength(int hours, int minutes)
        {
          std::cout << "virt setLength running" << std::endl;
        }
      virtual void getNumberOfStreams(int&, int&)
        {
          std::cout << "virt getNumStream running" << std::endl;
        }
      virtual void getNumberOfOriginals(int&, int&, int&)
        {
          std::cout << "virt getNumOrig running" << std::endl;
        }
      virtual void getStreamType(std::ostream&) const
        {
          std::cout << "virt getStreamType running" << std::endl;
        }

    protected:
      int videoType;
      int numEpisodes;
      std::string videoTitle;
      Duration videoDuration; // refractored way
  };

class MOVIE : public Video
  {
    public:
      MOVIE();
      MOVIE(const std::string& title, int type, int hours, int minutes, int episodes);
      int episodes() const;
      void setLength(int hours, int minutes);
      int type() const;
      std::string title() const;

      void getNumberOfStreams(int&, int&);
      void getStreamType(std::ostream&) const;
    private: 
      std::string videoTitle;
  };

class TVSHOW : public Video
  {
    public: 
      TVSHOW();
      TVSHOW(const std::string& title, int type, int hours, int minutes, int episodes);
      // number of episodes
      int episodes() const;
      void setLength(int hours, int minutes);
      int type() const;
      std::string title() const;

      void getNumberOfStreams(int&, int&);
      void getStreamType(std::ostream&) const;
    private:
      int numEpisodes;
      std::string videoTitle;
  };

class ORIGINAL : public Video
  {
    public:
      ORIGINAL();
      ORIGINAL(const std::string& title, int type, int hours, int minutes, int episodes);
      int episodes() const;
      void setLength(int hours, int minutes);
      int type() const;
      std::string title() const;

      void getNumberOfOriginals(int &, int &, int &);
      void getStreamType(std::ostream&) const;
    private: 
      int numEpisodes;
      std::string videoTitle;
  };

/*
class Video {
public:

    static const int MOVIE      = 0;
    static const int TVSHOW     = 1;
    static const int ORIGINAL   = 2;

    // constructor
    Video(const std::string& title, int type, int hours, int minutes, int episodes);

    // video title
    std::string title() const;

    // video type
    int type() const;

    // length of video in hours
    int hours() const;

    // length of video in minutes
    int Minutes() const;

    // number of episodes
    int episodes() const;

    // set video length
    void setLength(int hours, int minutes);

    void getNumberOfStreams(int& streamCount, int& viewings) const;

    void getNumberOfOriginals(int& streamCount, int& originals, int& viewings) const;

private:
    std::string videoTitle;
    int videoType;
    //int lengthHours;    // previous way
    //int lengthMinutes;  // previous way
    int numEpisodes;
    Duration videoDuration; // refractored way
};
*/
#endif
