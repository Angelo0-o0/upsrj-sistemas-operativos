#include <stdio.h>
#include "process.h"

int main() {
    int n;
    int time = 0; // Reloj global del sistema

    printf("Número de procesos: ");
    if (scanf("%d", &n) != 1) return 1;

    Process p[n];
    read_processes(p, n);
    init_processes(p, n);

    printf("\n--- Iniciando Simulación FCFS ---\n");

    // Lógica del scheduler FCFS
    for (int i = 0; i < n; i++) {
        // 1. Manejo del tiempo ocioso (Idle time)
        if (time < p[i].arrival_time) {
            printf("Tiempo %d: CPU Ocioso...\n", time);
            time = p[i].arrival_time;
        }

        // 2. Ejecución del proceso
        printf("Tiempo %d: Ejecutando P%d (BT=%d)\n",
               time, p[i].id, p[i].burst_time);

        // 3. Cálculo de métricas
        p[i].waiting_time = time - p[i].arrival_time;
        time += p[i].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        p[i].completed = 1;

        printf("   -> P%d terminó en tiempo %d\n", p[i].id, time);
    }

    printf("---------------------------------\n");
    print_results(p, n, "FCFS Scheduling");

    return 0;
}