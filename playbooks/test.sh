#!/usr/bin/env bash

log_dir="bazel-testlogs"
log_file="test.xml"
regex_all_tests='testsuite[[:space:]]name=\"[a-zA-Z/_]+\"[[:space:]]tests=\"[[:digit:]]+\"[[:space:]]failures=\"[[:digit:]]\"'
regex_passed_tests='testsuite[[:space:]]name=\"[a-zA-Z/_]+\"[[:space:]]tests=\"[[:digit:]]+\"[[:space:]]failures=\"0\"'

test_count(){
    result=$(find $log_dir/ -name $log_file | xargs cat | egrep "$2" | wc -l)
    echo $1 $result
}

test_count "TEST COUNT:" $regex_all_tests
test_count "PASSED TESTS:" $regex_passed_tests