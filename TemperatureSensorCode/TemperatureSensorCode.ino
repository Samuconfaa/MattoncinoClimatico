#include <math.h> 
/*10 k -> 10000 ohm*/ 
double Thermistor(int RawADC) { 
 double Temp; 
 Temp = log(10000.0*((1024.0/RawADC-1))); 
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp)) * Temp); 
 Serial.println();
 Serial.print(Temp);
 Serial.println(" - ");
 Temp = Temp - 273.15; 
 return Temp; 
} 
void Siren(bool high)
{if(high)
{
  digitalWrite(8,HIGH);
    tone(8,8000,8000);
    delay(200);
    digitalWrite(8,LOW);
    tone(8,0,0);
    delay(200);
}
else
{
  noTone(8);     
  digitalWrite(8, LOW); 
}

}
void setup() { 
 Serial.begin(9600); 
 pinMode(8,OUTPUT); 
} 
/*Lo scopo non era la comunicazione del valore, ma la segnalazione di una 
temperatura superiore ai 22°, accendendo un led*/ 
bool high = false;
void loop() { 
 double Temperatura = Thermistor(analogRead(0)); 
 Serial.println(Temperatura);
 if(Temperatura>=30)
 {
  high=true;
 }else
 {
  high=false;
 }
Siren(high);

 //Temperatura<22 ? digitalWrite(7,HIGH) : digitalWrite(7,LOW); 
 delay(100); 

} 
