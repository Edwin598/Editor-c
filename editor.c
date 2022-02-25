#include <stdio.h>
#include <fcntl.h>
int asignacionNull(char []);
int escrituraOut(char [],int *);
int asignacionNBytes(int,int *);
int asignacionContenido(char [],char [],int);
int mostrarDatos(char [],int);
int main(void){
	int count1=0, count2=0, nBytes=0, cBytes=1,comodin;
	char bufferOut[1000], bufferInt[cBytes];
	/*------------*****************************-------------*/
	asignacionNull(bufferOut);
	/*------------------------------------------------------*/
	escrituraOut(bufferOut,&nBytes);
	/*------------------------------------------------------*/
	asignacionNBytes(nBytes,&cBytes);
	/*asignacionNull(bufferInt);*/
	/*------------------------------------------------------*/
	asignacionContenido(bufferOut,bufferInt,cBytes);
	/*------------------------------------------------------*/
	mostrarDatos(bufferInt,cBytes);
};
int asignacionNull(char array1[]){
	printf("\nAsignando valores nulos\n");
	for(int i=0;i<=1000;i++)
		array1[i]='\0';
	printf("\nSe asignaron los valores nulos\n");
	return 0;
};
int escrituraOut(char array1[],int*count1){
	printf("\nEmpieza a escribir.\nPara dejar de escribir ingresa el caracter '^'\n");
	for(int i=0;i<=999;i++){
		array1[i]=getchar();
		if(array1[i]=='^'){
			array1[i]='\0';
			*count1=i;
			break;
		};
	};
	printf("\nvalor de i:%d\n",*count1);
	return 0;
};
int asignacionNBytes(int cantidad1,int*cantidad2){
	*cantidad2=cantidad1+*cantidad2;
	printf("\nLa cantidad de espacio en bytes asignados:%d in\n",*cantidad2);
};
int asignacionContenido(char array1[], char array2[],int cantidad1){
	printf("\nCopiando datos\n");
	printf("\n%d\n",cantidad1);
	for(int i=0;i<=cantidad1;i++){
		array2[i]=array1[i];/*
		printf("\n%ci",array2[i]);
		printf("%ci\n",array1[i]);*/
	};
	printf("\nCopia terminada\n");

};
int mostrarDatos(char array1[],int cantidad1){
	printf("%d",cantidad1);
	for(int i=0;i<cantidad1;i++){
		printf("%c",array1[i]);
	};
	printf("\n");
};
