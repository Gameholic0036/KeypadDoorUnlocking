*PROJECT NAME:- KEYPAD DOOR UNLOCKING**
- **INTRODUCTION** 
     Welcome to my project of making a keypad door unlocking system. It works with help of ardino uno . The Arduino uno has been coded such that if you enter the right password then a door will be open with help of a servo motor. 
- **Parts Required**

 	​1.- Arduino uno
 	2. Bread board
 	3. Lcd Display
 	4. Keypad 4*4
 	5. Jumper wires(male to male about 25 peices)
 	6. Buzzer
 	7. Servomotor
- **Work of all different parts stated above _**
-   Let's start with **_LCD DISPLAY _**
-  ​		LCD DISPLAY is used to present to the users the different messages that guides him/her in using the project. 

    As we can see an 16*2 lcd display is being used in the project.The term 16*2 signifies that displaying 16 character over 2 lines.It's display screen glow with a green blacklight.It can easily be operated on 5  voltage power, So it can be powered with help of ardino uno. 
It has as many as 18 pins which can be seen in picture. ![IMG-20200106-WA0005](IMG-20200106-WA0005.jpg)

    Starting from side we have 2 pins which which is used to power the back green light of the lcd. The rightmost pin named '**A**', '**K**' is also for the same purpose. The left most pins **VSS** and **VDD** is used for powering lcd displaying. The third pin named  **VO** provides help in controlling the contrast of lcd display. The fourth pin is **register select** which is connected to a pin in Arduino board, the fifth pin is a called**Read Write** pin , it is grounded while sixth pin is the  ** ENABLE ** which also occupies an pin on Arduino board. 
