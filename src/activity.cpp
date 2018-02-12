//Activity class methods
#include <memory>
#include "activity.hpp"

Activity::Activity(std::string title, std::string description, std::string duration)
    : title(title), description(description), duration(duration)
{}

//Getters
std::string Activity::get_title(){
    return title;
}

std::string Activity::get_description(){
    return description;
}

std::string Activity::get_duration(){
    return duration;
}
