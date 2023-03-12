#include"petle_1.h"

int petle_1() {
	//omp_set_num_threads(nr_w);
	int nr_w = 4;
	int rozmiar_porcji = 3;
	int rozmiar = 150000;
	int liczba = 0;
	double start = omp_get_wtime();
#pragma omp parallel for schedule(static,rozmiar_porcji) 
	for (int i = 0; i < rozmiar; i++)
	{
		//printf("thread %d, indeks %d\n",omp_get_thread_num(),i);
		liczba++;


	}
	double end = omp_get_wtime();

	printf("Czas static, porcja 3 %lf\n", end - start);

	start = omp_get_wtime();
#pragma omp parallel for schedule(static) 
	for (int i = 0; i < rozmiar; i++)
	{
		//printf("thread %d, indeks %d\n",omp_get_thread_num(),i);
		liczba++;


	}
	end = omp_get_wtime();

	printf("Czas static %lf\n", end - start);

	start = omp_get_wtime();
#pragma omp parallel for schedule(dynamic,rozmiar_porcji) 
	for (int i = 0; i < rozmiar; i++)
	{
		//printf("thread %d, indeks %d\n",omp_get_thread_num(),i);
		liczba++;


	}
	end = omp_get_wtime();

	printf("Czas dynamic, porcja 3 %lf\n", end - start);

	start = omp_get_wtime();
#pragma omp parallel for schedule(dynamic) 
	for (int i = 0; i < rozmiar; i++)
	{
		//printf("thread %d, indeks %d\n",omp_get_thread_num(),i);
		liczba++;


	}
	end = omp_get_wtime();

	printf("Czas dynamic %lf\n", end - start);



}