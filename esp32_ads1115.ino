#include <Wire.h>
#include <Adafruit_ADS1015.h>

Adafruit_ADS1115 ads(0x48);
float Voltage = 0.0;

void setup(void) 
{
Serial.begin(9600); 
ads.begin();
}

void loop(void) 
{
int16_t adc0;

adc0 = ads.readADC_SingleEnded(0);
Voltage = (adc0 * 0.1875)/1000;  //adc değerini, 0.1875'in ADS1115'in çözünürlüğü olduğu voltaja dönüştürür

Serial.print("AIN0: "); 
Serial.print(adc0);
Serial.print("\tVoltage: ");
Serial.println(Voltage, 7); 
Serial.println();

delay(1000);
}
