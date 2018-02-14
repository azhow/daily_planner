#ifndef ACTIVITY_HPP
#define ACTIVITY_HPP

#include <string>
#include <vector>
#include <memory>

//Class activity
class Activity {
    private:
        std::string title, description, duration;
        std::vector<std::string> tags;
    public:
        //Constructor
        Activity(std::string title, std::string description, std::string duration, std::vector<std::string> tags);
        //Methods
        std::string get_title() const;
        std::string get_description() const;
        std::string get_duration() const;
        std::vector<std::string> get_tags() const;
        bool operator==(const std::shared_ptr<Activity> &a) const;
};

#endif
