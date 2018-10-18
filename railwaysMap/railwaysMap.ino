/*Interactive installation of railways map of Ukraine. Read the question, push the button, see some activity*/

int but1 = 23;
int but2 = 25;
int but3 = 27;
int but4 = 31;
int but5 = 35;
int but6 = 39;
int but7 = 43;
int but8 = 47;

int mosfet1_answerLED1 = 22; // HIGH signal = close circuit
int mosfet2_answerLED2 = 24; // HIGH signal = close circuit
int mosfet3_answerLED3 = 26; // HIGH signal = close circuit
int mosfet4_answerLED4 = 28; // HIGH signal = close circuit
int mosfet5_answerLED5 = 30; // HIGH signal = close circuit
int mosfet6_answerLED6 = 32; // HIGH signal = close circuit
int mosfet7_answerLED7 = 34; // HIGH signal = close circuit
int mosfet8_answerLED8 = 36; // HIGH signal = close circuit

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

	pinMode(mosfet1_answerLED1, OUTPUT);
    pinMode(mosfet2_answerLED2, OUTPUT);
    pinMode(mosfet3_answerLED3, OUTPUT);
    pinMode(mosfet4_answerLED4, OUTPUT);
    pinMode(mosfet5_answerLED5, OUTPUT);
    pinMode(mosfet6_answerLED6, OUTPUT);
    pinMode(mosfet7_answerLED7, OUTPUT);
    pinMode(mosfet8_answerLED8, OUTPUT);

	digitalWrite(mosfet1_answerLED1, LOW);
  	digitalWrite(mosfet2_answerLED2, LOW);
  	digitalWrite(mosfet3_answerLED3, LOW);
  	digitalWrite(mosfet4_answerLED4, LOW);
  	digitalWrite(mosfet5_answerLED5, LOW);
  	digitalWrite(mosfet6_answerLED6, LOW);
  	digitalWrite(mosfet7_answerLED7, LOW);
  	digitalWrite(mosfet8_answerLED8, LOW);
  	digitalWrite(stepper_curtains_en, LOW);
}

void loop()
{
	but1_rel();
}

void but1_rel() // 1Gramofon
{
	if (digitalRead(but1) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0)
	{
		delay(50);
		flag1 = 1;
		Serial.println("Button1_pushed, run Gramofon");
		
		mp3_set_serial(Serial3);
		delay(10);
		mp3_set_volume (20);
		mp3_play(1);  // play track "Gramofon"

		ButtonTime1 = millis();
	}

	if ((millis() - ButtonTime1 > 2000) && flag1 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag1 = 0;
		digitalWrite(mosfet1_answerLED1, HIGH); //show the answer
		Serial.println("Gramofon done, light is on for delay_time to read an answer");
		RamkaTime1 = millis();
		delay(delay_time);
		digitalWrite(mosfet1_answerLED1, LOW); //hide the answer
		Serial.println("Light1 is off");

	}
}