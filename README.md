# Every.h

Utility macros for periodically doing stuff in a non-blocking loop.

## Usage:

``` cpp
void loop() {
  EVERY(2.5 SECONDS) {
    static bool ledOn = false;
    ledOn = !ledOn;
    digitalWrite(LED_BUILTIN, ledOn);
  }
}
```

## Notes:

* Every ~50 days the Arduino internal timer overflows, these macros
  are susceptible to this overflow.
* Every ~70 hours the microseconds counter overflows, these macros
  are susceptible to this overflow when using MICROSECONDS as units.
* Although you might ask for EVERY(10 MICROSECONDS) {...} you might
  not get this frequency (an 8-bit MCU @ 8Mhz or 16Mhz only has so
  many cycles per microsecond)

