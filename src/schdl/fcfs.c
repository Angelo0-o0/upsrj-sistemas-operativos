#include <stdio.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void fcfs_schedule(Process p[], int n)
{
    // 1. Ordenar procesos por arrival_time (y por ID si hay empate)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j+1].arrival_time ||
                (p[j].arrival_time == p[j+1].arrival_time && p[j].id > p[j+1].id)) {
                // Intercambiar procesos
                Process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
    
    // 2. Calcular tiempos para cada proceso
    int current_time = 0;
    
    for (int i = 0; i < n; i++) {
        // Si el proceso llega después del tiempo actual
        if (current_time < p[i].arrival_time) {
            current_time = p[i].arrival_time;
        }
        
        // Waiting time = tiempo esperando antes de ejecutar
        p[i].waiting_time = current_time - p[i].arrival_time;
        
        // Avanzar tiempo por el burst del proceso
        current_time += p[i].burst_time;
        
        // Turnaround time = tiempo total en el sistema
        p[i].turnaround_time = current_time - p[i].arrival_time;
        
        // Marcar como completado
        p[i].completed = 1;
    }
}

/* ============================================================
 * DO NOT MODIFY MAIN
 * ============================================================ */
#ifndef UNIT_TEST
int main(void)
{
    int n;
    int time = 0; // Reloj global del sistema

    printf("Número de procesos: ");
    if (scanf("%d", &n) != 1) return 1;

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    fcfs_schedule(p, n);

    print_results(p, n, "FCFS Scheduling");

    return 0;
}
#endif