
#include <stdio.h>

double h = 1.054E-34, Me = 9.1093E-31, e = 1.602E-19;
int l = 40;
int check(double box[]){
	int i;
	int curve = 0;
	int a = 1;
	for(i = 0; i <= l;i++){
		if(box[i] > 0 && a){
			curve++;
			a = !a;
		}else if(box[i] < 0 && !a){
			curve++;
			a = !a;
		}
	}
	return curve;
}
double energy(double dx){
	double E;
	double a = h*h/(2*Me);
	E = a/(dx*dx);
	return E;
}
int main(){
	double box[40];
	double E = energy(0.5);
	double eV;
	double a = h*h/(Me*2);
	box[0] = 0;
	box[1] = 1;
	box[l] = 1;
	int i = 0;
	int n = 2;
	double dx = 5E-10;
	double temp = 2;
	while(i != n || box[l] > 0.01 || box[l] < -0.01){
		eV = E/e;
		printf("%0.5f : energy :", eV);
		for(i = 1; i < l;i++){
			box[i+1] = (2 -dx*dx*E/a)*box[i] - box[i-1];
		}
		for(i = 0; i <= l;i++){
			printf("%0.2f :", box[i]);
		}
		i = check(box);
		printf("\n %d\n", i);
		if(i > n){
			E = (E - 2*a/(dx*dx*temp*temp));
		}else if(i <= n){
			E = (E + 2*a/(dx*dx*temp*temp));
		}
		temp++;
		if(temp > 150){
			break;
		}
	}

	return 0;
}
