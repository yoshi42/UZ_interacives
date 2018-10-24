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
int darlington2_buttonLED2 = 24; // HIGH signal = close circuit
int darlington3_buttonLED3 = 26; // HIGH signal = close circuit
int darlington4_buttonLED4 = 28; // HIGH signal = close circuit
int darlington5_buttonLED5 = 30; // HIGH signal = close circuit
int darlington6_buttonLED6 = 32; // HIGH signal = close circuit
int darlington7_buttonLED7 = 34; // HIGH signal = close circuit
int darlington8_buttonLED8 = 36; // HIGH signal = close circuit
int darlington9_buttonLED9 = 38; // HIGH signal = close circuit
int darlington10_buttonLED10 = 40; // HIGH signal = close circuit

int push_counter = 42;//

int mosfet1 = 19;
int mosfet2 = 18;
int mosfet3 = 17;
int mosfet4 = 16;
int mosfet5 = 15;
int mosfet6 = 14;
int mosfet7 = 2;
int mosfet8 = 3;

int mosfet9 = 4;
int mosfet10 = 5;
int mosfet11 = 6;
int mosfet12 = 7;
int mosfet13 = 8;
int mosfet14 = 9;
int mosfet15 = 10;
int mosfet16 = 11;

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

void but1_rel() //
{
	if (digitalRead(but1) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0)
	{
		delay(50);
		flag1 = 1;
		Serial.println("Button1_pushed, run something");
		
		all_buttons_light_off();
		digitalWrite(darlington1_buttonLED1, HIGH);
		delay(1000); //to lift eyes to the map
		digitalWrite(mosfet1, HIGH);

		ButtonTime1 = millis();
	}

	if ((millis() - ButtonTime1 > 5000) && flag1 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag1 = 0;

		digitalWrite(mosfet1, LOW);
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
		delay(1000); //to lift eyes to the map
		digitalWrite(mosfet2, HIGH);

		ButtonTime2 = millis();
	}

	if ((millis() - ButtonTime2 > 5000) && flag2 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag2 = 0;

		digitalWrite(mosfet2, LOW);
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
		delay(1000); //to lift eyes to the map
		digitalWrite(mosfet3, HIGH);

		ButtonTime3 = millis();
	}

	if ((millis() - ButtonTime3 > 5000) && flag3 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag3 = 0;

		digitalWrite(mosfet3, LOW);
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
		delay(1000); //to lift eyes to the map
		digitalWrite(mosfet4, HIGH);

		ButtonTime4 = millis();
	}

	if ((millis() - ButtonTime4 > 5000) && flag4 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag4 = 0;

		digitalWrite(mosfet4, LOW);
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
		delay(1000); //to lift eyes to the map
		digitalWrite(mosfet5, HIGH);

		ButtonTime5 = millis();
	}

	if ((millis() - ButtonTime5 > 5000) && flag5 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag5 = 0;

		digitalWrite(mosfet5, LOW);
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
		delay(1000); //to lift eyes to the map
		digitalWrite(mosfet6, HIGH);

		ButtonTime6 = millis();
	}

	if ((millis() - ButtonTime6 > 5000) && flag6 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag6 = 0;

		digitalWrite(mosfet6, LOW);
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
		delay(1000); //to lift eyes to the map
		digitalWrite(mosfet7, HIGH);

		ButtonTime7 = millis();
	}

	if ((millis() - ButtonTime7 > 5000) && flag7 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag7 = 0;

		digitalWrite(mosfet7, LOW);
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
		delay(1000); //to lift eyes to the map
		digitalWrite(mosfet8, HIGH);

		ButtonTime8 = millis();
	}

	if ((millis() - ButtonTime8 > 5000) && flag8 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag8 = 0;

		digitalWrite(mosfet8, LOW);
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
		delay(1000); //to lift eyes to the map
		digitalWrite(mosfet9, HIGH);

		ButtonTime9 = millis();
	}

	if ((millis() - ButtonTime9 > 5000) && flag9 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag9 = 0;

		digitalWrite(mosfet9, LOW);
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
		delay(1000); //to lift eyes to the map
		digitalWrite(mosfet10, HIGH);

		ButtonTime10 = millis();
	}

	if ((millis() - ButtonTime10 > 5000) && flag10 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag10 = 0;

		digitalWrite(mosfet10, LOW);
		Serial.println("something done, buttons light on, ready for new loop");
		RamkaTime10 = millis();
		all_buttons_light_on();
	}
}