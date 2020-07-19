//pin declartaion
//pin mode declaration
//pin data declaration

int ledPin = 7;
int inputPin = 2;
int pirState = LOW;
int val = 0;
int calibrationTime = 30;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(inputPin, INPUT);
    Serial.begin(9600);
    Serial.println("Waiting for the sensor to warm up.");
    delay(calibrationTime * 1000);
    Serial.println("SENSOR ACTIVE");
}

void loop()
{
    val = digitalRead(inputPin);

    if (val == HIGH)
    {
        digitalWrite(ledPin, HIGH);
        if (pirState == LOW)
        {

            Serial.println("Motion detected!");
            pirState = HIGH;
        }
    }
    else
    {
        digitalWrite(ledPin, LOW);
        if (pirState == HIGH)
        {

            Serial.println("Motion ended!");
            pirState = LOW;
        }
    }
    delay(1000);
}
