#include <stddef.h>
#include <stdexcept>
#include "dtFechaHora.h"

using namespace std;

//Constructores
dtFechaHora::dtFechaHora(){
    //Constructor por defecto
}

deFechaHora::dtFechaHora(int d, int m, int a, int h, int mi, int s){
    this->dia = d;
    this->mes = m;
    this->anio = a;
    this->hora = h;
    this->minuto = mi;
    this->segundo = s;
}

dtFechaHora::dtFechaHora(const dtFechaHora& fh){
    dia = fh.dia;
    mes = fh.mes;
    anio = fh.anio;
    hora = fh.hora;
    minuto = fh.minuto;
    segundo = fh.segundo;
}

//Setters
void dtFechaHora::setDia(int d){
    this->dia = d;
}

void dtFechaHora::setMes(int m){
    this->mes = m;
}

void dtFechaHora::setAnio(int a){
    this->anio = a;
}

void dtFechaHora::setHora(int h){
    this->hora = h;
}

void dtFechaHora::setMinutos(int mi){
    this->minuto = mi;
}

void dtFechaHora::setSegundos(int s){
    this->segundo = s;
}

//Getters
int dtFechaHora::getDia() const{
    return this->dia;
}

int dtFechaHora::getMes() const{
    return this->mes;
}

int dtFechaHora::getAnio() const{
    return this->anio;
}

int dtFechaHora::getHora() const{
    return this->hora;
}

int dtFechaHora::getMinutos() const{
    return this->minuto;
}

int dtFechaHora::getSegundos() const{
    return this->segundo;
}

//Funciones Sobrecargadas
void dtFechaHora::write(ostream& os) const{
    cout << this->dia << "/" << this->mes << "/" << this->anio << ", " << this->hora << ":" << this->minuto << ":" << this->segundo << ".";
}

ostream& operator<<(ostream& os, const dtFechaHora& fh){
    fh.write(os);
    return os;
}

bool dtFechaHora::operator==(dtFechaHora fh) const{
    return ((this->dia==fh.getDia())&&(this->mes==fh.getMes())&&(this->anio == fh.getAnio())&&
            (this->hora==fh.getHora())&&(this->minuto==fh.getMinutos())&&(this->segundo==fh.getSegundos()));
}

bool dtFechaHora::operator>(dtFechaHora fh) const{
    return  ((this->anio>fh.getAnio())||
            ((this->anio==fh.getAnio())&&(this->mes>fh.getMes()))||
            ((this->anio==fh.getAnio())&&(this->mes==fh.getMes())&&(this->dia>fh.getDia()))||
            ((this->anio==fh.getAnio())&&(this->mes==fh.getMes())&&(this->dia==fh.getDia())&&(this->hora>fh.getHora()))||
            ((this->anio==fh.getAnio())&&(this->mes==fh.getMes())&&(this->dia==fh.getDia())&&(this->hora==fh.getHora())&&(this->minuto>fh.getMinutos()))||
            ((this->anio==fh.getAnio())&&(this->mes==fh.getMes())&&(this->dia==fh.getDia())&&(this->hora==fh.getHora())&&(this->minuto==fh.getMinutos())&&(this->segundo>fh.getSegundos())));
}

bool dtFechaHora::operator<(dtFechaHora fh) const{
    return  ((this->anio<fh.getAnio())||
            ((this->anio==fh.getAnio())&&(this->mes<fh.getMes()))||
            ((this->anio==fh.getAnio())&&(this->mes==fh.getMes())&&(this->dia<fh.getDia()))||
            ((this->anio==fh.getAnio())&&(this->mes==fh.getMes())&&(this->dia==fh.getDia())&&(this->hora<fh.getHora()))||
            ((this->anio==fh.getAnio())&&(this->mes==fh.getMes())&&(this->dia==fh.getDia())&&(this->hora==fh.getHora())&&(this->minuto<fh.getMinutos()))||
            ((this->anio==fh.getAnio())&&(this->mes==fh.getMes())&&(this->dia==fh.getDia())&&(this->hora==fh.getHora())&&(this->minuto==fh.getMinutos())&&(this->segundo<fh.getSegundos())));
}

//Función Derivada de OrderedKey
ComparisonRes dtFechaHora::compare(OrderedKey* k) const{
    dtFechaHora* fh = dynamic_cast<dtFechaHora*>(k);
    if(fh==NULL)
        throw invalid_argument("Invalid key k");
    if(this->operator==(*fh))
        return EQUAL;
    else if(this->operator>(*fh))
        return GREATER;
    else
        return LESSER;
}

//Destructor
dtFechaHora::~dtFechaHora(){
    //Destructor por defecto
}
