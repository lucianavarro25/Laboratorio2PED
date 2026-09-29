#include <iostream>
#include <string>

using namespace std;

struct Producto
{
    int codigo;
    string nombre;
    float precio;
};

struct Nodo
{
    Producto producto;
    Nodo *siguiente;
    Nodo *anterior;
};

Nodo *inicio = nullptr;

// declaracion de funciones
void insertarInicio();
void eliminarIntermedio();
void imprimir();

int main()
{
    int opcion;

    do
    {
        cout << "\nINVENTARIO DE PRODUCTOS \n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Eliminar intermedio\n";
        cout << "3. Imprimir inventario\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            insertarInicio();
            break;

        case 2:
            eliminarIntermedio();
            break;

        case 3:
            imprimir();
            break;

        case 0:
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);

    return 0;
}
//primera funcion insertar inicio

void insertarInicio()
{
    Nodo *nuevo = new Nodo;

    cout << "\nINSERTAR PRODUCTO AL INICIO \n";

    cout << "Codigo: ";
    cin >> nuevo->producto.codigo;
    cin.ignore();

    cout << "Nombre: ";
    getline(cin, nuevo->producto.nombre);

    cout << "Precio: ";
    cin >> nuevo->producto.precio;

    nuevo->anterior = nullptr;
    nuevo->siguiente = inicio;

    if (inicio != nullptr)
    {
        inicio->anterior = nuevo;
    }

    inicio = nuevo;

    cout << "Producto insertado correctamente.\n";
}