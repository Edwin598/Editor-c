#include <stdio.h>
#include <fcntl.h>
int asignacionNull(char []);
int asignacionDatos(char [],int *);
int asignacionNBytes(int,int *);/*change*/
int asignacionContenido(char [],char [],int);/*change*/
int mostrarDatos(char [],int);
int nameFile(char [],int *);
int mkOrMkOpen(int (*a)(char [],int *),int (*b)(char[],int *,char),char [],int *,int *,int,int);
int mkFile(char [],int *);
int openAndOrCreatFile(char [],int *,char);
int closeFile(int);
/*int permisos(int);*/
int main(void){
	int count1=0, count2=0, nBytes1=0, nBytes2=0,fd1,fd2,comodin;/*change*/
	char bufferOut[1000],fileName[100];
	/*------------*****************************-------------*/
	asignacionNull(bufferOut);
	/*------------*****************************-------------*/
	asignacionDatos(bufferOut,&nBytes1);
	/*------------*****************************-------------*/
	/*-----asignacionNBytes(nBytes,&cBytes);-----------*/
	/*------------*****************************-------------*/
	/*----asignacionContenido(bufferOut,bufferInt,cBytes);-*/
	/*------------*****************************-------------*/
	mostrarDatos(bufferOut,nBytes1);
	/*------------*****************************-------------*/
	asignacionNull(fileName);
	nameFile(fileName,&nBytes2);
	/*------------*****************************-------------*/
	mkOrMkOpen(mkFile,openAndOrCreatFile,fileName,&fd1,&fd2,comodin,count1);
	/*mkFile(fileName,&fd1);
	openAndOrCreatFile(fileName,&fd2,comodin);*/
	return 0;
};
int asignacionNull(char array1[]){
	printf("\nAsignando valores nulos\n");
	for(int i=0;i<=1000;i++)
		array1[i]='\0';
	printf("\nSe asignaron los valores nulos\n");
	return 0;
};
int asignacionDatos(char array1[],int*count1){
	printf("\nEmpieza a escribir.\nPara dejar de escribir ingresa el caracter '^'\n");
	for(int i=0;i<=999;i++){
		array1[i]=getchar();
		if(array1[i]=='\n'){
			
		};
		switch(array1[i]){
			case'^':
				array1[i]='\0';
				*count1=i;
				i=1000;
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
	for(int i=0;i<cantidad1;i++){
		printf("%c",array1[i]);
	};
	printf("\n");
};
int nameFile(char array1[],int *count1){
	printf("\nEscribe un nombre de archivo de menos de 100 caracteres\n");
	array1[1]=getchar();
	for(int i=0;i<100;i++){
		array1[i]=getchar();
		*count1=i;
		switch(array1[i]){
			case'\n':
				array1[i]='\0';
				i=100;
				break;
		};
	};
};
/*------------------------int mkOrMkOpen(int (*a),int (*b),char [],int *,int *,int,int);-------------------------------*/
int mkOrMkOpen(int (*a)(char array1[],int*fd1), int (*b)(char array1[],int*fd1,char respuesta),char arrayName1[],int *filedescriptor1,int *filedescriptor2,int comodin,int count1){
	printf("\nIntroduce el numero '1' si quieres solo crear un archivo.\nIntroduce el numero '2' si quieres abrir, o crear y abrir un archivo al mismo tiempo");
	scanf("%d",&comodin);
	while(count1!=1){
		switch(comodin){
			case 1:
				(*a)(arrayName1,&*filedescriptor1);
				count1=1;
			break;
			case 2:
				comodin=0;
				(*b)(arrayName1,&*filedescriptor2,comodin);
			break;
		};
	};
};
int mkFile(char array1[],int*fd1){
	switch(*fd1=creat(array1,0666)){
		case 1:
			printf("\nError al crear el archivo\n");
			break;
		case 0:
			printf("\nSe creo el archivo con exito\n");
			break;
	};
};
int openAndOrCreatFile(char array1[],int*fd1,char respuesta){
	int i=0;
	while(i==0){
		printf("\nIngresa el numero '1' si quieres abrir un archivo y crearlo.\nIngresa el numero '2' para solo abrir un archivo.\nIngresa el numero '3' si quieres salir.\n");
		scanf("%c",&respuesta);
		if(respuesta=='1'){
			switch(*fd1=open(array1,O_RDWR|O_CREAT|O_APPEND,0666)){
				case 1:
					printf("\nError al crear el archivo\n");
				break;
				case 0:
					printf("\nSe creo el archivo con exito\n");
					i=1;
				break;
			};
		}else if(respuesta=='2'){
			switch(*fd1=open(array1,O_RDWR|O_APPEND)){
				case 1:
					printf("\nError al crear el archivo\n");
				break;
				case 0:
					printf("\nSe creo el archivo con exito\n");
					i=1;
				break;
			};
		}else if(respuesta=='3') i=1;
		else printf("Entrada erronea");
	};
	
};
/*int permisos(int comodin){
	printf("\nSelecciona los permisos para tu archivo.\n0) Ningun permiso,\n1)k"
};*/
