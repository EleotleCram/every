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

// Note:
//
// Every ~50 days the Arduino internal timer overflows, these macros
// are susceptible to this overflow.

#include <stdint.h>

#define MILLISECONDS * 1
#define SECONDS * 1000 MILLISECONDS
#define SECOND (1 SECONDS)
#define MINUTES * 60 SECONDS
#define MINUTE (1 MINUTES)
#define HOURS * 60 MINUTES
#define HOUR (1 HOURS)
#define DAYS * 24 HOURS
#define DAY (1 DAYS)
#define WEEKS * 7 DAYS
#define WEEK (1 WEEKS)

#define EVERY(N)                                                             \
  for (static uint32_t _lasttime;                                              \
       (uint32_t)((uint32_t)millis() - _lasttime) >= (N); _lasttime += (N))
