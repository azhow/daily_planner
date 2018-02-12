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
    Schedule *s = new Schedule(argv[1]);

    s->print_schedule();

    return 0;
}
