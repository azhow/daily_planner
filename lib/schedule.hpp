#ifndef SCHEDULE_HPP
#define SCHEDULE_HPP

#include "activity.hpp"

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
        void set_start(std::string s);
        void set_end(std::string e);
        //Methods
        void insert_activity(std::shared_ptr<Activity> activ);
        void modify_activity(std::string activ_title, std::string activ_duration, std::shared_ptr<Activity> activp = nullptr);
        void remove_activity(std::string activ_title, std::string activ_duration, std::shared_ptr<Activity> activp = nullptr);
        void export_to_json_file(std::string path) const;
};

#endif
