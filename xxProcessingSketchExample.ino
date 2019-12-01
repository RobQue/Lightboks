//import processing.serial.*;
//
//Serial myPort;  // Create object from Serial class
//int val;        // Data received from the serial port
//byte[] ledVals = new byte[72];
//
//void setup() 
//{
//  size(200, 200);
//  // I know that the first port in the serial list on my mac
//  // is always my  FTDI adaptor, so I open Serial.list()[0].
//  // On Windows machines, this generally opens COM1.
//  // Open whatever port is the one you're using.
//  String portName = Serial.list()[0];
//  myPort = new Serial(this, portName, 115200);
//}
//
//void draw() {
//  
//  while (myPort.available() > 0) {
//    int inByte = myPort.read();
//    println(inByte);
//  }
//  
//  background(255);
//  if (mouseOverRect() == true) {  // If mouse is over square,
//    fill(204);                    // change color and
//    //myPort.write("setled"); 
//    
//    for(int i = 0; i < 72; i++)
//    {
//      ledVals[i] = 10;
//    }
//    myPort.write("setled");
//    myPort.write(ledVals);
//    
//  } 
//  else {                        // If mouse is not over square,
//    fill(0);                      // change color and
//    //myPort.write("setled"); 
//    
//    for(int i = 0; i < 72; i++)
//    {
//      ledVals[i] = 100;
//    }
//    myPort.write("setled");
//    myPort.write(ledVals);
//    // send an L otherwise
//  }
//  rect(50, 50, 100, 100);         // Draw a square
//}
//
//boolean mouseOverRect() { // Test if mouse is over square
//  return ((mouseX >= 50) && (mouseX <= 150) && (mouseY >= 50) && (mouseY <= 150));
//}
