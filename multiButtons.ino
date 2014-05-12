/*
MultiButtons.ino

Handles multiple counters for indiviual button presses.
Uses two global arrayt.
			One to track the counters.
			Second to track old button states.
If require more or less pins modify array sizes.

This sketch monitors from I/O pins 4 to 6.

Tracking button pressed or release can be managed changing the return values on
stdButton()

*/



int lstCounter[] = {0,0,0};																									
int lstOldButton [] = {0,0,0};

/*----------------------------Main------------------------------------*/

void setup(){
	Serial.begin(9600);
	Serial.println("Iniciando ------");

	
}

void loop(){
  for(int i=4; i < 7; i++){																								// from pin 4 to 6 (7-1)
    if(stdButton(i) == 1){
      counterAdd(i);
      char btnLog[40]; btnLog[0]= '\0';
      sprintf(btnLog, "Button/Counter: %i - %i", i, lstCounter[i-4]);
      Serial.println(btnLog);
    }
  }
}

/*-----------------------functions--------------------------------------*/


void counterAdd(int index){
	index -= 4;
  lstCounter[index] +=1;
}

int stdButton(int button){
  int btnCurrent = digitalRead(button);
  delay(10);																																//lazy debounce
	int buttonIndex = button - 4;
  
  if (lstOldButton[buttonIndex] == btnCurrent){
    return 0;
  }
  else if (lstOldButton[buttonIndex] == 1 && btnCurrent == 0){
     lstOldButton[buttonIndex] = btnCurrent;
    return 1;
  }
  else if ( lstOldButton[buttonIndex] == 0 && btnCurrent == 1){
    lstOldButton[buttonIndex] = btnCurrent;
    return 0;
  }
}



	
