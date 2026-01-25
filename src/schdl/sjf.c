#include <stdio.h>
#include <limits.h>
#include "process.h"

void sjf_schedule(Process p[], int n)
{
    // Crear arreglo temporal para ordenar
    Process temp[100];
    for (int i = 0; i < n; i++) {
        temp[i] = p[i];
    }
    
    int time = 0;
    int completed = 0;
    int order_idx = 0;
    
    while (completed < n)
    {
        int idx = -1;
        int min_burst = INT_MAX;
        
        // Buscar proceso con menor burst_time disponible
        for (int i = 0; i < n; i++)
        {
            if (temp[i].arrival_time <= time && temp[i].completed == 0)
            {
                if (temp[i].burst_time < min_burst)
                {
                    min_burst = temp[i].burst_time;
                    idx = i;
                }
            }
        }

        if (idx != -1)
        {
            temp[idx].waiting_time = time - temp[idx].arrival_time;
            time += temp[idx].burst_time;
            temp[idx].turnaround_time = time - temp[idx].arrival_time;
            temp[idx].completed = 1;
            
            // Copiar al arreglo original en orden de ejecución
            p[order_idx++] = temp[idx];
            completed++;
        }
        else
        {
            time++;
        }
    }
}