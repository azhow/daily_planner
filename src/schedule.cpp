#include "schedule.hpp"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <vector>

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

std::vector<Activity*> Schedule::get_activities(){
    return activities;
}

void Schedule::insert_activity(Activity* activ){
    activities.push_back(activ);
}
/*
void Schedule::export_to_json(std::string path, std::string name){
    std::ofstream out_file(path + name + ".json");
    nlohmann::json j;
    j["activities"] = activities;
    out_file << std::setw(4) << j << std::endl;
    out_file.close();
}*/
