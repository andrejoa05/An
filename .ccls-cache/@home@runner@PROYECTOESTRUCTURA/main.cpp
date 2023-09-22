#include <cstring>
#include <iostream>
#include "LecturaDatos.h"
using namespace std;

void menu();
void pedirOpcion(int *&op);
void calcularPromedio(float *&prom);

struct Estudiante{
  char Genero;
  char Nombre[40];
  char Codigo[8]; 
  int Edad;
  float Promedio;
};

int main(){
  
  int *op = new int;
  char *gen = new char;
  int *edadP = new int;
  float *PG = new float;
  int *n = new int;

  Estudiante *Est = new Estudiante[20]; 
  do{
    menu();
    pedirOpcion(op);

    switch (*op){
    case 1: 
      {
      cout<<"_________________________________"<<endl;
      cout<<"        INGRESAR DATOS           "<<endl;
      cout<<"_________________________________"<<endl;
      
      //----------------------------------------------------
      do{
      cout<<"Ingresa la cantidad de estudiantes: ";
      *n=leedatoe();
      *n= *n + 1;
        if(*n<0)
          cout<<"Error.Vuelva a ingresar...."<<endl;
      }while(*n<0);
      //----------------------------------------------------
      
      for(int i = 1; i <= *n; i++){
        cout<<endl;
        //-------------------------------------------------------
        cout<< i <<".- Ingrese su nombre (deje en blanco para salir): ";
        cin.ignore();
        cin.getline(Est[i].Nombre, 40);

        if(strlen(Est[i].Nombre) == 0){
          cout<<"Regresando al menu"<<endl;
          break;
        }
        //-----------------------------------------------------------
        do{
          cout<<" Ingrese genero (F/M): ";
          *gen = leedatoc();
          cin.ignore();
          Est[i].Genero = *gen;

          if(*gen!='f' && *gen!='F' && *gen!='M' && *gen!='m')
            cout<<"Error, vuelva a ingresar..."<<endl;
        }while(*gen!='f' && *gen!='F' && *gen!='M' && *gen!='m');
        //-----------------------------------------------------------
        cout<<" Ingrese Codigo (DNI): ";
        cin.ignore();
        cin.getline(Est[i].Codigo, 8);
        //-----------------------------------------------------------
        do{
          cout<<" Ingrese edad: ";
          Est[i].Edad = leedatoe();
          if(Est[i].Edad <= 0 || Est[i].Edad > 100)
            cout<<"Error, vuelva a ingresar..."<<endl;
        }while(Est[i].Edad <= 0 || Est[i].Edad > 100);
        //-----------------------------------------------------------
        do{
          cout<<" Ingrese promedio general: ";
          Est[i].Promedio = leedatof();
          if(Est[i].Promedio <= 0 || Est[i].Promedio > 20)
            cout<<"Error, vuelva a ingresar..."<<endl;
        }while(Est[i].Promedio <= 0 || Est[i].Promedio > 20);
        cout<<"Datos ingresados con exito."<<endl;
        cout<<"_________________________________"<<endl;
      } // for i
    }break;

    case 2:{
      cout<<"_________________________________"<<endl;
      cout<<"        MOSTRAR A TODOS          "<<endl;
      cout<<"_________________________________"<<endl;
      cout<<"Resultados obtenidos: "<<endl;
      for(int i=1; i<*n; i++){
        cout<<"[" << i << "] Genero: " << Est[i].Genero
             << " Nombre: " << Est[i].Nombre << " Codigo: " << Est[i].Codigo
             << " Edad: " << Est[i].Edad
             << " Promedio General: " << Est[i].Promedio <<endl;
      }
      cout<<"_________________________________"<<endl;
    }break;

    case 3:{
      cout<<"_________________________________"<<endl;
      cout<<"        MOSTRAR POR EDAD         "<<endl;
      cout<<"_________________________________"<<endl;
      cout<<"Ingrese edad a consultar (0 para salir): ";
      *edadP = leedatoe();

      if(*edadP == 0)
        break;

      cout<<"Resultados para la edad: "<<*edadP<< endl;

      for(int i=1; i<*n; i++){
        if(*edadP == Est[i].Edad)
          cout<<"[" << i << "] Genero: " << Est[i].Genero
               << " Nombre: " << Est[i].Nombre << " Codigo: " << Est[i].Codigo
               << " Edad: " << Est[i].Edad
               << " Promedio General: " << Est[i].Promedio <<endl;
      }
      cout<< "_________________________________"<<endl;
    }break;

    case 4:{
      cout<<"_________________________________"<<endl;
      cout<<"        MOSTRAR POR PROMEDIO     "<<endl;
      cout<<"_________________________________"<<endl;
      cout<<"Ingrese el promedio de los estudiantes (0 para salir): ";
      *PG = leedatof();

      if(*PG == 0)
        break;

      cout<<"Resultados para el promedio: " <<*PG<<endl;

      for(int i=1; i<*n; i++) {
        if(*PG == Est[i].Promedio)
          cout<<"[" << i << "] Genero: " << Est[i].Genero
               << " Nombre: " << Est[i].Nombre << " Codigo: " << Est[i].Codigo
               << " Edad: " << Est[i].Edad
               << " Promedio General: " << Est[i].Promedio <<endl;
      }

      cout<<"_________________________________"<<endl;
    }break;

    case 5:{
      cout<<"Saliendo del programa..."<<endl;
    }break;
    }//cierre del switch

  }while(*op != 5);

  delete[] Est;
  delete op;
  delete gen;
  delete edadP;
  delete PG;
  delete n;
  return 0;
}

void menu(){
  cout<<endl<<endl;
  cout<<"_________________________________"<<endl;
  cout<<"             MENU                "<<endl;
  cout<<"_________________________________"<<endl;
  cout<<"___[1] INGRESAR DATOS ___________"<<endl;
  cout<<"___[2] MOSTRAR A TODOS___________"<<endl;
  cout<<"___[3] MOSTRAR POR EDAD__________"<<endl;
  cout<<"___[4] MOSTRAR POR PROMEDIO______"<<endl;
  cout<<"___[5] SALIR_____________________"<<endl;
  cout<<"_________________________________"<<endl;
}

void pedirOpcion(int *&op){
  do{
    cout<<"Ingrese opcion (1-5): ";
    *op=leedatoe();

    if(*op<0 || *op>5)
      cout<<"Error, ingrese una opción válida (1-5)..."<<endl;

  } while(*op<0 || *op>5);
  return;
}