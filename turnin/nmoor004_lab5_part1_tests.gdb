# Test file for Lab5_ATMega


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

test "PINA: 0x02 => PORTC: 0x30" 
setPINA 0x02
continue 5
expectPORTC 0x30
checkResult

test "PINA: 0x04 => PORTC: 0x30" 
setPINA 0x04
continue 5
expectPORTC 0x38
checkResult

test "PINA: 0x06 => PORTC: 0x18" 
setPINA 0x06
continue 5
expectPORTC 0x18
checkResult

test "PINA: 0x09 => PORTC: 0x1C" 
setPINA 0x09
continue 5
expectPORTC 0x1C
checkResult

test "PINA: 0x0C => PORTC: 0x1E" 
setPINA 0x0C
continue 5
expectPORTC 0x1E
checkResult

test "PINA: 0x0F => PORTC: 0x1F" 
setPINA 0x0F
continue 5
expectPORTC 0x1F
checkResult

# Add tests below

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
