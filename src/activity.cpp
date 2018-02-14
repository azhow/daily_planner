//Activity class methods
#include "activity.hpp"

Activity::Activity(std::string title, std::string description, std::string duration, std::vector<std::string> tags)
    : title(title), description(description), duration(duration), tags(tags)
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

std::vector<std::string> Activity::get_tags() const{
    return tags;
}

//Comparator overload
bool Activity::operator==(const std::shared_ptr<Activity> &a) const{
    return this->title == a->get_title() && this->duration == a->get_duration();
}
