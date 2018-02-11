// Daily planner but without repetition
// Generates a random daily schedule with the activities on a json
#include <iostream>
#include "activity.hpp"
#include "schedule.hpp"

int main(int argc, char** argv){
    Schedule *s = new Schedule();
    Activity *a = new Activity("no title", "no descrip", 0);
    Activity *b = new Activity("no title1", "no descrip1", 2);

    //std::cout << "Title: " << a->get_title() << std::endl;
    //std::cout << "Description: " << a->get_description() << std::endl;
    //std::cout << "Duration: " << a->get_duration() << std::endl;

    s->insert_activity(a);
    s->insert_activity(b);
    s->print_schedule();

    return 0;
}
