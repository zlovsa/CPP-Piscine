catreplace() {
	echo "------text.replace------"
	cat text.replace
	echo "\n------------------------"
	read -n 1 -s -r -p "Press any key to continue"
	echo ""
}

replace() {
	echo $1
	$1
}

echo "<----- ERROR HANDLING ----->"
replace "./replace"
echo "./replace file a \"\""
./replace file a ""
echo "./replace file \"\" b"
./replace file "" b
replace "./replace qwerty a b"
ls -l readonly.replace
replace "./replace readonly a b"

echo "\n<------ FILE REPLACE ------>"
echo "text:"
echo "----------text----------"
cat text
echo "\n------------------------"
replace "./replace text a b"
catreplace
replace "./replace text 1 23"
catreplace
echo "./replace text \" \" -"
./replace text " " -
catreplace
replace "./replace text ab A"
catreplace
replace "./replace text 2 2"
catreplace
replace "./replace text 1 21"
catreplace