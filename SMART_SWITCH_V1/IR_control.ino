void ir(){
  if (irrecv.decode()) {
   // Serial.println(results.value, HEX);
//Serial.println(irrecv.decodedIRData.decodedRawData, HEX);
    irrecv.resume(); // Receive the next value
    delay(50);


    if(irrecv.decodedIRData.decodedRawData==IR_Button_1){
      relay_state1=EEPROM.read(1);
      digitalWrite(RelayPin1,!relay_state1);
      my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, relay_state1);
      EEPROM.put(1, !relay_state1);
      EEPROM.commit();
  }

  if(irrecv.decodedIRData.decodedRawData==IR_Button_2){
      relay_state2=EEPROM.read(2);
      digitalWrite(RelayPin2,!relay_state2);
      my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, relay_state2);
      EEPROM.put(2, !relay_state2);
      EEPROM.commit();
  }

  if(irrecv.decodedIRData.decodedRawData==IR_Button_3){
      relay_state3=EEPROM.read(3);
      digitalWrite(RelayPin3,!relay_state3);
      my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, relay_state3);
      EEPROM.put(3, !relay_state3);
      EEPROM.commit();
  }

  if(irrecv.decodedIRData.decodedRawData==IR_Button_4){
      relay_state4=EEPROM.read(4);
      digitalWrite(RelayPin4,!relay_state4);
      my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, relay_state4);
      EEPROM.put(4, !relay_state4);
      EEPROM.commit();
  }

  if(irrecv.decodedIRData.decodedRawData==IR_Button_5){
      relay_state5=EEPROM.read(5);
      digitalWrite(RelayPin5,!relay_state5);
      my_switch5.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, relay_state5);
      EEPROM.put(5, !relay_state5);
      EEPROM.commit();
  }

  if(irrecv.decodedIRData.decodedRawData==IR_Button_6){
      relay_state6=EEPROM.read(6);
      digitalWrite(RelayPin6,!relay_state6);
      my_switch6.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, relay_state6);
      EEPROM.put(6, !relay_state6);
      EEPROM.commit();
  }

  if(irrecv.decodedIRData.decodedRawData==IR_Button_7){
      my_fan.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
      
      cur_speed=EEPROM.read(9);
      if(cur_speed<4){
        cur_speed=cur_speed+1;
      }
        if (cur_speed == 0)
        {
          my_fan.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);
          EEPROM.put(7, true);
          EEPROM.put(9, 0);
          EEPROM.commit();
         zero();
        }
        if (cur_speed == 1)
        {
          EEPROM.put(7, true);
          EEPROM.put(9, 1);
          EEPROM.commit();
          one();
        }
        if (cur_speed == 2)
        {
          EEPROM.put(7, true);
          EEPROM.put(9, 2);
          EEPROM.commit();
          two();
        }
        if (cur_speed == 3)
        {
          EEPROM.put(7, true);
          EEPROM.put(9, 3);
          EEPROM.commit();
          three();
        }
        if (cur_speed == 4)
        {
          EEPROM.put(7, true);
          EEPROM.put(9, 4);
          EEPROM.commit();
          four();
        }
        
        }



        if(irrecv.decodedIRData.decodedRawData==IR_Button_8){
      my_fan.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
      EEPROM.put(7, true);
      cur_speed=EEPROM.read(9);
      if(cur_speed>0){
        EEPROM.put(7, true);
        cur_speed=cur_speed-1;
      }
        if (cur_speed == 0)
        {
          my_fan.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, false);
          EEPROM.put(7, true);
          EEPROM.put(9, 0);
          EEPROM.commit();
         zero();
        }
        if (cur_speed == 1)
        {
          EEPROM.put(7, true);
          EEPROM.put(9, 1);
          EEPROM.commit();
          one();
        }
        if (cur_speed == 2)
        {
          EEPROM.put(7, true);
          EEPROM.put(9, 2);
          EEPROM.commit();
          two();
        }
        if (cur_speed == 3)
        {
          EEPROM.put(7, true);
          EEPROM.put(9, 3);
          EEPROM.commit();
          three();
        }
        if (cur_speed == 4)
        {
          EEPROM.put(7, true);
          EEPROM.put(9, 4);
          EEPROM.commit();
          four();
        }
        
        }

        
      
 }
  }
    



          


          
