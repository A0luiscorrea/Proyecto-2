//
//  Clases.h
//  Proyecto2
//
//  Created by Luis Alejandro Correa Vargas on 19/10/20.
//  Copyright © 2020 Luis Alejandro Correa Vargas. All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

    class Actor /*-----------Clase ACTOR------------*/
{
public: //Métodos
    Actor();
    Actor(int,string);//Constructor
    void setID(int i) { ID = i; };
    int getID() {return ID;};
    void setNombre(string nom) { nombre = nom; };
    string getNombre() {return nombre;};
    void muestra();

protected: //Atributos
    int ID;
    string nombre;
};
Actor::Actor()
{
    ID = 0;
    nombre = " ";
}
Actor::Actor(int i,string nom)
{
    ID = i;
    nombre = nom;
}
void Actor::muestra()
{
    cout << "ID: " << ID << endl;
    cout << "Nombre: " << nombre << endl;
}
/*--------------------------------------------------------------------*/
   class Hora /*-----------Clase Hora------------*/
{
public: //Métodos
    Hora();
    Hora(int,int);//Constructor
    void setHora(int h) {hora = h;};
    int getHora() {return hora;};
    void setMinutos(int m) {minutos = m;};
    int getMinutos() {return minutos;};
    void muestra();

protected: //Atributos
    int hora,minutos;
    
};
Hora::Hora()
{
    hora = 0;
    minutos = 0;
}
Hora::Hora(int h,int m)
{
    hora = h;
    minutos = m;
}
void Hora::muestra()
{
    cout << endl;
    cout << "Hora->" << hora << ":" << minutos << endl;
}
/*--------------------------------------------------------------------*/
class Funcion : public Hora/*-----------Clase Funcion------------*/
{
public: //Métodos
    Funcion();
    Funcion(string,int,Hora h,int);//Constructor
    void setSala(int s) { sala = s; };
    void setHora(Hora hr);
    Hora getHora(){return horas;};
    int getSala() {return sala;};
    void setNumpeli(int np) { numpeli = np; };
    int getNumpeli() {return numpeli;};
    void setClave(string clave) { cveFuncion = clave; };
    string getClave() {return cveFuncion;};
    void muestra();

private: //Atributos
    Hora horas;
    int sala,numpeli;
    string cveFuncion;
};
Funcion::Funcion()
{
    cveFuncion = " ";
    numpeli = 0;
    Hora arrHora[20];
    horas = arrHora[19];
    sala = 0;
}
Funcion::Funcion(string clave,int np,Hora h,int s)
{
    horas = h;
    cveFuncion = clave;
    numpeli = np;
    sala = s;
}
void Funcion::muestra()
{
    cout << endl;
    cout << "Clave: " << cveFuncion << endl;
    cout << "Número de película: " << numpeli << endl;
    cout << "Sala: " << sala << endl;
    cout << "*---------------------------------------*" << endl;
}
/*--------------------------------------------------------------------*/
   class Pelicula /*-----------Clase Pelicula------------*/
{
public: //Métodos
    Pelicula();
    Pelicula(int,string,int,int,string,int,Actor act);//Constructor
    void setlistaActores(Actor ac);
    Actor getlistaActores() {return listaActores;};
    void setNumeroP(int np) {numPelicula = np;};
    int getNumeroP() {return numPelicula;};
    void setTitulo(string t) { titulo = t; };
    string getTitulo() {return titulo;};
    void setAnio(int a) { anio = a; };
    int getAnio() {return anio;};
    void setDuracion(int d) { duracion = d; };
    int getDuracion() {return duracion;};
    void setGenero(string g) { genero = g; };
    string getGenero() {return genero;};
    int getCantActores() {return cantActores;};
    void muestra();
    bool agregarActor();

private: //Atributos
    Actor listaActores;
    int numPelicula,anio,duracion,cantActores;
    string titulo,genero;
};
Pelicula::Pelicula()
{
    numPelicula = 0;
    titulo = " ";
    anio = 0;
    duracion = 0;
    genero = " ";
    cantActores = 0;
    Actor arrActores[10];
    listaActores = arrActores[9];
}
Pelicula::Pelicula(int np,string t,int a,int d,string g,int ca,Actor ac)
{
    numPelicula = np;
    titulo = t;
    anio = a;
    duracion = d;
    genero = g;
    cantActores = ca;
    listaActores = ac;
}
void Pelicula::muestra()
{
    //cout << "Número de Película: " << numPelicula << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Año: " << anio << endl;
    cout << "Duración: " << duracion << " minutos" << endl;
    cout << "Género: " << genero << endl;
    cout << "*------------------------------------*" << endl;;
    //cout << "Cantidad Actores: " << cantActores << endl;
    //cout << "Lista de Actores: " << listaActores.getNombre() << endl;
}
bool Pelicula::agregarActor()
{
    string n_actor;
    if(cantActores>=9)
    {
        return false;
    }
    else
    {
    cout << "Ingresa el nombre del actor: ";
    cin >> n_actor;
    listaActores.setNombre(n_actor);
    cantActores++;
        return true;
    }
}
