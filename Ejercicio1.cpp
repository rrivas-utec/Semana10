// Librerias 
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

// Namespaces
using namespace std;

// Crear clases contenidas 
struct TLlanta
{
    string marca;
    string perfiles;
    float radio;
    float espesor;
};

struct TMotor
{
    string marca;
    string modelo;
    float cilindrada;
    float potencia;
    float rpms;
};

struct TTimon
{
    string marca;
    float radio;
};

struct TAsiento
{
    string material;
    string color;
};

class CAuto
{
    TMotor motor;                       // Relacion con ocurrencia 1 a 1
    TTimon timon;                       // Relacion con ocurrencia 1 a 1
    vector<TLlanta> listaLLantas;       // Relacion con ocurrencia 1 a muchos
    vector<TAsiento> listaAsientos;     // Relacion con ocurrencia 1 a muchos
    
public:
    CAuto()
    {
        // Crear 4 llantas
        for (int i= 0; i < 4; i++)
            listaLLantas.push_back({"Dunlop", "60", 17, 10});
            
        // Crear 5 Asientos
        for (int i= 0; i < 5; i++)
            listaAsientos.push_back({"Cuero", "Negro"});
        
        // Definimos el timon
        timon.marca = "Mono";
        timon.modelo = "Deportivo";
        
        // Definimos el Motor
        motor.marca = "Roll Royce";
        motor.modelo = "V8";
        motor.rpms = 6000;
        motor.potencia = 300;
        motor.cilindrada = 4000;
    }
    
    CAuto(int nLlantas, int nAsientos, TTimon timon, TMotor motor)
    {
        // Crear n llantas
        for (int i= 0; i < nLlantas; i++)
            listaLLantas.push_back({"Dunlop", "60", 17, 10});
            
        // Crear n Asientos
        for (int i= 0; i < nAsientos; i++)
            listaAsientos.push_back({"Cuero", "Negro"});
        
        // Definimos el timon
        this->timon = timon; 
        
        // Definimos el Motor
        this->motor = motor;
    }
};

// Programa Principal
int main ()
{
    CAuto estandar;     // 4 Ruedas, 5 Asientos, Timon, Motor
    
    TTimon timon;
    timon.marca = "Pegaso";
    timon.modelo = "Deportivo";
    
    TMotor motor;
    motor.marca = "Ferrari";
    motor.modelo = "V8";
    motor.rpms = 6000;
    motor.potencia = 500;
    motor.cilindrada = 6000;    
    
    CAuto personalizado (4, 2, timon, motor);
    
    return 0;
}