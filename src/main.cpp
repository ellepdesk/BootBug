#include <Arduino.h>
#include <HID-Project.h>

const int pin_enable_drive = 10;
const int pin_enable_read = 11;

bool enabled()
{
    return digitalRead(pin_enable_read);
}

void setup() {
    pinMode(pin_enable_drive, OUTPUT);
    digitalWrite(pin_enable_drive, 0);
    pinMode(pin_enable_read, INPUT_PULLUP);

    BootKeyboard.begin();

    for (int i=0; i<8; i++)
    {
        if (enabled())
        {
            BootKeyboard.write(KEY_DELETE);
        }
        delay(1000);
    }
    for (int i=0; i<5; i++)
    {
        if (enabled())
        {
            BootKeyboard.write(KEY_RIGHT_ARROW);
        }
        delay(100);
    }
    for (int i=0; i<11; i++)
    {
        if (enabled())
        {
            BootKeyboard.write(KEY_DOWN_ARROW);
        }
        delay(100);
    }
    if (enabled())
    {
        BootKeyboard.write(KEY_RETURN);
    }
    BootKeyboard.end();
}

void loop() {
    delay(1000);
}
