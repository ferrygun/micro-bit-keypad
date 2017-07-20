#include "MicroBit.h"

MicroBit uBit;


#define EVENT_ID    8888
char W;
uint8_t a = 0;

void onControllerEvent(MicroBitEvent e) {
  a = e.value;
  W = static_cast<char>(a);
  uBit.display.print(W);
}

void onConnected(MicroBitEvent) {
  //uBit.display.print("C");
}

 
void onDisconnected(MicroBitEvent){
  // uBit.display.print("D");
}

int main() {
  uBit.init();
  uBit.display.scroll("DC");
  uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_CONNECTED, onConnected);
  uBit.messageBus.listen(MICROBIT_ID_BLE, MICROBIT_BLE_EVT_DISCONNECTED, onDisconnected);
  uBit.messageBus.listen(EVENT_ID, 0, onControllerEvent);
  release_fiber();
}