#include <stdio.h>
#include <string.h>
#include <math.h>

int toDecimal (char numeroDeOtroSistema[],int baseDeSistema,char numeros[]);
int convertirCharANumero(char caracter,char numeros[]);
int validar(int k,int baseDeSistema);
char* decimalToAnyBase(int numeroEntrada, int baseAConvertir, char numeros[]);

int main(int argc, char *argv[]) {
	char numeros[16]= {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int base;
	int res = 0;
	char numeroEntrada[20];
	int nuevoDecimal;
	int baseAConvertir;
	char* resultado;

	while(res!=2){
		printf("------CONVERTIDOR DE NUMEROS------\n");
		printf("Ingresa el numero: ");
		scanf("%s",numeroEntrada);
		printf("Ingresa la base del numero: ");
		scanf("%d",&base);
		printf("Ingrese en que base desea convertirlo: ");
		scanf("%d", &baseAConvertir);

		nuevoDecimal=toDecimal(numeroEntrada,base,numeros);
		resultado = decimalToAnyBase(nuevoDecimal,baseAConvertir,numeros);

		printf("El numero %s base %d es %s: \n", numeroEntrada, baseAConvertir, resultado);
		printf("1.Continuar -- 2.Salir \n");
		scanf("%d",&res);
	}
	return 0;
}

//Conversión de cualquier sistema a decimal
int toDecimal (char numeroDeOtroSistema[],int baseDeSistema,char numeros[]){
	int i,j,k;
	for (i=0;numeroDeOtroSistema[i]!='\0';i++){
		//Solo guarda la i
	}
	i--;
	int elevado=0;
	int sumatoria=0;
	for (j=i;j>=0;j--){
		k=convertirCharANumero(numeroDeOtroSistema[j],numeros);
		if (validar(k,baseDeSistema)==1){
			break;
		}
		elevado=k*pow(baseDeSistema,i-j);
		sumatoria=sumatoria+elevado;
	}
	return sumatoria;
}

int convertirCharANumero(char caracter,char numeros[]){
	int k;
	for (k=0;numeros[k]!=caracter;k++){
		//Solo guarda la k
	}
	return k;
}

int validar(int k,int baseDeSistema){
	int flag=0;
	if (k<0 || k>=baseDeSistema){
		printf("Uno de los digitos ingresados no es valido!!!\n");
		flag=1;
	}
	return flag;
}

//Convertir de decimal a cualquier base
char* decimalToAnyBase(int numeroEntrada, int baseAConvertir, char numeros[]){ //Se ingresa número decimal y la base a la que se desea convertir
	char res_aux[100];
	char temp;
	char aux_resultado[100];
	char *resultado = &aux_resultado[0];
	int longitud = 0, residuo = 0, i;

	for(i=0;numeroEntrada!=0;i++){ //Ciclo que almacena los residuos en un vector
		residuo = numeroEntrada % baseAConvertir;
		res_aux[i] = numeros[residuo]; //Va al arreglo de numeros y almacena el caracter en la posicion que equivale el residuo
		numeroEntrada = (numeroEntrada - residuo)/baseAConvertir;
		longitud++;
	}

	for(i=longitud;i>=0;i--){ //Invertir el arreglo
		*(resultado + (longitud-i)) = res_aux[i-1];
	}
	 return resultado;
}
