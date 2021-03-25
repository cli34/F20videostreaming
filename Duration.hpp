// Duration.hpp
#ifndef DURATION_H
#define DURATION_H

// Used to determin the length in hour and minutes of a video.
class Duration {

    public:
        Duration()
        {
            hours = 0;
            minutes = 0;
        }
        Duration(int Nhours, int Nminutes) 
        {
            hours = Nhours;
            minutes = Nminutes; 
        };
        int Hours() const { return hours; };
        int Minutes() const { return minutes; };
    
    private:
        int hours;
        int minutes;

};

#endif
