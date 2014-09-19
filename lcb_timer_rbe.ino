//Nam Tran Ngoc- RBE2001
//Homework #3
//Display elapsed time since the program started in hh:mm:ss format on LCD screen.
//Using a pushbutton attached to pin 2 to act as a reset timer button.

#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,1); //Create lcd object

volatile int state = LOW;
int elapsedTime=0;
int currentTime=0;

void setup(){
  lcd.begin(16,2);
  attachInterrupt(0, changeState, CHANGE);  
}

void loop(){
  lcd.setCursor(0,0);
  elapsedTime=(millis()/1000)-currentTime;
  displayTime(elapsedTime);
}

void changeState(){
  currentTime=millis()/1000;
}

void displayTime(int total){
  //convert total seconds to hour and minutes
  int hour=total/3600;
  int minute=(total/60)%60;
  int second=total%60;
  //add padding to the time
  displayWithPad(hour,minute,second);
}

void displayWithPad(int hour,int minute, int second){

  String trueHour;
  String trueMinute;
  String trueSecond;
  
  if (hour<10){
    trueHour='0'+String(hour);
  }else {trueHour= String(hour);}
  
  if (minute<10){
    trueMinute='0'+String(minute);
  }else {trueMinute= String(minute);}
  
  if (second<10){
    trueSecond='0'+String(second);
  }else {trueSecond=String(second);}
  
  lcd.print(trueHour+":"+trueMinute+":"+trueSecond);
}
