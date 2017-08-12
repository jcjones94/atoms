#include "wave.h"
#include <math.h>


double h = 1.054571800E-34;
double Me = 9.10938356E-31;
double Z = 8.9875517E9;
double Q = 1.60217662E-19;

int hydrogen_wave(double E, double wave[], int size, double dx){

	int i;
	int hills = 1;
	double x;
	double a = 2*Q*(Z*Q)*(Me/h)*(dx*dx/h);
	double b = 2*E*(dx*dx/h)*(Me/h);

	for(i = 1; i < size; i++)
	{
		x = i*dx;
		wave[i + 1] = (2 - a/x - b)*wave[i] - wave[i - 1];
		if(hills%2 == 1 && wave[i] < 0)
			hills++;
		else if(hills%2 == 0 && wave[i] > 0)
			hills++;

	}
	return hills;

}

int helium_wave(double E, double wave[], int size, double dx){
	int i;
	int hills = 1;
	double x;
	double a = 4*Q*(Z*Q)*(Me/h)*(dx*dx/h);
	double b = Q*(Z*Q)*(Me/h)*(dx*dx/h);
	double c = 2*E*(dx*dx/h)*(Me/h);

	for(i = 1; i < size; i++){
		x = i*dx;
		wave[i+1] = (2 - a/x + b/x - c)*wave[i] - wave[i-1];
		if(hills%2 == 1 && wave[i] < 0){
			hills++;
		}else if(hills%2 == 0 && wave[i] > 0){
			hills++;
		}
	}
	return hills;
}

int lithium_wave(double E, double wave[], int size, double dx, double subshell){
	int i;
	int hills = 1;
	double x;
	double a = 6*Q*(Z*Q)*(Me/h)*(dx*dx/h);
	double b = 4*Q*(Z*Q)*(Me/h)*(dx*dx/h);
	double c = 2*E*(dx*dx/h)*(Me/h);

	for(i = 1; i < size; i++){
		x = i*dx;
		wave[i+1] = (2 - a/x + b/sqrt(subshell*subshell + x*x) - c)*wave[i] - wave[i-1];
		if(hills%2 == 1 && wave[i] < 0){
			hills++;
		}else if(hills%2 == 0 && wave[i] > 0){
			hills++;
		}
	}
	return hills;

}

int beryllium_wave(double E, double wave[], int size, double dx, double subshell){
	int i;
	int hills = 1;
	double x;
	double a = 7*Q*(Z*Q)*(Me/h)*(dx*dx/h);
	double b = 4*Q*(Z*Q)*(Me/h)*(dx*dx/h);
	double c = 2*E*(Me/h)*(dx*dx/h);

	for(i = 1; i < size; i++){
		x = i*dx;
		wave[i+1] = (2 - a/x + b/sqrt(subshell*subshell + x*x) - c)*wave[i] - wave[i-1];
		if(hills%2 == 1 && wave[i] < 0){
			hills++;
		}else if(hills%2 == 0 && wave[i] > 0){
			hills++;
		}
	}
	return hills;

}

int norm(double wave[], int size){
	int i;
	double sum = 0;

	for(i = 0; i <= size; i++){
		wave[i] = wave[i]*wave[i];
		sum += wave[i];
	}

	for(i = 0; i <= size; i++)
		wave[i] = wave[i]/sum;
	return sum;
}
