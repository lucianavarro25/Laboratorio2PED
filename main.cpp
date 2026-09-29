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

void eliminarIntermedio()
{
    if (inicio == nullptr)
    {
        cout << "\nEl inventario esta vacio.\n";
        return;
    }
  int codigo;

    cout << "\n=== ELIMINAR PRODUCTO INTERMEDIO ===\n";
    cout << "Ingrese el codigo del producto: ";
    cin >> codigo;

    Nodo *actual = inicio;

    while (actual != nullptr)
    {
        if (actual->producto.codigo == codigo)
        {
            // Verificar que el nodo sea intermedio
            if (actual == inicio || actual->siguiente == nullptr)
            {
                cout << "\nEl producto seleccionado no es intermedio.\n";
                return;
            }

            // Conectar el nodo anterior con el siguiente
            actual->anterior->siguiente = actual->siguiente;

            // Conectar el nodo siguiente con el anterior
            actual->siguiente->anterior = actual->anterior;

            // Liberar memoria
            delete actual;

            cout << "\nProducto eliminado correctamente.\n";
            return;
        }

        actual = actual->siguiente;
    }

    cout << "\nProducto no encontrado.\n";
}


//FUNCION PARA IMPRIMIR LA LISTA
void imprimir()
{
    if (inicio == nullptr)
    {
        cout << "El inventario esta vacio." << endl;
        return;
    }

    cout << "\nINVENTARIO DE PRODUCTOS" << endl;

    Nodo *actual = inicio;

    while (actual != nullptr)
    {
        cout << "\nCodigo: " << actual->producto.codigo << endl;
        cout << "Nombre: " << actual->producto.nombre << endl;
        cout << "Precio: $" << actual->producto.precio << endl;

        actual = actual->siguiente;
    }
}