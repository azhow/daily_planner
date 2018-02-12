#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP

#include <string>
#include <vector>
#include "activity.hpp"
#include <memory>

//Class schedule
class Schedule {
    private:
        std::vector<std::shared_ptr<Activity>> activities;
        int duration;
        std::string start, end;
    public:
        //Constructor
        Schedule();
        Schedule(std::string path);
        //Methods
        void insert_activity(std::shared_ptr<Activity> activ);
        void print_schedule();
        int get_duration();
        std::string get_start();
        std::string get_end();
        std::vector<std::shared_ptr<Activity>> get_activities();
        void export_to_json(std::string path, std::string name);
        std::vector<std::shared_ptr<Activity>> read_activities(std::string path);
        void import_schedule(std::string path);
        int get_total_time();
        void set_start(int s);
        void set_end(int e);
};

#endif
