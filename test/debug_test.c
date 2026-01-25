#include <stdio.h>
#include "../src/schdl/process.h"

int main() {
    Process p[4];
    
    p[0] = (Process){ .id = 1, .arrival_time = 2, .burst_time = 4 };
    p[1] = (Process){ .id = 2, .arrival_time = 0, .burst_time = 3 };
    p[2] = (Process){ .id = 3, .arrival_time = 1, .burst_time = 2 };
    p[3] = (Process){ .id = 4, .arrival_time = 2, .burst_time = 1 };
    
    printf("Datos iniciales:\n");
    for (int i = 0; i < 4; i++) {
        printf("p[%d] = {id=%d, arrival=%d, burst=%d}\n", 
               i, p[i].id, p[i].arrival_time, p[i].burst_time);
    }
    
    init_processes(p, 4);
    
    printf("\nDespués de init_processes:\n");
    for (int i = 0; i < 4; i++) {
        printf("p[%d] = {id=%d, arrival=%d, burst=%d, remaining=%d, completed=%d}\n", 
               i, p[i].id, p[i].arrival_time, p[i].burst_time, 
               p[i].remaining_time, p[i].completed);
    }
    
    return 0;
}
