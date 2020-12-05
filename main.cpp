#include <iostream>
#include "Admi.h"

using namespace std;

int main()
{
    int op;
    Admi c;

    do {
        system("cls");
        cout<<endl<<"**MENU DE OPCIONES** "<<endl;
        cout<<"1.- Agregar nuevo cliente"<<endl;
        cout<<"2.- Mostrar clientes"<<endl;
        cout<<"3.- Modificar cliente "<<endl;
        cout<<"4.- Buscar cliente "<<endl;
        cout<<"5.- Eliminar cliente"<<endl;
        cout<<"0.- Salir"<<endl;
        cout<<"Selecciona una opcion: "<<endl;
        cin>> op;
        switch (op) {
        case 1:
            c.Registrar_Cliente();
            system("pause");
            break;
        case 2:
            c.Mostrar_Cliente();
            system("pause");
            break;
        case 3:
            c.Modificar_Cliente();
            system("pause");
            break;
        case 4:
            c.Buscar_Cliente();
            system("pause");
            break;
        case 5:
            c.Eliminar_Cliente();
            system("pause");
            break;
        }
    }while (op != 0);
}

