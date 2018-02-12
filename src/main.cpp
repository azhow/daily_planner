// Daily planner but without repetition
// Generates a random daily schedule with the activities on a json
#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include "json.hpp"
#include "activity.hpp"
#include "schedule.hpp"

std::shared_ptr<Schedule> create_schedule(std::shared_ptr<Schedule> schedule);

int main(int argc, char** argv){
    //Creates empty schedule
    std::shared_ptr<Schedule> s(new Schedule());
    std::shared_ptr<Activity> a(new Activity("tit", "des", "5"));
    std::shared_ptr<Activity> b(new Activity("tit", "des", "5"));
    std::shared_ptr<Activity> c(new Activity("t2it", "des", "5"));

    ///s->insert_activity(a);

    //s = create_schedule(s);

    ///s->print_schedule();

    return 0;
}

std::shared_ptr<Schedule> create_schedule(std::shared_ptr<Schedule> schedule){
    std::string tit, des, dur;
    while(true){
        std::cout << "Title: ";
        std::cin >> tit;

        if(tit == "exit") break;

        std::cout << "Description: ";
        std::cin >> des;

        std::cout << "Duration: ";
        std::cin >> dur;
        std::cout << std::endl;

        std::shared_ptr<Activity> a(new Activity(tit, des, dur));
        schedule->insert_activity(a);
    }


    return schedule;
}
