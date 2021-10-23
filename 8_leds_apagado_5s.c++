const unsigned long SECOND = 1000;
const unsigned long MINUTE = 60000;

int leds[] = {2, 3, 4, 5, 6, 7, 8, 9}; // simplificación a la hora de definir las variables. Está definiendo los 5 pines.
int pot;                               // Esta variable se refiere al potenciómetro
int oldPot = 0;
int n = 0; // Variable auxiliar que utilizaremos como contador en el bucle.
int loopCount = 0;
bool espera = false;

void setup()
{
    for (n = 0; n < 8; n++)
    {
        pinMode(leds[n], OUTPUT);
    }
    Serial.begin(9600); //Iniciamos la comunicación con el puerto monitor serial
}

void loop()
{

    pot = analogRead(0); // Definimos el valor de la variable pot como una analógica en el puerto A0

    /*Monitorizamos el valor del potenciómetro con el serial.print seguido entre paréntesis de lo que queremos que nos muestre.*/
    Serial.print("Valor del potenciometro: ");
    Serial.print(pot);
    Serial.print("\n");
    delay(500);

    if (!espera)
    {

        for (n = 0; n < 8; n++) //Los demás LEDs están apagados
            digitalWrite(leds[n], LOW);
        /*Ahora definimos los límites de acuerdo con los valores que va obteniendo el potenciómetro, para determinar a partir de qué valor se encenderá cada LED*/

        if (pot >= 1 && pot <= 100)
        {                                    //Definimos el rango para el cual se encenderá el LED
            for (n = 0; n < 1; n++)          //solo se enciende un LED, de ahí el número 1
                digitalWrite(leds[n], HIGH); // Se encienden n LEDs, aquí n = 1
            for (n = 1; n < 8; n++)          //Los demás LEDs están apagados
                digitalWrite(leds[n], LOW);
        }

        //Para los demás bucles se procederá de la misma forma, modificando las condiciones de encendido

        if (pot >= 100 && pot <= 200)
        {
            for (n = 0; n < 2; n++)
                digitalWrite(leds[n], HIGH);
            for (n = 2; n < 8; n++)
                digitalWrite(leds[n], LOW);
        }
        if (pot >= 200 && pot <= 300)
        {
            for (n = 0; n < 3; n++)
                digitalWrite(leds[n], HIGH);
            for (n = 3; n < 8; n++)
                digitalWrite(leds[n], LOW);
        }
        if (pot >= 300 && pot <= 400)
        {
            for (n = 0; n < 4; n++)
                digitalWrite(leds[n], HIGH);
            for (n = 4; n < 8; n++)
                digitalWrite(leds[n], LOW);
        }
        if (pot >= 400 && pot <= 500)
        {
            for (n = 0; n < 5; n++)
                digitalWrite(leds[n], HIGH);
            for (n = 5; n < 8; n++)
                digitalWrite(leds[n], LOW);
        }
        if (pot >= 500 && pot <= 600)
        {
            for (n = 0; n < 6; n++)
                digitalWrite(leds[n], HIGH);
            for (n = 6; n < 8; n++)
                digitalWrite(leds[n], LOW);
        }
        if (pot >= 600 && pot <= 700)
        {
            for (n = 0; n < 7; n++)
                digitalWrite(leds[n], HIGH);
            for (n = 7; n < 8; n++)
                digitalWrite(leds[n], LOW);
        }
        if (pot >= 700)
        {
            for (n = 0; n < 8; n++)
                digitalWrite(leds[n], HIGH);
        }
    }
    if (pot == oldPot)
    {
        loopCount = loopCount + 500;
        if (loopCount >= 5000)
        {
            espera = true;
            for (n = 0; n < 8; n++)
                digitalWrite(leds[n], LOW);
        }
    }
    else
    {
        oldPot = pot;
        espera = false;
        loopCount = 0;
    }
}
