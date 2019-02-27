/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

/* USB Device descriptor parameter */
#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x6464
#define DEVICE_VER 0x0001
/* in python2: list(u"whatever".encode('utf-16-le')) */
/*   at most 32 characters or the ugly hack in usb_main.c borks */
#define MANUFACTURER QMK
#define PRODUCT ChibiOS QMK test
#define DESCRIPTION QMK keyboard firmware test for ChibiOS

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 1
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#ifdef PS2_USE_USART
#  define PS2_CLOCK_PORT PORTD
#  define PS2_CLOCK_PIN PIND
#  define PS2_CLOCK_DDR DDRD
#  define PS2_CLOCK_BIT 5
#  define PS2_DATA_PORT PORTD
#  define PS2_DATA_PIN PIND
#  define PS2_DATA_DDR DDRD
#  define PS2_DATA_BIT 2

/* synchronous, odd parity, 1-bit stop, 8-bit data, sample at falling edge */
/* set DDR of CLOCK as input to be slave */
#  define PS2_USART_INIT()                                                                     \
    do {                                                                                       \
      PS2_CLOCK_DDR &= ~(1 << PS2_CLOCK_BIT);                                                  \
      PS2_DATA_DDR &= ~(1 << PS2_DATA_BIT);                                                    \
      UCSR1C = ((1 << UMSEL10) | (3 << UPM10) | (0 << USBS1) | (3 << UCSZ10) | (0 << UCPOL1)); \
      UCSR1A = 0;                                                                              \
      UBRR1H = 0;                                                                              \
      UBRR1L = 0;                                                                              \
    } while (0)
#  define PS2_USART_RX_INT_ON()                \
    do {                                       \
      UCSR1B = ((1 << RXCIE1) | (1 << RXEN1)); \
    } while (0)
#  define PS2_USART_RX_POLL_ON() \
    do {                         \
      UCSR1B = (1 << RXEN1);     \
    } while (0)
#  define PS2_USART_OFF()                       \
    do {                                        \
      UCSR1C = 0;                               \
      UCSR1B &= ~((1 << RXEN1) | (1 << TXEN1)); \
    } while (0)
#  define PS2_USART_RX_READY (UCSR1A & (1 << RXC1))
#  define PS2_USART_RX_DATA UDR1
#  define PS2_USART_ERROR (UCSR1A & ((1 << FE1) | (1 << DOR1) | (1 << UPE1)))
#  define PS2_USART_RX_VECT USART1_RX_vect
#endif

#endif
