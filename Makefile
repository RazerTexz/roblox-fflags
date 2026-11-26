SRCS = main.c

CF = -c -std=c23 -O2 -fPIC
LF = -shared -s

CP = $(ANDROID_NDK_LATEST_HOME)/toolchains/llvm/prebuilt/linux-x86_64/bin/aarch64-linux-android21-clang 

build/librobloxfflags.so: $(SRCS:%.c=build/%.o)
	$(CP) $(LF) $^ -o $@

build/%.o: src/%.c
	mkdir -p $(dir $@)
	$(CP) $(CF) $< -o $@
