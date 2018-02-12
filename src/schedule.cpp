#include "schedule.hpp"
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>

//Class constructor empty class
Schedule::Schedule()
    : activities(), duration(0), start("0000"), end("0000")
{}

//Class constructor that imports from JSON
Schedule::Schedule(std::string path){
    std::ifstream ifs(path);
    nlohmann::json j;
    ifs >> j;

    for(auto x : j["activities"]){
        std::shared_ptr<Activity> a(new Activity(x[0], x[1], x[2]));
        insert_activity(a);
    }
    start = j["start"];
    end = j["end"];
    duration = get_total_time();
}

//Class destructor
Schedule::~Schedule() {}

//Prints the title of each activity in the schedule
void Schedule::print_schedule(){
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

//Getters
int Schedule::get_duration(){
    return duration;
}

std::string Schedule::get_start(){
    return start;
}

std::string Schedule::get_end(){
    return end;
}

std::vector<std::shared_ptr<Activity>> Schedule::get_activities(){
    return activities;
}

//Setters
void Schedule::set_start(int s){
    start = s;
}

void Schedule::set_end(int e){
    end = e;
}

//Inserts a activity on the list
void Schedule::insert_activity(std::shared_ptr<Activity> activ){
    activities.push_back(activ);
    //Updates the duration
    duration = get_total_time();
}

//Exports the schedule to a JSON file
void Schedule::export_to_json(std::string path, std::string name){
    std::ofstream out_file(path + name + ".json");
    nlohmann::json j;
    std::vector<std::vector<std::string>> v;

    for(auto x : activities){
        v.push_back({x->get_title(), x->get_description(), x->get_duration()});
    }

    j["activities"] = v;
    out_file << std::setw(4) << j << std::endl;
    out_file.close();
}

//Read and generate a vector with the activities of a JSON file
std::vector<std::shared_ptr<Activity>> Schedule::read_activities(std::string path){
    std::ifstream ifs(path);
    nlohmann::json j;
    std::vector<std::shared_ptr<Activity>> v;
    ifs >> j;

    for(auto x : j["activities"]){
        std::shared_ptr<Activity> a(new Activity(x[0], x[1], x[2]));
        v.push_back(a);
    }

    return v;
}

//Imports a schedule from a JSON file
//It overwrites the activities on the schedule
void Schedule::import_schedule(std::string path){
    activities = read_activities(path);
}

//Gets the schedule total duration
int Schedule::get_total_time(){
    int tt = 0;

    for(auto x : activities)
        tt += std::stoi(x->get_duration());

    return tt;
}
