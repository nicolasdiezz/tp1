#ifndef EJ1_HPP
#define EJ1_HPP

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

class EntidadOrganizativa {
    private:
        string nombre;
        vector<EntidadOrganizativa*> entidades;
    public:
        EntidadOrganizativa(string _nombre);
        string getNombre();
        void agregarSubentidad(EntidadOrganizativa* entidad);
        int contarSubentidades();
};

class Departamento;

class Empresa : public EntidadOrganizativa {
    private:
        string nombre;
        string direccion;
        vector<Departamento*> departamentos;
    public:
        Empresa(string _nombre, string _direccion);
        Departamento* getDepByName(string nombre);
        vector<Departamento*> getDepNames();
};

class GerenteAlto;
class GerenteMedio;
class Empleado;

class CentralRegional : public EntidadOrganizativa {
    private:
        string nombre;
        set<string> paises;
        int cantdidad_empleados;
        vector<GerenteAlto*> gerentes_alto;
        vector<GerenteMedio*> gerentes_medio;
        set<Empresa*> empresas;
    public:
        CentralRegional(string _nombre, set<string> _paises);
        int getCantEmpleados();
        vector<string> getNombresEmpresas();
        vector<GerenteAlto*> getGerentesAlto();
        vector<GerenteMedio*> getGerentesMedio();
};

class Departamento : public EntidadOrganizativa{
    private:
        string nombre;
        string ubicacion;
        vector<Empleado*> empleados;
    public:
        Departamento(string _nombre, string _ubicacion);
        int contarEmpleados();
        vector<Empleado*> getEmpleados();
        bool contratarEmpleado(Empleado* nuevo_empleado);
        bool despedirEmpleado(Empleado* chau_empleado);
};

class Empleado {
    private:
        string nombre;
        string puesto;
        int antiguedad;
        float salario;
    public:
        Empleado(string _nombre, string _puesto, int _antiguedad, float _salario);
        string getNombre();
        int getAntiguedad();
        bool updateSalario(float nuevo_salario);
        float getSalario();
};

class Manager : public Empleado {
    private:
        float bono;
        string level;
    public:
        Manager(string _nombre, string _puesto, int _antiguedad, float _salario, float _bono, string _level);
        bool updateBono(float nuevo_bono);
        float getBono();
        bool setLevel(string _level);
};

class GerenteAlto : public Manager {
    public:
        GerenteAlto(string _nombre, string _puesto, int _antiguedad, float _salario, float _bono, string _level);
};

class GerenteMedio : public Manager {
    public:
        GerenteMedio(string _nombre, string _puesto, int _antiguedad, float _salario, float _bono, string _level);
};

class GerenteBajo : public Manager {
    public:
        GerenteBajo(string _nombre, string _puesto, int _antiguedad, float _salario, float _bono, string _level);
};

class LiderEquipo : public Manager {
    public:
        LiderEquipo(string _nombre, string _puesto, int _antiguedad, float _salario, float _bono, string _level);
};

#endif