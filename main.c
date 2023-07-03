/*Se debe crear un software para la agencia de autos KALX, con un menú de 3 opciones (variable tipo entero) venta, compra y salir;
las operaciones se pueden repetir las veces que el usuario desee, hasta seleccionar la opción “Salir”.
Para el módulo de ventas se solicita los datos de marca (variable tipo texto), modelo (variable tipo texto),
precio base venta (variable tipo decimal), porcentaje descuento (variable tipo decimal) y vendedor (variable tipo texto).
El porcentaje descuento será de 5% si el precio del vehículo es menor a $100,000.00,
8% si el precio está entre $170,000.00 y $250,000.00 o de 10% si el precio es mayor a $300,000.00.
Para el módulo de compras se solicita los datos de narca (variable tipo texto), modelo (variable tipo texto),
precio compra (variable tipo decimal) y porcentaje aumento para venta base (constante tipo decimal) del 20%.*/

//Directivas al procesador
#include <stdio.h>//Funciones de entrada y salida
#include <stdlib.h>//Funciones del sistema
#include <locale.h>//Funciones de formato de acuerdo a la configuración regional

//Prototipos de las funciones
//Función de venta de autos
void ventaAutos();

//Función de compra de autos
void compraAutos();

//Función Principal
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "");
    int opMenu;

    do//Se ejecuta el ciclo, minimo una vez.
	{//Impresión del menú
	    system("cls");//Instrucción para borrar la pantalla

	    //Imprimir los datos del desarrollador
	    printf("UNIVERSIDAD ABIERTA Y A DISTANCIA DE MEXICO\n");
	    printf("ASIGNATURA: FUNDAMENTOS DE PROGRAMACION\n");
	    printf("NOMBRE: Eduardo Damián Ramírez Paniagua\n");
	    printf("MATRICULA: ES231103942\n\n");
	    //Imprimir el menú
	    printf("**********VENTA Y COMPRA DE AUTOS**********\n");
		printf("¿QUE OPCION DESEA?:\n");
		printf("1.- VENTA DE AUTOS.\n");
		printf("2.- COMPRA DE AUTOS.\n");
		printf("3.- SALIR.\n");
		scanf("%d", &opMenu);

        switch (opMenu)
		{
			case 1:
				ventaAutos();//Mandamos llamar el método de venta de autos
				system("pause");
				break;

			case 2:
				compraAutos();//Mandamos llamar el método de compra de autos
				system("pause");
				break;

			case 3:
				printf("Adiós.\n");
				break;

	 		default:
				printf("Opción no valida.\n");
				system("pause");
		}
	} while (opMenu != 3);//Repetimos el ciclo hasta que la opción del menú sea la 3, que es salir.

	system("pause");
	return 0;
}

//Definición de funciones
//Método de venta de autos
void ventaAutos()
{
	float precVenta, porcenDesc;
    char marcaAuto[20], modAuto[20], vendAuto[100];

    printf("INGRESA LA MARCA DE AUTO:\n");
	scanf("%s", &marcaAuto);
    printf("INGRESA EL MODELO DE AUTO:\n");
	scanf("%s", &modAuto);
    printf("INGRESA EL PRECIO BASE DEL AUTO:\n");
	scanf("%f", &precVenta);
    printf("INGRESA EL PORCENTAJE DE DESCUENTO DEL AUTO:\n");
	scanf("%f", &porcenDesc);
    printf("INGRESA EL NOMBRE DEL VENDEDOR:\n");
	scanf("%s", &vendAuto);

	printf("EL AUTO CON LA MARCA:%s, MODELO:%s, CON PRECIO BASE DE: $%.2f\n", marcaAuto, modAuto, precVenta);
	//Deberá calcular el precio final del auto tomando en cuenta su descuento capturado.
	printf("TIENE UN PRECIO FINAL CON SU DESCUENTO DE: $%.2f\n", precVenta - ((precVenta/100) * porcenDesc));

    //En c no se encuentra mayor que con el uso de switch
	/*switch ((int)precVenta)
	{
		case 1 ... 100000:
			printf("EL VENDEDOR %s TIENE UNA COMISION POR SU VENTA DE: $%.2f\n", vendAuto, (precVenta/100) * 5);
			break;

		case 170000 ... 250000:
			printf("EL VENDEDOR %s TIENE UNA COMISION POR SU VENTA DE: $%.2f\n", vendAuto, (precVenta/100) * 8);
			break;

		//En c no se encuentra mayor que con el uso de switch
		case precVenta > 300000:
			printf("EL VENDEDOR %s TIENE UNA COMISION POR SU VENTA DE: $%.2f\n", vendAuto, (precVenta/100) * 10);
			break;

 		default:
			printf("EL VENDEDOR %s TIENE UNA COMISION POR SU VENTA DE: $0\n", vendAuto);
	}*/

	//Se usa validaciones por medio de if por el problema presentado en el uso de switch
	//Deberá mostrar la comisión del vendedor.
	if(precVenta < 100000)//5% si el precio del vehículo es menor a $100,000.00
		printf("EL VENDEDOR %s TIENE UNA COMISION POR SU VENTA DE: $%.2f\n", vendAuto, (precVenta/100) * 5);
	else if (precVenta > 170000 && precVenta < 250000)//8% si el precio está entre $170,000.00 y $250,000.00
		printf("EL VENDEDOR %s TIENE UNA COMISION POR SU VENTA DE: $%.2f\n", vendAuto, (precVenta/100) * 8);
	else if (precVenta > 300000)//10% si el precio es mayor a $300,000.00
		printf("EL VENDEDOR %s TIENE UNA COMISION POR SU VENTA DE: $%.2f\n", vendAuto, (precVenta/100) * 10);
	else//Rangos no definidos
		printf("EL VENDEDOR %s TIENE UNA COMISION POR SU VENTA DE: $0\n", vendAuto);
}

//Método de compra de autos
void compraAutos()
{
    const float porcenAum = 20;

    float precCompra;
    char marcaAuto[20], modAuto[20];

    printf("INGRESA LA MARCA DE AUTO:\n");
	scanf("%s", &marcaAuto);
    printf("INGRESA EL MODELO DE AUTO:\n");
	scanf("%s", &modAuto);
    printf("INGRESA EL PRECIO DE AUTO:\n");
	scanf("%f", &precCompra);

	//Deberá calcular el precio de venta final del auto, tomando en cuenta el 20% de aumento sobre su precio base.
	printf("EL AUTO CON LA MARCA:%s, MODELO:%s, TIENE UN PRECIO DE VENTA DE: $%.2f\n", marcaAuto, modAuto, precCompra + ((precCompra/100) * porcenAum));
}
