files	d, d, r(1), r(1)
$list
$include btree
$list
$include partdefs

dim byte @_avail[1024]

procedure @_ALLOCATE( node = integer)
	var i, x = integer
	node = node-1
	i = node/8
	x = @_avail[i]
	x = 2^(node-(i*8)) or x
	@_avail[i] = x
	end

procedure @_UN.ALLOCATE( node = integer)
	var i, x = integer
	node = node-1
	i = node/8
	x = @_avail[i]
	x = not (2^(node-(i*8))) and x
	@_avail[i] = x
	end

function @_NEXT.AVAIL.NODE = integer
	var i, x, j, k = integer
	i = 0
	while @_avail[i]=255 do i=i+1
	x = -1
	repeat begin
		x = x+1
		k = @_avail[i]
		j = 2^x and k
		end until j=0
	end = i*8+x+1

procedure open_data_file( bytes_per_record=integer )
	var x=integer
	open #data_file; "PARTLIST.DAT", bytes_per_record
	for x=0 to bytes_per_record-1
		read #data_file,0; @_avail[x]
		next x
	end

procedure close_data_file( bytes_per_record=integer )
	var x=integer
	for x=0 to bytes_per_record-1
		write #data_file,0; @_avail[x]
		next x
	close #data_file
	end

var last_record=integer

procedure get_record( r=integer )
	var x = integer
	if r=last_record then read #data_file,0
	last_record = r
	read #data_file,r; part_num, atrib, description, version, check_num, quantity, life_time
	for x=0 to max_sub
		read #data_file,r; sub_part_num[x]
		next x
	end

procedure put_record( r=integer )
	var x = integer
	if r=last_record then read #data_file,0
	last_record = r
	write #data_file,r; part_num, atrib, description, version, check_num, quantity, life_time
	for x=0 to max_sub
		write #data_file,r; sub_part_num[x]
		next x
	end

procedure blank_record
	var x = integer
	part_num	= ""
	atrib		= ""
	description	= ""
	version		= ""
	check_num	= ""
	quantity	= 0
	life_time	= ""
	for x=0 to max_sub
		sub_part_num[x] = ""
		next x
	end

Procedure clear_data_file( bytes_per_record=integer )
	var x=integer
	close.btree
	close_data_file bytes_per_record
	create.btree "PARTLIST.DIR", 12, 36, 342
	delete "PARTLIST.DAT"
	create "PARTLIST.DAT"
	open #data_file; "PARTLIST.DAT", bytes_per_record
	for x=0 to bytes_per_record-1
		@_avail[x] = 0
		next x
	@_avail[0] = 1
	for x=0 to bytes_per_record-1
		write #data_file,0; @_avail[x]
		next x
	blank_record
	part_num = "NF"
	description = "No record for this part number."
	put_record 1
	part_num = deleted
	description = ""
	put_record 2
	end

procedure hard_copy( i=integer )
	var x = integer
	for x=1 to i+1
		print #list; "    ";
		next x
	print using line_format1; #list; part_num, description;
	while pos(list)<90 do print #list; ' ';
	print using line_format2; #list;\
		atrib, version, check_num, quantity, life_time
	if pos(-list)>55 then print #list; chr(0ch);
	end of hard_copy

function non_blank( s=string )=integer
	var result = integer
	result = true
	if len(s)=0 then result=false
	end = result

procedure modify_record
	var x=integer
	var y=string
	input "part_num"; part_num
	input "atrib"; atrib
	input "description"; description
	input "version"; version
	input "check_num"; check_num
	input "quantity"; quantity
	input "life_time"; life_time
	print "Enter part number list, end with return only"
	x=0
	y=""
	repeat begin
		print x;
		input y
		sub_part_num[x]=y
		x=x+1
		end until y=""
	sub_part_num[x-1]=""
	end

Procedure print_part_num
	var indent = integer
	procedure print_record( pn=string )
		var r, index = integer
		index = 0
		r = search(pn)
		if r=bad_search then begin
			get_record not_found
			part_num = pn
			end
		    else
			get_record r
		hard_copy indent
		indent = indent+1
		while index<max_sub and non_blank(sub_part_num[index]) do begin
			print_record sub_part_num[index]
			get_record r
			index = index+1
			end
		indent = indent-1
		end
	indent = 0
	print_record part_num
	end of print_part_num

Procedure add_part
	var r,d=integer
	blank_record
	modify_record
	r = @_next.avail.node
	@_allocate r
	put_record r
	d = search(part_num)
	insert part_num, r
	print "Part added to data base."
	end

Procedure delete_part
	var r=integer
	r = search( part_num )
	if r<>bad_search then begin
		delete.key part_num
		blank_record
		part_num = deleted
		put_record r
		@_un.allocate r
		end
	    else print "Part not found."
	end


var option = char
open_data_file 512
open.btree "PARTLIST.DIR", 12, 36, 342

repeat begin
	input "Print, Add, Delete, Exit ";option
	case option of
		'P':	begin
				input "Part number"; part_num
				print_part_num
				end
		'A':	add_part
		'D':	begin
				input "Part number"; part_num
				delete_part
				end
		'E':	begin
				close.btree
				close_data_file 512
				end
		'C':	begin
				var x=char
				input "Erase data base";x
				if x then clear_data_file 512
				end
		end of case
	end until option='E'
