//
//  main.cpp
//  Proyecto2
//
//  Created by Luis Alejandro Correa Vargas on 19/10/20.
//  Copyright © 2020 Luis Alejandro Correa Vargas. All rights reserved.
//

#include <iostream>
#include "Clases.h"
#include <string>
#include <fstream>
using namespace std;
int id1,id2,id3,id4,id5;
int main()
{
    
    Actor arrActores[20];
    Pelicula arrPeliculas[20];
    Hora arrHora[20];
    Funcion arrFunciones[20];
    //F1.muestra();
    //P1.agregarActor();
    //P1.muestra();
    ifstream archEntAct;
    int ID,cont=0;
    string nombre,apellido,nc;
    archEntAct.open("actores.txt");
    while (archEntAct >> ID >> nombre >> apellido)
    {
        nc = nombre + " " + apellido;
            arrActores[cont].setID(ID);
            arrActores[cont].setNombre(nc);
        cont++;
    }
    archEntAct.close();
    ifstream archEntPel;
    
    string linea;
    int pos=0,np,anio,dur,act;
    string gen,t;
    int cont1=0;
    archEntPel.open("peliculas.txt");
    while (getline(archEntPel,linea))
    {
        //cout << linea << endl;
        //AÑO
        anio = stod(linea.substr(4,4));
        arrPeliculas[cont1].setAnio(anio);
        //DURACION
        dur = stod(linea.substr(9,3));
        arrPeliculas[cont1].setDuracion(dur);
        //NUMERO DE PELICULA
        np=stod(linea.substr(0,3));
        arrPeliculas[cont1].setNumeroP(np);
        arrFunciones[cont1].setNumpeli(np);
        
        //BORRA LOS PRIMEROS DATOS
        linea.erase(0,13);
        //GENERO
        pos = linea.find(' ');
        gen = linea.substr(0,pos);
        arrPeliculas[cont1].setGenero(gen);
        //BORRA EL GENERO
        linea.erase(0,pos+1);
        //CANTIDAD DE ACTORES
        act = stod(linea.substr(0,1));
        //ID DE ACTORES
        if(act == 4)
        {
            id1 = stod(linea.substr(2,2));
            id2 = stod(linea.substr(5,2));
            id3 = stod(linea.substr(8,2));
            id3 = stod(linea.substr(11,2));
            linea.erase(0,14);
            arrActores[cont1].setID(id1);
            arrActores[cont1].setID(id2);
            arrActores[cont1].setID(id3);
            arrActores[cont1].setID(id4);
        }
        if(act == 3)
        {
            id1 = stod(linea.substr(2,2));
            id2 = stod(linea.substr(5,2));
            id3 = stod(linea.substr(8,2));
            linea.erase(0,11);
            arrActores[cont1].setID(id1);
            arrActores[cont1].setID(id2);
            arrActores[cont1].setID(id3);
        }
        if(act==2)
        {
            id1 = stod(linea.substr(2,2));
            id2 = stod(linea.substr(5,2));
            linea.erase(0,8);
            arrActores[cont1].setID(id1);
            arrActores[cont1].setID(id2);
        }
        if(act==1)
        {
            id1 = stod(linea.substr(2,2));
            linea.erase(0,5);
            arrActores[cont1].setID(id1);
        }
        t = linea;
        arrPeliculas[cont1].setTitulo(t);
        cont1++;
    }
    archEntPel.close();
    int h,m,sala;
    string clave;
    for(int i=0;i<=5;i++)
    {
        cout << "Ingrese la clave de la función " << i+1 << ": ";
        cin >> clave;
        arrFunciones[i].setClave(clave);
    }
    for(int i=0;i<=5;i++)
       {
           cout << "Ingrese la sala de la función " << i+1 << ": ";
           cin >> sala;
           arrFunciones[i].setSala(sala);
       }
    for(int i=0;i<=5;i++)
       {
           cout << "Ingrese la hora de la función " << i+1<<endl;;
           cout << "Hora: ";
           cin >> h;
           cout << "Minutos: ";
           cin >> m;
           arrHora[i].setHora(h);
           arrHora[i].setMinutos(m);
       }
    /*for(int i=0;i<=19;i++)
    {
        cout << arrFunciones[i].getClave() << endl;
    }*/
    //Prueba para ver si guarda los datos correctamente//
    /*for(int i=0;i<=19;i++)
    {
    cout << arrActores[i].getID() << " ";
    cout << arrActores[i].getNombre() << endl;
    }
     */
    //------------------MENU-------------------/
    char op;
    while(op!='g')
    {
    cout << "a) Consulta de todos los actores de la lista." << endl;
    cout << "b) Peliculas Disponibles" << endl;
    cout << "c) Funciones Disponibles" << endl;
    cout << "d) Consultar funciones por hora" << endl;
    cout << "e) Consultar por clave de función" << endl;
    cout << "f) Consultar por actor participante" << endl;
    cout << "g) Salir" << endl;
    cout << "Seleccione una opción para continuar: ";
    cin >> op;
        if(op=='a')
        {
            cout << "*-----LISTA DE ACTORES-----*" << endl;
            cout << "*--ID------NOMBRE--------*" << endl;
            for(int i=0;i<=19;i++)
            {
                
                cout <<"   " << arrActores[i].getID() << " ";
                cout << "     " <<arrActores[i].getNombre() << endl;
            }
        }
        if(op=='b')
        {
            cout << "*---------PELICULAS DISPONIBLES--------*"<< endl;
            for(int i=0;i<=19;i++)
            {
                arrPeliculas[i].muestra();
            }
        }
        if(op=='c')
        {
            cout << "*---------FUNCIONES DISPONIBLES--------*"<< endl;
            for(int i=0;i<=19;i++)
            {
                cout << "Título: " << arrPeliculas[i].getTitulo() << endl;
                cout << "Hora: " << arrHora[i].getHora()<<":"<<arrHora[i].getMinutos();
                arrFunciones[i].muestra();
            }
        }
        if(op=='d')
        {
            int h,m;
            cout << "Ingrese la hora y minutos de la función que desea buscar" << endl;
            cout << "Hora: ";
            cin >> h;
            cout << "Minutos: ";
            cin >> m;
            for(int i=0;i<=19;i++)
            {
                if((arrHora[i].getHora()==h)&&(arrHora[i].getMinutos()==m))
                {
                    cout << "-------------------------------------------" << endl;
                    cout << "Título: " << arrPeliculas[i].getTitulo() << endl;
                    cout << "Sala: " << arrFunciones[i].getSala() << endl;
                    cout << "-------------------------------------------" << endl;
                }
            }
        }
        if(op=='e')
        {
            string c;
            cout << "Ingrese la clave de la película a buscar: ";
            cin >> c;
            
            for(int i=0;i<=19;i++)
            {
                if(arrFunciones[i].getClave()==c)
                {
                    cout << "-------------------------------------------" << endl;
                    cout << "Sala: " <<  arrFunciones[i].getSala() << endl;;
                    cout << "Título: " << arrPeliculas[i].getTitulo() << endl;
                    cout << "Hora: " << arrHora[i].getHora() << ":" << arrHora[i].getMinutos()<< endl;
                    cout << "Duración: " << arrPeliculas[i].getDuracion() << endl;
                    cout << "Género: " << arrPeliculas[i].getGenero() << endl;
                    cout << "-------------------------------------------" << endl;
                }
            }
        }
        if(op=='f')
        {
            int id;
            cout << "Ingrese el ID del actor: ";
            cin >> id;
            for(int i=0;i<=19;i++)
            {
                if(arrActores[i].getID()==id)
                {
                    cout << "-------------------------------------------" << endl;
                    cout << "Película: " << arrPeliculas[i].getTitulo() << endl;
                    cout << "Año: " << arrPeliculas[i].getAnio() << endl;
                    cout << "-------------------------------------------" << endl;
                }
            }
        }
    }
    return 0;
}
