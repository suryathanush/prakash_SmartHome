void BT(){
  if(Serial2.available()) {
   cmd = Serial2.readString();
    //Serial.println(cmd);



    if (cmd=="A") {
    digitalWrite(RelayPin1, LOW);
    
    my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
    EEPROM.put(1, false);
    EEPROM.commit();
  }
 else if (cmd=="a") {
    digitalWrite(RelayPin1, HIGH);
   
    my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,false);
    EEPROM.put(1, true);
    EEPROM.commit();
  }


  else if (cmd=="B") {
    digitalWrite(RelayPin2, LOW);
    
    my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
    EEPROM.put(2, false);
    EEPROM.commit();
  }
 else if (cmd=="b") {
    digitalWrite(RelayPin2, HIGH);
   
    my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,false);
    EEPROM.put(2, true);
    EEPROM.commit();
  }



  else if (cmd=="C") {
    digitalWrite(RelayPin3, LOW);
    
    my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
    EEPROM.put(3, false);
    EEPROM.commit();
  }
 else if (cmd=="c") {
    digitalWrite(RelayPin3, HIGH);
   
    my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,false);
    EEPROM.put(3, true);
    EEPROM.commit();
  }



  else if (cmd=="D") {
    digitalWrite(RelayPin4, LOW);
    
    my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
    EEPROM.put(4, false);
    EEPROM.commit();
  }
 else if (cmd=="d") {
    digitalWrite(RelayPin4, HIGH);
   
    my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,false);
    EEPROM.put(4, true);
    EEPROM.commit();
  }



  else if (cmd=="E") {
    digitalWrite(RelayPin5, LOW);
    
    my_switch5.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
    EEPROM.put(5, false);
    EEPROM.commit();
  }
 else if (cmd=="e") {
    digitalWrite(RelayPin5, HIGH);
   
    my_switch5.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,false);
    EEPROM.put(5, true);
    EEPROM.commit();
  }


  else if (cmd=="F") {
    digitalWrite(RelayPin6, LOW);
    
    my_switch6.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
    EEPROM.put(6, false);
    EEPROM.commit();
  }
 else if (cmd=="f") {
    digitalWrite(RelayPin6, HIGH);
   
    my_switch6.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,false);
    EEPROM.put(6, true);
    EEPROM.commit();
  }
  

  else if (cmd=="Z") {
    digitalWrite(RelayPin1, LOW);
    digitalWrite(RelayPin2, LOW);
    digitalWrite(RelayPin3, LOW);
    digitalWrite(RelayPin4, LOW);
    digitalWrite(RelayPin5, LOW);
    digitalWrite(RelayPin6, LOW);
    
   
    my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,true);
    my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,true);
    my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,true);
    my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,true);
    my_switch5.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,true);
    my_switch6.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,true);
    
    EEPROM.put(1, false);
    EEPROM.put(2, false);
    EEPROM.put(3, false);
    EEPROM.put(4, false);
    EEPROM.put(5, false);
    EEPROM.put(6, false);
    
    EEPROM.commit();
  }

  else if (cmd=="z") {
    digitalWrite(RelayPin1, HIGH);
    digitalWrite(RelayPin2, HIGH);
    digitalWrite(RelayPin3, HIGH);
    digitalWrite(RelayPin4, HIGH);
    digitalWrite(RelayPin5, HIGH);
    digitalWrite(RelayPin6, HIGH);
    
   
    my_switch1.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,false);
    my_switch2.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,false);
    my_switch3.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,false);
    my_switch4.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,false);
    my_switch5.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,false);
    my_switch6.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME,false);
    
    EEPROM.put(1, true);
    EEPROM.put(2, true);
    EEPROM.put(3, true);
    EEPROM.put(4, true);
    EEPROM.put(5, true);
    EEPROM.put(6, true);
    
    EEPROM.commit();
  }

  else if (cmd=="G") {
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

   else if (cmd=="g") {
    my_fan.updateAndReportParam(ESP_RMAKER_DEF_POWER_NAME, true);
    cur_speed=EEPROM.read(9);
      if(cur_speed>0){
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
