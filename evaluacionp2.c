#include <stdio.h>

#define NUM_ALUMNOS 23
#define NUM_PROGRESOS 3

// Función para obtener el promedio de calificaciones de un alumno durante el semestre
float obtenerPromedioAlumno(float calificaciones[]) {
    float suma = 0;
    for (int i = 0; i < NUM_PROGRESOS; i++) {
        suma += calificaciones[i];
    }
    return suma / NUM_PROGRESOS;
}

// Función para obtener la nota promedio del grupo de estudiantes para cada progreso
void obtenerPromedioGrupo(float calificaciones[][NUM_PROGRESOS], float promedios[]) {
    for (int i = 0; i < NUM_PROGRESOS; i++) {
        float suma = 0;
        for (int j = 0; j < NUM_ALUMNOS; j++) {
            suma += calificaciones[j][i];
        }
        promedios[i] = suma / NUM_ALUMNOS;
    }
}

// Función para obtener el alumno que obtuvo el mayor promedio de calificación durante el semestre
int obtenerMejorAlumno(float calificaciones[][NUM_PROGRESOS]) {
    int mejorAlumno = 0;
    float mejorPromedio = obtenerPromedioAlumno(calificaciones[0]);

    for (int i = 1; i < NUM_ALUMNOS; i++) {
        float promedioActual = obtenerPromedioAlumno(calificaciones[i]);
        if (promedioActual > mejorPromedio) {
            mejorPromedio = promedioActual;
            mejorAlumno = i;
        }
    }

    return mejorAlumno;
}

int main() {
    float calificaciones[NUM_ALUMNOS][NUM_PROGRESOS];
    float promediosAlumnos[NUM_ALUMNOS];
    float promediosGrupo[NUM_PROGRESOS];

    // Solicitar las calificaciones de cada alumno
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        printf("Ingrese las calificaciones del alumno %d:\n", i + 1);
        for (int j = 0; j < NUM_PROGRESOS; j++) {
            printf("Progreso %d: ", j + 1);
            scanf("%f", &calificaciones[i][j]);
        }
    }

    // Calcular el promedio de calificaciones de cada alumno durante el semestre
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        promediosAlumnos[i] = obtenerPromedioAlumno(calificaciones[i]);
    }

    // Calcular la nota promedio del grupo de estudiantes para cada progreso
    obtenerPromedioGrupo(calificaciones, promediosGrupo);

    // Obtener el alumno que obtuvo el mayor promedio de calificación durante el semestre
    int mejorAlumno = obtenerMejorAlumno(calificaciones);

    // Imprimir los resultados
    printf("\nPromedios de calificaciones de cada alumno durante el semestre:\n");
    for (int i = 0; i < NUM_ALUMNOS; i++) {
        printf("Alumno %d: %.2f\n", i + 1, promediosAlumnos[i]);
    }

    printf("\nNotas promedio del grupo de estudiantes para cada progreso:\n");
    for (int i = 0; i < NUM_PROGRESOS; i++) {
        printf("Progreso %d: %.2f\n", i + 1, promediosGrupo[i]);
    }

    printf("\nEl alumno con el mayor promedio de calificación durante el semestre es el alumno %d\n", mejorAlumno + 1);

    return 0;
}