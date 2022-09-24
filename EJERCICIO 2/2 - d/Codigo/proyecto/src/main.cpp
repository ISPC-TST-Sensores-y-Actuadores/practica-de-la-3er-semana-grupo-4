#include <Arduino.h>

int LED = 13;  // Led conectado al pin 13
int IR = 2;    // Entrada digital conectada al sensor infrarrojo
int LED1 = 12; // Led conectado al pin 13
int IR1 = 3;   // Entrada digital conectada al sensor infrarrojo
int motor = 7;
int motor1 = 6;
int motor2 = 5;
int motor3 = 4;

void setup()
{
    Serial.begin(9600);

    pinMode(LED1, OUTPUT);
    pinMode(LED, OUTPUT);
    pinMode(motor, OUTPUT);
    pinMode(motor1, OUTPUT);
    pinMode(motor2, OUTPUT);
    pinMode(motor3, OUTPUT);
    pinMode(IR, INPUT);  // Sensor infrarrojo como entrada
    pinMode(IR1, INPUT); // Sensor infrarrojo como entrada
}
void loop()
{

    int estado = digitalRead(IR);        // leemos el valor del sensor infrarrojo
    int estado1 = digitalRead(IR1);      // leemos el valor del sensor infrarrojo
    if ((estado == 0) && (estado1 == 0)) //        Si ambos sensores retornan 0(zona negra)el robot avanaza
    {
        digitalWrite(LED, LOW);
        digitalWrite(motor1, HIGH);
        digitalWrite(motor, LOW);
        digitalWrite(motor2, HIGH);
        digitalWrite(motor3, LOW);
    }
    if ((estado == 1) && (estado1 == 1)) // Si el resultado de ambos sensores es 1(zona blanca)el robot se para, se fue de linea

    {
        digitalWrite(LED, HIGH);
        digitalWrite(LED1, HIGH);
        digitalWrite(motor1, LOW);
        digitalWrite(motor, LOW);
        digitalWrite(motor2, LOW);
        digitalWrite(motor3, LOW);
    }

    if ((estado == 1) && (estado1 == 0) // si el sensor de la izquierda retorna 1(zona blanca) y el sensor de la derecha retorna 0(zona negra) el robot gira a la derecha, para volver sobre la linea, moviendo motor izquierdo, deteniendo derecho
    )
    {
        digitalWrite(LED, HIGH);
        digitalWrite(LED1, LOW);
        digitalWrite(motor1, LOW);
        digitalWrite(motor, LOW);
        digitalWrite(motor2, HIGH);
        digitalWrite(motor3, LOW);
    }
    if ((estado == 0) && (estado1 == 1) // si el sensor de la derecha retorna 1(zona blanca) y el sensor de la izquierda retorna 0(zona negra) el robot gira a la izquierda, para volver sobre la linea, moviendo motor derecho, deteniendo el izquierdo
    )
    {
        digitalWrite(LED, LOW);
        digitalWrite(LED1, HIGH);
        digitalWrite(motor1, HIGH);
        digitalWrite(motor, LOW);
        digitalWrite(motor2, LOW);
        digitalWrite(motor3, LOW);
    }
}