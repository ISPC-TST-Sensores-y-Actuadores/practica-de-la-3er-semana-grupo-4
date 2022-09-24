#include <Arduino.h>

int LED = 13; // Led conectado al pin 5
int IR = 2;   // Entrada digital conectada al sensor infrarrojo

void setup()
{
    Serial.begin(9600);
    pinMode(LED, OUTPUT); // LED como salida
    pinMode(IR, INPUT);   // Sensor infrarrojo como entrada
}
void loop()
{

    int estado = digitalRead(IR); // leemos el valor del sensor infrarrojo
    if (estado == HIGH)
    {
        digitalWrite(LED, HIGH); //
    }
    if (estado == LOW)
    {
        digitalWrite(LED, LOW);
    }
}