files	d, d, r(1), r(1)

$list
$include btree
$include partdefs
$list
procedure put_record( r=integer )
	var x=integer
	write #data_file,r; part_num, atrib, description, version, check_num, quantity, life_time
	for x=0 to max_sub
		write #data_file,r; sub_part_num[x]
		next x
	end

create.btree "PARTLIST.DIR", 12, 36, 342
delete "PARTLIST.DAT"
create "PARTLIST.DAT"
open #data_file; "PARTLIST.DAT", 512
part_num = deleted
atrib=""
description=""
version = ""
check_num = ""
quantity = 0
life_time = ""
var x=integer
for x=0 to 31
sub_part_num[x]=""
next x
for x=0 to 100
	put_record x
	next x

