#include "BluetoothSerial.h"

BluetoothSerial SerialBT;


void BTsetup() {
  
//  uint64_t macAddress = ESP.getEfuseMac();
//  uint64_t macAddressTrunc = macAddress << 40;
//  uint64_t chipID = macAddressTrunc >> 40;
//https://github.com/espressif/arduino-esp32/blob/master/libraries/ESP32/examples/ChipID/GetChipID/GetChipID.ino

  uint64_t chipid=ESP.getEfuseMac();
  String id = String((uint16_t)(chipid>>32));     //print High 2 bytes
  //String id = String((uint32_t)chipid);         //print Low 4bytes
  
  SerialBT.begin("ESP32 " + id );
}

//setled
//getxyz
String SerialBTBUFFER = "";

void BTserialHandler()
{
  while (SerialBT.available() > 0) 
  {
    char inChar = SerialBT.read();
    SerialBTBUFFER += inChar;
  }

 // print the message and a notice if it's changed:
  if (SerialBTBUFFER.length() != 0 ) {

    //bufferTest(); 

    if (SerialBTBUFFER.length() == 78) {
#ifdef DEBUG       SerialBT.println("Great, got 78");
#endif
      if (SerialBTBUFFER.startsWith("setled"))
      {
        //parse led data from  6th string member
        
        SerialBTBUFFER.remove(0, 6); //remove header


        for(int i = 0; i < SerialBTBUFFER.length()/3; i++)
        {
          LedData += SerialBTBUFFER.substring(i*3, i*3+3) + char(1)+ char(1)+ char(1);  //+ SerialBUFFER.substring(i*3, i*3+3); 
        }
           
        
        //String LedData = SerialBUFFERx + SerialBUFFER;
        LedData.getBytes((unsigned char*)leds, NUM_LEDS * 3);
        LedData = "";
        FastLED.show();
        
        //SerialBTBUFFER.getBytes(PixelBUFFER, SerialBTBUFFER.length()); //PixelBUFFER in Neopixels
        //neoPixelsUpdate(); //update displayed neopixels
        
#ifdef DEBUG         SerialBT.println("Leds are set");
        SerialBT.println(SerialBTBUFFER);
#endif        
      }
      else if (SerialBTBUFFER.startsWith("getxyz"))
      {
        SerialBT.println("xyz parsed, leds are set");
      }
    } 

    else if (SerialBTBUFFER.length() == 6) {
      SerialBT.println("Great, got 6");

      if (SerialBTBUFFER.startsWith("getxyz"))
      {
        SerialBT.println("xyz parsed, leds are not set");
      }
      
    }
    
    else {
      SerialBT.println("UC " + String(SerialBTBUFFER.length(),DEC) ); //
    }

    
    // reset buffer
    SerialBTBUFFER = "";
  }
  
  
}
void BTprint (String in)
{
  SerialBT.println(in);

}
