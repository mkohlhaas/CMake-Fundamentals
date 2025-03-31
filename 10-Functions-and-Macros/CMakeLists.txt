cmake_minimum_required(VERSION 3.31)

project(ProjectName)

# ##############################################################################

# myFunction1 prints `foo` and `bar`
function(myFunction1 foo bar)
  message("myFunction: ${foo}, ${bar}")
endfunction()

myfunction1("hello" "functions") # myFunction: hello, functions

# ##############################################################################

# MY_MACRO prints `foo` and `bar`
macro(MY_MACRO foo bar)
  message("myMacro: ${foo}, ${bar}")
endmacro()

my_macro("hello" "macros") # myMacro: hello, macros

# ##############################################################################

# SET_FOO1 sets FOO1
macro(SET_FOO_1 value)
  set(FOO_1 ${value})
endmacro()

set_foo_1("Assign this value to FOO_1")

if(DEFINED FOO_1)
  message("FOO_1: ${FOO_1}") # FOO_1: Assign this value to FOO_1
else()
  message("FOO_1 is undefined")
endif()

# ##############################################################################

# set_bar_1 sets BAR
function(set_bar_1 value)
  set(bar_1 ${value})
  message("set_bar_1: ${bar_1}")
endfunction()

set_bar_1("Assign this value to bar_1") # set_bar_1: Assign this value to bar_1
message("set_bar_1: ${bar_1}") # set_bar_1:

if(DEFINED bar_1)
  message("bar_1: ${bar_1}")
else()
  message("bar_1 is undefined") # bar_1 is undefined
endif()

# ##############################################################################

# set_bar_2 sets bar
function(set_bar_2 value)
  set(bar_2
      ${value}
      PARENT_SCOPE)
  message("set_bar_2: ${bar_2}")
endfunction()

set_bar_2("Assign this value to bar_2") # set_bar_2:
message("${bar_2}") # Assign this value to bar_2

if(DEFINED bar_2)
  message("bar_2: ${bar_2}") # bar_2: Assign this value to bar_2
else()
  message("bar_2 is undefined")
endif()

# ##############################################################################

# sets bar also in parent scope
function(set_bar_3 value)
  set(bar_3 ${value})
  set(bar_3
      ${bar_3}
      PARENT_SCOPE)
  message("set_bar_3: ${bar_3}")
endfunction()

set_bar_3("Assign this value to bar_3") # set_bar_3: Assign this value to bar_3
message("${bar_3}") # Assign this value to bar_3

if(DEFINED bar_3)
  message("bar_3: ${bar_3}") # bar_3: Assign this value to bar_3
else()
  message("bar_3 is undefined")
endif()

# ##############################################################################

# sets variable `varName` to `value`
function(setVariable varName value)
  set(${varName} ${value})
  set(${varName}
      ${${varName}} # deref twice to get value
      PARENT_SCOPE)
  message("setVariable: ${varName} = ${${varName}}")
endfunction()

# setVariable: Foobar = Assign this value to Foobar
setvariable(Foobar "Assign this value to Foobar")

message("Foobar = ${Foobar}") # Foobar = Assign this value to Foobar

# ##############################################################################

# sets foo and bar
function(myFunction foo bar)
  message("myFunction:")
  message("  foo:   ${foo}, bar: ${bar}")
  message("  ARGC:  ${ARGC}")
  message("  ARGV:  ${ARGV}")
  message("  ARGN:  ${ARGN}")

  math(EXPR indices "${ARGC} - 1")
  foreach(index RANGE 0 ${indices} 1)
    message("  ARGV${index}: ${ARGV${index}}")
  endforeach()
endfunction()

myfunction("Michael" "Kohlhaas" "Thomas" "von Aquin")

# myFunction:
#
# foo:   Michael, bar: Kohlhaas
#
# ARGC:  4
#
# ARGV:  Michael;Kohlhaas;Thomas;von Aquin
#
# ARGN:  Thomas;von Aquin
#
# ARGV0: Michael
#
# ARGV1: Kohlhaas
#
# ARGV2: Thomas
#
# ARGV3: von Aquin

# ##############################################################################

# adds a test
function(add_test_1 targetName dependency)
  add_executable(${targetName} ${ARGN})

  target_link_libraries(${targetName} PRIVATE ${dependency})

  add_test(NAME ${targetName} COMMAND ${targetName})
endfunction()

add_test_1(testFoo Bar test_foo.cpp)

# ##############################################################################

# adds a test
function(add_test_2 targetName)
  set(flags)
  set(args)
  set(listArgs SOURCES DEPENDENCIES)

  cmake_parse_arguments(arg "${flags}" "${args}" "${listArgs}" ${ARGN})

  if(NOT arg_SOURCES)
    message(FATAL_ERROR "[AddTest]: SOURCES is a required argument")
  endif()

  if(SOURCES IN_LIST arg_KEYWORDS_MISSING_VALUES)
    message(FATAL_ERROR "[AddTest]: SOURCES requires at least one value")
  endif()

  add_executable(${targetName} ${arg_SOURCES})
  target_link_libraries(${targetName} PRIVATE ${arg_DEPENDENCIES})
  add_test(NAME ${targetName} COMMAND ${targetName})
endfunction()

add_test_2(testFoo SOURCES DEPENDENCIES Bar)
add_test_2(testFoo SOURCES test_foo.cpp DEPENDENCIES Bar)

# ##############################################################################

# adds a test
function(add_test_3 targetName)
  set(flags WILL_FAIL)
  set(args WORKING_DIRECTORY)
  set(listArgs SOURCES DEPENDENCIES)

  cmake_parse_arguments(arg "${flags}" "${args}" "${listArgs}" ${ARGN})

  # ...
  if(WORKING_DIRECTORY IN_LIST arg_KEYWORDS_MISSING_VALUES)
    message(FATAL_ERROR "[AddTest]: WORKING_DIRECTORY is missing a value")
  endif()

  add_test(
    NAME ${targetName}
    COMMAND ${targetName}
    WORKING_DIRECTORY ${arg_WORKING_DIRECTORY})

  set_tests_properties(${targetName} PROPERTIES WILL_FAIL ${arg_WILL_FAIL})

endfunction()
