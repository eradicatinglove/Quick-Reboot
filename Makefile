MAKEFILES := $(subst ./,,$(shell find . -mindepth 2 -name Makefile))

TARGETS	:= $(dir $(MAKEFILES))

all: $(TARGETS)

.PHONY: $(TARGETS)

$(TARGETS):
	@$(MAKE) -C $@

clean:
	@for i in $(TARGETS); do $(MAKE) -C $$i clean || exit 1; done;
