all: bitbang relay ftdi_state

bitbang: bitbang.c
	gcc bitbang.c -o $@ -lftdi -lusb

relay: relay.c
	gcc relay.c -o $@ -lftdi -lusb

ftdi_state: ftdi_state.c
	gcc ftdi_state.c -o $@ -lftdi -lusb
