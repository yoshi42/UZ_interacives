/*Interactive installation of railways map of Ukraine. Read the question, push the button, see some activity, read an answer*/

int but1 = 23;
int but2 = 25;
int but3 = 27;
int but4 = 29;
int but5 = 31;
int but6 = 33;
int but7 = 35;
int but8 = 37;
int but9 = 39;
int but10 = 41;


int darlington1_buttonLED1 = 22; // HIGH signal = close circuit
int darlington2_buttonLED2 = 24;
int darlington3_buttonLED3 = 26;
int darlington4_buttonLED4 = 28;
int darlington5_buttonLED5 = 30;
int darlington6_buttonLED6 = 32;
int darlington7_buttonLED7 = 34;
int darlington8_buttonLED8 = 36;
int darlington9_buttonLED9 = 38;
int darlington10_buttonLED10 = 40;

int push_counter = 42;//

int mosfet1 = 4;  // HIGH signal = close circuit
int mosfet2 = 5; //dot
int mosfet3 = 6; //__empty
int mosfet4 = 7; //dot
int mosfet5 = 8; //line
int mosfet6 = 9; //line
int mosfet7 = 10; //line
int mosfet8 = 11; //dot

int mosfet9 = 19; //dot
int mosfet10 = 18; //___empty
int mosfet11 = 17; //1,6,10
int mosfet12 = 16; //3,6
int mosfet13 = 15; //5,6
int mosfet14 = 14; //10,6
int mosfet15 = 2; //5,6,10
int mosfet16 = 3; //1,5,6,10

unsigned long RamkaTime1;
unsigned long RamkaTime2;
unsigned long RamkaTime3;
unsigned long RamkaTime4;
unsigned long RamkaTime5;
unsigned long RamkaTime6;
unsigned long RamkaTime7;
unsigned long RamkaTime8;
unsigned long RamkaTime9;
unsigned long RamkaTime10;

unsigned long ButtonTime1;
unsigned long ButtonTime2;
unsigned long ButtonTime3;
unsigned long ButtonTime4;
unsigned long ButtonTime5;
unsigned long ButtonTime6;
unsigned long ButtonTime7;
unsigned long ButtonTime8;
unsigned long ButtonTime9;
unsigned long ButtonTime10;

bool flag1 = 0;
bool flag2 = 0;
bool flag3 = 0;
bool flag4 = 0;
bool flag5 = 0;
bool flag6 = 0;
bool flag7 = 0;
bool flag8 = 0;
bool flag9 = 0;
bool flag10 = 0;


int del = 5000; //still on line time
int del_dot = 500; //blinking time

void setup()
{
	pinMode(but1, INPUT_PULLUP);
    pinMode(but2, INPUT_PULLUP);
    pinMode(but3, INPUT_PULLUP);
    pinMode(but4, INPUT_PULLUP);
    pinMode(but5, INPUT_PULLUP);
    pinMode(but6, INPUT_PULLUP);
    pinMode(but7, INPUT_PULLUP);
    pinMode(but8, INPUT_PULLUP);
    pinMode(but9, INPUT_PULLUP);
    pinMode(but10, INPUT_PULLUP);

	pinMode(darlington1_buttonLED1, OUTPUT);
    pinMode(darlington2_buttonLED2, OUTPUT);
    pinMode(darlington3_buttonLED3, OUTPUT);
    pinMode(darlington4_buttonLED4, OUTPUT);
    pinMode(darlington5_buttonLED5, OUTPUT);
    pinMode(darlington6_buttonLED6, OUTPUT);
    pinMode(darlington7_buttonLED7, OUTPUT);
    pinMode(darlington8_buttonLED8, OUTPUT);
    pinMode(darlington9_buttonLED9, OUTPUT);
    pinMode(darlington10_buttonLED10, OUTPUT);

    pinMode(push_counter, OUTPUT);

    pinMode(mosfet1, OUTPUT);
    pinMode(mosfet2, OUTPUT);
    pinMode(mosfet3, OUTPUT);
    pinMode(mosfet4, OUTPUT);
    pinMode(mosfet5, OUTPUT);
    pinMode(mosfet6, OUTPUT);
    pinMode(mosfet7, OUTPUT);
    pinMode(mosfet8, OUTPUT);

    pinMode(mosfet9, OUTPUT);
    pinMode(mosfet10, OUTPUT);
    pinMode(mosfet11, OUTPUT);
    pinMode(mosfet12, OUTPUT);
    pinMode(mosfet13, OUTPUT);
    pinMode(mosfet14, OUTPUT);
    pinMode(mosfet15, OUTPUT);
    pinMode(mosfet16, OUTPUT);

	digitalWrite(darlington1_buttonLED1, HIGH);
  	digitalWrite(darlington2_buttonLED2, HIGH);
  	digitalWrite(darlington3_buttonLED3, HIGH);
  	digitalWrite(darlington4_buttonLED4, HIGH);
  	digitalWrite(darlington5_buttonLED5, HIGH);
  	digitalWrite(darlington6_buttonLED6, HIGH);
  	digitalWrite(darlington7_buttonLED7, HIGH);
  	digitalWrite(darlington8_buttonLED8, HIGH);
  	digitalWrite(darlington9_buttonLED9, HIGH);
  	digitalWrite(darlington10_buttonLED10, HIGH);

  	digitalWrite(push_counter, LOW);

  	digitalWrite(mosfet1, LOW);
  	digitalWrite(mosfet2, LOW);
  	digitalWrite(mosfet3, LOW);
  	digitalWrite(mosfet4, LOW);
  	digitalWrite(mosfet5, LOW);
  	digitalWrite(mosfet6, LOW);
  	digitalWrite(mosfet7, LOW);
  	digitalWrite(mosfet8, LOW);

  	digitalWrite(mosfet9, LOW);
  	digitalWrite(mosfet10, LOW);
  	digitalWrite(mosfet11, LOW);
  	digitalWrite(mosfet12, LOW);
  	digitalWrite(mosfet13, LOW);
  	digitalWrite(mosfet14, LOW);
  	digitalWrite(mosfet15, LOW);
  	digitalWrite(mosfet16, LOW);

  	Serial.begin(9600);
  	//all_map_on(); //for static work testing
	//all_buttons_light_on();
  	//all_buttons_light_off();
  	//dely(5000);
  	//demo(); //for dynamic work testing
 	//all_map_on();
  	//all_mosfets_test();
}

void loop()
{
	but1_rel();
	but2_rel();
	but3_rel();
	but4_rel();
	but5_rel();
	but6_rel();
	but7_rel();
	but8_rel();
	but9_rel();
	but10_rel();
}

void all_buttons_light_off()
{
	digitalWrite(darlington1_buttonLED1, LOW);
  	digitalWrite(darlington2_buttonLED2, LOW);
  	digitalWrite(darlington3_buttonLED3, LOW);
  	digitalWrite(darlington4_buttonLED4, LOW);
  	digitalWrite(darlington5_buttonLED5, LOW);
  	digitalWrite(darlington6_buttonLED6, LOW);
  	digitalWrite(darlington7_buttonLED7, LOW);
  	digitalWrite(darlington8_buttonLED8, LOW);
  	digitalWrite(darlington9_buttonLED9, LOW);
  	digitalWrite(darlington10_buttonLED10, LOW);

  	digitalWrite(push_counter, HIGH);
  	delay(50);
  	digitalWrite(push_counter, LOW);
}

void all_buttons_light_on()
{
	digitalWrite(darlington1_buttonLED1, HIGH);
  	digitalWrite(darlington2_buttonLED2, HIGH);
  	digitalWrite(darlington3_buttonLED3, HIGH);
  	digitalWrite(darlington4_buttonLED4, HIGH);
  	digitalWrite(darlington5_buttonLED5, HIGH);
  	digitalWrite(darlington6_buttonLED6, HIGH);
  	digitalWrite(darlington7_buttonLED7, HIGH);
  	digitalWrite(darlington8_buttonLED8, HIGH);
  	digitalWrite(darlington9_buttonLED9, HIGH);
  	digitalWrite(darlington10_buttonLED10, HIGH);
}

void all_map_off()
{
	digitalWrite(mosfet1, LOW);
  	digitalWrite(mosfet2, LOW);
  	digitalWrite(mosfet3, LOW);
  	digitalWrite(mosfet4, LOW);
  	digitalWrite(mosfet5, LOW);
  	digitalWrite(mosfet6, LOW);
  	digitalWrite(mosfet7, LOW);
  	digitalWrite(mosfet8, LOW);

  	digitalWrite(mosfet9, LOW);
  	digitalWrite(mosfet10, LOW);
  	digitalWrite(mosfet11, LOW);
  	digitalWrite(mosfet12, LOW);
  	digitalWrite(mosfet13, LOW);
  	digitalWrite(mosfet14, LOW);
  	digitalWrite(mosfet15, LOW);
  	digitalWrite(mosfet16, LOW);
}

void all_map_on()
{
	digitalWrite(mosfet1, HIGH);
  	digitalWrite(mosfet2, HIGH);
  	digitalWrite(mosfet3, HIGH);
  	digitalWrite(mosfet4, HIGH);
  	digitalWrite(mosfet5, HIGH);
  	digitalWrite(mosfet6, HIGH);
  	digitalWrite(mosfet7, HIGH);
  	digitalWrite(mosfet8, HIGH);

  	digitalWrite(mosfet9, HIGH);
  	digitalWrite(mosfet10, HIGH);
  	digitalWrite(mosfet11, HIGH);
  	digitalWrite(mosfet12, HIGH);
  	digitalWrite(mosfet13, HIGH);
  	digitalWrite(mosfet14, HIGH);
  	digitalWrite(mosfet15, HIGH);
  	digitalWrite(mosfet16, HIGH);
}

void all_mosfets_test()
{
	digitalWrite(mosfet1, HIGH);
	delay(1000);
  	digitalWrite(mosfet2, HIGH);
  	delay(1000);
  	digitalWrite(mosfet3, HIGH);
  	delay(1000);
  	digitalWrite(mosfet4, HIGH);
  	delay(1000);
  	digitalWrite(mosfet5, HIGH);
  	delay(1000);
  	digitalWrite(mosfet6, HIGH);
  	delay(1000);
  	digitalWrite(mosfet7, HIGH);
  	delay(1000);
  	digitalWrite(mosfet8, HIGH);
  	delay(1000);
  	digitalWrite(mosfet9, HIGH);
  	delay(1000);
  	digitalWrite(mosfet10, HIGH);
  	delay(1000);
  	digitalWrite(mosfet11, HIGH);
  	delay(1000);
  	digitalWrite(mosfet12, HIGH);
  	delay(1000);
  	digitalWrite(mosfet13, HIGH);
  	delay(1000);
  	digitalWrite(mosfet14, HIGH);
  	delay(1000);
  	digitalWrite(mosfet15, HIGH);
  	delay(1000);
  	digitalWrite(mosfet16, HIGH);
}

void demo()
{
	int save_del = del; //for saving previous value of variable
	int save_del_dot = del_dot; //
	del = 3000;
	del_dot = 300;

	answer1_on_off();
	delay(2000);
	answer2_on_off();
	delay(2000);
	answer3_on_off();
	delay(2000);
	answer4_on_off();
	delay(2000);
	answer5_on_off();
	delay(2000);
	answer6_on_off();
	delay(2000);
	answer7_on_off();
	delay(2000);
	answer8_on_off();
	delay(2000);
	answer9_on_off();
	delay(2000);
	answer10_on_off();

	del = save_del; //restore value of "del" variable
	del_dot = save_del_dot; //
}

void answer1_on_off()
{
	digitalWrite(mosfet1, HIGH);
	digitalWrite(mosfet11, HIGH);
	digitalWrite(mosfet16, HIGH);
	delay(del);
	digitalWrite(mosfet1, LOW);
	digitalWrite(mosfet11, LOW);
	digitalWrite(mosfet16, LOW);
}

void answer2_on_off()
{
	for(int i = 0; i <= 3; i++)
	{
		digitalWrite(mosfet2, HIGH);
		delay(del_dot);
		digitalWrite(mosfet2, LOW);
		delay(del_dot);
	}
}

void answer3_on_off()
{
	digitalWrite(mosfet12, HIGH);
	delay(del);
	digitalWrite(mosfet12, LOW);
}

void answer4_on_off()
{
	for(int i = 0; i <= 3; i++)
	{
		digitalWrite(mosfet4, HIGH);
		delay(del_dot);
		digitalWrite(mosfet4, LOW);
		delay(del_dot);
	}
}

void answer5_on_off()
{
	digitalWrite(mosfet5, HIGH);
	digitalWrite(mosfet13, HIGH);
	digitalWrite(mosfet15, HIGH);
	digitalWrite(mosfet16, HIGH);
	delay(del);
	digitalWrite(mosfet5, LOW);
	digitalWrite(mosfet13, LOW);
	digitalWrite(mosfet15, LOW);
	digitalWrite(mosfet16, LOW);
}

void answer6_on_off()
{
	digitalWrite(mosfet6, HIGH);
	digitalWrite(mosfet11, HIGH);
	digitalWrite(mosfet12, HIGH);
	digitalWrite(mosfet13, HIGH);
	digitalWrite(mosfet14, HIGH);
	digitalWrite(mosfet15, HIGH);
	digitalWrite(mosfet16, HIGH);
	delay(del);
	digitalWrite(mosfet6, LOW);
	digitalWrite(mosfet11, LOW);
	digitalWrite(mosfet12, LOW);
	digitalWrite(mosfet13, LOW);
	digitalWrite(mosfet14, LOW);
	digitalWrite(mosfet15, LOW);
	digitalWrite(mosfet16, LOW);
}

void answer7_on_off()
{
	digitalWrite(mosfet7, HIGH);
	delay(del);
	digitalWrite(mosfet7, LOW);
}

void answer8_on_off()
{
	for(int i = 0; i <= 5; i++)
	{
		digitalWrite(mosfet8, HIGH);
		delay(del_dot);
		digitalWrite(mosfet8, LOW);
		delay(del_dot);
	}
}

void answer9_on_off()
{
	for(int i = 0; i <= 3; i++)
	{
		digitalWrite(mosfet9, HIGH);
		delay(del_dot);
		digitalWrite(mosfet9, LOW);
		delay(del_dot);
	}
}

void answer10_on_off()
{
	digitalWrite(mosfet11, HIGH);
	digitalWrite(mosfet14, HIGH);
	digitalWrite(mosfet15, HIGH);
	digitalWrite(mosfet16, HIGH);
	delay(del);
	digitalWrite(mosfet11, LOW);
	digitalWrite(mosfet14, LOW);
	digitalWrite(mosfet15, LOW);
	digitalWrite(mosfet16, LOW);
}

void but1_rel() //
{
	if (digitalRead(but1) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0)
	{
		delay(50);
		flag1 = 1;
		Serial.println("Button1_pushed, run something");
		
		all_buttons_light_off();
		digitalWrite(darlington1_buttonLED1, HIGH);

		answer1_on_off();

		ButtonTime1 = millis();
	}

	if ((millis() - ButtonTime1 > 10) && flag1 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag1 = 0;

		Serial.println("something done, buttons light on, ready for new loop");
		RamkaTime1 = millis();
		all_buttons_light_on();
	}
}

void but2_rel() //
{
	if (digitalRead(but2) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0 && flag9 == 0 && flag10 == 0)
	{
		delay(50);
		flag2 = 1;
		Serial.println("Button2_pushed, run something");
		
		all_buttons_light_off();
		digitalWrite(darlington2_buttonLED2, HIGH);
		answer2_on_off();

		ButtonTime2 = millis();
	}

	if ((millis() - ButtonTime2 > 10) && flag2 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag2 = 0;

		Serial.println("something done, buttons light on, ready for new loop");
		RamkaTime2 = millis();
		all_buttons_light_on();
	}
}

void but3_rel() //
{
	if (digitalRead(but3) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0 && flag9 == 0 && flag10 == 0)
	{
		delay(50);
		flag3 = 1;
		Serial.println("Button3_pushed, run something");
		
		all_buttons_light_off();
		digitalWrite(darlington3_buttonLED3, HIGH);
		answer3_on_off();

		ButtonTime3 = millis();
	}

	if ((millis() - ButtonTime3 > 10) && flag3 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag3 = 0;

		Serial.println("something done, buttons light on, ready for new loop");
		RamkaTime3 = millis();
		all_buttons_light_on();
	}
}

void but4_rel() //
{
	if (digitalRead(but4) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0 && flag9 == 0 && flag10 == 0)
	{
		delay(50);
		flag4 = 1;
		Serial.println("Button4_pushed, run something");
		
		all_buttons_light_off();
		digitalWrite(darlington4_buttonLED4, HIGH);
		answer4_on_off();

		ButtonTime4 = millis();
	}

	if ((millis() - ButtonTime4 > 10) && flag4 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag4 = 0;

		Serial.println("something done, buttons light on, ready for new loop");
		RamkaTime4 = millis();
		all_buttons_light_on();
	}
}

void but5_rel() //
{
	if (digitalRead(but5) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0 && flag9 == 0 && flag10 == 0)
	{
		delay(50);
		flag5 = 1;
		Serial.println("Button5_pushed, run something");
		
		all_buttons_light_off();
		digitalWrite(darlington5_buttonLED5, HIGH);
		answer5_on_off();

		ButtonTime5 = millis();
	}

	if ((millis() - ButtonTime5 > 10) && flag5 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag5 = 0;

		Serial.println("something done, buttons light on, ready for new loop");
		RamkaTime5 = millis();
		all_buttons_light_on();
	}
}

void but6_rel() //
{
	if (digitalRead(but6) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0 && flag9 == 0 && flag10 == 0)
	{
		delay(50);
		flag6 = 1;
		Serial.println("Button6_pushed, run something");
		
		all_buttons_light_off();
		digitalWrite(darlington6_buttonLED6, HIGH);
		answer6_on_off();

		ButtonTime6 = millis();
	}

	if ((millis() - ButtonTime6 > 10) && flag6 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag6 = 0;

		Serial.println("something done, buttons light on, ready for new loop");
		RamkaTime6 = millis();
		all_buttons_light_on();
	}
}

void but7_rel() //
{
	if (digitalRead(but7) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0 && flag9 == 0 && flag10 == 0)
	{
		delay(50);
		flag7 = 1;
		Serial.println("Button7_pushed, run something");
		
		all_buttons_light_off();
		digitalWrite(darlington7_buttonLED7, HIGH);
		answer7_on_off();

		ButtonTime7 = millis();
	}

	if ((millis() - ButtonTime7 > 10) && flag7 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag7 = 0;

		Serial.println("something done, buttons light on, ready for new loop");
		RamkaTime7 = millis();
		all_buttons_light_on();
	}
}

void but8_rel() //
{
	if (digitalRead(but8) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0 && flag9 == 0 && flag10 == 0)
	{
		delay(50);
		flag8 = 1;
		Serial.println("Button8_pushed, run something");
		
		all_buttons_light_off();
		digitalWrite(darlington8_buttonLED8, HIGH);
		answer8_on_off();

		ButtonTime8 = millis();
	}

	if ((millis() - ButtonTime8 > 10) && flag8 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag8 = 0;

		Serial.println("something done, buttons light on, ready for new loop");
		RamkaTime8 = millis();
		all_buttons_light_on();
	}
}

void but9_rel() //
{
	if (digitalRead(but9) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0 && flag9 == 0 && flag10 == 0)
	{
		delay(50);
		flag9 = 1;
		Serial.println("Button9_pushed, run something");
		
		all_buttons_light_off();
		digitalWrite(darlington9_buttonLED9, HIGH);
		answer9_on_off();

		ButtonTime9 = millis();
	}

	if ((millis() - ButtonTime9 > 10) && flag9 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag9 = 0;

		Serial.println("something done, buttons light on, ready for new loop");
		RamkaTime9 = millis();
		all_buttons_light_on();
	}
}

void but10_rel() //
{
	if (digitalRead(but10) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0 && flag9 == 0 && flag10 == 0)
	{
		delay(50);
		flag10 = 1;
		Serial.println("Button10_pushed, run something");
		
		all_buttons_light_off();
		digitalWrite(darlington10_buttonLED10, HIGH);
		answer10_on_off();

		ButtonTime10 = millis();
	}

	if ((millis() - ButtonTime10 > 10) && flag10 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag10 = 0;

		Serial.println("something done, buttons light on, ready for new loop");
		RamkaTime10 = millis();
		all_buttons_light_on();
	}
}