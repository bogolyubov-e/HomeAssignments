# Компилятор и флаги
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I.
GTEST_FLAGS = -lgtest -lgtest_main -pthread

# Основные исходники
MAIN_SOURCE = main.cpp
SOURCES = transformer.cpp weapon.cpp vehicle.cpp autobot.cpp decepticon.cpp maximal.cpp
OBJECTS = $(SOURCES:.cpp=.o)
MAIN_OBJECT = $(MAIN_SOURCE:.cpp=.o)

# Тестовые файлы
TEST_SOURCES = tests/test_transformer.cpp tests/test_weapon.cpp tests/test_vehicle.cpp \
               tests/test_autobot.cpp tests/test_decepticon.cpp tests/test_maximal.cpp
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
ALL_TESTS_SOURCE = tests/test_all.cpp
ALL_TESTS_OBJECT = $(ALL_TESTS_SOURCE:.cpp=.o)

# Исполняемые файлы
MAIN_TARGET = transformers_app
ALL_TESTS_TARGET = test_all

# Имена отдельных тестов
TEST_TARGETS = test_transformer test_weapon test_vehicle test_autobot test_decepticon test_maximal

.PHONY: all app test_all clean help

# По умолчанию
all: app test_all

# Основное приложение
app: $(MAIN_TARGET)

$(MAIN_TARGET): $(MAIN_OBJECT) $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

# Все тесты вместе
test_all: $(ALL_TESTS_TARGET)

$(ALL_TESTS_TARGET): $(OBJECTS) $(ALL_TESTS_OBJECT)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

# Отдельные тесты
test_transformer: transformer.o weapon.o vehicle.o tests/test_transformer.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

test_weapon: weapon.o tests/test_weapon.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

test_vehicle: vehicle.o tests/test_vehicle.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

test_autobot: transformer.o weapon.o vehicle.o autobot.o tests/test_autobot.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

test_decepticon: transformer.o weapon.o vehicle.o decepticon.o tests/test_decepticon.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

test_maximal: transformer.o weapon.o vehicle.o maximal.o tests/test_maximal.o
	$(CXX) $(CXXFLAGS) -o $@ $^ $(GTEST_FLAGS)

# Правила компиляции объектов
transformer.o: transformer.cpp transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c transformer.cpp -o transformer.o

weapon.o: weapon.cpp weapon.h
	$(CXX) $(CXXFLAGS) -c weapon.cpp -o weapon.o

vehicle.o: vehicle.cpp vehicle.h
	$(CXX) $(CXXFLAGS) -c vehicle.cpp -o vehicle.o

autobot.o: autobot.cpp autobot.h transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c autobot.cpp -o autobot.o

decepticon.o: decepticon.cpp decepticon.h transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c decepticon.cpp -o decepticon.o

maximal.o: maximal.cpp maximal.h transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c maximal.cpp -o maximal.o

main.o: main.cpp transformer.h weapon.h vehicle.h autobot.h decepticon.h maximal.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Тестовые объекты
tests/test_transformer.o: tests/test_transformer.cpp transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c tests/test_transformer.cpp -o tests/test_transformer.o

tests/test_weapon.o: tests/test_weapon.cpp weapon.h
	$(CXX) $(CXXFLAGS) -c tests/test_weapon.cpp -o tests/test_weapon.o

tests/test_vehicle.o: tests/test_vehicle.cpp vehicle.h
	$(CXX) $(CXXFLAGS) -c tests/test_vehicle.cpp -o tests/test_vehicle.o

tests/test_autobot.o: tests/test_autobot.cpp autobot.h transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c tests/test_autobot.cpp -o tests/test_autobot.o

tests/test_decepticon.o: tests/test_decepticon.cpp decepticon.h transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c tests/test_decepticon.cpp -o tests/test_decepticon.o

tests/test_maximal.o: tests/test_maximal.cpp maximal.h transformer.h weapon.h vehicle.h
	$(CXX) $(CXXFLAGS) -c tests/test_maximal.cpp -o tests/test_maximal.o

tests/test_all.o: tests/test_all.cpp
	$(CXX) $(CXXFLAGS) -c tests/test_all.cpp -o tests/test_all.o

# Запуск
run_app: app
	./$(MAIN_TARGET)

run_test_all: test_all
	./$(ALL_TESTS_TARGET)

run_test_transformer: test_transformer
	./test_transformer

run_test_autobot: test_autobot
	./test_autobot

run_test_decepticon: test_decepticon
	./test_decepticon

run_test_maximal: test_maximal
	./test_maximal

# Очистка
clean:
	rm -f *.o
	rm -f tests/*.o
	rm -f $(MAIN_TARGET) $(ALL_TESTS_TARGET) $(TEST_TARGETS)

# Помощь
help:
	@echo "=== Transformers Project Commands ==="
	@echo "make app              - Build main application"
	@echo "make test_all         - Build and run all tests"
	@echo "make test_transformer - Build Transformer tests"
	@echo "make test_autobot     - Build Autobot tests"
	@echo "make test_decepticon  - Build Decepticon tests"
	@echo "make test_maximal     - Build Maximal tests"
	@echo "make run_app          - Run main application"
	@echo "make clean            - Clean project"
