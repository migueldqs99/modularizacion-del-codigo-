#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

struct Producto {
    string codigo;
    string nombre;
    int cantidad;
    Producto():codigo(""),nombre(""),cantidad(0){}
    Producto(string c,string n,int q):codigo(c),nombre(n),cantidad(q){}
};

int buscarProducto(const vector<Producto>& inv,string cod){
    for(int i=0;i<inv.size();i++){
        if(inv[i].codigo==cod) return i;
    }
    return -1;
}

void limpiarEntrada(){
    cin.clear();
    cin.ignore(10000,'
');
}

int leerEntero(string msg){
    int v;
    while(true){
        cout<<msg;
        if(cin>>v){ limpiarEntrada(); return v; }
        cout<<"Entrada invalida
";
        limpiarEntrada();
    }
}

string leerLinea(string msg){
    cout<<msg;
    string s;
    getline(cin,s);
    return s;
}

void mostrarMenu(){
    cout<<"
1 Agregar
2 Listar
3 Actualizar
4 Reporte
0 Salir
";
}

void agregarProducto(vector<Producto>& inv){
    string cod;
    cout<<"Codigo: "; cin>>cod; limpiarEntrada();
    if(buscarProducto(inv,cod)!=-1){ cout<<"Ya existe
"; return; }
    string nom=leerLinea("Nombre: ");
    int cant=leerEntero("Cantidad: ");
    Producto p(cod,nom,cant);
    inv.push_back(p);
}

void listarProductos(const vector<Producto>& inv){
    for(int i=0;i<inv.size();i++){
        cout<<inv[i].codigo<<" "<<inv[i].nombre<<" "<<inv[i].cantidad<<"
";
    }
}

void actualizarCantidad(vector<Producto>& inv){
    string cod; cout<<"Codigo: "; cin>>cod; limpiarEntrada();
    int pos=buscarProducto(inv,cod);
    if(pos==-1){ cout<<"No encontrado
"; return; }
    inv[pos].cantidad=leerEntero("Nueva cantidad: ");
}

void reporte(vector<Producto>& inv){
    int lim=leerEntero("Limite: ");
    for(int i=0;i<inv.size();i++){
        if(inv[i].cantidad<=lim)
            cout<<inv[i].codigo<<" "<<inv[i].nombre<<" "<<inv[i].cantidad<<"
";
    }
}

int main(){
    vector<Producto> inv;
    int op;
    do{
        mostrarMenu();
        cin>>op;
        switch(op){
            case 1: agregarProducto(inv); break;
            case 2: listarProductos(inv); break;
            case 3: actualizarCantidad(inv); break;
            case 4: reporte(inv); break;
        }
    }while(op!=0);
}
