#include <stdio.h>
#include <string.h>
#include <ftdi.h>
#include <unistd.h>

#define MOTOR_RELAY 7
#define SLEEP_TIME 200  

int main(int argc, char *argv[])
{
    struct ftdi_context ftdic;
    int portrelay = MOTOR_RELAY;  
    unsigned char relay = 0;

    /* Initialize context for subsequent function calls */
    ftdi_init(&ftdic);

    /* Open FTDI device based on FT232R vendor & product IDs */
    if(ftdi_usb_open(&ftdic, 0x0403, 0x6001) < 0) {
        puts("Can't open device");
        fprintf(stderr, "unable to open ftdi device: (%s)\n", ftdi_get_error_string(&ftdic));
        return EXIT_FAILURE;
    }
    ftdi_set_bitmode(&ftdic, 0xFF, BITMODE_BITBANG);

    /* Reading existing state */
    relay = 0;     
    ftdi_read_data(&ftdic, &relay, 1);

    printf("Activating relay %d\n", MOTOR_RELAY);
    relay |= (1 << portrelay);
//    ftdi_write_data(&ftdic, &relay, 1);

    printf("Sleeping for %dms\n", SLEEP_TIME);
    usleep(SLEEP_TIME * 1000); // usleep want microsecs 

    printf("Dectivating relay %d\n", MOTOR_RELAY);
    relay &= ~(1 << portrelay);
//    ftdi_write_data(&ftdic, &relay, 1);


}

