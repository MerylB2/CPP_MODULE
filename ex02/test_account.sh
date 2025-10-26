#!/bin/bash

echo "=== Account Test - Output Comparison ==="
echo ""

# Run the test
./Account > my_output.log

echo "Generated output saved to: my_output.log"
echo ""
echo "=== Comparing with expected output (ignoring timestamps) ==="
echo ""

# Compare without timestamps
sed 's/\[[0-9_]*\]/[TIMESTAMP]/' my_output.log > my_output_no_time.log
sed 's/\[[0-9_]*\]/[TIMESTAMP]/' 19920104_091532.log > expected_no_time.log

if diff -q my_output_no_time.log expected_no_time.log > /dev/null; then
    echo "✅ SUCCESS! Output matches expected log (excluding timestamps)"
    echo ""
    echo "Your Account.cpp implementation is correct!"
else
    echo "❌ DIFFERENCE FOUND"
    echo ""
    echo "Differences (excluding timestamps):"
    diff my_output_no_time.log expected_no_time.log
fi

# Clean up temp files
rm -f my_output_no_time.log expected_no_time.log

echo ""
echo "=== Full output with timestamps ==="
cat my_output.log