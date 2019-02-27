// Source from: https://github.com/abondis/tmk_keyboard/blob/abondis_atreus_joystick/tmk_core/protocol/ps2_io_chibios.c
#include <stdbool.h>
#include "ps2_io.h"
#include "ch.h"
#include "hal.h"
#include "util.h"
//#include "gpio_api.h"



/*
 * Clock
 */
void clock_init(void)
{
    /* gpio_init(PS2_CLOCK_PORT, PS2_CLOCK_PIN, P0_9);
    gpio_mode(PS2_CLOCK_PORT, PS2_CLOCK_PIN, OpenDrain|PullNone);*/
    palSetPadMode(PS2_CLOCK_PORT, PS2_CLOCK_PIN, PAL_MODE_OUTPUT_OPENDRAIN);
}

void clock_lo(void)
{
    // gpio_dir(PS2_CLOCK_PORT, PS2_CLOCK_PIN, PIN_OUTPUT_OPENDRAIN);
    palSetPadMode(PS2_CLOCK_PORT, PS2_CLOCK_PIN, PAL_MODE_OUTPUT_OPENDRAIN);
    // gpio_write(PS2_CLOCK_PORT, PS2_CLOCK_PIN, 0);
    palClearPad(PS2_CLOCK_PORT, PS2_CLOCK_PIN);
}
void clock_hi(void)
{
    // gpio_dir(PS2_CLOCK_PORT, PS2_CLOCK_PIN, PIN_OUTPUT_OPENDRAIN);
    palSetPadMode(PS2_CLOCK_PORT, PS2_CLOCK_PIN, PAL_MODE_OUTPUT_OPENDRAIN);
    // gpio_write(PS2_CLOCK_PORT, PS2_CLOCK_PIN, 1);
    palSetPad(PS2_CLOCK_PORT, PS2_CLOCK_PIN);
}

bool clock_in(void)
{
    // gpio_dir(PS2_CLOCK_PORT, PS2_CLOCK_PIN, PIN_INPUT);
    palSetPadMode(PS2_CLOCK_PORT, PS2_CLOCK_PIN, PAL_MODE_INPUT);
    //return gpio_read(PS2_CLOCK_PORT, PS2_CLOCK_PIN);
    return palReadPad(PS2_CLOCK_PORT, PS2_CLOCK_PIN);
}

/*
 * Data
 */
void data_init(void)
{
    /*gpio_init(PS2_DATA_PORT, PS2_DATA_PIN, P0_8);
    gpio_mode(PS2_DATA_PORT, PS2_DATA_PIN, OpenDrain|PullNone);*/
    palSetPadMode(PS2_DATA_PORT, PS2_DATA_PIN, PAL_MODE_OUTPUT_OPENDRAIN);
}

void data_lo(void)
{
    //gpio_dir(PS2_DATA_PORT, PS2_DATA_PIN, PIN_OUTPUT_OPENDRAIN);
    palSetPadMode(PS2_DATA_PORT, PS2_DATA_PIN, PAL_MODE_OUTPUT_OPENDRAIN);
    //gpio_write(PS2_DATA_PORT, PS2_DATA_PIN, 0);
    palClearPad(PS2_DATA_PORT, PS2_DATA_PIN);
}

void data_hi(void)
{
    //gpio_dir(PS2_DATA_PORT, PS2_DATA_PIN, PIN_OUTPUT_OPENDRAIN);
    palSetPadMode(PS2_DATA_PORT, PS2_DATA_PIN, PAL_MODE_OUTPUT_OPENDRAIN);
    //gpio_write(PS2_DATA_PORT, PS2_DATA_PIN, 1);
    palSetPad(PS2_DATA_PORT, PS2_DATA_PIN);
}

bool data_in(void)
{
    //gpio_dir(PS2_DATA_PORT, PS2_DATA_PIN, PIN_INPUT);
    palSetPadMode(PS2_DATA_PORT, PS2_DATA_PIN, PAL_MODE_INPUT);
    //return gpio_read(PS2_DATA_PORT, PS2_DATA_PIN);
    return palReadPad(PS2_DATA_PORT, PS2_DATA_PIN);
}

/* Reset pin */
void reset_init(void) {
    palSetPadMode(PS2_RST_PORT, PS2_RST_PIN, PAL_MODE_OUTPUT_OPENDRAIN);
}

void reset_lo(void) {
    palClearPad(PS2_RST_PORT, PS2_RST_PIN);
}

void reset_hi(void) {
    palSetPad(PS2_RST_PORT, PS2_RST_PIN);
}
