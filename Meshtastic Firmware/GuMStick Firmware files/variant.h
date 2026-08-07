#ifndef _GUMSTICK_
#define _GUMSTICK_


/** Master clock frequency */
#define VARIANT_MCK (64000000ul)

#define USE_LFXO // Board uses 32khz crystal for LF
// #define USE_LFRC    // Board uses RC for LF

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "variant.h"

/*#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

Xiao pin assignments

| Pin   | Default  | I2C  | BTB  | BLE-L |     | Pin   | Default | I2C  | BTB  | BLE-L |
| ----- | -------- | ---- | ---- | ----- | --- | ----- | ------- | ---- | ---- | ----- |
|       |          |      |      |       |     |       |         |      |      |       |
| D0    | G_STBY   | UBTN | DIO1 | CS    |     | 5v    |         |      |      |       |
| D1    | DIO1     | DIO1 | Busy | DIO1  |     | GND   |         |      |      |       |
| D2    | NRST     | NRST | NRST | Busy  |     | 3v3   |         |      |      |       |
| D3    | Busy     | Busy | CS   | NRST  |     | D10   | MOSI    | MOSI | MOSI | MOSI  |
| D4    | CS       | CS   | RXEN | SDA   |     | D9    | MISO    | MISO | MISO | MISO  |
| D5    | RXEN     | RXEN |      | SCL   |     | D8    | SCK     | SCK  | SCK  | SCK   |
| D6    | G_TX     | SDA  | G_TX |       |     | D7    | G_RX    | SCL  | G_RX | RXEN  |
|       |          |      |      |       |     |       |         |      |      |       |
|       | End      |      |      |       |     |       |         |      |      |       |
| NFC1/ | SDA      | G_TX | SDA  | G_TX  |     | NFC2/ | SCL     | G_RX | SCL  | G_RX  |
| D30   |          |      |      |       |     | D31   |         |      |      |       |
|       |          |      |      |       |     |       |         |      |      |       |
|       | Internal |      |      |       |     |       |         |      |      |       |
| D16   | SCL1     | SCL1 | SCL1 | SCL1  |     |       |         |      |      |       |
| D17   | SDA1     | SDA1 | SDA1 | SDA1  |     |       |         |      |      |       |

The default column shows the pin assignments for the Wio-SX1262 for XIAO
(standalone SKU 113010003 or nRF52840 kit SKU 102010710).
The I2C column shows an alternative pin assignment using I2C on D6/D7 in place of the GNSS.
The BTB column shows the pin assignment for the Wio-SX1262 -30-pin board-to-board connector version from the ESP32S3 kit.
The BLE-L column shows the pin assignment for the original DIY xiao_ble, and which is retained for legacy users.
Note that the in addition to the difference between the default and the I2C pinouts in placing the pins on NFC or
D6/D7, the user button is activated on D0. The button conflicts with the official GNSS module, so caution is advised.
*/

#define PINS_COUNT (33)
#define NUM_DIGITAL_PINS (33)
#define NUM_ANALOG_INPUTS (8)
#define NUM_ANALOG_OUTPUTS (0)

/*
 * Digital Pins
 */
#define D0 0    // P0.02 Buzzer
#define D1 1    // P0.03 DIO
#define D2 2    // P0.28 RST
#define D3 3    // P0.29 BUSY
#define D4 4    // P0.04 NSS/CS
#define D5 5    // P0.05 SW1
#define D6 6    // P1.11 SDA
#define D7 7    // P1.12 SCL
#define D8 8    // P1.13 SCK
#define D9 9    // P1.14 MISO
#define D10 10  // P1.15 MOSI

/*
 * Analog pins
 */
#define PIN_A0 (0)
#define PIN_A1 (1)
#define PIN_A2 (32)
#define PIN_A3 (3)
#define PIN_A4 (4)
#define PIN_A5 (5)
#define PIN_VBAT (32)
#define VBAT_ENABLE (14)

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;
#define ADC_RESOLUTION 12

/*
 * LEDs
 */
#define LED_STATE_ON (0) // RGB LED is common anode
#define LED_RED (11)
#define LED_GREEN (13)
#define LED_BLUE (12)

#define PIN_LED1 LED_GREEN // PIN_LED1 is used in src/platform/nrf52/architecture.h to define LED_POWER
#define PIN_LED2 LED_BLUE
#define PIN_LED3 LED_RED


/*
 * Serial Interfaces
 */

#define PIN_SERIAL1_RX (-1)
#define PIN_SERIAL1_TX (-1)

#define PIN_SERIAL2_RX (-1)
#define PIN_SERIAL2_TX (-1) 



/*
 * Pinout for SX126x
 */
#define USE_SX1262


// Common pinouts for all SX126x pinouts above
#define SX126X_TXEN RADIOLIB_NC
#define SX126X_DIO2_AS_RF_SWITCH // DIO2 is used to control the TX side of the RF switch
#define SX126X_DIO3_TCXO_VOLTAGE 1.8 //should be 3.1? 200 mV below VCC per datasheet, changed 8/3/26 due to non detection of SX1262
/*
 * SPI Interfaces
 * Defined after pinout for SX1262x to factor in CS pinout variations
 */
#define SPI_INTERFACES_COUNT 1

#define SX126X_DIO1 D1
#define SX126X_RESET D2
#define SX126X_BUSY D3
#define SX126X_CS D4
#define SX126X_RXEN D5 //added 08/03/26, was missing

#define PIN_SPI_MISO D9
#define PIN_SPI_MOSI D10
#define PIN_SPI_SCK D8

static const uint8_t SS = SX126X_CS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK = PIN_SPI_SCK;

// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
//  Buzzer
// ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━
// Buzzer

#define PIN_BUZZER D0 // P0.02, pwm output


/*
 * Battery
 */
#define BATTERY_PIN PIN_VBAT      // P0.31: VBAT voltage divider
#define ADC_MULTIPLIER (3)        // ... R17=1M, R18=510k
#define ADC_CTRL VBAT_ENABLE      // P0.14: VBAT voltage divider
#define ADC_CTRL_ENABLED LOW      // ... sink
#define EXT_CHRG_DETECT (23)      // P0.17: Charge LED
#define EXT_CHRG_DETECT_VALUE LOW // ... BQ25101 ~CHG indicates charging
#define HICHG (22)                // P0.13: BQ25101 ISET 100mA instead of 50mA

#define BATTERY_SENSE_RESOLUTION_BITS (10)

/*
 * Wire Interfaces
 * Keep this section after potentially conflicting pin definitions
 */
#define I2C_NO_RESCAN           // I2C is a bit finicky, don't scan too much
#define WIRE_INTERFACES_COUNT 1 // changed to 1 for now, as LSM6DS3TR has issues.


// I2C pins
#define PIN_WIRE_SDA D6
#define PIN_WIRE_SCL D7



static const uint8_t SDA = PIN_WIRE_SDA; // Not sure if this is needed
static const uint8_t SCL = PIN_WIRE_SCL; // Not sure if this is needed


#ifdef __cplusplus    
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif
