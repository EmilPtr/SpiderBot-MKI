#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <string.h>
#include "Motion.hpp"
#include "BleController.hpp"

#define SERVICE_UUID "6e400001-b5a3-f393-e0a9-e50e24dcca9e"
#define COMMAND_UUID "6e400002-b5a3-f393-e0a9-e50e24dcca9e"

BLECharacteristic *commandCharacteristic;
volatile MotionState *statePointer;

class CommandCallbacks : public BLECharacteristicCallbacks {
public:
    void onWrite(BLECharacteristic *characteristic) override {
        std::string value = characteristic->getValue();

        if (value == "STOP") {
            *statePointer = STOPPED;
        }
        else if (value == "FORWARD") {
            *statePointer = WALKING;
        }
        else if (value == "BACKWARD") {
            *statePointer = BACKWARD;
        }
        else if (value == "LEFT") {
            *statePointer = TURNING_LEFT;
        }
        else if (value == "RIGHT") {
            *statePointer = TURNING_RIGHT;
        }
    }
};

void setupBLE(volatile MotionState* statePtr) {
    statePointer = statePtr;

    BLEDevice::init("SpiderBot");

    BLEServer *server = BLEDevice::createServer();

    BLEService *service =
        server->createService(SERVICE_UUID);

    commandCharacteristic =
        service->createCharacteristic(
            COMMAND_UUID,
            BLECharacteristic::PROPERTY_WRITE
        );

    commandCharacteristic->setCallbacks(
        new CommandCallbacks()
    );

    service->start();

    server->getAdvertising()->start();

}