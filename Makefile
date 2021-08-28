libhook.so: hook.c
	gcc -fPIC -shared -Os -o $@ $^

run: libhook.so
	./run-hooked
