# This gets all new text from W_test_boards.h and converts all W_ to B_ then appends it to B_test_boards.h
# The new file may have to be edited if there are Pawns, 
diff="$(git diff W_test_boards.h | grep -e '^\+[^\+]' | sed 's/^\+//g' | sed 's/W_/B_/g')"
echo -e "$diff" >> B_test_boards.h
