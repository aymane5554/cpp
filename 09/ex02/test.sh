shuf -i 0-2147483647 -n 3000 > input

make all clean > /dev/null

./RPN $(cat input | tr '\n' ' ') > output

cat input | sort -n > output2

diff output output2

rm -f input output output2