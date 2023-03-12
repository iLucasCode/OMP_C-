#include"kwadrat.h"


int kwadrat() {
	//omp_set_num_threads(nr_w);
	int nr_w = 4;
	int rozmiar_porcji = 3;
	int rozmiar = 5000;
	int liczba = 3;
	int suma = 0;
	double start = omp_get_wtime();
#pragma omp parallel for 
	for (int i = 0; i < 5000; i++)
	{
#pragma omp atomic
		suma += liczba * liczba;


	}
	double end = omp_get_wtime();
	printf("Suma atomic: %d \n", suma);
	printf("Czas: %lf \n", end - start);

	suma = 0;

	start = omp_get_wtime();
#pragma omp parallel for reduction(+:suma)
	for (int i = 0; i < 5000; i++)
	{

		suma += liczba * liczba;


	}
	end = omp_get_wtime();
	printf("Suma reduction: %d \n", suma);
	printf("Czas: %lf \n", end - start);



}