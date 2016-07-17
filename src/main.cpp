#include "mbed.h"
#include "SEGGER_RTT.h"
#include "ble/services/UARTService.h"

DigitalOut led1(p9);

BLEDevice ble;
UARTService *uart;

void ble_uart_print( const char * format, ... )
{
  char buffer[256];
  va_list args;
  va_start (args, format);
  vsprintf (buffer,format, args);
  if (uart) uart->write(buffer, strlen(buffer));
  va_end (args);
}

const static char     DEVICE_NAME[]        = "K3DPrinter";
//static const uint16_t uuid16_list[]        = {GattService::UUID_HEART_RATE_SERVICE,
//                                              GattService::UUID_DEVICE_INFORMATION_SERVICE};

bool consoleConnected = false;

bool bleConsoleIsConnected(){
    return consoleConnected;
}

void connectionCallback(const Gap::ConnectionCallbackParams_t *params){
	consoleConnected = true;
	rtt_print("\nBLE Gap connection callback.");
}

void timeoutCallback(Gap::TimeoutSource_t t){
	rtt_print("\nBLE Gap timeout callback.");
}

void disconnectionCallback(const Gap::DisconnectionCallbackParams_t *params)
{
	consoleConnected = false;
	rtt_print("\nBLE Gap disconnection callback.");
    BLE::Instance(BLE::DEFAULT_INSTANCE).gap().startAdvertising(); // restart advertising
}

void onRadioEnable(bool enable){
	rtt_print("\nBLE radio enabled: %d",enable);
}

void onDataSent(unsigned length){
	rtt_print("\nBLE data sent: %d",length);
}

void onDataWritten(const GattWriteCallbackParams *eventDataP) {
	rtt_print("\nBLE data written");
}
void onDataRead(const GattReadCallbackParams *eventDataP) {
	rtt_print("\nBLE data read");
}

void onSecuritySetupInitiated(Gap::Handle_t, bool allowBonding, bool requireMITM, SecurityManager::SecurityIOCapabilities_t iocaps)
{
	rtt_print("\nBLE security setup initiated.");
}

void onSecuritySetupComplete(Gap::Handle_t, SecurityManager::SecurityCompletionStatus_t status){
	rtt_print("\nBLE security setup complete.");
}

void periodicCallback(void)
{
	rtt_print("\nTick");
    if(bleConsoleIsConnected()){
    	led1 = !led1; // Do blinky on LED1 while we're waiting for BLE events
        ble_uart_print("\n Tick");
    }
}

void bleInitComplete(BLE::InitializationCompleteCallbackContext *params)
{
    BLE &ble          = params->ble;
    ble_error_t error = params->error;

    if (error != BLE_ERROR_NONE) {
    	rtt_print("\nBLE init error %d",error);
        return;
    }
    rtt_print("\nBLE init complete.");
    Gap& gap = ble.gap();
    gap.onConnection(connectionCallback);
    gap.onTimeout(timeoutCallback);
    gap.onDisconnection(disconnectionCallback);

    gap.onRadioNotification(onRadioEnable);

    ble.onDataSent(onDataSent);
    ble.onDataWritten(onDataWritten);
    ble.onDataRead(onDataRead);

    ble.onSecuritySetupInitiated(onSecuritySetupInitiated);
    ble.onSecuritySetupCompleted(onSecuritySetupComplete);

	// Setup primary service.
    uart = new UARTService(ble);

    // Setup auxiliary service.
    //deviceInfo = new DeviceInformationService(ble, "ARM", "Model1", "SN1", "hw-rev1", "fw-rev1", "soft-rev1");

    // Setup advertising.
    gap.accumulateAdvertisingPayload(GapAdvertisingData::BREDR_NOT_SUPPORTED | GapAdvertisingData::LE_GENERAL_DISCOVERABLE);
    //gap.accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_16BIT_SERVICE_IDS, (uint8_t *)uuid16_list, sizeof(uuid16_list));
    //gap.accumulateAdvertisingPayload(GapAdvertisingData::GENERIC_HEART_RATE_SENSOR);
    gap.accumulateAdvertisingPayload(GapAdvertisingData::SHORTENED_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));
    gap.accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LOCAL_NAME, (uint8_t *)DEVICE_NAME, sizeof(DEVICE_NAME));
    gap.accumulateAdvertisingPayload(GapAdvertisingData::COMPLETE_LIST_128BIT_SERVICE_IDS,
                                           (const uint8_t *)UARTServiceUUID_reversed, sizeof(UARTServiceUUID_reversed));
    gap.setAdvertisingType(GapAdvertisingParams::ADV_CONNECTABLE_UNDIRECTED);
    gap.setAdvertisingInterval(1000); //1000ms
    gap.startAdvertising();

    rtt_print("\nBluetooth Advertising Started");
}

int main(void)
{
	wait(5);
    rtt_print("\nApplication Start");
    led1 = 1;
    Ticker ticker;
    ticker.attach(periodicCallback, 1); // blink LED every second

    BLE& ble = BLE::Instance(BLE::DEFAULT_INSTANCE);
    ble.init(bleInitComplete);

    // SpinWait for initialization to complete. This is necessary because the
    // BLE object is used in the main loop below.
    while (ble.hasInitialized()  == false) {
    // spin loop
    }

    rtt_print("\nBluetooth Initialized");

    //const Gap& gap = ble.gap();
    // infinite loop
    while (1) {
        // check for trigger from periodicCallback()
//        if (triggerSensorPolling && gap.getState().connected){//ble.getGapState().connected) {
//        	hrService->updateHeartRate(hrmCounter);
//        } else {
            ble.waitForEvent(); // low power wait for event
        //}
    }
}

#include "system_nrf51.h"
extern "C" {
	void HardFault_Handler(void)
	{
	  __asm volatile("BKPT #01");
	  //while(1);
	}
}

/*
#include "mbed.h"
#include "rtos.h"

DigitalOut myled(LED1);
bool c=false;
void led1_thread(void const *argument) {

    while (!c) {
        myled = !myled;
        Thread::wait(200);
    }
    myled=1;
}
int main() {

    Thread th1(led1_thread);
    while(1) {
        unsigned long n=100000000;
        float x=0;
        while(x*x <n)
            x = x + 0.01 ;
        c=true;
    }

}
*/
