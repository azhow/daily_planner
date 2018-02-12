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
        Schedule(std::string path);
        //Methods
        void insert_activity(Activity* activ);
        void print_schedule();
        int get_duration();
        int get_start();
        int get_end();
        std::vector<Activity*> get_activities();
        void export_to_json(std::string path, std::string name);
        std::vector<Activity*> read_activities(std::string path);
        void import_schedule(std::string path);
        int get_total_time();
};

#endif
