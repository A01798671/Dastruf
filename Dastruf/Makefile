# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -mconsole -Iinclude
TARGET = Dastruf
SOURCES = $(wildcard src/*.cpp) # Incluye todos los .cpp en src/
OBJECTS = $(SOURCES:.cpp=.o)

# Regla principal para compilar el programa
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

# Regla para compilar cada archivo .cpp en un .o
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para ejecutar el programa en modo REPL
run: $(TARGET)
	./$(TARGET)

# Regla para ejecutar con un archivo de script
run-script: $(TARGET)
	./$(TARGET) script.lox

# Regla para limpiar los archivos generados
clean:
	rm -f $(TARGET) src/*.o