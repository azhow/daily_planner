#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP

#include <string>
#include <vector>
#include "activity.hpp"

//Class schedule
class Schedule {
    private:
        std::vector<Activity*> activities;
        int duration, start, end;
    public:
        //Constructor
        Schedule();
        //Methods
        void insert_activity(Activity* activ);
        void print_schedule();
        int get_duration();
        int get_start();
        int get_end();
};

#endif
