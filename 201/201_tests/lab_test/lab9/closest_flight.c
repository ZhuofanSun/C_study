#include <stdio.h>
#define FLIGHT_NUM 7
typedef struct {
    int dep_time;
    int arr_time;
} FlightInfo;

int convert_to_min(int hr, int min){
    return (hr*60 + min);
}
void add_daily_flights(FlightInfo* flight, int dep_hr, int dep_min, int arr_hr, int arr_min){
    flight->dep_time = convert_to_min(dep_hr, dep_min);
    flight->arr_time = convert_to_min(arr_hr, arr_min);
}

void find_next(int curr_time, FlightInfo flight_info_arr[]){
    int index = 0;  // next flight is tomorrow morning
    for (int i = 0; i < FLIGHT_NUM; ++i) {
        if (flight_info_arr[i].dep_time > curr_time){
            index = i;
            break;  // because in time-order
        }
    }
    int dep_time = flight_info_arr[index].dep_time, arr_time = flight_info_arr[index].arr_time;
    if (dep_time < 12*60){  // 00:00 - 11:59
        printf("Next flight is at %d:%02d a.m, ", dep_time/60, dep_time%60);
    }
    else if (dep_time < 13*60){  // 12:00 - 12:59
            printf("Next flight is at %d:%02d p.m, ", dep_time/60, dep_time%60);
    }
    else{  // 13:00 - 23:59
        dep_time -= 12 * 60;
        printf("Next flight is at %d:%02d p.m, ", dep_time/60, dep_time%60);
    }

    if (arr_time < 12*60){  // 00:00 - 11:59
        printf("arriving at %d:%02d a.m.\n", arr_time/60, arr_time%60);
    }
    else if (arr_time < 13*60){  // 12:00 - 12:59
        printf("arriving at %d:%02d p.m.\n", arr_time/60, arr_time%60);
    }
    else{  // 13:00 - 23:59
        arr_time -= 12 * 60;
        printf("arriving at %d:%02d p.m.\n", arr_time/60, arr_time%60);
    }

}


int main(){
    FlightInfo flight1, flight2, flight3, flight4, flight5, flight6, flight7;
    add_daily_flights(&flight1, 8,1,10,17);
    add_daily_flights(&flight2,10,58,13,11);
    add_daily_flights(&flight3, 11,19,13,31);
    add_daily_flights(&flight4, 12,47,15,0);
    add_daily_flights(&flight5,16,16,18,30);
    add_daily_flights(&flight6,19,22,21,55);
    add_daily_flights(&flight7, 21,13,23,25);
    FlightInfo flight_info_arr[FLIGHT_NUM] = {flight1, flight2,
                                     flight3, flight4, flight5, flight6, flight7};
    int hr, min;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hr, &min);
    find_next(convert_to_min(hr, min), flight_info_arr);
    return 0;
}