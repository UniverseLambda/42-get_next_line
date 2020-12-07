#!/bin/sh

sh build.sh

mkdir results tests

function gln_test {
	echo "=============================================================================================================="
	echo "testing with $1..."
	wc -l tests/$1 | sed -E 's| *([0-9]*).*|\1|' > results/$1_expected
	./gln_main tests/$1 > results/$1_result
	echo "***** RET CODE: $? *****"
	diff results/$1_expected results/$1_result
}

gln_test 1_newline
gln_test 41_char
gln_test 42_char
gln_test 43_char
gln_test 4_newlines
gln_test alphabet
gln_test codecat
gln_test empty
gln_test empty_file
gln_test empty_lines
gln_test half_marge_bottom
gln_test half_marge_top
gln_test huge_alphabet
gln_test huge_file
gln_test huge_line
gln_test huge_lines
gln_test huge_lines2
gln_test lf
gln_test mix_marge1
gln_test mix_marge2
gln_test rand1
gln_test rand2

