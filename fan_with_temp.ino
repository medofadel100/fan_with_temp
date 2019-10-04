/* 
 *  this code writen by ahmed shelbaya at 31/3/2016
 *  you can follow ahmed at facebook from here 
 *  www.fb.com/ahmedshelbaya.SET
 *  
 *  this code to operate a PC fan with changing in Temperature 
 */
#include "DHT.h" // include Temperature sensor DHT11 library 
#define DHTPIN 5 // arduino pin 7 
#define DHTTYPE DHT11 // sensor Type DHT11 
DHT dht (DHTPIN, DHT11); // initialize the DHT11 Temperature sensor  
int buzzerpin = 7; //buzzer is conected on arduino pin 8 
int fanpin = 6; // fan is conected on arduino pin 9 
void setup() {
dht.begin(); //start DHT11 sensor 
pinMode(fanpin,OUTPUT); //define fan pin as output 
pinMode(buzzerpin,OUTPUT); // define buzzer pin as output 
}
void loop() {
delay(1000); // wait 1s 
float t = dht.readTemperature (); // read temperature in celise 
delay(1000); // wait 1s after each reading 
//cheak if sensor read or not 
if (isnan(t)) 
{
  alarm(); // start alarm if no reading form sensor 
  return;
}
//cheak if temperature 
if (t > 22 ) 
// if it greater than 22 turn on  the fan 
{
  digitalWrite(fanpin,HIGH);
  return;
}
// if it less than or equal 22 turn off the fan 
else if (t <= 22 )
{
  digitalWrite(fanpin,LOW);
}}
// alarm function 
void alarm()
{
  digitalWrite(buzzerpin,HIGH);
  delay(500);
  digitalWrite(buzzerpin,LOW);
  delay(1000); 
  digitalWrite(buzzerpin,HIGH);
  delay(500);
  digitalWrite(buzzerpin,LOW);
}
