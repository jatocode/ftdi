all: bitbang relay ftdi_state lm60

bitbang: bitbang.c
	gcc bitbang.c -o $@ -lftdi -lusb

relay: relay.c
	gcc relay.c -o $@ -lftdi -lusb

ftdi_state: ftdi_state.c
	gcc ftdi_state.c -o $@ -lftdi -lusb

lm60: lm60.c
	gcc lm60.c -o $@ -lftdi -lusb
