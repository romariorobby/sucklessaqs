PREFIX := /usr/local
#PREFIX := ${HOME}/.local

CC := gcc
CFLAGS := -O3 -Wall -Wextra
# CFLAGSEXTRA := -Wno-missing-field-initializers -Wno-unused-parameter

X11CFLAGS := $(shell pkg-config --cflags x11)
X11LIBS := $(shell pkg-config --libs x11)

all: dwmblocks sigdwmblocks/sigdwmblocks xgetrootname/xgetrootname

dwmblocks: dwmblocks.c config.h block.h
	${CC} -o $@ -Wno-missing-field-initializers -Wno-unused-parameter ${CFLAGS} ${CFLAGSEXTRA} ${X11CFLAGS} $< ${X11LIBS}

sigdwmblocks/sigdwmblocks: sigdwmblocks/sigdwmblocks.c
	${CC} -o $@ ${CFLAGS} $<

xgetrootname/xgetrootname: xgetrootname/xgetrootname.c
	${CC} -o $@ ${CFLAGS} ${X11CFLAGS} $< ${X11LIBS}

clean:
	rm -f dwmblocks sigdwmblocks/sigdwmblocks xgetrootname/xgetrootname

install: all
	mkdir -p ${DESTDIR}${PREFIX}/bin
	install -m 0755 dwmblocks ${DESTDIR}${PREFIX}/bin/dwmblocks
	install -m 0755 sigdwmblocks/sigdwmblocks ${DESTDIR}${PREFIX}/bin/sigdwmblocks
	install -m 0755 xgetrootname/xgetrootname ${DESTDIR}${PREFIX}/bin/xgetrootname
	install -m 644 statusbar.hook /usr/share/libalpm/hooks/dwmblocks-statusbar.hook

uninstall:
	rm -f ${DESTDIR}${PREFIX}/bin/dwmblocks ${DESTDIR}${PREFIX}/bin/sigdwmblocks ${DESTDIR}${PREFIX}/bin/xgetrootname /usr/share/libalpm/hooks/dwmblocks-statusbar.hook


.PHONY: all clean install uninstall
