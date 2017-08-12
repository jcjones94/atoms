#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "wave.h"

double k = 1.60217662E-19;

int main(int argc, char *argv[]){

	int i = 2;
	int hills;
	int n = 2;
	int size = 200*n + 200*(n-1)*(n-1);

	double E = -1.2E-18;
	double dx = 1E-12;
	double wave[size];
	double subshell = 0.25E-10;

	wave[0] = 0;
	wave[1] = 1;
	wave[size] = 40;

	int state = 0;

	while((wave[size] > 0.1 || wave[size] < -0.1) || hills != n || !state)
	{
		hills = beryllium_wave(E, wave, size, dx, subshell);
		printf("%d : %d\n", hills, i);
		if(hills > n){
			E = E - n*k/i;
			state = !state;
		}else if(hills <= n){
			E = E + n*k/i;
		}
		if(i > 100000)break;
		i++;
	}

	norm(wave, size);


	double sum = 0;
	double wave_sum = 0;
	int largest = 0;
	for(i = 0; i <= size; i++){
		sum += wave[i]*dx*i;
		wave_sum += wave[i];
		if(wave[i] > wave[largest]) largest = i;
	}

	printf("distance: %f, Energy(eV) : %f \n", largest*dx*1E10, E/k);


	FILE *f = fopen("data.txt", "w");
	dx = dx*1E10;
	fprintf(f, "%f\n%d\n", dx, size);
	for(i = 0; i <= size; i++){
		fprintf(f, "%f\n", wave[i]);
	}
	fclose(f);

	system("python display.py");

}
