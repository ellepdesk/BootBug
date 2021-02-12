#include <Arduino.h>
#include <HID-Project.h>

const int pin_enable_drive = 10;
const int pin_enable_read = 11;
const int pin_led = 13;
static uint8_t led_state = 0;

const int key_delay = 500;

bool enabled()
{
    return digitalRead(pin_enable_read);
}

void blink()
{
    led_state = !led_state;
    digitalWrite(pin_led, led_state);
}

void hit_del_to_enter_setup()
{
 for (int i=0; i<15; i++)
    {
        if (enabled())
        {
            BootKeyboard.write(KEY_DELETE);
        }
        blink();
        delay(500);
        blink();
        delay(500);
    }
}

void press_key(KeyboardKeycode k, int reps=1)
{
for (int i=0; i<reps; i++)
    {
        if (enabled())
        {
            BootKeyboard.write(k);
        }
        blink();
        delay(key_delay);
    }
}


void setup() {
    pinMode(pin_led, OUTPUT);
    pinMode(pin_enable_drive, OUTPUT);
    digitalWrite(pin_enable_drive, 0);
    pinMode(pin_enable_read, INPUT_PULLUP);

    BootKeyboard.begin();

    hit_del_to_enter_setup();
    press_key(KEY_RIGHT_ARROW, 2);
    press_key(KEY_DOWN_ARROW);
    press_key(KEY_RETURN);
    press_key(KEY_UP_ARROW);
    press_key(KEY_RETURN);
    press_key(KEY_PAGE_UP);
    press_key(KEY_DOWN_ARROW);
    press_key(KEY_RETURN);
    press_key(KEY_F10);
    press_key(KEY_RETURN);

    BootKeyboard.end();
}

void loop() {
    blink();
    delay(1500);
    blink();
    delay(500);
}
