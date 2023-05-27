export EXECUTABLE := my_proj

.PHONY: default
default: $(EXECUTABLE)

export DEBUG_FLAGS ?= -O3
export SOURCE_FILES := $(wildcard *.cpp)
export OBJ_FILES := $(patsubst %.cpp, %.o, $(SOURCE_FILES))
export DEP_FILES := $(patsubst %.cpp, %.dep, $(SOURCE_FILES))
export TEMP_FILES := $(OBJ_FILES) $(DEP_FILES) $(EXECUTABLE)

$(EXECUTABLE):  
		@echo "Compiling $<"
		@g++  $(SOURCE_FILES)  -o $(EXECUTABLE) 

.PHONY: clean
clean:
		@echo "Cleaning the temprorary files"
		@-rm $(EXECUTABLE)
		@-rm *.png
		@-rm *.gv

.PHONY: run
run: $(EXECUTABLE)
		@echo "Running the tests"
		@ ./$(EXECUTABLE)
		@feh new.png


