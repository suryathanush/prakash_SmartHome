//IRremote Library 3.6.1: https://github.com/Arduino-IRremote/Arduino-IRremote
#include <IRremote.h>

int RECV_PIN = 13;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(115200);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode()) {
//    Serial.println(results.value, HEX);
Serial.print("0x");
Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
    irrecv.resume(); // Receive the next value
  }
  
}
