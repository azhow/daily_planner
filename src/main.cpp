// Daily planner but without repetition
// Generates a random daily schedule with the activities on a json
#include <iostream>
#include <fstream>
#include <vector>
#include "json.hpp"
#include "activity.hpp"
#include "schedule.hpp"

int main(int argc, char** argv){
    //Creates empty schedule
    Schedule *s = new Schedule();
    //Creates activities for the schedule
    Activity *a = new Activity("no title", "no descrip", "0");
    Activity *b = new Activity("no title1", "no descrip1", "2");
    //Reads the file passed on the command line
    //std::ifstream ifs(argv[1]);
    //Creates JSON object
    nlohmann::json j;
    //Assign file read to JSON object
    //ifs >> j;
    std::vector<std::vector<std::string>> v = { {a->get_title(), a->get_description(), a->get_duration()}, {b->get_title(), b->get_description(), b->get_duration()} };


    j["activities"] =  v;
    //std::cout << argv[1] << std::endl;
    //std::cout << j["activities"] << std::endl;
    std::cout << std::setw(4) << j << std::endl;
    //std::cout << "Title: " << j["title"] << std::endl;
    //std::cout << "Description: " << j["description"] << std::endl;
    //std::cout << "Duration: " << j["duration"] << std::endl;

    //std::cout << "Title: " << a->get_title() << std::endl;
    //std::cout << "Description: " << a->get_description() << std::endl;
    //std::cout << "Duration: " << a->get_duration() << std::endl;

    //s->insert_activity(a);
    //s->insert_activity(b);
    //s->print_schedule();

    return 0;
}
