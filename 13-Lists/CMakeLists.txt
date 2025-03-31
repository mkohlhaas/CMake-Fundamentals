cmake_minimum_required(VERSION 3.13)

project(List)

set(IM_A_LIST_1 "This;is;a;list")
set(IM_A_LIST_2 This is a list as well)

set(NOT_A_LIST "This is just a string")

message("${IM_A_LIST_1}") # This;is;a;list
message("${IM_A_LIST_2}") # This;is;a;list;as;well
message("${NOT_A_LIST}") # This is just a string

# ##############################################################################

set(FOO A B C)
set(BAR 2 3 4)

set(FOO ${FOO} D)
set(BAR "1;${BAR}")
set(FOOBAR ${FOO} ${BAR})

message("${FOO}") # A;B;C;D
message("${BAR}") # 1;2;3;4
message("${FOOBAR}") # A;B;C;D;1;2;3;4

# ##############################################################################

set(FOO A B C)
set(BAR 2 3 4)
set(FOOBAR)

message("${FOO}") # A;B;C
message("${BAR}") # 2;3;4
message("${FOOBAR}") #

list(APPEND FOO D)
list(PREPEND BAR 1)
list(APPEND FOOBAR ${FOO} ${BAR})

message("${FOO}") # A;B;C;D
message("${BAR}") # 1;2;3;4
message("${FOOBAR}") # A;B;C;D;1;2;3;4

list(POP_BACK FOOBAR four three)
message("${FOOBAR}") # A;B;C;D;1;2
list(POP_FRONT FOOBAR a b)
message("${FOOBAR}") # C;D;1;2
list(
  INSERT
  FOOBAR
  2
  ${four}
  ${a}
  ${three}
  ${b})

message("${FOO}") # A;B;C;D
message("${BAR}") # 1;2;3;4
message("${FOOBAR}") # C;D;4;A;3;B;1;2

# ##############################################################################

set(FOOBAR
    1
    a
    2
    b
    3
    c
    4
    d)

message("${FOOBAR}") # 1;a;2;b;3;c;4;d

list(LENGTH FOOBAR FOOBAR_LEN)
message("${FOOBAR_LEN}") # 8
list(FIND FOOBAR 2 index_2)
message("${index_2}") # 2
list(SUBLIST FOOBAR ${index_2} 4 MIDDLE)
message("${MIDDLE}") # 2;b;3;c
list(
  GET
  FOOBAR
  1
  3
  5
  7
  ALPHA)
message("${ALPHA}") # a;b;c;d
list(REMOVE_AT FOOBAR 1 3 5 7)
message("${FOOBAR}") # 1;2;3;4

# ##############################################################################

set(FOOBAR 1 " 2A" 3 "4B " 5 6C)
message("${FOOBAR}") # 1; 2A;3;4B ;5;6C
list(TRANSFORM FOOBAR STRIP)
message("${FOOBAR}") # 1;2A;3;4B;5;6C
list(TRANSFORM FOOBAR TOLOWER)
message("${FOOBAR}") # 1;2a;3;4b;5;6c
list(
  TRANSFORM FOOBAR
  REPLACE "([0-9])([a-z])" "\\2\\1\\2"
  REGEX "[0-9][a-z]")
message("${FOOBAR}") # 1;a2a;3;b4b;5;c6c

# ##############################################################################

foreach(elem ${FOOBAR})
  message("${elem}") # 1 a2a 3 b4b 5 c6c
endforeach()

foreach(elem IN LISTS FOO BAR)
  message("${elem}") # A B C D 1 2 3 4
endforeach()

# ##############################################################################

set(FOOBAR 1 a 2 b 3)

list(LENGTH FOOBAR FOOBAR_LEN)

# subtract 1 from foobar_len and place the result back in foobar_len
math(EXPR FOOBAR_LEN "${FOOBAR_LEN} - 1")
message("${FOOBAR_LEN}") # 4

foreach(idx RANGE 0 ${FOOBAR_LEN} 1)
  list(SUBLIST FOOBAR ${idx} 2 SUBBAR)
  message("${idx}: ${SUBBAR}")
endforeach()

# ##############################################################################

set(FOO 1 2 3)
set(BAR a b c)
foreach(al num IN ZIP_LISTS FOO BAR)
  message("${al}: ${num}")
endforeach()
