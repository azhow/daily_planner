//Activity class methods
#include "activity.hpp"

Activity::Activity(std::string title, std::string description, std::string duration)
    : title(title), description(description), duration(duration)
{}

std::string Activity::get_title(){
    return title;
}

std::string Activity::get_description(){
    return description;
}

std::string Activity::get_duration(){
    return duration;
}
