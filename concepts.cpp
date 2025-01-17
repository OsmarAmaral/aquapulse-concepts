// AquaPulse - Irrigação Automatica com Arduino, v1.0

const int soilMoistureSensor = AO; /* Sensor de umidade*/
const int button = 2; /* Botão */
const int waterPump = 3; /* Bomba de água */

int minimunSoilMoisture = 307; /* Umidade minima = 30% */
int delayTime = 6000; /* 6 segundos */

void setup () {
    pinMode(soilMoistureSensor, INPUT);
    pinMode(button, INPUT);
    pinMode(waterPump, OUTPUT);

    digitalWrite(waterPump, LOW);
    Serial.begin(9600);
}

void loop () {
    int buttonState = digitalRead(button); /* leitura do botão */
    Serial.printl("Button: "+buttonState);
    if(buttonState == HIGH) {
        /* se estiver ligado */
        int currentSoilMoisture = analogRead(soilMoistureSensor); /* leitura da umidade*/
        Serial.printl("Umidade: "+currentSoilMoisture);
        if(currentSoilMoisture < minimunSoilMoisture) {
            /* se ela for menor que a minima */
            digitalWrite(waterPump, HIGH); /* ative a bomba */
            delay(delayTime); /* espera um tempo */
            digitalWrite(waterPump, LOW); /* desligue */
        }
    }
}
