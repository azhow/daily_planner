#ifndef ACTIVITY_HPP
#define ACTIVITY_HPP

#include <string>

//Class activity
class Activity {
    private:
        std::string title, description;
        int duration;
    public:
        //Constructor
        Activity(std::string title, std::string description, int duration);
        //Methods
        std::string get_title();
        std::string get_description();
        int get_duration();
};

#endif
