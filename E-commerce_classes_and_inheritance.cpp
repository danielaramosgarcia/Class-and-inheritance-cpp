/* Daniela Ramos García A01174259
29 de noviembre del 2021
Este programa planea ser una simulacion simple de una pagina de E-commerce de articulos
de salud y bienestar donde pueden ingresar tanto clientes como proveedores para 
vender y comprar articulos. */
#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;
class producto{
protected:
 int precio,clave;
 double descuento, peso;
 public:
 void setprecio(int prec){
 precio=prec;
 }
 void setclave(int clav){
 clave=clav;
 }
 void setdescuento(double desc){
 descuento=desc;
 }
 void setpeso(double pes){
 peso=pes;
 }
 int getprecio(){
 return precio;
 }
 int getclave(){
 return clave;
 }
 double getdescuento(){
 return descuento;
 }
 double getpeso(){
 return peso;
 }
};
class cliente:public producto{
 protected:
 string nombre,direccion;
 int cuentabanco;
 public:
 void setNombre(string nom){
 nombre=nom;
 }
 void setcuentabanco(int cuentb){
 cuentabanco=cuentb;
 }
 void setdireccion(string direc){
 direccion=direc;
 }
 string getnombre(){
 return nombre;
 }
 int getcuentabanco(){
 return cuentabanco;
 }
 string getdireccion(){
 return direccion;
 }
};
class proveedor:public producto{
 protected:
 string direccion,categoria,nombre;
 int tiempo_entrega;
 public:
 void settiempo_entrega(int tiempoe){
 tiempo_entrega=tiempoe;
 }
 void setdireccion(string direc){
 direccion=direc;
 } 
 void setcategoria(string cat){
 categoria=cat;
 }
 int gettiempo_entrega(){
 return tiempo_entrega;
 }
 string getDireccion(){
 return direccion;
 } 
 string getcategoria(){
 return categoria;
 }
 
};
int main(){
 string nombre,clienteoprov,x,direccion,queproducto,categoria; 
 int cuentabanco, tiempo_entrega,precio,clave,descuento,peso;
 cout<<"¡Buenos días! Esta es la página de E-commerce para articulos de salud y bienestar"<<endl;
 cout<<"En esta página puedes ingresar como proveedor o cliente con el fin de fomentar el comercio y competividad de  precios"<<endl;
 cout<<"Ademas de que estamos comprometidos con el bienestar y la salud por lo que nos hemos enfocado a promocionar  productos de salud e higiene"<<endl;
 cout<<"Especifica si eres cliente o proveedor para darte los permisos pertinentes"<<endl;
 cin>>clienteoprov;
 if (clienteoprov=="cliente"){
 x="cliente";
 }
 else if (clienteoprov=="proveedor"){
 x="proveedor";
 }
 else{
 cout<<"Incorrecto, tienes que escribir 'cliente' o 'proveedor' todo en minusculas"<<endl;
 return(0);
 }
 cout << "¿Cuál es tu nombre?";
 cin >> nombre;
 cout<<"¡Bienvenido "<<nombre<<"! Prosigamos con el proceso para que accedas como "<<x<<endl;
 
 if (x=="cliente"){
 cliente objcliente;
 objcliente.setNombre(nombre);
 cout<<"Ingresa tu cuenta de banco para que puedas pagar"<<endl;
 cin>>cuentabanco;
 objcliente.setcuentabanco(cuentabanco);
 cout<<"Ingresa tu direccion"<<endl;
 cin>>direccion;
 objcliente.setdireccion(direccion);
 cout<<"¿que quieres comprar, cubrebocas o gel?"<<endl;
 cin>>queproducto;
 if (queproducto=="cubrebocas"){
 objcliente.setprecio(1500);
 objcliente.setclave(12345);
 objcliente.setdescuento(0.1);
 objcliente.setpeso(1);
 }else if(queproducto=="gel"){
 objcliente.setprecio(700);
 objcliente.setclave(6789);
 objcliente.setdescuento(0.05);
 objcliente.setpeso(0.5);
 }
 cout<<nombre<<" el resumen de tu compra es el siguiente: "<< endl;
 cout<<"A la siguiente cuenta: "<<objcliente.getcuentabanco()<< " se le cobrará "<<objcliente.getprecio()<<endl;
 cout<<"Se enviará a "<<objcliente.getdireccion()<<" y se le hará un descuento de "<<objcliente.getdescuento()<<endl;
 cout<<"El precio se calcula multipicando el costo por el peso en kg menos el descuento. El peso del paquete es  "<<objcliente.getpeso()<<endl;
 cout<<"Por lo que el precio final será de "<<(objcliente.getprecio()*objcliente.getpeso())-(objcliente.getprecio()*objcliente.getdescuento())<<endl;
 
 
 }else if(x=="proveedor"){
 proveedor objproveedor;
 cout<<"Ingres el tiempo de entrega de lo que quieres vender: "<<endl;
 cin>>tiempo_entrega;
 objproveedor.settiempo_entrega(tiempo_entrega);
 cout<<"Ingresa la direccion"<<endl;
 cin>>direccion;
 objproveedor.setdireccion(direccion);
 cout<<"Ingresa la categoria"<<endl;
 cin>>categoria;
 objproveedor.setcategoria(categoria);
 cout<<"¿que quieres vender, cubrebocas o gel?"<<endl;
 cin>>queproducto;
 if (queproducto=="cubrebocas"){
 cout<<"Ingresa el precio"<<endl;
 cin>>precio;
 objproveedor.setprecio(precio);
 cout<<"Ingresa la clave"<<endl;
 cin>>clave;
 objproveedor.setclave(clave);
 cout<<"Ingresa el descuento"<<endl;
 cin>>descuento;
 objproveedor.setdescuento(descuento);
 cout<<"Ingresa el peso"<<endl;
 cin>>peso;
 objproveedor.setpeso(peso);
 }else if(queproducto=="gel"){
 cout<<"Ingresa el precio"<<endl;
 cin>>precio;
 objproveedor.setprecio(precio);
 cout<<"Ingresa la clave"<<endl;
 cin>>clave;
 objproveedor.setclave(clave);
 cout<<"Ingresa el descuento"<<endl;
 cin>>descuento;
 objproveedor.setdescuento(descuento);
 cout<<"Ingresa el peso"<<endl;
 cin>>peso;
 objproveedor.setpeso(peso);
 }
 cout<<"El resumen de tu venta es el siguiente: "<< endl;
 cout<<"En el tiempo de "<<objproveedor.gettiempo_entrega()<< " días se le pagará "<<objproveedor.getprecio()<<endl;
 cout<<"Se enviará con clave "<<objproveedor.getclave()<<" y se le hará un descuento de  "<<objproveedor.getdescuento()<<endl;
 cout<<"El precio se calcula multipicando el costo por el peso en kg menos el descuento. El peso del paquete es  "<<objproveedor.getpeso()<<endl;
 cout<<"Por lo que el precio final será de "<<(objproveedor.getprecio()*objproveedor.getpeso())- (objproveedor.getprecio()*objproveedor.getdescuento())<<endl;
 }
}
