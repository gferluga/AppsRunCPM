var	bad_search	; Btree return for bad search on key
	not_found	; record number to be used when key not found
	list		; channel number of printer
	true		; bool true
	false		; bool false
	= integer

var	deleted = string

var	line_format = string:132
line_format = "/...5....0./ /../ /...5....0....5....0....5....0....5..../ /.../ /.../ #### /...5../"

var	part_num	= string:12
var	atrib		= string:4
var	description	= string:50
var	version		= string:5
var	check_num	= string:5
var	quantity	= integer
var	life_time	= string:8

$constant data_file = 3
$constant max_sub = 31

dim string:12; sub_part_num[max_sub]

bad_search = -1
not_found = 1
list = 1
true = -1
false = 0
deleted = "DELETED"

var file_buffer = integer
location file file_buffer = #data_file
rem base part_num    at file_buffer+0
rem base atrib       at file_buffer+13
rem base description at file_buffer+18
rem base version     at file_buffer+69
rem base check_num   at file_buffer+75
rem base quantity    at file_buffer+81
rem base life_time   at file_buffer+83
rem locate sub_part_num at file_buffer+92

