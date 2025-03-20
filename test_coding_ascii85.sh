#!/bin/bash

set -e

echo "Starting encoding test..."

# Тестовые данные для кодирования
INPUT_DATA="Hello, World!"
EXPECTED_OUTPUT="87cURD_*#4DfTZ)+~>"

# Кодируем данные
ENCODED_OUTPUT=$(echo -n "$INPUT_DATA" | ./main -e)

# Проверяем результат
if [ "$ENCODED_OUTPUT" == "$EXPECTED_OUTPUT" ]; then
    echo "Encoding test passed: Output matches expected result."
else
    echo "Encoding test failed: Output does not match expected result."
    echo "Expected: $EXPECTED_OUTPUT"
    echo "Got: $ENCODED_OUTPUT"
    exit 1
fi
