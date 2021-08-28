## Ocenaudio hack
Changes the frequency display format to show corresponding closest note on the piano and the distance from it in cents, eg.: \
444 Hz -> 444 A4 +15

Run `make` to create `libhook.so` which can then be loaded using the `LD_PRELOAD` environmental variable in order to apply the change.\
Tested on Linux 64 bits version 3.10.12.
