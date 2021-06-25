#pragma once

// Utility macros for periodically doing stuff in a non-blocking loop.

// Usage:
//
// void loop() {
//   EVERY(2.5 SECONDS) {
//     static bool ledOn = false;
//     ledOn = !ledOn;
//     digitalWrite(LED_BUILTIN, ledOn);
//   }
// }

// Notes:
//
// * Every ~50 days the Arduino internal timer overflows, these macros
//   are susceptible to this overflow.
// * Every ~70 hours the microseconds counter overflows, these macros
//   are susceptible to this overflow when using MICROSECONDS as units.
// * Although you might ask for EVERY(10 MICROSECONDS) {...} you might
//   not get this frequency (an 8-bit MCU @ 8Mhz or 16Mhz only has so
//   many cycles per microsecond)

#include <stdint.h>

#define MICROSECONDS * 1, micros
#define MILLISECONDS * 1, millis
#define MILLISECOND 1 MILLISECONDS
#define SECONDS * 1000 MILLISECONDS
#define SECOND 1 SECONDS
#define MINUTES * 60 SECONDS
#define MINUTE 1 MINUTES
#define HOURS * 60 MINUTES
#define HOUR 1 HOURS
#define DAYS * 24 HOURS
#define DAY 1 DAYS
#define WEEKS * 7 DAYS
#define WEEK 1 WEEKS

#define EVERY_TIME(N, TIME_FN)                                                 \
  for (static uint32_t _lasttime;                                              \
       (uint32_t)((uint32_t)TIME_FN() - _lasttime) >= (N); _lasttime += (N))
#define EVERY(...) EVERY_TIME(__VA_ARGS__)
