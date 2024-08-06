# Alarm_RTC_System
## Description 
clock system based on RTC IC to provide real time clock , alarming system and timer. once clock hit time set for alarm, the buzzer is turned on for about 3 seconds. Timer can be used to turn buzzer on after certain amount of hours , minutes or seconds after time is set allowing user to be alarmed about something that will occur after a while
## Specification
the system provide the following functionalities :
<ol>
  <li>View real time clock and date : relaying on time provided by DS1307 RTC IC   </li>
  <li>Set Alarm in hours , minutes and seconds : to alarm user about important event  </li>
  <li>Set Timer in hours , minutes and seconds : help user to do multiple tasks and don't miss any deadlines</li>
  <li>Store both Alarm and Timer values in EEPROM : so that alarms and timers aren't missed   </li>
</ol>

## Components Used
this project utilized the following components :
<ul>
  <li> ATMEGA32 Microcontroller : to provide computational and multi task operations </li>
  <li> MS2408 EEPROM IC : to store and load data used for alarming   </li>
  <li> DS1307 RTC IC : to provide Real Time Clock and date </li>
  <li> LM041L LCD : to display time and date in addition to options of alarm and timer and any action done   </li>
  <li> 4*4 Keypad : to perform multiple functions either alarm or timer setting   </li>
  <li> Buzzer and Led : the led blinks to ensure system is working and buzzer is turned on by alarm or timer   </li>
</ul>

## Future Work
project is meant to grow to bigger one by doing the following
<ul>
  <li> Allow user to set time for which buzzer is on </li>
  <li> Allow user to cancel alarm or timer set  </li>
  <li> Enable intergrating this project with other project to perform smart phone like tasks </li>
</ul>
