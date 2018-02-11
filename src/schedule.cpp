#include "schedule.hpp"
#include <iostream>

Schedule::Schedule()
    : activities(), duration(0), start(0), end(0)
{}

void Schedule::print_schedule(){
    int index = 0;
    for(auto& x : this->activities) {
        std::cout << index << ": " << x->get_title() << std::endl;
        index++;
    }
}

int Schedule::get_duration(){
    return duration;
}

int Schedule::get_start(){
    return start;
}

int Schedule::get_end(){
    return end;
}

void Schedule::insert_activity(Activity* activ){
    this->activities.push_back(activ);
}
