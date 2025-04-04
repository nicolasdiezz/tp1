#include "ej1.hpp"

EntidadOrganizativa :: EntidadOrganizativa(string _nombre){
    nombre = _nombre;
}

string EntidadOrganizativa :: getNombre(){
    return nombre;
}

void EntidadOrganizativa :: agregarSubentidad(EntidadOrganizativa* entidad){
    entidades.push_back(entidad);
}

int EntidadOrganizativa :: contarSubentidades(){
    return entidades.size();
}



Empresa :: Empresa(string _nombre, string _direccion) : EntidadOrganizativa(_nombre){
    direccion = _direccion;
}

Departamento* Empresa :: getDepByName(string nombre){
    for(int i = 0; i < departamentos.size(); i++){
        if(departamentos[i]->getNombre() == nombre) return departamentos[i];
    }
    return nullptr;
}
vector<Departamento*> Empresa :: getDepNames(){
    return departamentos;
}


CentralRegional :: CentralRegional(string _nombre, set<string> _paises) : EntidadOrganizativa(_nombre){
    paises = _paises;
    cantdidad_empleados = 0;
}

int CentralRegional :: getCantEmpleados(){
    return cantdidad_empleados;
}


vector<string> CentralRegional :: getNombresEmpresas(){
    vector<string> nombres_empresas;
    for (auto empresa : empresas) {
        nombres_empresas.push_back(empresa->getNombre());
    }
    return nombres_empresas;
}

vector<GerenteAlto*> CentralRegional :: getGerentesAlto(){
    return gerentes_alto;
}

vector<GerenteMedio*> CentralRegional :: getGerentesMedio(){
    return gerentes_medio;
}




Departamento :: Departamento(string _nombre, string _ubicacion) : EntidadOrganizativa(_nombre){
    ubicacion = _ubicacion;
}

int Departamento :: contarEmpleados(){
    return empleados.size();
}

vector<Empleado*> Departamento :: getEmpleados(){
    return empleados;
}

bool Departamento :: contratarEmpleado(Empleado* nuevo_empleado){
    empleados.push_back(nuevo_empleado);
    return true;
}

bool Departamento :: despedirEmpleado(Empleado* chau_empleado){
    for(int i = 0; i < empleados.size(); i++){
        if (chau_empleado->getNombre() == empleados[i]->getNombre()) {
            empleados.erase(empleados.begin()+i);
            return true;
        }
    }
    return false;
}

Empleado :: Empleado(string _nombre, string _puesto, int _antiguedad, float _salario){
    nombre = _nombre;
    puesto = _puesto;
    antiguedad = _antiguedad;
    salario = _salario;
}

string Empleado :: getNombre(){
    return nombre;
}
int Empleado :: getAntiguedad(){
    return antiguedad;
}
bool Empleado :: updateSalario(float nuevo_salario){
    if(nuevo_salario < 0) return false;
    salario = nuevo_salario;
    return true;
}
float Empleado :: getSalario(){
    return salario;
}

Manager :: Manager(string _nombre, string _puesto, int _antiguedad, float _salario, float _bono, string _level) : Empleado(_nombre, _puesto, _antiguedad, _salario){
    bono = _bono;
    level = _level;
}

bool Manager :: updateBono(float nuevo_bono){
    if(nuevo_bono < 0) return false;
    bono = nuevo_bono;
    return true;
}
float Manager :: getBono(){
    return bono;
}
bool Manager :: setLevel(string _level){
    if(level == "alto" || level == "medio" || level == "bajo" || level == "lider"){ 
        level = _level;
        return true;
    }
    else return false;
}

GerenteAlto :: GerenteAlto(string _nombre, string _puesto, int _antiguedad, float _salario, float _bono, string _level) : Manager(_nombre, _puesto, _antiguedad, _salario, _bono, _level){
     
}
GerenteMedio :: GerenteMedio(string _nombre, string _puesto, int _antiguedad, float _salario, float _bono, string _level) : Manager(_nombre, _puesto, _antiguedad, _salario, _bono, _level){

}
GerenteBajo :: GerenteBajo(string _nombre, string _puesto, int _antiguedad, float _salario, float _bono, string _level) : Manager(_nombre, _puesto, _antiguedad, _salario, _bono , _level){  
}
LiderEquipo :: LiderEquipo(string _nombre, string _puesto, int _antiguedad, float _salario, float _bono, string _level) : Manager(_nombre, _puesto, _antiguedad, _salario, _bono, _level){
}