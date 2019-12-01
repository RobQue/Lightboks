//#define DEBUG

#define VoltagePin 14 // A16
//#define SERIAL_TX_BUFFER_SIZE 256  //noworky 128 max
//#define SERIAL_RX_BUFFER_SIZE 256

String LedData = ""; //shared

void setup() {
  // put your setup code here, to run once:
//  pinMode(VoltagePin, INPUT);
  Serial.begin(115200);
  setupSleep();
  fastLedSetup();
  BTsetup();
  setupBatMon();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  serialHandler();
  BTserialHandler();
  loopSleep();
  loopBatMon();
  //Serial.println(analogRead (VoltagePin) );
}
