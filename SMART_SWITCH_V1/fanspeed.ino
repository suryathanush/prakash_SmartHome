void zero(){
  digitalWrite(A_fan_speed_relay_1,HIGH);
  digitalWrite(A_fan_speed_relay_2,HIGH);
  digitalWrite(A_fan_speed_relay_3,HIGH);
  
}
void one(){
  
  //digitalWrite(A_fan_speed_relay_1,HIGH);
  digitalWrite(A_fan_speed_relay_2,HIGH);
  digitalWrite(A_fan_speed_relay_3,HIGH);
  //delay(500);
  digitalWrite(A_fan_speed_relay_1,LOW);
  
}
void two(){
  
  digitalWrite(A_fan_speed_relay_1,HIGH);
  //digitalWrite(A_fan_speed_relay_2,HIGH);
  digitalWrite(A_fan_speed_relay_3,HIGH);
  //delay(500);
  digitalWrite(A_fan_speed_relay_2,LOW);
  
}
void three(){
  
  //digitalWrite(A_fan_speed_relay_1,HIGH);
  //digitalWrite(A_fan_speed_relay_2,HIGH);
  digitalWrite(A_fan_speed_relay_3,HIGH);
  //delay(500);
  digitalWrite(A_fan_speed_relay_1,LOW);
  digitalWrite(A_fan_speed_relay_2,LOW);
  
}
void four(){
  
  digitalWrite(A_fan_speed_relay_1,HIGH);
  digitalWrite(A_fan_speed_relay_2,HIGH);
  //digitalWrite(A_fan_speed_relay_3,HIGH);
  //delay(500);
  digitalWrite(A_fan_speed_relay_3,LOW);
  
}
