#include <stdio.h>
#include "process.h"

/* ============================================================
 * Student implementation area
 * ============================================================ */
void fcfs_schedule(Process p[], int n)
{
    (void)p;
    (void)n;
    /* TODO: Implement FCFS scheduling algorithm here */
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