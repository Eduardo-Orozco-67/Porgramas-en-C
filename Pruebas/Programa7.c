// Programa 7 - corresponde al diagrama de flujo billetes 5
// 8 de Octubre del 2020
// Luis Antonio Alvarez Oval
// Aplicacion de Funciones Recursivas

#include <stdio.h>

// Variables globales

// Variable para el control del renglon que se captura
// de acuerdo al problema en la tabla que se presenta
short g_renglon = 1;

// Declaraci?n de arreglo bidimensional de tipo entero 
// para la Distribucion Financiera
//    renglon,columna
int distf[4][11];

// Arreglo que almacena el importe a distribuir
float a_importe[4];

// Controla el numero de veces que se invoca la funcion recursiva
int vcontrol = 0;
   
// Version RECURSIVA de la funcion que obtiene el total a pagar
float sumar(int pcontrol){
	float vtotal = 0 ;
	if (pcontrol < 4){
		return a_importe[pcontrol] + sumar(pcontrol +1);
	}
	else {
		return 0;
	}// Fin de si
}// Fin de la funcion sumarTotalRec

// Version simple de la funcion que obtiene el total a pagar
float sumarTotalSim(){
	// variables locales
	int vr = 0;
	float vtotal = 0.0;
	for(vr = 0; vr < 4; vr = vr + 1){
		vtotal = vtotal + a_importe[vr];
	} // Fin del for
	// Devolver el importe
	return vtotal;
} // Fin de funcion sumarTotalSim

// Desplegar en pantalla el contenido de los 3 arreglos
// cada arreglo tiene un solo renglon
void mostrarArreglo(){
	// variables locales
	// Control del renglon
	int vr = 0;
	// Control de la columna
	int vc = 0;
	
	// Desplegar en pantalla el contenido del arreglo bidimensional
	printf("Importe b500  b200  b100  b50  b20  m10  m5  m2  m1  m.50 \n");
	// Aqui recorro los renlones
	for(vr = 0; vr < 4; vr = vr + 1){
		// Aqui se imprime el importe
		printf("%f  ", a_importe[vr] );
		// Aqui se recorren de las columnas
		for(vc = 0; vc < 10; vc = vc + 1){
		   printf("%i     ", distf[vr][vc] );
		} // Fin del For para las columnas
		printf("\n");
	} // Fin del For para renglon
} // Fin Funcion MostrarArreglo


// Funcion que llena el arreglo
// pCol - indica la COLUMNA en el arreglo donde se almancena cantidad de billetes
// pCant - Indica la cantidad de billetes de cada denominacion a almacenar
// pRen - Indica el renglon de la hoja de calculo del laboratorio
// pImp - indica el importe a pagar que se distribuye
void llenarArreglo(int pCol, int pCant, int pRen, float pImp){
	int vren;
	// Renglon del arreglo
	vren = pRen - 1;
	// Almacenando el importe a pagar
	if (a_importe[vren] == 0){
		a_importe[vren] = pImp;
	} // Fin de si
	// Llenando el arreglo
	distf[vren][pCol] = pCant;
} // Fin funcion llenarArrelo


// Funci?n que ejecuta la distribucion financiera
// la almacena en un arreglo de una dimension
void distribuir(float pcant, int pReng){
	// declaraci?n de variables locales
  	int bi200, bi100, bi50, bi20, bi500;
  	int m10, m5, m2, m1, m050;
  	float cant;
  	
  	cant = pcant;
  	
  	// Inicializando variables
  	bi500 = 0;
  	bi200 = 0;
  	bi100 = 0;
  	bi50  = 0;
  	bi20  = 0;
  	m10   = 0;
  	m5    = 0;
  	m2    = 0;
  	m1    = 0;
  	m050  = 0;
  	
  	// printf(renglon); -- error porque son variables locales
  	// Si la cantidad es mayor de 120,000 usar billetes de 500
  	if(cant>120000){
  	 	// Si la condici?n es verdad entra x aqui
      	bi500 = (int)(cant / 500);
      	cant  = cant - (bi500*500);
        llenarArreglo(0, bi500, pReng, pcant );
  	} // Fin del IF
  	
  	// Calculando el numero de billetes de 200
  	bi200 = (int)(cant / 200);
  	cant  = cant - (bi200*200);
  	llenarArreglo(1, bi200, pReng, pcant);
  	
	// Calculando el numero de billetes de 100
 	bi100 = (int)(cant / 100);
 	cant  = cant - (bi100*100);
    llenarArreglo(2, bi100, pReng, pcant);
    
	// Calculando el numero de billetes de 50
  	bi50 = (int)(cant / 50);
  	cant  = cant - (bi50*50);
  	llenarArreglo(3, bi50, pReng, pcant);
  
  	// Calculando el numero de billetes de 20
  	bi20 = (int)(cant / 20);
  	cant  = cant - (bi20*20);
    llenarArreglo(4, bi20, pReng, pcant);
  
  	// Calculando el numero de monedas 10
  	m10 = (int)(cant / 10);
  	cant  = cant - (m10*10);
  	llenarArreglo(5, m10, pReng, pcant);
  
  	// Calculando el numero de monedas 5
  	m5 = (int)(cant / 5);
  	cant  = cant - (m5*5);
  	llenarArreglo(6, m5, pReng, pcant);
  
  	// Calculando el numero de monedas 2
  	m2 = (int)(cant / 2);
  	cant  = cant - (m2*2);
  	llenarArreglo(7, m2, pReng, pcant);
  
  	// Calculando el numero de monedas 1
  	m1 = (int)(cant / 1);
  	cant  = cant - (m1*1);
  	llenarArreglo(8, m1, pReng, pcant);
  
  	// Calculando el numero de monedas 10
  	m050 = (int)(cant / 0.5);
  	cant  = cant - (m050*0.5);
  	llenarArreglo(9, m050, pReng, pcant);
} // Fin funcion distribuir

// Funcion que ejecuta la captura de un renglon
// de la descripcion del proyecto
void capturaRenglon(){
  	float cant = 0;
  	// Solo se pueden capturar 4 renglones
  	if(g_renglon < 5){
  		// Si la condicion es verdad ejecuta estos comandos
  		// Inicializaci?n de variables
  		cant  = 0;
  		printf("valor de renglon: %i \n", g_renglon);
  		// Capturando el importe a distribuir
  		printf("Dame la cantidad que le debes pagar al proveedor: \n");
  		scanf("%f",&cant);
  		// Se ejecuta la funcion distribuir
  		distribuir(cant, g_renglon);
  		g_renglon = g_renglon + 1;
  	}
  	else {
  		printf("Solo se permite capturar hasta 4 renglones \n");
  	} // Fin del IF de validacion del renglon
} // Fin de funcion capturaRenglon

// Aqu? inicia el programa principal
void main(){
	short vopc = 0;
	int vsalir = 0;
	// Ciclo mientras vsalir tenga el valor de cero
	while (vsalir == 0){
		printf("Opciones que el usuario puede seleccionar: \n");
		printf("1. Capturar renglon \n");
		printf("2. Desplegar arrreglo \n");
		printf("3. Limpiar pantalla \n");
		printf("4. Salir \n");
		printf("5. Obtener el total a pagar SIMPLE\n");
		printf("6. Obtener el total a pagar RECURSIVA\n");
		vopc = 0;
		printf("Opcion: ");
		scanf("%i", &vopc);
		switch(vopc){
			case 1:
				capturaRenglon();
				break;
			case 2:
				mostrarArreglo();
				break;
			case 3:
				system("cls");
				break;
			case 4:
				vsalir = 1;
				break;
			case 5:
				printf("Total a pagar: %f \n", sumarTotalSim() );
				// uso alternativo de una funcion que devuelve valores
				// float vtot;
				// vtot = sumarTotalSim();
				// printf("Total a pagar: %f \n", vtot );
				break;
			case 6:
				printf("Total a pagar: %f \n", sumar( 0 ) );
				break;
		} // fin de switch
		vopc = 0;
		printf("\n");
	} // Fin ciclo 
} // Fin del programa principal
