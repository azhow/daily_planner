#ifndef ACTIVITY_HPP
#define ACTIVITY_HPP

#include <string>

//Class activity
class Activity {
    private:
        std::string title, description, duration;
    public:
        //Constructor
        Activity(std::string title, std::string description, std::string duration);
        //Methods
        std::string get_title();
        std::string get_description();
        std::string get_duration();
};

#endif
