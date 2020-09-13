CC		:= gcc

SRC_DIR     := ./src
SRCS    	:= $(wildcard $(SRC_DIR)/*.c)
OBJ_DIR     := ./obj
OBJS    	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

TESTS_DIR		:= ./tests
TESTS_OBJ_DIR 	:= ./tests/obj
TEST_SRCS    	:= $(wildcard $(TESTS_DIR)/*.c)
TEST_OBJS    	:= $(patsubst $(TESTS_DIR)/%.c, $(TESTS_OBJ_DIR)/%.o, $(TEST_SRCS))


test: $(TEST_OBJS)
	$(foreach file, $(wildcard $(TESTS_OBJ_DIR)/*), echo "\nRUNNING $(file):"; $(file);)

$(TESTS_OBJ_DIR)/%.o: $(TESTS_DIR)/%.c $(OBJS) | $(TESTS_OBJ_DIR)
	$(CC) $(CFLAGS) -o $@  $< $(OBJS)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(TESTS_OBJ_DIR):
	mkdir tests/obj

$(OBJ_DIR):
	mkdir obj
