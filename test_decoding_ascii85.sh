#!/bin/bash

set -e

echo "Starting decoding test..."

# Тестовые данные для декодирования
INPUT_DATA="87cURD_*#4DfTZ)+~>"
EXPECTED_OUTPUT="Hello, World!"

# Декодируем данные
DECODED_OUTPUT=$(echo -n "$INPUT_DATA" | ./main -d)

# Проверяем результат
if [ "$DECODED_OUTPUT" == "$EXPECTED_OUTPUT" ]; then
    echo "Decoding test passed: Output matches expected result."
else
    echo "Decoding test failed: Output does not match expected result."
    echo "Expected: $EXPECTED_OUTPUT"
    echo "Got: $DECODED_OUTPUT"
    exit 1
fi
