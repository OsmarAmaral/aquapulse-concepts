/* AquaPulse - Irrigação Automatica com Arduino, v1.0 */

const int soilMoistureSensor = A0; /* Sensor de umidade */
const int waterPump = 3; /* Bomba de água */

int minimunSoilMoisture = 307; /* Umidade minima = 30% */
int delayTime = 6000; /* 6 segundos */

void setup () {
    pinMode(soilMoistureSensor, INPUT);
    pinMode(waterPump, OUTPUT);

    digitalWrite(waterPump, LOW);
    Serial.begin(9600);
}

void loop () {
    int currentSoilMoisture = analogRead(soilMoistureSensor); /* leitura da umidade */
    Serial.println("Umidade: " + String(currentSoilMoisture));
    if (currentSoilMoisture < minimunSoilMoisture) {
        /* se ela for menor que a minima */
        digitalWrite(waterPump, HIGH); /* ative a bomba */
        delay(delayTime); /* espera um tempo */
        digitalWrite(waterPump, LOW); /* desligue */
    }
    delay(500); /* pequeno atraso para evitar leituras excessivas */
}
