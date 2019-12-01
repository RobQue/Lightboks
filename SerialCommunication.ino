//setled
//getxyz
String SerialBUFFER = "";
String SerialBUFFERx = "";


void serialHandler()
{
  while (Serial.available() > 0) 
  {
    char inChar = Serial.read();
    SerialBUFFER += inChar;
  }

 // print the message and a notice if it's changed:
  if (SerialBUFFER.length() != 0 ) {

    //bufferTest(); 
   

    if (SerialBUFFER.length() == 78) {
#ifdef DEBUG      Serial.println("Great, got 78");
#endif
      if (SerialBUFFER.startsWith("setled"))
      {
        //parse led data from  6th string member
        
        SerialBUFFER.remove(0, 6); //remove header


        for(int i = 0; i < SerialBUFFER.length()/3; i++)
        {
          LedData += SerialBUFFER.substring(i*3, i*3+3) + char(1)+ char(1)+ char(1);  // + SerialBUFFER.substring(i*3, i*3+3); //that could be so: on serial its 2 leds on bt 1 led
        }
           
        
        //String LedData = SerialBUFFERx + SerialBUFFER;
        LedData.getBytes((unsigned char*)leds, NUM_LEDS * 3);
        LedData = "";
        FastLED.show();
        
        //SerialBUFFER.getBytes(PixelBUFFER, SerialBUFFER.length()); //PixelBUFFER in Neopixels
        //neoPixelsUpdate(); //update displayed neopixels
        
#ifdef DEBUG        Serial.println("Leds are set");
        Serial.println(SerialBUFFER);
#endif
      }

      else if (SerialBUFFER.startsWith("preled"))
      {
        SerialBUFFERx = SerialBUFFER;
        SerialBUFFERx.remove(0, 6);
        Serial.println("FirstLedSetReceived");
      }
      
      else if (SerialBUFFER.startsWith("getxyz"))
      {
        Serial.println("xyz parsed, leds are set");
      }
    } 

    else if (SerialBUFFER.length() == 6) {
      Serial.println("Great, got 6");

      if (SerialBUFFER.startsWith("getxyz"))
      {
        Serial.println("xyz parsed, leds are not set");
      }
      
    }
    
    else {
      Serial.println("Unknown Command");
    }

    
    // reset buffer
    SerialBUFFER = "";
  }
  
  
}

void bufferTest() 
{
  Serial.println(SerialBUFFER);
    Serial.println(SerialBUFFER.length());
    // if the String's longer than 140 characters, complain:
    if (SerialBUFFER.length() < 20) {
      Serial.println("That's a perfectly acceptable text message");
    } else {
      Serial.println("That's too long for a text message.");
    }
}
