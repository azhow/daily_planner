#ifndef ACTIVITY_HPP
#define ACTIVITY_HPP

#include <string>
#include <memory>

//Class activity
class Activity {
    private:
        std::string title, description, duration;
    public:
        //Constructor
        Activity(std::string title, std::string description, std::string duration);
        //Methods
        std::string get_title() const;
        std::string get_description() const;
        std::string get_duration() const;
        bool operator==(const std::shared_ptr<Activity> &a) const;
};

#endif
