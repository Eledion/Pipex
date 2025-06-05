# Compiler definition and options
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I includes -I printf -I utils

# Main object directory
OBJ_DIR = obj

# Subdirectories within obj
OBJ_SUBDIRS = $(OBJ_DIR)/src $(OBJ_DIR)/utils

# Pipex source files
SRC_FILES = src/execute_command.c src/execute_child1.c src/execute_child2.c \
            src/pipex.c src/main.c src/find_path.c

# Utils source files
UTILS_FILES = utils/ft_split.c utils/ft_strjoin.c utils/ft_strlen.c utils/ft_strdup.c \
              utils/ft_memcpy.c utils/ft_memmove.c utils/ft_substr.c utils/ft_putstr_fd.c \
			  utils/ft_strncmp.c

# Object files generated in obj/
OBJ_FILES_SRC = $(patsubst src/%.c, $(OBJ_DIR)/src/%.o, $(SRC_FILES))
OBJ_FILES_UTILS = $(patsubst utils/%.c, $(OBJ_DIR)/utils/%.o, $(UTILS_FILES))
OBJS = $(OBJ_FILES_SRC) $(OBJ_FILES_UTILS)

# Executable name
NAME = pipex

# Default rule: compile Pipex only if there are changes
all: check_changes $(NAME)

# Check if there are outdated files before displaying the banner
check_changes:
	@if ! $(MAKE) --question $(NAME); then \
		echo "==========================================="; \
		echo " 🚀 PIPEX - COMPILATION PROCESS 🚀"; \
		echo "-------------------------------------------"; \
		echo " 🔧 Project: Pipex"; \
		echo " 🏆 Developer: DANOGUER "; \
		echo " 📅 Date: `date +'%d-%m-%Y %H:%M'`"; \
		echo "==========================================="; \
		echo ""; \
	else \
		echo "✅ No changes detected. Everything is up to date."; \
	fi

# Create obj folder and its subdirectories before compiling any object files
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/src $(OBJ_DIR)/utils

# Rule to compile Pipex
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "✅ Compilation completed successfully"

# Rule to compile object files in obj/src/
$(OBJ_DIR)/src/%.o: src/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile object files in obj/utils/
$(OBJ_DIR)/utils/%.o: utils/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean compiled object files
clean:
	@echo "🧹 Cleaning object files..."
	rm -f $(OBJS)
	@echo "✅ Cleanup completed successfully."

# Clean everything, including the binary and the obj/ folder
fclean: clean
	@echo "🗑️ Removing executable and compilation folder..."
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)
	@echo "✅ Fclean completed. Project ready for a fresh compilation."
	
# Recompile from scratch
re: fclean all

# PHONY to prevent conflicts with file names
.PHONY: all clean fclean re check_changes