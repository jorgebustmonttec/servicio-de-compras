// act-extra-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Producto {
private:
    string nombre,id,marca;
    double precio;
    int stock;
    bool existe;
    void actualizacion() {
        existe = true;
    }
public:
    Producto(){
        nombre = "indefinido";
        id = "00000";
        marca = "idefinido";
        precio = 0.00;
        stock = 0;
        existe = false;
    }
    Producto(string nombre_, string id_, string marca_, double precio_, int stock_) {
        nombre = nombre_;
        id = id_;
        marca = marca_;
        precio = precio_;
        stock = stock_;
        existe = true;
    }
    string getNombre() {
        return nombre;
    }
    string getId() {
        return id;
    }
    string getMarca() {
        return marca;
    } 
    double getPrecio() {
        return precio;
    }
    int getStock() {
        return stock;
    }
    void venta(int stock_){
        stock = stock-stock_;
    }
    void imprimirProducto() {
        cout << "Nombre: " << nombre << endl;
        cout << "ID: " << id << endl;
        cout << "Marca: " << marca << endl;
        cout << "Precio: " << precio << endl;
        cout << "Stock: " << stock << endl << endl << endl;
    }
    void imprimirProductoCorto() {
        cout << "Nombre: " << nombre << endl;
        cout << "Stock: " << stock << endl;
    }
    bool getExiste() {
        return existe;
    }
    bool buscarProducto(string busqueda) {
        if (existe) {
            if (busqueda == nombre || busqueda == id || busqueda == marca) {
                imprimirProducto();
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }
};

class Venta {
private:
    int cantidad;
    Producto producto;
public:
    Venta(int cantidad_, Producto producto_) {
        cantidad = cantidad_;
        producto = producto_;
        producto.venta(cantidad);
    }

};

int contarProductos(Producto lista[]) { //funcion que cuenta la cantidad de productos validos dentro del array de productos
    int cantidadProductos = 0;
    for (int i = 0; i < 100; i++) {
        if (lista[i].getExiste()) {
            cantidadProductos = cantidadProductos + 1;
        }
    }
    return cantidadProductos;
}



int main()
{
    Producto inventario[100]; //array para almacenar los posibles productos
    Producto test("tilin", "0001", "bethesda", 100.00, 6);
    Producto testdos("tilin", "0002", "nintendo", 200.00, 8);
    inventario[0] = test;
    inventario[1] = testdos;


    
    while (true) {
        int opcion;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "====================SISTEMA DE VENTAS CONSOLAS EL PEPE====================\n\n";
        cout << "MENU DE OPCIONES\n";
        cout << "1. imprimir Inventario\n";
        cout << "2. buscar producto\n";
        cout << "3. realizar venta\n";
        cout << "4.crear producto\n"; 
        cout << "5. cerrar programa\n";
        int cantidadProductos=contarProductos(inventario); //llamada a funcion que cuenta productos para actualizar
        cin >> opcion;
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
        if (opcion == 1) {
            for (int i = 0;i < cantidadProductos;i++) {
                if (inventario[i].getExiste()) {
                    cout << "\n" << i+1 << ". \n";
                    inventario[i].imprimirProductoCorto();
                    cout << "\n\n";
                }
            }
            if (cantidadProductos == 0) {
                cout << "\n\n\n\n\n\nNo existen productos.\n";
            }
            int x;
            while (true) {
                cout << "\n\nIngrese 0 para regresar al menu, o ingrese el numero del producto que desea imprimir.\n";
                cin >> x;
                if (x == 0) {
                    break;
                }
                else if (x <= cantidadProductos) {
                    inventario[x - 1].imprimirProducto();
                }
                else {
                    cout << "\n\nOpcion no valida, intente de nuevo.\n\n";
                }
            }
        }
        else if (opcion == 2) {
            while (true) {
                int encontrados=0;
                string elemento;
                cout << "\n\n\n\ningrese la palabra por la que desea buscar. Ingrese 0 para regresar. \n\n";
                cin >> elemento;
                if (elemento == "0") {
                    break;
                }
                else {
                    for (int i = 0; i < 100; i++) {
                        if (inventario[i].buscarProducto(elemento)) {
                            encontrados = encontrados + 1;
                        }
                    }
                    if (encontrados == 0) {
                        cout << "\nNo se encontraron productos con esos parametros.\n\n\n";
                    }
                    else {
                        cout << "\nSe encontraron " << encontrados << " productos. \n\n";
                    }

                }
            }
        }
        else if (opcion == 5) {
            break;
        }
        else {
            cout << "\n\n\n\nopcion no valida.\n\n\n";
        }
    }



}
