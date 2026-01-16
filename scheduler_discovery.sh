#!/bin/bash

# =========================================================================
# PRÁCTICA: EXPLORACIÓN DEL SCHEDULER REAL EN LINUX
# Nombre: Angelo Uriel Rivera Gascon
# Descripción: Localización y análisis del CFS (Completely Fair Scheduler)
# =========================================================================

# Definición de colores para una mejor visualización
VERDE="\e[0;32m"
CIAN="\e[0;36m"
AMARILLO="\e[1;33m"
ROJO="\e[0;31m"
RESET="\e[0m"

echo -e "${CIAN}------------------------------------------------------------${RESET}"
echo -e "${AMARILLO}INICIANDO EXPLORACIÓN DEL KERNEL - Por: Angelo Uriel Rivera Gascon${RESET}"
echo -e "${CIAN}------------------------------------------------------------${RESET}"

# Paso 1: Ubicación del código fuente
# El scheduler de Linux se encuentra en la ruta: /kernel/sched/
# El archivo principal que implementa el CFS es: fair.c

VERSION_KERNEL=$(uname -r)
RUTA_BASE="/usr/src/linux-headers-$VERSION_KERNEL"
RUTA_SCHED="$RUTA_BASE/kernel/sched/fair.c"

echo -e "${VERDE}Buscando el scheduler en:${RESET} $RUTA_SCHED"
echo ""

# Explicación teórica
echo -e "${AMARILLO}REFLEXIÓN TEÓRICA:${RESET}"
echo "El scheduler actual de Linux se llama CFS (Completely Fair Scheduler)."
echo "A diferencia de FCFS o RR, el CFS utiliza un Árbol Rojo-Negro para"
echo "organizar procesos basándose en su vruntime (virtual runtime)."



echo -e "${CIAN}------------------------------------------------------------${RESET}"

# Mostrar el contenido del archivo
echo -e "${AMARILLO}EXTRACTO DE IMPLEMENTACIÓN DE fair.c:${RESET}"
echo ""

if [ -f "$RUTA_SCHED" ]; then
    # Usamos nl para numerar las líneas y ver mejor la estructura
    head -n 100 "$RUTA_SCHED" | nl
    echo ""
    echo -e "${VERDE}... [Código truncado por brevedad] ...${RESET}"
else
    echo -e "${ROJO}ERROR:${RESET} No se encontró el archivo fair.c."
    echo "Sugerencia: Ejecuta sudo apt install linux-headers-6.8.0-90-generic para instalar las fuentes."
fi

echo ""
echo -e "${CIAN}------------------------------------------------------------${RESET}"
echo -e "${AMARILLO}ANÁLISIS DE ALGORITMOS:${RESET}"
echo -e "${CIAN}------------------------------------------------------------${RESET}"
echo -e "${VERDE}¿Por qué Linux prefiere CFS sobre FCFS o SJF?${RESET}"
echo ""
echo "1. Evita el Efecto Convoy de FCFS donde un proceso largo detiene todo."
echo "2. A diferencia de SJF, no necesita predecir el futuro (ráfagas de CPU)."
echo "3. Es más dinámico que el Round Robin (RR) estándar al usar pesos y prioridades."
echo ""
echo "El CFS garantiza que el sistema sea fluido tanto para el usuario (interactividad)"
echo "como para procesos de fondo (rendimiento)."


