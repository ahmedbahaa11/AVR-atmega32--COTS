MCU     = atmega32
CC      = avr-gcc
CFLAGS  = -Os -DF_CPU=8000000UL -mmcu=$(MCU)
TARGET  = program
SRC_DIR = ../program
OUT_DIR = ../build
BIN_DIR = ../build/bin

# Ensure the build directories exist
$(shell mkdir -p $(BIN_DIR))


# Recursive wildcard function to find all .c files in the program directory and subdirectories
define rwildcard
$(wildcard $(1)/*.c) $(foreach d,$(wildcard $(1)/*/),$(call rwildcard,$d))
endef

# Use the rwildcard function to find all .c files in the 'src' directory and its subdirectories
SRC  := $(call rwildcard,$(OUT_DIR)/Debug)
OBJ  := $(SRC:.c=.o)


# Rule to Build all Program Files
all: $(OUT_DIR)/$(TARGET).hex
	@mv $(OUT_DIR)/*.elf $(BIN_DIR)
	@mv $(OUT_DIR)/*.hex $(BIN_DIR)
	@echo
	@echo
	@echo "----------------------------------------------------------"
	@echo "---------- HEX File was Generated [Successful] -----------"
	@echo "----------------------------------------------------------"
	@echo "----------------------------------------------------------"
	@echo "------------ Developed by Eng - Ahmed Bahaa  -------------"
	@echo "--------- Automotive Embedded SW Engineer [ADAS] ---------"
	@echo "----------------------------------------------------------"
	@echo "----------------------------------------------------------"
	@echo
	@echo


# Rule to Compile all C files to Object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# Rule to prepare all C files
src: $(SRC)
	@echo
	@echo "***************************************************"
	@echo "****** [Compiling the following '.c' files] *******"
	@echo "***************************************************"
	@$(foreach file,$(SRC), echo $(file);)
	@echo "***************************************************"
	@echo


# Rule to Build all Object files
build : src $(OBJ)
	@echo
	@echo "******************************************************"
	@echo "****** [the following '.o' files was generated] ******"
	@echo "******************************************************"
	@$(foreach file,$(OBJ), echo $(file);)
	@echo "******************************************************"
	@echo


# Rule to generate ELF file from Object files
$(OUT_DIR)/$(TARGET).elf: build
	@echo
	@echo "----------------------------------------------------"
	@echo "------------   [Generating ELF file]   -------------"
	@echo "----------------------------------------------------"
	$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "----------------------------------------------------"
	@echo


# Rule to generate HEX file from ELF file
$(OUT_DIR)/$(TARGET).hex: $(OUT_DIR)/$(TARGET).elf
	@echo
	@echo "----------------------------------------------------"
	@echo "------------   [Generating HEX file]   -------------"
	@echo "----------------------------------------------------"
	avr-objcopy -O ihex -R .eeprom $(OUT_DIR)/$(TARGET).elf $(OUT_DIR)/$(TARGET).hex
	@echo "----------------------------------------------------"
	@echo


# Rule to clean all output files
clean:
	@rm -rf $(OUT_DIR)
	@echo
	@echo "----------------------------------------------------"
	@echo "-------- [Output directory was cleaned now] --------"
	@echo "----------------------------------------------------"
	@echo


# Rule to sync directories before building
sync: copy_dirs
	@echo
	@echo "----------------------------------------------------"
	@echo "------- [Source files ready for Compilation] -------"
	@echo "----------------------------------------------------"
	@echo


# Rule to copy directories
copy_dirs:
	@echo "----------------------------------------------------"
	@echo "----- [Copying directory 'program' to 'output'] ----"
	@cp -r $(SRC_DIR) $(OUT_DIR)
	@mv $(OUT_DIR)/program $(OUT_DIR)/Debug
	@echo "----------------------------------------------------"