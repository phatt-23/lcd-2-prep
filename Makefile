
PROGRAM  := target/program
CPPFLAGS +=-g -std=c++11 -Wall
SRC_DIR  := src
SRC      := $(wildcard $(SRC_DIR)/*.cpp wildcard $(SRC_DIR)/*.h)

# detect opencv lib
OPENCVLIB=$(strip $(shell pkgconf --list-package-names | grep opencv ))

ifeq ($(OPENCVLIB),)

all:
	@echo OpenCV lib not found!
	@exit 

else

CPPFLAGS += $(shell pkgconf --cflags $(OPENCVLIB))
LDFLAGS  += $(shell pkgconf --libs-only-L $(OPENCVLIB))
LDLIBS   += $(shell pkgconf --libs-only-l $(OPENCVLIB))

all: $(PROGRAM) 

endif

$(PROGRAM): clean
	g++ $(CPPFLAGS) $(SRC) -o $(PROGRAM) $(LDFLAGS) $(LDLIBS)

clean: 
	rm -rf $(PROGRAM)

run: $(PROGRAM) 
	./$(PROGRAM)