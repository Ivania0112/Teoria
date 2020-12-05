#include "Admi.h"
#include <iostream>
#include <regex>
#include <cstdlib>

using namespace std;
void Admi::Registrar_Cliente()
{
    Cliente c;
    string s,nombre,rfc,cor;
    int edad,cp,tel;
    regex re_nombre("^([A-Z]{1}[a-z]+\\s){2,}([A-Z]{1}[a-z]+)$");
    bool nombre_incorrecto = true;
    while(nombre_incorrecto){
        cout << "Introduce el nombre: ";
        getline(cin, nombre);
        if(regex_match(nombre, re_nombre)){
            c.setNombre(nombre);
            nombre_incorrecto = false;
        }else{
            cout << "Introduce un nombre valido" << endl;
        }
    }
    regex re_rfc("^[A-Z]{4}[0-9]{3}$");
    bool rfc_incorrecto = true;
    while(rfc_incorrecto){
        cout << "RFC: ";
        getline(cin, rfc);
        
        if(regex_match(rfc, re_rfc)){
            c.setRfc(rfc);
            rfc_incorrecto = false;
        }else{
            cout << "Introduce un RFC valido" << endl;
        }
    }

    cout << "Direccion: ";
    getline(cin,s);
    c.setDireccion(s);

    cout << "Codigo Postal: ";
    cin >> cp;
    c.setCp(cp);

    cout << "Colonia: ";
    cin.ignore();
    getline(cin,s);
    c.setColonia(s);

    cout << "Municipio: ";
    cin.ignore();
    getline(cin,s);
    c.setMunicipio(s);

    cout << "Estado: ";
    cin.ignore();
    getline(cin,s);
    c.setEstado(s);

    regex re_tel("^[A-Z]{4}[0-9]{3}$");
    bool tel_incorrecto = true;
    while(tel_incorrecto){
        cout << "Telefono: ";
        cin>>tel;
        
        if(regex_match(nombre, re_tel)){
            c.setTel(tel);
            tel_incorrecto = false;
        }else{
            cout << "Introduce un telefono valido" << endl;
        }
    }


    regex re_cor("^[A-Za-z0-9.'-'_]+@[A-Za-z\.]+\.[A-Za-z]{2,4}$");
    bool cor_incorrecto = true;
    while(cor_incorrecto){
        cout << "Correo: ";
        getline(cin, cor);
        c.setCorreo(cor);

        if(regex_match(cor, re_cor)){
            cout << "El correo introducido es valido: " << cor << endl;
            cor_incorrecto = false;
        }else{
            cout << "Introduce un correo valido" << endl;
        }
    }

    cout << "Genero: ";
    cin.ignore();
    getline(cin,s);
    c.setGenero(s);

    cout << "Edad: ";
    cin >> edad;
    c.setEdad(edad);

    cout << "Tipo de cliente: ";
    cin.ignore();
    getline(cin,s);
    c.setTipo(s);

    listClientes.push_back(c);

}

void Admi::Mostrar_Cliente()
{
    if(!listClientes.empty()){

        for(size_t i=0; i < listClientes.size() ; i++){
            cout << listClientes[i];
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
}

void Admi::Modificar_Cliente()
{
    string rfc;
    cout << "RFC a modificar: ";
    cin.ignore();
    getline(cin,rfc); cout<<endl;

    if(!listClientes.empty()){
        Cliente aux;
        bool band = false;
        size_t pos;
        for(size_t i=0; i < listClientes.size() ; i++){
            if(listClientes[i].getRfc() == rfc){
                aux = listClientes[i];
                band = true;
                pos = i;
                break;
            }
        }
        if(band){
           aux = Menu_Modificar(aux);
           //listClientes[pos] = aux;
           ListaSimple<Cliente> listaux;
           for(size_t i=0; i < listClientes.size() ;i++){
               if(i == pos){
                   listaux.push_back(aux);
               }else{
                   listaux.push_back(listClientes[i]);
               }
           }
           swap_list(listaux);

        }
        else{
            cout<<"No se encontro dicho cliente"<<endl;
        }
    }else{
        cout<<"Lista vacia"<<endl;
    }
}

Cliente Admi::Menu_Modificar(Cliente &c)
{
    int opc;
    int edad,cp,tel;
    string s;
    do {
        cout<<endl<<"Que desea modificar? "<<endl;
        cout<<"1.- Nombre "<<endl;
        cout<<"2.- RFC "<<endl;
        cout<<"3.- Direccion "<<endl;
        cout<<"4.- Codigo Postal "<<endl;
        cout<<"5.- Colonia "<<endl;
        cout<<"6.- Municipio "<<endl;
        cout<<"7.- Estado "<<endl;
        cout<<"8.- Telefono "<<endl;
        cout<<"9.- Correo "<<endl;
        cout<<"10.- Genero "<<endl;
        cout<<"11.- Edad "<<endl;
        cout<<"12.- Tipo de cliente "<<endl;
        cout<<"0.- Salir"<<endl;
        cout<<"Elige tu opcion: "<<endl;
        cin>> opc;

        switch (opc) {
        case 1:
            cout << "Nombre: ";
            cin.ignore();
            getline(cin,s);cout<<endl;
            c.setNombre(s);
            break;
        case 2:
            cout << "RFC: ";
            cin.ignore();
            getline(cin,s);
            cout<<endl;
            c.setRfc(s);
            break;
        case 3:

            cout << "Direccion: ";
            cin.ignore();
            getline(cin,s);
            cout<<endl;
            c.setDireccion(s);
            break;
        case 4:
            cout << "Codigo Postal: ";
            cin.ignore();
            cin >> cp;
            cout<<endl;
            c.setCp(cp);
            break;
        case 5:
            cout << "Colonia: ";
            cin.ignore();
            getline(cin,s);cout<<endl;
            c.setColonia(s);
            break;
        case 6:
            cout << "Municipio: ";
            cin.ignore();
            getline(cin,s);cout<<endl;
            c.setMunicipio(s);
            break;
        case 7:
            cout << "Estado: ";
            cin.ignore();
            getline(cin,s);cout<<endl;
            c.setEstado(s);
            break;
        case 8:
            cout << "Telefono: ";
            cin.ignore();
            cin>>tel;
            cout<<endl;
            c.setTel(tel);
            break;
        case 9:
            cout << "Correo: ";
            cin.ignore();
            getline(cin,s);cout<<endl;
            c.setCorreo(s);
            break;
        case 10:
            cout << "Genero: ";
            cin.ignore();
            getline(cin,s);cout<<endl;
            c.setGenero(s);
            break;
        case 11:
            cout << "Edad: ";
            cin.ignore();
            cin >> edad;
            cout<<endl;
            c.setEdad(edad);
            break;
        case 12:
            cout << "Tipo de cliente: ";
            cin.ignore();
            getline(cin,s);cout<<endl;
            c.setTipo(s);
            break;
        }
    }while (opc != 0);

    return c;
}

void Admi::Buscar_Cliente()
{
    if(!listClientes.empty()){

        string rfc;
        cout << "RFC a buscar: ";
        cin.ignore();
        getline(cin,rfc); cout<<endl;
        bool b = false;
        Cliente aux;
        for(size_t i=0; i < listClientes.size() ; i++){
            if(listClientes[i].getRfc() == rfc){
                aux = listClientes[i];
                b = true;
                break;
            }
        }
        if(b)
            cout<<aux;
        else
            cout<<"No se encontro el elemento"<<endl;

    }else{
        cout<<"Lista vacia"<<endl;
    }
}

void Admi::Eliminar_Cliente()
{
    if(!listClientes.empty()){

        string rfc;
        cout << "RFC a eliminar: ";
        cin.ignore();
        getline(cin,rfc); cout<<endl;

        ListaSimple<Cliente> listaux;
        Cliente aux;
        for(size_t i=0; i < listClientes.size() ; i++){
            if(listClientes[i].getRfc() != rfc){
                aux = listClientes[i];
                listaux.push_back(aux);
                break;
            }
        }
        swap_list(listaux);
        cout<<"Cliente eliminado"<<endl;

    }else{
        cout<<"Lista vacia"<<endl;
    }
}

void Admi::swap_list(ListaSimple<Cliente> &aux)
{
    listClientes.clear();

    if(!aux.empty()){
        for(size_t i=0; i < aux.size() ;i++){
            listClientes.push_back(aux[i]);
        }
    }
}

Admi::Admi()
{

}