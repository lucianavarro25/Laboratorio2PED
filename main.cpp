#include <iostream>
#include <string>

using namespace std;

// Struct para almacenar los datos del producto
struct Producto
{
    int codigo;
    string nombre;
    float precio;
};

// Struct Nodo - Representa cada nodo de la lista
struct Nodo
{
    Producto producto;
    Nodo *siguiente;
    Nodo *anterior;
};

// Puntero global al primer nodo
Nodo *inicio = nullptr;

// Declaraciones de funciones
void insertarInicio();
void insertarFinal();
void imprimir();

int main()
{
    int opcion;

    do
    {
        cout << "\n=== Inventario de Productos ===\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Imprimir inventario\n";
        cout << "0. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            insertarInicio();
            break;

        case 2:
            insertarFinal();
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

// Insertar un producto al inicio de la lista
void insertarInicio()
{
    Producto nuevoProducto;

    cout << "\n--- Insertar producto al inicio ---\n";

    cout << "Codigo: ";
    cin >> nuevoProducto.codigo;
    cin.ignore();

    cout << "Nombre: ";
    getline(cin, nuevoProducto.nombre);

    cout << "Precio: ";
    cin >> nuevoProducto.precio;

    Nodo *nuevoNodo = new Nodo;

    nuevoNodo->producto = nuevoProducto;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = inicio;

    if (inicio != nullptr)
    {
        inicio->anterior = nuevoNodo;
    }

    inicio = nuevoNodo;

    cout << "Producto agregado al inicio correctamente.\n";
}