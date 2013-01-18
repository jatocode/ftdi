#include <stdio.h>
#include <string.h>
#include <ftdi.h>


int main(int argc, char *argv[])
{
    struct ftdi_context ftdic;
    unsigned char state;

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
    state = 0;     
    ftdi_read_data(&ftdic, &state, 1);

    printf("Bitbang state, byte one: 0x%0x\n", state);
    
    return state;
}

