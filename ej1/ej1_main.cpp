#include "ej1.cpp"

int main(){
    CentralRegional central("Central", {"Argentina", "Chile"});
    Empresa empresa1("Empresa1", "Direccion1");
    Empresa empresa2("Empresa2", "Direccion2");
    Departamento dep1("Departamento1", "Ubicacion1");
    Departamento dep2("Departamento2", "Ubicacion2");
    Empleado emp1("Empleado1", "Puesto1", 5, 200);
    Empleado emp2("Empleado2", "Puesto2", 3, 150);
    GerenteAlto gerente1("Gerente1", "PuestoGerente1", 10, 1000,0, "alto");
    GerenteMedio gerente2("Gerente2", "PuestoGerente2", 7, 500,0, "medio");
    central.agregarSubentidad(&empresa1);
    central.agregarSubentidad(&empresa2);
    empresa1.agregarSubentidad(&dep1);
    empresa2.agregarSubentidad(&dep2);
    dep1.contratarEmpleado(&emp1);
    dep2.contratarEmpleado(&emp2);
    central.getGerentesAlto().push_back(&gerente1);
    central.getGerentesMedio().push_back(&gerente2);
    cout << "Nombre de la central: " << central.getNombre() << endl;
    cout << "Cantidad de empleados en la central: " << central.getCantEmpleados() << endl;
    cout << "Nombres de las empresas: ";
    for (auto& empresa : central.getNombresEmpresas()) {
        cout << empresa << " ";
    }
    cout << endl;
    cout << "Gerentes altos: ";
    for (auto& gerente : central.getGerentesAlto()) {
        cout << gerente->getNombre() << " ";
    }
    cout << endl;
    cout << "Gerentes medios: ";
    for (auto& gerente : central.getGerentesMedio()) {
        cout << gerente->getNombre() << " ";
    }
    cout << endl;
    cout << "Subentidades de la central: " << central.contarSubentidades() << endl;
    cout << "Subentidades de la empresa1: " << empresa1.contarSubentidades() << endl;
    cout << "Subentidades de la empresa2: " << empresa2.contarSubentidades() << endl;
    cout << "Empleados en el departamento1: " << dep1.contarEmpleados() << endl;
    cout << "Empleados en el departamento2: " << dep2.contarEmpleados() << endl;
    return 0;
}