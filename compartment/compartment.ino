/*Interactive installation of Franz Jozeph's train compartment. Read the question, push the button, see some activity,
read an answer */

/*All buttons are active. When you push one of them, all other become inactive */

//1 Gramophone
//2 Mirror
//3 Ticket
//4 Beep
//5 Curtain
//6 Tea
//7 Book
//8 Light

#include <Servo.h>
#include <DFPlayer_Mini_Mp3.h>
#include <FastLED.h>

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

int mosfet1_mirror = 46; // HIGH signal = close circuit
int mosfet2_tea = 44; // HIGH signal = close circuit
int mosfet7_book = 38; // HIGH signal = close circuit
int ssr1_light1 = 40; // LOW signal = close circuit
int ssr2_light2 = 42; // LOW signal = close circuit
int servo_pin = 6;

int empty_pin1 = 50;
int empty_pin2 = 52;
int empty_pin3 = 53;
int empty_pin4 = 51;

Servo servo; //declare variable for servo

int stepper_Gramophone_stp = 2;
int stepper_Gramophone_dir = 3;

int stepper_curtains_stp = 4; 
int stepper_curtains_dir = 5;

int stepper_book_dir = 29;
int stepper_book_stp = 33;
int stepper_book_ms = 37;

int push_counter = 41;

int pleer1_busy = 15; //LOW = play, HIGH = stop
int pleer2_busy = 17;

unsigned long RamkaTime1;
unsigned long RamkaTime2;
unsigned long RamkaTime3;
unsigned long RamkaTime4;
unsigned long RamkaTime5;
unsigned long RamkaTime6;
unsigned long RamkaTime7;
unsigned long RamkaTime8;

unsigned long ButtonTime1;
unsigned long ButtonTime2;
unsigned long ButtonTime3;
unsigned long ButtonTime4;
unsigned long ButtonTime5;
unsigned long ButtonTime6;
unsigned long ButtonTime7;
unsigned long ButtonTime8;

bool flag1 = 0;
bool flag2 = 0;
bool flag3 = 0;
bool flag4 = 0;
bool flag5 = 0;
bool flag6 = 0;
bool flag7 = 0;
bool flag8 = 0;

#define NUM_LEDS 16 //number of leds in led strip
#define led_data_pin 7 //
CRGB leds[NUM_LEDS]; //define the array of leds

const int delay_time = 3000; //time to read an answer

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
    pinMode(pleer1_busy, INPUT_PULLUP);
    pinMode(pleer2_busy, INPUT_PULLUP);

    pinMode(mosfet1_answerLED1, OUTPUT);
    pinMode(mosfet2_answerLED2, OUTPUT);
    pinMode(mosfet3_answerLED3, OUTPUT);
    pinMode(mosfet4_answerLED4, OUTPUT);
    pinMode(mosfet5_answerLED5, OUTPUT);
    pinMode(mosfet6_answerLED6, OUTPUT);
    pinMode(mosfet7_answerLED7, OUTPUT);
    pinMode(mosfet8_answerLED8, OUTPUT);

    pinMode(mosfet1_mirror, OUTPUT);
    pinMode(mosfet2_tea, OUTPUT);
    pinMode(mosfet7_book, OUTPUT);
    pinMode(ssr1_light1, OUTPUT);
    pinMode(ssr2_light2, OUTPUT);
    pinMode(empty_pin1, OUTPUT);
    pinMode(empty_pin2, OUTPUT);
    pinMode(empty_pin3, OUTPUT);
    pinMode(empty_pin4, OUTPUT);

    pinMode(stepper_Gramophone_stp, OUTPUT);
	pinMode(stepper_Gramophone_dir, OUTPUT);

    pinMode(stepper_curtains_stp, OUTPUT);
	pinMode(stepper_curtains_dir, OUTPUT);

	pinMode(stepper_book_stp, OUTPUT);
	pinMode(stepper_book_dir, OUTPUT);
	pinMode(stepper_book_ms, OUTPUT);

	pinMode(push_counter, OUTPUT);

	servo.attach(servo_pin); //declare servo pin D10

    digitalWrite(mosfet1_answerLED1, LOW);
  	digitalWrite(mosfet2_answerLED2, LOW);
  	digitalWrite(mosfet3_answerLED3, LOW);
  	digitalWrite(mosfet4_answerLED4, LOW);
  	digitalWrite(mosfet5_answerLED5, LOW);
  	digitalWrite(mosfet6_answerLED6, LOW);
  	digitalWrite(mosfet7_answerLED7, LOW);
  	digitalWrite(mosfet8_answerLED8, LOW);

  	digitalWrite(mosfet1_mirror, LOW);
  	digitalWrite(mosfet2_tea, LOW);
  	digitalWrite(mosfet7_book, LOW);
  	digitalWrite(ssr1_light1, HIGH);
  	digitalWrite(ssr2_light2, HIGH);
  	digitalWrite(empty_pin1, LOW);
  	digitalWrite(empty_pin2, LOW);
  	digitalWrite(empty_pin3, LOW);
  	digitalWrite(empty_pin4, LOW);

	Serial.begin(9600);
	Serial2.begin(9600);
	Serial3.begin(9600);

	FastLED.addLeds<WS2811, led_data_pin, RGB>(leds, NUM_LEDS);

	servo.write(175); //stand servo for i degrees

	light_on();
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
}

void ticket()
{
	for (int i = 175; i >= 85; i--)
	{
		servo.write(i); //stand servo for i degrees
		Serial.println(i);
		delay(20);
	}
		delay(3000); //wait time
		servo.write(175); //stand servo for i degrees
}

void led_strip() 
{
	int del = 120; // delay
	for (int i = 3; i > 0; i--)
	{   // Move a single white led 
	   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) 
	   {
	      // Turn our current led on to white, then show the leds
	      leds[whiteLed] = CRGB::White;
	      leds[whiteLed+1] = CRGB::White;
	      // Show the leds (only one of which is set to color, from above)
	      FastLED.show();
	      // Wait a little bit
	      delay(del);
	      // Turn our current led back to black for the next loop around
	      leds[whiteLed] = CRGB::Black;
	      //leds[NUM_LEDS] = CRGB::Black;
	      FastLED.show();
	   }
	}
}

void curtains_open()
{
	digitalWrite(stepper_curtains_dir, HIGH);
    for(int a=0; a<1250; a++){
      digitalWrite(stepper_curtains_stp, HIGH);
      delayMicroseconds(600);
      digitalWrite(stepper_curtains_stp, LOW);
      delayMicroseconds(600);
    }
}

void curtains_close()
{
    digitalWrite(stepper_curtains_dir, LOW);
    for(int a=0; a<1250; a++){
      digitalWrite(stepper_curtains_stp, HIGH);
      delayMicroseconds(600);
      digitalWrite(stepper_curtains_stp, LOW);
      delayMicroseconds(600);
    }
}

void book_open()
{
	digitalWrite(stepper_book_dir, LOW);
    for(int a=0; a<2000; a++){
      digitalWrite(stepper_book_stp, HIGH);
      delayMicroseconds(600);
      digitalWrite(stepper_book_stp, LOW);
      delayMicroseconds(600);
    }
}

void book_close()
{
    digitalWrite(stepper_book_dir, HIGH);
    for(int a=0; a<2000; a++){
      digitalWrite(stepper_book_stp, HIGH);
      delayMicroseconds(600);
      digitalWrite(stepper_book_stp, LOW);
      delayMicroseconds(600);
    }
}

void gramo()
{
	digitalWrite(stepper_Gramophone_dir, LOW);
    for(long int a=0; a<35000; a++){
      digitalWrite(stepper_Gramophone_stp, HIGH);
      delayMicroseconds(100);
      digitalWrite(stepper_Gramophone_stp, LOW);
      delayMicroseconds(100);
    }
}

void light_on()
{
	digitalWrite(ssr1_light1, LOW);
	digitalWrite(ssr2_light2, LOW);
	delay(50);
	digitalWrite(ssr1_light1, HIGH);
	digitalWrite(ssr2_light2, HIGH);
	delay(80);
	digitalWrite(ssr1_light1, LOW);
	digitalWrite(ssr2_light2, LOW);
	delay(100);
	digitalWrite(ssr1_light1, HIGH);
	digitalWrite(ssr2_light2, HIGH);
	delay(150);
	digitalWrite(ssr1_light1, LOW);
	digitalWrite(ssr2_light2, LOW);
}

void light_on_quick()
{
	digitalWrite(ssr1_light1, LOW);
	digitalWrite(ssr2_light2, LOW);
	delay(22);
	digitalWrite(ssr1_light1, HIGH);
	digitalWrite(ssr2_light2, HIGH);
	delay(22);
	digitalWrite(ssr1_light1, LOW);
	digitalWrite(ssr2_light2, LOW);
	delay(22);
	digitalWrite(ssr1_light1, HIGH);
	digitalWrite(ssr2_light2, HIGH);
	delay(22);
	digitalWrite(ssr1_light1, LOW);
	digitalWrite(ssr2_light2, LOW);
}

void light_off()
{
	digitalWrite(ssr1_light1, HIGH);
	digitalWrite(ssr2_light2, HIGH);
}

void but1_rel() // 1Gramophone
{
	if (digitalRead(but1) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0)
	{
		delay(50);
		flag1 = 1;
		Serial.println("Button1_pushed, run Gramophone");
		
		mp3_set_serial(Serial3);
		delay(10);
		mp3_set_volume (30);
		mp3_play(1);  // play track "Gramophone"
		gramo(); //twis vinyl

		ButtonTime1 = millis();
	}

	if ((millis() - ButtonTime1 > 2000) && flag1 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag1 = 0;
		digitalWrite(mosfet1_answerLED1, HIGH); //show the answer
		Serial.println("Gramophone done, light is on for delay_time to read an answer");
		RamkaTime1 = millis();
		delay(delay_time);
		digitalWrite(mosfet1_answerLED1, LOW); //hide the answer
		Serial.println("Light1 is off");

	}
}

void but2_rel() // 2Mirror
{
	if (digitalRead(but2) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0)
	{
		delay(50);
		flag2 = 1;
		Serial.println("Button2_pushed, do something for a few seconds");

		mp3_set_serial(Serial2);
		delay(10);
		mp3_set_volume (20);
		mp3_play(2);

		digitalWrite(mosfet1_mirror, HIGH); //light on the mirror
		delay(5000);
		digitalWrite(mosfet1_mirror, LOW); //light off the mirror

		ButtonTime1 = millis();
	}

	if ((millis() - ButtonTime2 > 2000) && flag2 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag2 = 0;
		digitalWrite(mosfet2_answerLED2, HIGH); //show the answer
		Serial.println("Something done, light is on for some time to read an answer");
		RamkaTime2 = millis();
		delay(delay_time);
		digitalWrite(mosfet2_answerLED2, LOW); //hide the answer
		Serial.println("Light2 is off");

	}
}

void but3_rel() // 3Ticket
{
	if (digitalRead(but3) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0)
	{
		delay(50);
		flag3 = 1;
		Serial.println("Button3_pushed, do something for a few seconds");

		mp3_set_serial(Serial2);
		delay(10);
		mp3_set_volume (20);
		mp3_play(3);

		ticket();

		ButtonTime3 = millis();
	}

	if ((millis() - ButtonTime3 > 2000) && flag3 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag3 = 0;
		digitalWrite(mosfet3_answerLED3, HIGH); //show the answer
		Serial.println("Something done, light is on for some time to read an answer");
		RamkaTime3 = millis();
		delay(delay_time);
		digitalWrite(mosfet3_answerLED3, LOW); //hide the answer
		Serial.println("Light3 is off");

	}
}

void but4_rel() // 4Beep
{
	if (digitalRead(but4) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0)
	{
		delay(50);
		flag4 = 1;
		Serial.println("Button4_pushed, do something for a few seconds");

		mp3_set_serial(Serial2);
		delay(10);
		mp3_set_volume (30);
		mp3_play(4);

		ButtonTime4 = millis();
	}

	if ((millis() - ButtonTime4 > 2000) && flag4 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag4 = 0;
		digitalWrite(mosfet4_answerLED4, HIGH); //show the answer
		Serial.println("Something done, light is on for some time to read an answer");
		RamkaTime4 = millis();
		delay(delay_time);
		digitalWrite(mosfet4_answerLED4, LOW); //hide the answer
		Serial.println("Light4 is off");

	}
}

void but5_rel() // 5Curtains
{
	if (digitalRead(but5) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0)
	{
		delay(50);
		flag5 = 1;
		Serial.println("Button5_pushed, do something for a few seconds");

		mp3_set_serial(Serial2);
		delay(10);
		mp3_set_volume (30);
		mp3_play(5); //curtains on
		delay(200);
		curtains_open();

		mp3_set_serial(Serial2);
		delay(10);
		mp3_set_volume (15);
		mp3_play(9); //kolesa
		delay(200);
		led_strip();

		delay(200);
		mp3_set_serial(Serial2);
		delay(10);
		mp3_set_volume (25);
		mp3_play(10); //curtains off
		delay(100);
		curtains_close();

		ButtonTime5 = millis();
	}

	if ((millis() - ButtonTime5 > 2000) && flag5 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag5 = 0;
		digitalWrite(mosfet5_answerLED5, HIGH); //show the answer
		Serial.println("Something done, light is on for some time to read an answer");
		RamkaTime5 = millis();
		delay(delay_time);
		digitalWrite(mosfet5_answerLED5, LOW); //hide the answer
		Serial.println("Light5 is off");

	}
}

void but6_rel() // 6Tea
{
	if (digitalRead(but6) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0)
	{
		delay(50);
		flag6 = 1;
		Serial.println("Button6_pushed, do something for a few seconds");

		mp3_set_serial(Serial2);
		delay(10);
		mp3_set_volume (20);
		mp3_play(6);

		digitalWrite(mosfet2_tea, HIGH);
		delay(500);
		digitalWrite(mosfet2_tea, LOW);

		ButtonTime6 = millis();
	}

	if ((millis() - ButtonTime6 > 2000) && flag6 == 1) // in "ButtonTime > xxxx", where "xxxx" - wait time
	{
		flag6 = 0;
		digitalWrite(mosfet6_answerLED6, HIGH); //show the answer
		Serial.println("Something done, light is on for some time to read an answer");
		RamkaTime6 = millis();
		delay(delay_time);
		digitalWrite(mosfet6_answerLED6, LOW); //hide the answer
		Serial.println("Light6 is off");

	}
}

void but7_rel() // 7Book
{
	if (digitalRead(but7) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0)
	{
		delay(50);
		flag7 = 1;
		Serial.println("Button7_pushed, do something for a few seconds");

		book_open();
		mp3_set_serial(Serial2);
		delay(10);
		mp3_set_volume (20);
		mp3_play(7);
		delay(2000);
		book_close();

		ButtonTime7 = millis();
	}

	if ((millis() - ButtonTime7 > 2000) && flag7 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag7 = 0;
		digitalWrite(mosfet7_answerLED7, HIGH); //show the answer
		Serial.println("Something done, light is on for some time to read an answer");
		RamkaTime7 = millis();
		delay(delay_time);
		digitalWrite(mosfet7_answerLED7, LOW); //hide the answer
		Serial.println("Light7 is off");

	}
}

void but8_rel() // 8Light
{
	if (digitalRead(but8) == LOW && flag1 == 0 && flag2 == 0 && flag3 == 0 && flag4 == 0 && flag5 == 0 && flag6 == 0 && flag7 == 0 && flag8 == 0)
	{
		delay(50);
		flag8 = 1;
		Serial.println("Button8_pushed, do something for a few seconds");

		mp3_set_serial(Serial2);
		delay(10);
		mp3_set_volume (20);
		mp3_play(8);
		delay(100);
		light_on();
		delay(5000);
		light_off();

		ButtonTime8 = millis();
	}

	if ((millis() - ButtonTime8 > 2000) && flag8 == 1) // in "ButtonTime > xxxx", where "xxxx" - time of some action
	{
		flag8 = 0;
		digitalWrite(mosfet8_answerLED8, HIGH); //show the answer
		Serial.println("Something done, light is on for some time to read an answer");
		RamkaTime8 = millis();
		delay(delay_time);
		digitalWrite(mosfet8_answerLED8, LOW); //hide the answer
		Serial.println("Light8 is off");

	}
}
