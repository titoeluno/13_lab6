#ifndef dtFechaHora_H
#define dtFechaHora_H

using namespace std;

#include <iostream>
#include "interfaces/ICollectible.h"
#include "interfaces/OrderedKey.h"

class dtFechaHora: public OrderedKey{
private:
	int dia;
	int mes;
	int anio;
	int hora;
	int minuto;
	int segundo;
public:
	//Constructores
	dtFechaHora();
	dtFechaHora(int d, int m, int a, int h, int mi, int s);
	dtFechaHora(const dtFechaHora&);
	//Setters
	void setDia(int d);
	void setMes(int m);
	void setAnio(int a);
	void setHora(int h);
	void setMinutos(int mi);
	void setSegundos(int s);
	//Getters
	int getDia() const;
	int getMes() const;
	int getAnio() const;
	int getHora() const;
	int getMinutos() const;
	int getSegundos() const;
	//Funciones Sobrecargadas
	void write(ostream& os) const;
	bool operator==(dtFechaHora) const;
	bool operator>(dtFechaHora) const;
	bool operator<(dtFechaHora) const;
	//Función Derivada de OrderedKey
	ComparisonRes compare(OrderedKey* k) const;
	//Destructor
	virtual ~dtFechaHora();
};

ostream& operator<<(ostream& os, const dtFechaHora& dfh);

#endif //dtFechaHora_H
