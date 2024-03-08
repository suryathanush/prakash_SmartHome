void manual_control()
{
  if (digitalRead(SwitchPin1) == LOW && SwitchState_1 == LOW) {
    Serial.println("Switch 1");
    relay_state1 = EEPROM.read(1);
    digitalWrite(RelayPin1, !relay_state1);
    
    
    SwitchState_1 = HIGH;
    my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, relay_state1);
    EEPROM.put(1, !relay_state1);
    EEPROM.put(11, SwitchState_1);
    EEPROM.commit();
//    Serial.println("Switch-1 on");
//    Serial.println(EEPROM.read(1));
  }
  if (digitalRead(SwitchPin1) == HIGH && SwitchState_1 == HIGH) {
    Serial.println("Switch 1");
    relay_state1 = EEPROM.read(1);
    digitalWrite(RelayPin1, !relay_state1);
    
    SwitchState_1 = LOW;
    my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,relay_state1);
    EEPROM.put(1, !relay_state1);
    EEPROM.put(11, SwitchState_1);
    EEPROM.commit();
//    Serial.println("Switch-1 off");
//    Serial.println(EEPROM.read(1));
  }

//---------------------------------------------------------------------------------------------------------
  
  if (digitalRead(SwitchPin2) == LOW && SwitchState_2 == LOW) {
    Serial.println("Switch 2");
    relay_state2 = EEPROM.read(2);
    digitalWrite(RelayPin2, !relay_state2);
    
    SwitchState_2 = HIGH;
    my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,relay_state2);
    EEPROM.put(2, !relay_state2);
    EEPROM.put(12, SwitchState_2);
    EEPROM.commit();
//    Serial.println("Switch-2 on");
  }
  if (digitalRead(SwitchPin2) == HIGH && SwitchState_2 == HIGH) {
    Serial.println("Switch 2");
    relay_state2 = EEPROM.read(2);
    digitalWrite(RelayPin2, !relay_state2);
    
    SwitchState_2 = LOW;
    my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,relay_state2);
    EEPROM.put(2, !relay_state2);
    EEPROM.put(12, SwitchState_2);
    EEPROM.commit();
//    Serial.println("Switch-2 off");
  }


//---------------------------------------------------------------------------------------------------------
  
  
  if (digitalRead(SwitchPin3) == LOW && SwitchState_3 == LOW) {
    Serial.println("Switch 3");
    relay_state3 = EEPROM.read(3);
    digitalWrite(RelayPin3, !relay_state3);
    
    SwitchState_3 = HIGH;
    my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,relay_state3);
    EEPROM.put(3, !relay_state3);
    EEPROM.put(13, SwitchState_3);
    EEPROM.commit();
//    Serial.println("Switch-3 on");
  }
  if (digitalRead(SwitchPin3) == HIGH && SwitchState_3 == HIGH) {
    Serial.println("Switch 3");
    relay_state3 = EEPROM.read(3);
    digitalWrite(RelayPin3, !relay_state3);
    
    SwitchState_3 = LOW;
    my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,relay_state3);
    EEPROM.put(3, !relay_state3);
    EEPROM.put(13, SwitchState_3);
    EEPROM.commit();
//    Serial.println("Switch-3 off");
  }


//---------------------------------------------------------------------------------------------------------
  
  
  if (digitalRead(SwitchPin4) == LOW && SwitchState_4 == LOW) {
    Serial.println("Switch 4");
    relay_state4 = EEPROM.read(4);
    digitalWrite(RelayPin4, !relay_state4);
    
    
    SwitchState_4 = HIGH;
    my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, relay_state4);
    EEPROM.put(4, !relay_state4);
    EEPROM.put(14, SwitchState_4);
    EEPROM.commit();
    Serial.println("Switch-4 on");
    Serial.println(EEPROM.read(4));
  }
  if (digitalRead(SwitchPin4) == HIGH && SwitchState_4 == HIGH) {
    Serial.println("Switch 4");
    relay_state4 = EEPROM.read(4);
    digitalWrite(RelayPin4, !relay_state4);
    
    SwitchState_4 = LOW;
    my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,relay_state4);
    EEPROM.put(4, !relay_state4);
    EEPROM.put(14, SwitchState_4);
    EEPROM.commit();
    Serial.println("Switch-4 off");
    Serial.println(EEPROM.read(4));
  }


//---------------------------------------------------------------------------------------------------------
  

  if (digitalRead(SwitchPin5) == LOW && SwitchState_5 == LOW) {
    Serial.println("Switch 5");
    relay_state5 = EEPROM.read(5);
    digitalWrite(RelayPin5, !relay_state5);
    
    
    SwitchState_5 = HIGH;
    my_switch5.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, relay_state5);
    EEPROM.put(5, !relay_state5);
    EEPROM.put(15, SwitchState_5);
    EEPROM.commit();
    Serial.println("Switch-5 on");
    Serial.println(EEPROM.read(5));
  }
  if (digitalRead(SwitchPin5) == HIGH && SwitchState_5 == HIGH) {
    Serial.println("Switch 5");
    relay_state5 = EEPROM.read(5);
    digitalWrite(RelayPin5, !relay_state5);
    
    SwitchState_5 = LOW;
    my_switch5.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,relay_state5);
    EEPROM.put(5, !relay_state5);
    EEPROM.put(15, SwitchState_5);
    EEPROM.commit();
    Serial.println("Switch-5 off");
    Serial.println(EEPROM.read(5));
  }


//---------------------------------------------------------------------------------------------------------
  

  if (digitalRead(SwitchPin6) == LOW && SwitchState_6 == LOW) {
    relay_state6 = EEPROM.read(6);
    digitalWrite(RelayPin6, !relay_state6);
    
    
    SwitchState_6 = HIGH;
    my_switch6.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, relay_state6);
    EEPROM.put(6, !relay_state6);
    EEPROM.put(16, SwitchState_6);
    EEPROM.commit();
    Serial.println("Switch-6 on");
    Serial.println(EEPROM.read(6));
  }
  if (digitalRead(SwitchPin6) == HIGH && SwitchState_6 == HIGH) {
    relay_state6 = EEPROM.read(6);
    digitalWrite(RelayPin6, !relay_state6);
    
    SwitchState_6 = LOW;
    my_switch6.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,relay_state6);
    EEPROM.put(6, !relay_state6);
    EEPROM.put(16, SwitchState_6);
    EEPROM.commit();
    Serial.println("Switch-6 off");
    Serial.println(EEPROM.read(6));
  }
}
