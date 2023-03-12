#include"petle.h"


int petle() {
	int nr_w = 12;
	omp_set_num_threads(nr_w);
	int rozmiar_porcji = 3;
	int rozmiar = 15;
	printf("------static Porcja 3------\n");
#pragma omp parallel for schedule(static,rozmiar_porcji)
	for (int i = 0; i < rozmiar; i++)
	{
		printf("thread %d, indeks %d\n", omp_get_thread_num(), i);

	}

	printf("------static Porcja def------\n");
#pragma omp parallel for schedule(static)
	for (int i = 0; i < rozmiar; i++)
	{
		printf("thread %d, indeks %d\n", omp_get_thread_num(), i);

	}

	printf("------dynamic Porcja 3------\n");
#pragma omp parallel for schedule(dynamic,rozmiar_porcji)
	for (int i = 0; i < rozmiar; i++)
	{
		printf("thread %d, indeks %d\n", omp_get_thread_num(), i);

	}

	printf("------dynamic Porcja def------\n");
#pragma omp parallel for schedule(dynamic)
	for (int i = 0; i < rozmiar; i++)
	{
		printf("thread %d, indeks %d\n", omp_get_thread_num(), i);

	}


}
