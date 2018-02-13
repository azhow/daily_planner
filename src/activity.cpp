//Activity class methods
#include <memory>
#include <iostream>
#include "activity.hpp"

Activity::Activity(std::string title, std::string description, std::string duration)
    : title(title), description(description), duration(duration)
{}

//Getters
std::string Activity::get_title() const{
    return title;
}

std::string Activity::get_description() const{
    return description;
}

std::string Activity::get_duration() const{
    return duration;
}

bool Activity::operator==(const std::shared_ptr<Activity> &a) const{
    std::cout << this->title << std::endl;
    std::cout << a->get_title() << std::endl;
    return this->title == a->get_title() && this->duration == a->get_duration();
}
