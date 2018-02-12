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
    Schedule *s = new Schedule("./r1.json");

    s->print_schedule();
    std::cout << s->get_duration() << std::endl;

    return 0;
}
