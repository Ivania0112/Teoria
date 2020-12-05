#ifndef ADMI_H
#define ADMI_H
#include <iostream>
#include "Lista.h"
#include "Clientes.h"

using namespace std;

class Admi
{
    ListaSimple<Cliente> listClientes;
public:
    Admi();
    void Registrar_Cliente();
    void Mostrar_Cliente();
    void Modificar_Cliente();
    Cliente Menu_Modificar(Cliente &c);
    void Buscar_Cliente();
    void Eliminar_Cliente();
    void swap_list(ListaSimple<Cliente> &aux);
};

#endif // ADMI_H
