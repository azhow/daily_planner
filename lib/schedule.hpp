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
        //Destructor
        ~Schedule();
        //Getters
        void print_schedule() const;
        int get_duration() const;
        int get_total_time() const;
        std::string get_start() const;
        std::string get_end() const;
        std::vector<std::shared_ptr<Activity>> get_activities() const;
        //Setters
        void set_start(int s);
        void set_end(int e);
        //Methods
        void insert_activity(std::shared_ptr<Activity> activ);
        void import_schedule(std::string path);
        void export_to_json_file(std::string path) const;
};

#endif
