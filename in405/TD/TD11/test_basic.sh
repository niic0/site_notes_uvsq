#!/usr/bin/sh

PROG="./pattern-finder"

TESTS=(
    "Lorem 0\n"
    "lorem 271\n1235\n"
    "lor 14\n271\n490\n861\n1235\n1632\n"
)

for tst in "${TESTS[@]}"; do
    pattern=$(echo $tst | cut -d' ' -f1 -)
    results=$(echo -e $tst | cut -d' ' -f2 -)
    echo -n "$pattern: "
    res=$($PROG 1 $pattern lorem.txt)
    if [ "$res" == "$results" ]; then
        echo "OK!"
    else
        echo "KO."
    fi
done
