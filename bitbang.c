#include <stdio.h>
#include <unistd.h>
#include <ftdi.h>


int main()
{
    unsigned char d = 0;
    unsigned char i;
    struct ftdi_context ftdic;

    /* Initialize context for subsequent function calls */
    ftdi_init(&ftdic);

    /* Open FTDI device based on FT232R vendor & product IDs */
    if(ftdi_usb_open(&ftdic, 0x0403, 0x6001) < 0) {
        puts("Can't open device");
        fprintf(stderr, "unable to open ftdi device: (%s)\n", ftdi_get_error_string(&ftdic));
        return EXIT_FAILURE;
    }
    ftdi_set_bitmode(&ftdic, 0xFF, BITMODE_BITBANG);

    ftdi_write_data(&ftdic, &d, 1);
    sleep(1);
    for(i=0;i<8;i++) {
        printf("%d\n",d); 
        d |= d<<1;
    	ftdi_write_data(&ftdic, &d, 1);
	usleep(200 * 1000);
    }
    sleep(2);
    d = 0;
    ftdi_write_data(&ftdic, &d, 1);
   
    return 0;
}
