#include <stdio.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void rr_schedule(Process p[], int n, int quantum)
{
    int remaining_time[100];  // Tiempo restante para cada proceso
    int time = 0;            // Tiempo actual del sistema
    int completed = 0;       // Contador de procesos completados
    
    // Inicializar tiempos restantes
    for (int i = 0; i < n; i++) {
        remaining_time[i] = p[i].burst_time;
        p[i].waiting_time = 0;
        p[i].turnaround_time = 0;
        p[i].completed = 0;
    }
    
    // Simulación Round Robin
    while (completed < n) {
        int all_idle = 1;  // Suponemos que no hay procesos listos
        
        for (int i = 0; i < n; i++) {
            // Solo procesar si el proceso ha llegado y no ha terminado
            if (p[i].arrival_time <= time && remaining_time[i] > 0) {
                all_idle = 0;  // Hay al menos un proceso listo
                
                if (remaining_time[i] > quantum) {
                    // Ejecutar por quantum
                    time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    // Proceso termina
                    time += remaining_time[i];
                    
                    // Calcular tiempos
                    p[i].waiting_time = time - p[i].arrival_time - p[i].burst_time;
                    p[i].turnaround_time = time - p[i].arrival_time;
                    p[i].completed = 1;
                    
                    remaining_time[i] = 0;
                    completed++;
                }
            }
        }
        
        // Si todos los procesos están idle (esperando llegar o ya terminados)
        if (all_idle) {
            time++;
        }
    }
}

/* ============================================================
 * DO NOT MODIFY MAIN
 * ============================================================ */
#ifndef UNIT_TEST
int main(void)
{
    int n;
    int quantum;

    printf("Número de procesos: ");
    scanf("%d", &n);

    printf("Quantum: ");
    scanf("%d", &quantum);

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    rr_schedule(p, n, quantum);

    print_results(p, n, "RR Scheduling");
    return 0;
}
#endif