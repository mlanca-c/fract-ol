# **************************************************************************** #
# fract-ol
#
# version: 1
# Author: mlanca-c
# URL: 
# **************************************************************************** #

USER := mlanca-c
PROJECT := fract-ol

# **************************************************************************** #
# Project Variables
# **************************************************************************** #

NAME1 := fractol

NAMES := ${NAME1}

# **************************************************************************** #
# Configs
# **************************************************************************** #

# Verbose levels
# 0: Make will be totaly silenced
# 1: Make will print echos and printf
# 2: Make will not be silenced but target commands will not be printed
# 3: Make will print each command
# 4: Make will print all debug info
#
# If no value is specified or an incorrect value is given make will print each
# command like if VERBOSE was set to 3.
VERBOSE := 1

GREEN := \e[38;5;118m
YELLOW := \e[38;5;226m
RED := \e[38;5;9m
RESET := \e[0m
_SUCCESS := [${GREEN}SUCCESS${RESET}]
_INFO := [${YELLOW}INFO${RESET}]
_NORM := [${RED}Norminette${RESET}]
_NORM_SUCCESS := ${GREEN}      OK: ${RESET}
_NORM_INFO := ${YELLOW}FILES No: ${RESET}

# **************************************************************************** #
# Compiler and Flags
# **************************************************************************** #

CC := gcc
CLIB := ar -rc

CFLAGS := -Wall -Wextra -Werror
DFLAGS := -g
OFLAGS := -O3
FSANITIZE := -fsanitize=address

# **************************************************************************** #
# Root Folders
# **************************************************************************** #

SRC_ROOT := sources/
INC_ROOT := includes/
LIB_ROOT := libraries/
OBJ_ROOT := objects/
BIN_ROOT := ./

# **************************************************************************** #
# Content Folders
# **************************************************************************** #


SRC_DIRS_LIST := ${SRC_ROOT}
SRC_DIRS_LIST := $(foreach dl,${SRC_DIRS_LIST},$(subst :,:${SRC_ROOT},${dl}))

SRC_DIRS = $(subst :,${SPACE},${SRC_DIRS_LIST})
OBJ_DIRS = $(subst ${SRC_ROOT},${OBJ_ROOT},${SRC_DIRS})

INC_DIRS = ${INC_ROOT}

# **************************************************************************** #
# Files
# **************************************************************************** #

SRCS_LIST = $(foreach dl,${SRC_DIRS_LIST},$(subst ${SPACE},:,$(strip $(foreach\
	dir,$(subst :,${SPACE},${dl}),$(wildcard ${dir}*.c)))))
OBJS_LIST = $(subst ${SRC_ROOT},${OBJ_ROOT},$(subst .c,.o,${SRCS_LIST}))

SRCS = $(foreach dir,${SRC_DIRS},$(wildcard ${dir}*.c))
OBJS = $(subst ${SRC_ROOT},${OBJ_ROOT},${SRCS:.c=.o})

INCS := ${addprefix -I,${INC_DIRS}}
INCS += -I${LIB_ROOT}libft

# **************************************************************************** #
# VPATHS
# **************************************************************************** #

vpath %.o ${OBJ_ROOT}
vpath %.h ${INC_ROOT}
vpath %.c ${SRC_DIRS}

# **************************************************************************** #
# Conditions
# **************************************************************************** #

ifeq ($(shell uname), Linux)
	MLX = minilibx_linux
	MLX_FLAGS = -lbsd -L${LIB_ROOT}${MLX} -lmlx -lXext -lX11 -lm
else ifeq ($(shell uname), Darwin)
	MLX = minilibx_mms
	MLX_FLAGS = -I${LIB_ROOT}${MLX} -L${LIB_ROOT}${MLX} -lmlx
	CP_CMD = cp ${LIB_ROOT}${MLX}/libmlx.dylib ./
endif

ifeq (${VERBOSE}, 0)
	MAKEFLAGS += --silent
	BLOCK := &/dev/null
else ifeq (${VERBOSE}, 1)
	MAKEFLAGS += --silent
	AT := @
else ifeq (${VERBOSE}, 2)
	AT := @
else ifeq (${VERBOSE}, 4)
	MAKEFLAGS += --debug=v
endif

# **************************************************************************** #
# Mandatory Targets
# **************************************************************************** #

.PHONY: all
all: cl ${NAMES}

${NAME1}: ${OBJS}
	${AT} ${MAKE} -C ${LIB_ROOT}libft ${BLOCK}
	${AT} ${MAKE} -C ${LIB_ROOT}${MLX} ${BLOCK}
	${AT} ${CP_CMD} ${BLOCK}
	${AT} ${CC} ${CFLAGS} ${OFLAGS} ${INCS}  ${OBJS} ${MLX_FLAGS} ${LIB_ROOT}libft/libft.a -o $@ ${BLOCK}
	${AT}printf "${_SUCCESS} ${@F} created.\n\n\n" ${BLOCK}
	${AT}printf "${GREEN}HOW TO COMPILE:\n" ${BLOCK}
	${AT}printf "\t[./fractol <fractal> [x] [y] [-p <precision>] [-c <color>]\n" ${BLOCK}
	${AT}printf "\nCOLOR OPTIONS:\n\t1: black and white\n\t2: red\n\t3: green\n\t4: blue\n\t5: mix" ${BLOCK}
	${AT}printf "\n\t If not given any color, default is any other number.\n" ${BLOCK}
	${AT}printf "\nPRECISION OPTIONS:\n\t If not given any precision, default is at 85.\n${RESET}" ${BLOCK}

# **************************************************************************** #
# Clean Targets
# **************************************************************************** #

.PHONY: cl
cl:
	${AT}clear ${BLOCK}

.PHONY: clean
clean:
	${AT}mkdir -p ${OBJ_ROOT} ${BLOCK}
	${AT}find ${OBJ_ROOT} -type f -delete ${BLOCK}
	${AT} ${MAKE} fclean -C ${LIB_ROOT}libft ${BLOCK}
	${AT}printf "$(_INFO) cleaned ${OBJ_ROOT} folder.\n" ${BLOCK}

.PHONY: fclean
fclean: clean
	${AT}rm -f ${NAMES} ${BLOCK}
	${AT}printf "$(_INFO) ${NAMES} removed.\n" ${BLOCK}

.PHONY: re
re: fclean all

# **************************************************************************** #
# Debug Targets
# **************************************************************************** #

debug_san: CFLAGS += ${DFLAGS} ${FSANITIZE}
debug_san: all

debug: CFLAGS += ${DFLAGS}
debug: all

debug_re: fclean debug

# **************************************************************************** #
# Norminette Targets
# **************************************************************************** #

.PHONY: norm
norm:
	${AT} norminette ${SRCS} ${INC_ROOT} ${BLOCK}

.PHONY: norm_status
norm_status:
	${AT} printf "${_NORM}\n\n" ${BLOCK}
	${AT} printf "${_NORM_INFO}" ${BLOCK}
	${AT} norminette ${SRCS} ${INC_ROOT}|wc -l ${BLOCK}
	${AT} printf "${_NORM_SUCCESS}" ${BLOCK}
	${AT} norminette ${SRCS} ${INC_ROOT}|grep -wc "OK" ${BLOCK}


# **************************************************************************** #
# Target Templates
# **************************************************************************** #

define make_obj
${1} : ${2}
	$${AT}mkdir -p $${@D} $${BLOCK}
	$${AT} $${CC} $${OFLAGS} $${CFLAGS} $${INCS} -I$${LIB_ROOT}$${MLX} -c $$< -o $$@ $${BLOCK}
endef

# **************************************************************************** #
# Target Generator
# **************************************************************************** #

$(foreach src,${SRCS},$(eval\
$(call make_obj,$(subst ${SRC_ROOT},${OBJ_ROOT},${src:.c=.o}),${src})))
