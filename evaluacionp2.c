#include <stdio.h>  //Libreria que nos permite usar las funciones del programa
#include <stdlib.h> //Libreria que nos permite usar las funciones del programa
#include <string.h> //Libreria que nos permite usar las funciones del programa
#include <locale.h> //Libreria que nos permite usar las funciones del programa
#include <time.h>   //Libreria que nos permite usar las funciones del programa


int Menu(int flag, int semestres[3][23]);
char *Estudiantes[23] = {"Lara David", "Eduardo Franquiz", "Matias Villacis", "Emilia Davila", "Julian Serrano", "Mateo Lopez", "Angela Moreira", "Byron Davila", "Pepe Perez", "Angela Moreira", "Angela Moreira", "Angela Moreira", "Angela Moreira", "Angela Moreira", "Angela Moreira", "Angela Moreira", "Angela Moreira", "Angela Moreira", "Angela Moreira", "Angela Moreira", "Angela Moreira", "Angela Moreira", "Angela Moreira"};
int main()
{
	
	// Se inicializan los numeros aleatorios
	srand(time(NULL));
	// Creacion de un arreglo
	int progresos[3][23]= {0};
	// Creacion de la variable booleana flag para el menu
	int flag = 1;
	
	// Uso de triple ciclo For 
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 23; j++)
			{
				progresos[i][j] = rand() % 11;
			}
		}
	
	// Se pone en pantalla el menu hasta que el usuario decida cerrar el programa mientras la variable flag sea verdadera
	while (flag)
	{
		flag = Menu(flag, progresos);
	}
	
	return 0;
}
// Funcion que permite al usuario ver el Menu
int Menu(int flag, int progresos[3][23])
{
	// Creacion de las variables para que el usuario pueda ingresar la opcion que desee y la variablle que se encarga de verificar si la respuesta colocada por el usuario es correcta
	int opc, result;
	int Menu = 1; // Variable booleana para observar el menu
	
	// Uso de la variable booleana menumostrar para que cuando sea verdadera, muestre el menu
	while (Menu)
	{
		printf("------------------Bienvenido-------------------\n");
		printf("Ingrese el numero de la opcion que desea:\n 1.El numero de estudiantes de cada anio en su respectiva carrera \n 2.El anio en que ingreso la mayor cantidad de alumnos a la universidad.\n 3.La Carrera que recibio la mayor cantidad de alumnos en el ultimo anio.\n 4.Anio en que la carrera de Ingenieria de Software recibio la mayor cantidad de alumnos\n 5. Salir del programa\n");
		result = scanf("%d", &opc);
		// En caso de que la entrada ingresada no sea correcta, se limpia el buffer de entrada y se le pide que ingrese de nuevo otro dato
		while (result != 1)
		{
			while (getchar() != '\n')
				; // Se encarga de limpiar el buffer de entrada
			
			printf("\nOpcion incorrecta. Ingrese un numero de nuevo: ");
			result = scanf("%d", &opc);
		}
		
		// Dependiendo de la eleccion elegida por el usuario, se ejecuta una serie de comandos gracias al condicional switch case
		switch (opc)
		{
		case 1:
			Menu = 0; // Se deja de visualizar el menu
			// Se imprime los estudiantes
			printf("Las carreras son:\n 1. Ingenieria de Software. \n 2. Matematicas\n 3. Ingenieria Industrial\n 4. Contabilidad\n 5. Administracion\n 6. Relaciones Internacionales\n 7. Economia");
			// Uso de un triple for para recorrer años, carrears y semestres
			for (int i = 0; i < 3; i++)
			{
				printf("\nProgreso %d:\n", i + 1);
				for (int j = 0; j < 7; j++)
				{
					for (int k = 0; k < 2; k++)
					{
						printf(" %s tiene como promedio %d es: ", Estudiantes[j], progresos[i][j]);
					}
				}
			}
			break;
		case 2:
			Menu = 0;              // Se deja de visualizar el menu
			int max1;              
			int cantmax1[3] = {0}; // Creacion de un arreglo unidimensional para los progresos
			// Doble ciclo For para recorrer el arreglo
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 23; j++)
					{
						cantmax1[i] += progresos[i][j];
					}
				}
			max1 = 0;
			for (int i = 1; i < 3; i++)
			{
				if (cantmax1[i] > cantmax1[max1])
				{
					max1 = i;
				}
			}
			printf("Respuesta:  el promedio de calificaciones de cada alumno durante el semeste fue %d", );
			break;
		case 3:
			Menu = 0;        // Se deja de visualizar el menu
			int max2 = 0;     
			int cantmax2[23] = {0}; // Creacion de un arreglo unidimensional para los alumnos
			
			for (int i = 0; i < 7; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					cantmax2[i] = cantmax2[i] + progresos[i][j];
				}
			}
			
			// Encuentra el alumno con mejor nota gracias a un ciclo for y un condicional if que ira ordenando las notas
			for (int i = 0; i < 7; i++)
			{
				if (cantmax2[i] > cantmax2[max2])
				{
					max2 = i;
				}
			}
			// Imprime la respuesta
			printf("Respuesta: El alumno que obtuvo la mayor nota es %s con un total de %d alumnos\n\n", Carreras[max2], cantmax2[max2]);
			break;
		case 4:
			Menu = 0;        // Se deja de visualizar el menu
			int max3 = 0;        // Variable a la que se le asignara el numero de los alumnos
			int cantmax3[5] = {0}; // Creacion de un arreglo unidimensional para los anios
			
			// Doble ciclo For 
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					cantmax3[i] = cantmax3[i] + progresos[i][j];
				}
			}
			
			// Uso de un ciclo For y un condicional If para poder encontrar el alumno con mejor calificacion en todo el semestre
			max3 = 0;
			for (int i = 0; i < 5; i++)
			{
				if (cantmax3[i] > cantmax3[max3])
				{
					max3 = i;
				}
			}
			
			// Imprime la respuesta
			printf("Respuesta: El alumno que obtuvo la mayor nota durante todo el semestre fue  %d con %d \n\n", max3 + 1, cantmax3[max3]);
			break;
		case 5:
			Menu = 0; // Se deja de visualizar el menu
			flag = 0; // La variable booleana se vuelve falsas y esto hace que se cierre el programa
			break;
		default:
			printf("\nRespuesta invalida. Ingrese de nuevo\n");
			break;
		}
		// Se coloca un texto que permite que el usuario despues de dar entre, vuelva al menu
		getchar();
		printf("Presione ENTER para regresar al menu...");
		getchar();
	}
	// Esto permite que mientras la variable siga siendo verdadera, se reinicie el menu
	return flag;
}