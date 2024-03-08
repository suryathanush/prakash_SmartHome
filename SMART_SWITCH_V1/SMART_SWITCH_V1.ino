#include "RMaker.h"
#include "WiFi.h"
#include "WiFiProv.h"
#include <EEPROM.h>
#include <IRremote.h>
const char *service_name = "SMART SWITCH";
const char *pop = "1234567";




#define IR_Button_1   0xB14EFE01
#define IR_Button_2   0xF20DFE01
#define IR_Button_3   0xF30CFE01
#define IR_Button_4   0xB54AFE01
#define IR_Button_5   0xF609FE01
#define IR_Button_6   0xF708FE01
#define IR_Button_7   0xE916FE01 ///A fan speed + button
#define IR_Button_8   0xE51AFE01 ///A fan speed - button




// define the Device Names
char deviceName_1[] = "Light1";
char deviceName_2[] = "Light2";
char deviceName_3[] = "Light3";
char deviceName_4[] = "Light4";
char deviceName_5[] = "Light5";
char deviceName_6[] = "Light6";//-----------------------------------------------------------------------------------
char deviceName_7[] = "Fan1";

// define the GPIO connected with Relays and switches
static uint8_t RelayPin1 = 22;  //D23
static uint8_t RelayPin2 = 17;  //D22
static uint8_t RelayPin3 = 32;  //D21
static uint8_t RelayPin4 = 33;  //D19
static uint8_t RelayPin5 = 25;  //D18
static uint8_t RelayPin6 = 26;  //D5//-----------------------------------------------------------------------------------

//Fan speed control relay
static uint8_t A_fan_speed_relay_1=27;
static uint8_t A_fan_speed_relay_2=14;
static uint8_t A_fan_speed_relay_3=12;


static uint8_t SwitchPin1=34;  //D13
static uint8_t SwitchPin2=35;  //D12
static uint8_t SwitchPin3=1;  //D14
static uint8_t SwitchPin4=3;  //D27
static uint8_t SwitchPin5=21;  //D25
static uint8_t SwitchPin6=19;  //D33

//Afan regulator
static uint8_t s1=18;
static uint8_t s2=5;
static uint8_t s3=4;
static uint8_t s4=15;
//-----------------------------------------------------------------------------------

int RECV_PIN = 13; 
static uint8_t RX2Pin       = 16;
static uint8_t TX2Pin       = 17;

static uint8_t wifiLed    = 2;   //D2
static uint8_t gpio_reset = 0;

// Switch State
bool SwitchState_1 = LOW;
bool SwitchState_2 = LOW;
bool SwitchState_3 = LOW;
bool SwitchState_4 = LOW;
bool SwitchState_5 = LOW;
bool SwitchState_6 = LOW;//-----------------------------------------------------------------------------------

bool relay_state1 = true;
bool relay_state2 = true;
bool relay_state3 = true;
bool relay_state4 = true;
bool relay_state5 = true;
bool relay_state6 = true;
bool fan_state=true;

bool speed1_flag = 1;
bool speed2_flag = 1;
bool speed3_flag = 1;
bool speed4_flag = 1;
bool speed0_flag = 1;//-----------------------------------------------------------------------------------

String cmd="" ;


      /////////////////////////////////////////////////////////////

IRrecv irrecv(RECV_PIN);/////////////////  IR SECTION  /////////////////////////////

decode_results results;/////////////////////////////////////////////////////////////

static Switch my_switch1(deviceName_1, &RelayPin1);
static Switch my_switch2(deviceName_2, &RelayPin2);
static Switch my_switch3(deviceName_3, &RelayPin3);
static Switch my_switch4(deviceName_4, &RelayPin4);
static Switch my_switch5(deviceName_5, &RelayPin5);
static Switch my_switch6(deviceName_6, &RelayPin6);
static Fan my_fan(deviceName_7);
#define DEFAULT_DIMMER_LEVEL 0
//-----------------------------------------------------------------------------------
int cur_speed=0;
int pos;
void sysProvEvent(arduino_event_t *sys_event)
{
    switch (sys_event->event_id) {      
        case ARDUINO_EVENT_PROV_START:
#if CONFIG_IDF_TARGET_ESP32
        Serial.printf("\nProvisioning Started with name \"%s\" and PoP \"%s\" on BLE\n", service_name, pop);
        printQR(service_name, pop, "ble");
#else
        Serial.printf("\nProvisioning Started with name \"%s\" and PoP \"%s\" on SoftAP\n", service_name, pop);
        printQR(service_name, pop, "softap");
#endif        
        break;
        case ARDUINO_EVENT_WIFI_STA_CONNECTED:
        Serial.printf("\nConnected to Wi-Fi!\n");
        digitalWrite(wifiLed, true);
        break;
    }
}

void write_callback(Device *device, Param *param, const param_val_t val, void *priv_data, write_ctx_t *ctx)
{
    const char *device_name = device->getDeviceName();
    const char *param_name = param->getParamName();

    

    if(strcmp(device_name, deviceName_1) == 0) {
      
      Serial.printf("Lightbulb = %s\n", val.val.b? "true" : "false");
      
      if(strcmp(param_name, "Power") == 0) {
          Serial.printf("Received value = %s for %s - %s\n", val.val.b? "true" : "false", device_name, param_name);
        relay_state1 = val.val.b;
        digitalWrite(RelayPin1, !relay_state1);
        EEPROM.put(1, !relay_state1);
        EEPROM.commit();
      

        param->updateAndReport(val);
      }
      
    } else if(strcmp(device_name, deviceName_2) == 0) {
      
      Serial.printf("Switch value = %s\n", val.val.b? "true" : "false");

      if(strcmp(param_name, "Power") == 0) {
        Serial.printf("Received value = %s for %s - %s\n", val.val.b? "true" : "false", device_name, param_name);
        relay_state2 = val.val.b;
        digitalWrite(RelayPin2, !relay_state2);
        EEPROM.put(2, !relay_state2);
        EEPROM.commit();

        param->updateAndReport(val);
      }
  
    } else if(strcmp(device_name, deviceName_3) == 0) {
      
      Serial.printf("Switch value = %s\n", val.val.b? "true" : "false");

      if(strcmp(param_name, "Power") == 0) {
        Serial.printf("Received value = %s for %s - %s\n", val.val.b? "true" : "false", device_name, param_name);
        relay_state3 = val.val.b;
        digitalWrite(RelayPin3, !relay_state3);
        EEPROM.put(3, !relay_state3);
        EEPROM.commit();

        param->updateAndReport(val);
      }
  
    } else if(strcmp(device_name, deviceName_4) == 0) {
      
      Serial.printf("Switch value = %s\n", val.val.b? "true" : "false");

      if(strcmp(param_name, "Power") == 0) {
        Serial.printf("Received value = %s for %s - %s\n", val.val.b? "true" : "false", device_name, param_name);
        relay_state4 = val.val.b;
        digitalWrite(RelayPin4, !relay_state4);
        EEPROM.put(4, !relay_state4);
        EEPROM.commit();

        param->updateAndReport(val);
      }  
    }else if(strcmp(device_name, deviceName_5) == 0) {
      
      Serial.printf("Switch value = %s\n", val.val.b? "true" : "false");

      if(strcmp(param_name, "Power") == 0) {
        Serial.printf("Received value = %s for %s - %s\n", val.val.b? "true" : "false", device_name, param_name);
        relay_state5 = val.val.b;
        digitalWrite(RelayPin5, !relay_state5);
        EEPROM.put(5, !relay_state5);
        EEPROM.commit();

        param->updateAndReport(val);
      }  
    }else if(strcmp(device_name, deviceName_6) == 0) {
      
      Serial.printf("Switch value = %s\n", val.val.b? "true" : "false");

      if(strcmp(param_name, "Power") == 0) {
        Serial.printf("Received value = %s for %s - %s\n", val.val.b? "true" : "false", device_name, param_name);
        relay_state6 = val.val.b;
        digitalWrite(RelayPin6, !relay_state6);
        EEPROM.put(6, !relay_state6);
        EEPROM.commit();

        param->updateAndReport(val);
      }  
    }
    
    if(strcmp(device_name, deviceName_7) == 0) {
      Serial.println(device_name);
      Serial.println(param_name);
      if(strcmp(param_name, "Power") == 0) {
        fan_state = val.val.b;
        Serial.printf("\nReceived value = %d for %s - %s\n", fan_state, device_name, param_name);
        
        EEPROM.put(7, fan_state);
        EEPROM.commit();
        Serial.println(EEPROM.read(7));
        cur_speed=EEPROM.read(9);
        
        if(fan_state==1){
        if (cur_speed == 0)
        {
         zero();
        }
        if (cur_speed == 1)
        {
          one();
        }
        if (cur_speed == 2)
        {
          two();
        }
        if (cur_speed == 3)
        {
          three();
        }
        if (cur_speed == 4)
        {
          four();
        }
        }
        else{
         zero();
         param->updateAndReport(val);
      }
        
      }
      
      if (strcmp(param_name, "Level") == 0) {
         pos = val.val.i;
        Serial.printf("\nReceived value = %d for %s - %s\n", pos, device_name, param_name);
        Serial.println(pos);
//        EEPROM.put(8, pos);
//        EEPROM.commit();
        if(pos==0){
          my_fan.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
          EEPROM.put(7, true);
          cur_speed=0;
          EEPROM.put(9, cur_speed);
          EEPROM.commit();
          zero();
        }
        else if(pos==1){
          EEPROM.put(9, 1);
          EEPROM.commit();
          my_fan.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
          EEPROM.put(7, true);
          EEPROM.commit();
          one();
        }
        else if(pos==2){
          EEPROM.put(9, 2);
          EEPROM.commit();
          my_fan.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
          EEPROM.put(7, true);
          EEPROM.commit();
          two();
        }
        else if(pos==3){
          EEPROM.put(9, 3);
          EEPROM.commit();
          my_fan.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
          EEPROM.put(7, true);
          EEPROM.commit();
          three();
        }
        else if(pos==4){
          EEPROM.put(9, 4);
          EEPROM.commit();
          my_fan.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
          EEPROM.put(7, true);
          EEPROM.commit();
          four();
        }

        param->updateAndReport(val);
      }
    }


    
    
    //-----------------------------------------------------------------------------------
}

  

void setup()
{
    uint32_t chipId = 0;
    
    Serial.begin(115200);
    Serial2.begin(9600, SERIAL_8N1, RX2Pin, TX2Pin);
    irrecv.enableIRIn();
    EEPROM.begin(500);
    relay_state1 = EEPROM.read(1);
    relay_state2 = EEPROM.read(2);
    relay_state3 = EEPROM.read(3);
    relay_state4 = EEPROM.read(4);
    relay_state5 = EEPROM.read(5);
    relay_state6 = EEPROM.read(6);
    fan_state = EEPROM.read(7);
    cur_speed=EEPROM.read(9);
    
    SwitchState_1=EEPROM.read(11);
    SwitchState_2=EEPROM.read(12);
    SwitchState_3=EEPROM.read(13);
    SwitchState_4=EEPROM.read(14);
    SwitchState_5=EEPROM.read(15);
    SwitchState_6=EEPROM.read(16);//-----------------------------------------------------------------------------------
    my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, !relay_state1);
    my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, !relay_state2);
    my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, !relay_state3);
    my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, !relay_state4);
    my_switch5.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, !relay_state5);
    my_switch6.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, !relay_state6);
    my_fan.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, fan_state);//-----------------------------------------------------------------------------------


    delay(1000);
    
    
    // Set the Relays GPIOs as output mode
    pinMode(RelayPin1, OUTPUT);
    pinMode(RelayPin2, OUTPUT);
    pinMode(RelayPin3, OUTPUT);
    pinMode(RelayPin4, OUTPUT); 
    pinMode(RelayPin5, OUTPUT);
    pinMode(RelayPin6, OUTPUT);
    pinMode(A_fan_speed_relay_1, OUTPUT);
    pinMode(A_fan_speed_relay_2, OUTPUT);
    pinMode(A_fan_speed_relay_3, OUTPUT);//-----------------------------------------------------------------------------------
    pinMode(wifiLed, OUTPUT);
    
    digitalWrite(RelayPin1,HIGH);
    digitalWrite(RelayPin2,HIGH);
    digitalWrite(RelayPin3,HIGH);
    digitalWrite(RelayPin4,HIGH);
    digitalWrite(RelayPin5,HIGH);
    digitalWrite(RelayPin6,HIGH);
    digitalWrite(A_fan_speed_relay_1,HIGH);
    digitalWrite(A_fan_speed_relay_2,HIGH);
    digitalWrite(A_fan_speed_relay_2,HIGH);


    
    // Configure the input GPIOs
    pinMode(SwitchPin1, INPUT_PULLUP);
    pinMode(SwitchPin2, INPUT_PULLUP);
    pinMode(SwitchPin3, INPUT_PULLUP);
    pinMode(SwitchPin4, INPUT_PULLUP);
    pinMode(SwitchPin5, INPUT_PULLUP);
    pinMode(SwitchPin6, INPUT_PULLUP);
    pinMode(s1, INPUT_PULLUP);
    pinMode(s2, INPUT_PULLUP);
    pinMode(s3, INPUT_PULLUP);
    pinMode(s4, INPUT_PULLUP);//-----------------------------------------------------------------------------------
    pinMode(gpio_reset, INPUT);
    
    // Write to the GPIOs the default state on booting
    digitalWrite(RelayPin1, relay_state1);
    digitalWrite(RelayPin2, relay_state2);
    digitalWrite(RelayPin3, relay_state3);
    digitalWrite(RelayPin4, relay_state4);
    digitalWrite(RelayPin5, relay_state5);
    digitalWrite(RelayPin6, relay_state6);
    
    
    if(fan_state==1){
        if (cur_speed == 0)
        {
         zero();
        }
        if (cur_speed == 1)
        {
          one();
        }
        if (cur_speed == 2)
        {
          two();
        }
        if (cur_speed == 3)
        {
          three();
        }
        if (cur_speed == 4)
        {
          four();
        }
        }
        else{
         zero();
      }



      
    //-----------------------------------------------------------------------------------
    
    //wifi indicator
    digitalWrite(wifiLed, LOW);

    Node my_node;    
    my_node = RMaker.initNode("Surya");


    
    //Standard switch device
    my_switch1.addCb(write_callback);
    my_switch2.addCb(write_callback);
    my_switch3.addCb(write_callback);
    my_switch4.addCb(write_callback);
    my_switch5.addCb(write_callback);
    my_switch6.addCb(write_callback);//-----------------------------------------------------------------------------------

    //Add switch device to the node   
    my_node.addDevice(my_switch1);
    my_node.addDevice(my_switch2);
    my_node.addDevice(my_switch3);
    my_node.addDevice(my_switch4);
    my_node.addDevice(my_switch5);
    my_node.addDevice(my_switch6);//-----------------------------------------------------------------------------------

   //fan control
  Param level_param("Level", "custom.param.level", value(DEFAULT_DIMMER_LEVEL), PROP_FLAG_READ | PROP_FLAG_WRITE);
    level_param.addBounds(value(0), value(4), value(1)); //sart_value, end_value, interval
    level_param.addUIType(ESP_RMAKER_UI_SLIDER);
    my_fan.addParam(level_param);
  
    my_fan.addCb(write_callback);
    
    my_node.addDevice(my_fan);
    my_fan.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, 0);

//////////////////////////////////////////////////////////

    //This is optional 
    RMaker.enableOTA(OTA_USING_PARAMS);
    //If you want to enable scheduling, set time zone for your region using setTimeZone(). 
    //The list of available values are provided here https://rainmaker.espressif.com/docs/time-service.html
    // RMaker.setTimeZone("Asia/Shanghai");
    // Alternatively, enable the Timezone service and let the phone apps set the appropriate timezone
    RMaker.enableTZService();
    RMaker.enableSchedule();

    //Service Name
    for(int i=0; i<17; i=i+8) {
      chipId |= ((ESP.getEfuseMac() >> (40 - i)) & 0xff) << i;
    }

    Serial.printf("\nChip ID:  %d Service Name: %s\n", chipId, service_name);

    Serial.printf("\nStarting ESP-RainMaker\n");
    RMaker.start();

    WiFi.onEvent(sysProvEvent);
#if CONFIG_IDF_TARGET_ESP32
    WiFiProv.beginProvision(WIFI_PROV_SCHEME_BLE, WIFI_PROV_SCHEME_HANDLER_FREE_BTDM, WIFI_PROV_SECURITY_1, pop, service_name);
#else
    WiFiProv.beginProvision(WIFI_PROV_SCHEME_SOFTAP, WIFI_PROV_SCHEME_HANDLER_NONE, WIFI_PROV_SECURITY_1, pop, service_name);
#endif
}

void loop()
{
//      Serial.println(EEPROM.read(1));
    // Read GPIO0 (external button to reset device
    if(digitalRead(gpio_reset) == LOW) { //Push button pressed
        Serial.printf("Reset Button Pressed!\n");
        // Key debounce handling
        delay(100);
        int startTime = millis();
        while(digitalRead(gpio_reset) == LOW) delay(50);
        int endTime = millis();

        if ((endTime - startTime) > 10000) {
          // If key pressed for more than 10secs, reset all
          Serial.printf("Reset to factory.\n");
          RMakerFactoryReset(2);
        } else if ((endTime - startTime) > 3000) {
          Serial.printf("Reset Wi-Fi.\n");
          // If key pressed for more than 3secs, but less than 10, reset Wi-Fi
          RMakerWiFiReset(2);
        }
    }
    delay(100);

    if (WiFi.status() != WL_CONNECTED)
    {
      //Serial.println("WiFi Not Connected");
      digitalWrite(wifiLed, false);
    }
    else
    {
      //Serial.println("WiFi Connected");
      digitalWrite(wifiLed, true);
    }

    manual_control();
    BT();
    ir();
    fan();
}
