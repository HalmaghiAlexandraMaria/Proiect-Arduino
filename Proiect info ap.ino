#define trigPin 2
#define echoPin 3
#define LEDlampRed 4
#define LEDlampYellow 5
#define LEDlampGreen 6
#define soundbuzzer 7
int sound = 500;

void setup() {
Serial.begin (9600);
//viteză de transmitere/Pornește comunicarea serială
pinMode(trigPin, OUTPUT);
//setez pinul ca ieșire
pinMode(echoPin, INPUT);
pinMode(LEDlampRed, OUTPUT);
pinMode(LEDlampYellow, OUTPUT);
pinMode(LEDlampGreen, OUTPUT);
pinMode(soundbuzzer, OUTPUT);
}
void loop() {
long durationindigit, distanceincm;
digitalWrite(trigPin, LOW);// Șterge întârzierea
delayMicroseconds(3);
digitalWrite(trigPin, HIGH);
delayMicroseconds(15);//setează trigPin pe starea HIGH pentru 10 microsecunde 
digitalWrite(trigPin, LOW);//unda sonoră se va termina
durationindigit = pulseIn(echoPin, HIGH);// Citește echoPin, returnează timpul de călătorie a undei sonore în microsecunde
distanceincm =durationindigit *0.034 / 2 ;// Calcularea distanței 
Serial.println(distanceincm);

if (distanceincm < 50) {
digitalWrite(LEDlampGreen, HIGH);
}
else {
digitalWrite(LEDlampGreen, LOW);
}

if (distanceincm < 20) {
digitalWrite(LEDlampYellow, HIGH);
}
else {
digitalWrite(LEDlampYellow,LOW);
}
if (distanceincm < 5) {
digitalWrite(LEDlampRed, HIGH);
sound = 1000;

}
else {
digitalWrite(LEDlampRed,LOW);
}

if (distanceincm > 5 || distanceincm <= 0){
Serial.println("În afara intervalului permis de distanțe");
noTone(soundbuzzer);
}
else {
Serial.print(distanceincm);// Tipărește distanța pe monitor
Serial.println(" cm");
tone(soundbuzzer, sound);
}

delay(300);
}