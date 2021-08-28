#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <dlfcn.h>
#include <math.h>

uint64_t (*original_fun)(void* arg1, int32_t arg2, char arg3, char* arg4, int64_t arg5, char *arg6, double arg7);

uint64_t OCENDRAW_VerticalScaleString(void* arg1, int32_t arg2, char arg3, char* arg4, int64_t arg5, char *arg6, double val_hz) {
	uint32_t r12 = *(uint32_t*)(*(uint64_t*)(arg1 + 0x18)+0x464);
	if (arg2 == 2 && arg3 && (r12 == 0)) {
		const char* notes[] = {"A", "Bb", "B", "C", "Dd", "D", "Eb", "E", "F", "Gb", "G", "Ab"};

		double diff = 12 * log2(val_hz / 440);
		int sem = floor(diff);
		int cent = floor(100 * (diff - sem));
		char c;
		if (cent > 50) {
			++sem;
			cent = 100 - cent;
			c = '-';
		} else {
			c = '+';
		}
		int oct = (sem + 10) / 12 + 4 - (sem < -9);
		int index = sem % 12;
		if (index < 0) index += 12;

		snprintf(arg4, arg5, "%d %s%d %c%d", (int)val_hz, notes[index], oct, c, cent);

		return 1;
	}
	if (!original_fun) {
		original_fun = dlsym(RTLD_NEXT, "OCENDRAW_VerticalScaleString");
	}
	return (*original_fun)(arg1, arg2, arg3, arg4, arg5, arg6, val_hz);
}
