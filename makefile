all: bitbang relay

bitbang: bitbang.c
	gcc bitbang.c -o $@ -lftdi -lusb

relay: relay.c
	gcc relay.c -o $@ -lftdi -lusb

