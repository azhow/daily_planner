// Daily planner but without repetition
// Generates a random daily schedule with the activities on a json
#include "schedule.hpp"
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/algorithm/string/split.hpp>

std::shared_ptr<Schedule> create_schedule(std::shared_ptr<Schedule> schedule);


int main(int argc, char** argv){
    //Creates empty schedule
    std::shared_ptr<Schedule> s(new Schedule());

    //std::cout << (*a==b) << std::endl;
    //std::cout << (*a==c) << std::endl;

    s = create_schedule(s);
    s->print_schedule();
    s->export_to_json_file(argv[1]);

    return 0;
}

std::shared_ptr<Schedule> create_schedule(std::shared_ptr<Schedule> schedule){
    std::string tit, des, dur, tags, s, e;
    while(true){
        std::cout << "Title: ";
        getline(std::cin, tit);
        std::string t1 = boost::algorithm::to_lower_copy(tit);

        if(t1 == "exit" || t1 == "q" || t1 == "quit" || t1 == "e" || std::cin.eof()) break;

        std::cout << "Description: ";
        getline(std::cin, des);

        std::cout << "Duration: ";
        getline(std::cin, dur);

        std::cout << "Tags: ";
        getline(std::cin, tags);
        std::cout << std::endl;

        boost::algorithm::trim(des);
        boost::algorithm::trim(tit);
        boost::algorithm::trim(dur);
        boost::algorithm::trim(tags);

        std::shared_ptr<Activity> a(new Activity(tit, des, dur, tags));
        schedule->insert_activity(a);
    }
    std::cout << "Start: ";
    getline(std::cin, s);

    std::cout << "End: ";
    getline(std::cin, e);
    std::cout << std::endl;

    schedule->set_start(s);
    schedule->set_end(e);

    return schedule;
}
