## Synopsis

Some small code-snippets to access FTDI and bitbang-mode between my RaspberryPI and a Sainsmart 8-channel USB Relay module.


## Binaries

- bitbang: Simple test, turns on all relays and then off again
- relay: Accepts relay + state or bitmask 
- ftdi_state: Returns state of relays in form of bitmask
- lm60: Special case for my application. Flips relay 7 on/off with delay between

## Motivation

I want to turn relays on/off with my raspberry pi

## Installation

libftdi-dev is needed for compile and link

## Useful links

http://www.intra2net.com/en/developer/libftdi/


