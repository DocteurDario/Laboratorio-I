
#include <iostream>
#include <iomanip>

int main() {
    int notasAlumnos[101][4] = { 0 };
    int legajo = 0, tipo = 0, nota = 0;
    int aprobados = 0, desaprobados = 0, totalAlumnos = 0;

    std::cout << "Indicar legajo: ";
    std::cin >> legajo;

    while (legajo != 0) {
        std::cout << "Cargar TIPO examen: ";
        std::cin >> tipo;
        std::cout << "Nota del Examen: ";
        std::cin >> nota;

        if (nota > 5 && tipo > 2) {
            notasAlumnos[legajo - 1500][tipo] = 7;
        } else {
            if (nota < 6 && tipo > 2) {
                 notasAlumnos[legajo - 1500][tipo] = 5;
            }
            else {
                notasAlumnos[legajo - 1500][tipo] = nota;
            }
        }
        std::cout << "Indicar legajo: ";
        std::cin >> legajo;
    }

    for (int leg = 0; leg < 101; leg++) {
        std::cout << "Legajo " << leg + 1500 << " : ";
        for (int tip = 0; tip < 4; tip++) {
            std::cout << notasAlumnos[leg][tip] << " ";
        }
        std::cout << std::endl;
    } 
    int contadorAlumnosAprobados = 0, contadorAlumnosDesaprobados = 0;
    for (int leg = 0; leg < 101; leg++) {
        int contadorParcialAprobado = 0, contadorParcialDesaprobado = 0;
        for (int tip = 0; tip < 4; tip++) {
            if (notasAlumnos[leg][tip] >= 6) { // Cuenta parcial Aprobados
                contadorParcialAprobado++;
            }
            else{
                    // Cuenta parcial desaprobados
                    contadorParcialDesaprobado++;
            }   
        }
        if (contadorParcialAprobado >= 2) {
            contadorAlumnosAprobados++;
        }
        if (contadorParcialDesaprobado >= 3) {
            contadorAlumnosDesaprobados++;
        }
    }
    double porcentajeAprobados =(contadorAlumnosAprobados*100)/101.f;
    double porcentajeDesaprobados=(contadorAlumnosDesaprobados * 100) / 101.f; // el .f es para que muestre bien la parte decimal

    std::cout << "APROBADOS: " << std::fixed << std::setprecision(2) << porcentajeAprobados << "%" << std::endl;
    std::cout << "DESAPROBADOS: " << std::fixed << std::setprecision(2) << porcentajeDesaprobados << "%" << std::endl;
    
    // La nota final de cada alumno:
    for (int leg = 0; leg < 101; leg++) {
        std::cout << "Legajo " << leg + 1500 << " : ";
            if (notasAlumnos[leg][0] >= 6 && notasAlumnos[leg][1] >= 6) {
                std::cout << (notasAlumnos[leg][0] + notasAlumnos[leg][0]) / 2;
            }
            if (notasAlumnos[leg][2] ==7 && notasAlumnos[leg][3] == 7 
                || notasAlumnos[leg][0] >= 6 && notasAlumnos[leg][2] == 7 
                || notasAlumnos[leg][1] >= 6 && notasAlumnos[leg][3] == 7) {
                std::cout << " 7 ";
            }   
            //desaprobacion-
            if (notasAlumnos[leg][1] == 5 || notasAlumnos[leg][3] == 5 
                || notasAlumnos[leg][0] == 0 && notasAlumnos[leg][1] == 0 
                && notasAlumnos[leg][2] == 0 && notasAlumnos[leg][3] == 0) {
                std::cout << 5;
            }
        std::cout << std::endl;
    }
    return 0;
}