/*
  Account.cpp
 
  Definition file for Account class
*/
 
#include "Account.hpp"
#include "Video.hpp"
 
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
 
// constructor
Account::Account(const std::string& name)
    : account_name(name)
{ }
 
// account name
std::string Account::name() const {
 
    return account_name;
}
 
// add a stream to this account
void Account::addStream(const Stream& stream) {
 
    streams.push_back(stream);
}
 
// account streaming report
std::string Account::report() const {
 
    // returned string
    std::ostringstream output;
 
    // customer name
    output << "Stream Report for Account: " << name() << '\n';
 
    // list streams
    output << "Streams:" << '\n';
    int totalStreams = 0;
    int totalOriginals = 0;
    int totalHours = 0;
    int totalMinutes = 0;
   
    for (std::vector<Stream>::const_iterator it = streams.begin(); it != streams.end(); ++it) {
        
        // stream counts and originals
            int streamCount = 0;
            int originals = 0;

        if (it->getIsMovie()){
            // stream title
            output << '\t' << it->movie().title();
 
            // current total hours and minutes
            totalHours += it->movie().hours() * it->viewings();
            totalMinutes += it->movie().Minutes() * it->viewings();

            int viewings = it->viewings();

            it->movie().getNumberOfStreams(streamCount, viewings);
            it->movie().getNumberOfOriginals(streamCount, originals, viewings);
        }

        if (it->getIsTV()){
            // stream title
            output << '\t' << it->tvshow().title();
 
            // current total hours and minutes
            totalHours += it->tvshow().hours() * it->viewings();
            totalMinutes += it->tvshow().Minutes() * it->viewings();

            int viewings = it->viewings();

            it->tvshow().getNumberOfStreams(streamCount, viewings);
            it->tvshow().getNumberOfOriginals(streamCount, originals, viewings);
        }

        if (it->getIsOriginal()){
            // stream title
            output << '\t' << it->original().title();
 
            // current total hours and minutes
            totalHours += it->original().hours() * it->viewings();
            totalMinutes += it->original().Minutes() * it->viewings();

            int viewings = it->viewings();

            it->original().getNumberOfStreams(streamCount, viewings);
            it->original().getNumberOfOriginals(streamCount, originals, viewings);
        }
 
        // stream counts for this video
        std::ostringstream out_str_stream;
        output << '\t' << streamCount << '\n';
 
        totalStreams += streamCount;
        totalOriginals += originals;
    }
 
    output << '\n';
 
    // total stream counts
    output << "Total Stream Events: " << totalStreams << '\n';
 
    // total non-original stream counts
    output << "Non-Original Stream Events: " << (totalStreams - totalOriginals) << '\n';
 
    // total time
    int totalTime = totalHours + totalMinutes / 60;
    output << "Total Time: " << totalTime;
    int remainingTime = totalMinutes % 60;
    output << remainingTime << '\n';
 
    return output.str();
}
 
// account data in CSV
std::string Account::data() const {
 
    // returned string
    std::ostringstream output;
 
    // customer name
    std::string name = this->name();
 
    // list of streams
    for (std::vector<Stream>::const_iterator it = streams.begin(); it != streams.end(); ++it) {
 
        // customer name
        output << name << ',';

        if(it->getIsTV()){
            it->tvshow().getStreamType(output);  
            // stream title
            output << ',' << it->tvshow().title();
 
            // stream hours and minutes
            output << ',' << (it->tvshow().hours() * it->viewings());
            output << ',' << (it->tvshow().Minutes() * it->viewings());
        }

        if(it->getIsMovie()){
            it->movie().getStreamType(output);  
            // stream title
            output << ',' << it->movie().title();
 
            // stream hours and minutes
            output << ',' << (it->movie().hours() * it->viewings());
            output << ',' << (it->movie().Minutes() * it->viewings());
        }

        if(it->getIsOriginal()){
            it->original().getStreamType(output);  
            // stream title
            output << ',' << it->original().title();
 
            // stream hours and minutes
            output << ',' << (it->original().hours() * it->viewings());
            output << ',' << (it->original().Minutes() * it->viewings());
        }
 
        // stream counts
        output << ',';

        if (it->getIsMovie()) 
        {
            if (it->movie().hours()) {
                output << (it->viewings() * it->movie().hours());
            } else {
                output << it->viewings();
            }
        }
        else
            output << it->viewings();
        
        output << '\n';
    }
    return output.str();
}
