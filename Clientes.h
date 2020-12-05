#ifndef CLIENTES_H
#define CLIENTES_H
#include <iostream>
#include <iomanip>
#include "Lista.h"
using namespace std;

class Cliente
{
private:
    string nombre;
    string rfc;
    string direccion;
    int cp;
    string colonia;
    string municipio;
    string estado;
    int tel;
    string correo;
    string genero;
    int edad;
    string tipo;
public:
    Cliente();
    void setNombre(const string &c);
    string getNombre();
    void setRfc(const string &c);
    string getRfc();
    void setDireccion(const string &c);
    string getDireccion();
    void setCp(int c);
    int getCp();
    void setColonia(const string &c);
    string getColonia();
    void setMunicipio(const string &c);
    string getMunicipio();
    void setEstado(const string &c);
    string getEstado();
    void setTel(int c);
    int getTel();
    void setCorreo(const string &c);
    string getCorreo();
    void setGenero(const string &c);
    string getGenero();
    void setEdad(int c);
    int getEdad();
    void setTipo(const string &c);
    string getTipo();

    friend ostream & operator<<(ostream &out, const Cliente &c){

        out<<"Nombre: "<<c.nombre<<endl;
        out<<"RFC: "<<c.rfc<<endl;
        out<<"Direccion: "<<c.direccion<<endl;
        out<<"Codigo Postal: "<<c.cp<<endl;
        out<<"Colonia: "<<c.colonia<<endl;
        out<<"Municipio: "<<c.municipio<<endl;
        out<<"Estado: "<<c.estado<<endl;
        out<<"Telefono: "<<c.tel<<endl;
        out<<"Correo: "<<c.correo<<endl;
        out<<"Genero: "<<c.genero<<endl;
        out<<"Edad: "<<c.edad<<endl;
        out<<"Tipo de Cliente: "<<c.tipo<<endl<<endl;

        return out;
    }
    


};

#endif // CLIENTE_H