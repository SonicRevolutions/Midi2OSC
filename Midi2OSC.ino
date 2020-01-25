#include <MIDI.h>
#include <SPI.h>        
#include <Ethernet.h>
#include <EthernetUdp.h>
#include <OSCMessage.h>

float cc;
const char* message;

MIDI_CREATE_DEFAULT_INSTANCE();

EthernetUDP Udp;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 229, 7); //Arduino IP adjust as needed
IPAddress outIp(192, 168, 229, 200); //destination IP adjust as needed
const unsigned int outPort = 10024; //destination port adjust as needed

void setup() {
  Ethernet.begin(mac,ip);
  Udp.begin(8888);

  MIDI.begin(4); // Midi channel adjust as needed
  MIDI.setHandleControlChange(MyCCFunction);
}

void loop() {
  MIDI.read(); // Read midi
}

void handleOSC(float cc, const char* message) 
{
  OSCMessage msg(message);
  msg.add(cc);
  
  Udp.beginPacket(outIp, outPort);
  msg.send(Udp); // send the bytes to the SLIP stream
  Udp.endPacket(); // mark the end of the OSC Packet
  msg.empty(); // free space occupied by message
}

void MyCCFunction(byte midich, byte number, byte value) {
  switch (number) {
    case 21: // Midi CC adjust as needed
      cc = value / 127.0;
      message = "/ch/01/mix/01"; // OSC message adjust as needed
      handleOSC(cc, message);
      break;
    case 22:
      cc = value / 127.0;
      message = "/ch/02/mix/01";
      handleOSC(cc, message);
      break;
    case 23:
      cc = value / 127.0;
      message = "/ch/03/mix/01";
      handleOSC(cc, message);
      break;
    case 24:
      cc = value / 127.0;
      message = "/ch/04/mix/01";
      handleOSC(cc, message);
      break;
    case 25:
      cc = value / 127.0;
      message = "/ch/05/mix/01";
      handleOSC(cc, message);
      break;
    case 26:
      cc = value / 127.0;
      message = "/ch/07/mix/01";
      handleOSC(cc, message);
      break;
    case 27:
      cc = value / 127.0;
      message = "/ch/09/mix/01";
      handleOSC(cc, message);
      break;
    case 28:
      cc = value / 127.0;
      message = "/ch/10/mix/01";
      handleOSC(cc, message);
      break;
  }
}
