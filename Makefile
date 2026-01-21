CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -fPIC
AR = ar
RANLIB = ranlib

SRC_DIR = src
OBJS_DIR = objs
INC_DIR = include
BUILD_DIR = build
LIB_DIR = lib
INSTALL_PREFIX = /usr/local
TEST_DIR = tests

SRCS = $(SRC_DIR)/cipuada.c
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJS_DIR)/%.o)
HEADERS = $(INC_DIR)/cipuada.h

LIB_NAME = libcipuada
LIB_STATIC = $(LIB_DIR)/$(LIB_NAME).a
LIB_SHARED = $(LIB_DIR)/$(LIB_NAME).so

TARGET_STATIC = $(LIB_STATIC)
TARGET_SHARED = $(LIB_SHARED)

.PHONY: all prepare static shared clean clean_tests install uninstall run_test

all: prepare static shared

prepare:
	@mkdir -p $(OBJS_DIR) $(LIB_DIR)

static: $(TARGET_STATIC)

$(TARGET_STATIC): $(OBJS)
	@echo "Creating static library: $@"
	$(AR) rcs $@ $^
	$(RANLIB) $@

shared: $(TARGET_SHARED)

$(TARGET_SHARED): $(OBJS)
	@echo "Creating shared library: $@"
	$(CC) -shared -o $@ $^

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(LIB_STATIC) $(LIB_SHARED)
	rm -rf $(OBJS_DIR) $(LIB_DIR) $(BUILD_DIR)

install: all
	install -d $(INSTALL_PREFIX)/include
	install $(HEADERS) $(INSTALL_PREFIX)/include/
	install -d $(INSTALL_PREFIX)/lib
	install $(LIB_STATIC) $(INSTALL_PREFIX)/lib/
	install $(LIB_SHARED) $(INSTALL_PREFIX)/lib/
	-ldconfig $(INSTALL_PREFIX)/lib 2>/dev/null || true
	@echo "Lib inslated atm $(INSTALL_PREFIX)"

uninstall:
	rm -f $(INSTALL_PREFIX)/include/cipuada.h
	rm -f $(INSTALL_PREFIX)/lib/libcipuada.a
	rm -f $(INSTALL_PREFIX)/lib/libcipuada.so
	-ldconfig 2>/dev/null || true
	@echo "Uninstall lib"

run_test:
	@echo "Compiling tests..."
	$(MAKE) -C $(TEST_DIR) tests

clean_tests:
	@echo "Cleaning tests..."
	$(MAKE) -C $(TEST_DIR) clean
