// Daily planner but without repetition
// Generates a random daily schedule with the activities on a json
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <boost/algorithm/string.hpp>    
#include <json/json.hpp>
#include "activity.hpp"
#include "schedule.hpp"

std::shared_ptr<Schedule> create_schedule(std::shared_ptr<Schedule> schedule);

int main(int argc, char** argv){
    //Creates empty schedule
    std::shared_ptr<Schedule> s(new Schedule());
    std::shared_ptr<Activity> a(new Activity("tit", "des", "5"));
    std::shared_ptr<Activity> b(new Activity("tit", "des", "5"));
    std::shared_ptr<Activity> c(new Activity("t2it", "des", "5"));

    //std::cout << (*a==b) << std::endl;
    //std::cout << (*a==c) << std::endl;
    ///s->insert_activity(a);

    s = create_schedule(s);
    s->print_schedule();
    s->export_to_json_file(argv[1]);

    return 0;
}

std::shared_ptr<Schedule> create_schedule(std::shared_ptr<Schedule> schedule){
    std::string tit, des, dur;
    while(true){
        std::cout << "Title: ";
        getline(std::cin, tit);
        std::string t1 = boost::algorithm::to_lower_copy(tit);

        if(t1 == "exit" || t1 == "q" || t1 == "quit" || t1 == "e" || std::cin.eof()) break;

        std::cout << "Description: ";
        getline(std::cin, des);

        std::cout << "Duration: ";
        getline(std::cin, dur);
        std::cout << std::endl;

        boost::algorithm::trim(des);
        boost::algorithm::trim(tit);
        boost::algorithm::trim(dur);
        std::shared_ptr<Activity> a(new Activity(tit, des, dur));
        schedule->insert_activity(a);
    }


    return schedule;
}
