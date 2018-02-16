#include "schedule.hpp"
#include <json/json.hpp>
#include <iostream>
#include <fstream>

//Class constructor empty class
Schedule::Schedule()
    : activities(), duration(0), start("0000"), end("0000")
{}

//Class constructor that imports from JSON file
Schedule::Schedule(std::string path){
    std::ifstream ifs(path);
    nlohmann::json j;
    ifs >> j;

    for(auto x : j["activities"]){
        std::shared_ptr<Activity> a(new Activity(x[0], x[1], x[2], x[3]));
        insert_activity(a);
    }
    start = j["start"];
    end = j["end"];
    duration = get_total_time();
}

//Class destructor
Schedule::~Schedule() {}

//Getters
void Schedule::print_schedule() const{
    int index = 0;

    std::cout << "Start: " << start << std::endl;
    std::cout << "End: " << end << std::endl;
    std::cout << "Duration: " << duration << std::endl;
    std::cout << "Activities: " << std::endl;
    for(auto x : activities) {
        std::cout << "\t" << index << ": " << x->get_title() << std::endl;
        index++;
    }
}

int Schedule::get_duration() const{
    return duration;
}

std::string Schedule::get_start() const{
    return start;
}

std::string Schedule::get_end() const{
    return end;
}

std::vector<std::shared_ptr<Activity>> Schedule::get_activities() const{
    return activities;
}

int Schedule::get_total_time() const{
    int tt = 0;

    for(auto x : activities)
        tt += std::stoi(x->get_duration());

    return tt;
}

//Setters
void Schedule::set_start(std::string s){
    start = s;
}

void Schedule::set_end(std::string e){
    end = e;
}

//Inserts a activity on the list
void Schedule::insert_activity(std::shared_ptr<Activity> activ){
    activities.push_back(activ);
    //Updates the duration
    duration = get_total_time();
}

//Modifies an activity
void modify_activity(std::string activ_title, std::string activ_duration, std::shared_ptr<Activity> activp = nullptr){
}

//Removes an activity
void remove_activity(std::string activ_title, std::string activ_duration, std::shared_ptr<Activity> activp = nullptr){
}

//Exports the schedule to a JSON file
void Schedule::export_to_json_file(std::string path) const{
    std::ofstream out_file(path);
    nlohmann::json j;
    std::vector<std::vector<std::string>> v;
    j["start"] = start;
    j["end"] = end;

    for(auto x : activities){
        v.push_back({x->get_title(), x->get_description(), x->get_duration(), x->get_tags()});
    }

    j["activities"] = v;
    out_file << std::setw(4) << j << std::endl;
    out_file.close();
}
