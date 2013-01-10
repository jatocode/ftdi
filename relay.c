#include <stdio.h>
#include <string.h>
#include <ftdi.h>


int main(int argc, char *argv[])
{
    struct ftdi_context ftdic;
    int inputmask = 0;
    unsigned char state = 0;
    unsigned char relay = 0;

    if(argc < 2) {
	puts ("Usage: relay bitmask or relay number state");
	printf("\n");
    }
    inputmask = atoi(argv[1]);
    if((inputmask < 0) || (inputmask > 255)) {
	puts ("Wrong mask or number of relay");
    }

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

    if (argc > 2) {
        // Relaynumber + state
        inputmask -= 1; // Relays from 1-8
        state = (unsigned char)atoi(argv[2]);
	if(state == 1) 
          relay |= (1 << inputmask);
        else
          relay &= ~(1 << inputmask);
    } else {
        relay = (unsigned char)inputmask;
    }

    ftdi_write_data(&ftdic, &relay, 1);

}

