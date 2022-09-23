#include <Arduino.h>

int LED = 13; // Led conectado al pin 13
int IR = 2;   // Entrada digital conectada al sensor infrarrojo

void setup()
{

    pinMode(LED, OUTPUT); // LED como salida
    pinMode(IR, INPUT);   // Sensor infrarrojo como entrada
}
void loop()
{

    int estado = digitalRead(IR); // leemos el valor del sensor infrarrojo
    if (estado == HIGH)
    {
        digitalWrite(LED, LOW); //  Si llegala luz al fotorreceptor se ilumirá un LED en el sensor y enviará una señal LOW al exterior.
    }
    if (estado == LOW)
    {
        digitalWrite(LED, HIGH); // Si no está llegando no se iluminará el LED y enviará una señal HIGH.
    }
}