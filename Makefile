CC := g++
DED_FLAGS  := -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code \
	-Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra \
	-Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security \
	-Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor \
	-Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel \
	-Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
ADD_FLAGS  :=
COMP_FLAGS := $(DED_FLAGS) $(ADD_FLAGS)
LINK_FLAGS := $(DED_FLAGS) $(ADD_FLAGS)

SRC_DIR := source
INC_DIR := include
OBJ_DIR := object
LOG_DIR := logs

SOURCES  := $(wildcard $(SRC_DIR)/*.cpp)
INCLUDES := $(wildcard $(INC_DIR)/*.h)
OBJECTS  := $(SOURCES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
EXE      := Translator.exe

DOCS_NAME := Docs_config

all: $(OBJ_DIR) $(EXE)

$(OBJ_DIR):
	@mkdir $@

$(EXE): $(OBJECTS)
	@$(CC) $(LINK_FLAGS) $(OBJECTS) -o $@

$(OBJECTS): $(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(INCLUDES)
	@$(CC) -c $(COMP_FLAGS) -I$(INC_DIR) $< -o $@

$(LOG_DIR):
	@mkdir $@

run: $(EXE) $(LOG_DIR) $(TEX_DIR)
	@$(EXE)

docs:
	doxygen $(DOCS_NAME)


clean: clean_obj clean_exe

clean_obj:
	rm $(OBJ_DIR)/*.o

clean_exe:
	rm *.exe

clean_logs: $(LOG_DIR)
	rm $(LOG_DIR)/*
