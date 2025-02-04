CC := g++
DED_FLAGS  := -D _DEBUG -ggdb3 -std=c++17 -O0 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations -Wc++14-compat 	\
	-Wmissing-declarations -Wcast-align -Wcast-qual -Wchar-subscripts -Wconditionally-supported -Wconversion 			\
	-Wctor-dtor-privacy -Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-signedness 			\
	-Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor -Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith 	\
	-Winit-self -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=2 	\
	-Wsuggest-attribute=noreturn -Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override -Wswitch-default 		\
	-Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code -Wunused -Wuseless-cast -Wvariadic-macros -Wno-literal-suffix 	\
	-Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast -Wno-varargs -Wstack-protector -fcheck-new 		\
	-fsized-deallocation -fstack-protector -fstrict-overflow -flto-odr-type-merging -fno-omit-frame-pointer 			\
	-Wlarger-than=8192 -Wstack-usage=8192 -pie -fPIE -Werror=vla 														\
	-fsanitize=address,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,undefined,unreachable,vla-bound,vptr
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
