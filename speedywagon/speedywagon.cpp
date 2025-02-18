#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:

bool connection_check(pillar_men_sensor* sensor) {
    if (sensor) {return true;}
    return false;
}

// pillar_men_sensor sensor_array[3] = {{0}, {101}, {22}};
// int totalActivity = activity_counter(sensor_array, 3);
// totalActivity => 123
int activity_counter(pillar_men_sensor* sensor_array, int size) {
    int counter = 0;
    pillar_men_sensor* ptr = sensor_array;
    for(int i =0; i < size; i++){
        counter = counter + ((ptr + i) -> activity);
    }
    return counter;
}

// pillar_men_sensor db{9008, "songokunoie", {7, 7, 7}};
// bool alarm = alarm_control(&db);
// alarm => true

bool alarm_control(pillar_men_sensor* sensor){
    if (!connection_check(sensor) || !(sensor->activity)) {return false;}
    for (int element : sensor->data) {
        if (element > 0) {return true;}
    }
    return false;
}

bool uv_alarm(pillar_men_sensor* sensor){
    if (!connection_check(sensor)) {return false;}
    if(uv_light_heuristic(&sensor->data) > sensor->activity) {return true;}
    return false;
}

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}


}  // namespace speedywagon
