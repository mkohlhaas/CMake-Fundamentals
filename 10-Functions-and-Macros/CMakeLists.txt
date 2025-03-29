cmake_minimum_required(VERSION 3.31)

project(ProjectName)

#############################################

function(myFunction foo bar)
    message("myFunction: ${foo}, ${bar}")
endfunction()

myFunction("hello" "functions")

#############################################

macro(myMacro foo bar)
    message("myMacro: ${foo}, ${bar}")
endmacro()

myMacro("hello" "macros")

#############################################

macro(setFoo value)
    set(Foo ${value})
endmacro()

setFoo("Assign this value to Foo")

if (DEFINED Foo)
    message("Foo: ${Foo}")
else()
    message("Foo is undefined")
endif()

#############################################

function(setBar value)
    set(Bar ${value})
    message("setBar: ${Bar}")
endfunction()

setBar("Assign this value to Bar")
message("${Bar}")  # empty

if (DEFINED Bar)
    message("Bar: ${Bar}")
else()
    message("Bar is undefined")
endif()

#############################################

function(setBar value)
    set(Bar ${value} PARENT_SCOPE)
    message("setBar: ${Bar}")
endfunction()

setBar("Assign this value to Bar")
message("${Bar}")

if (DEFINED Bar)
    message("Bar: ${Bar}")
else()
    message("Bar is undefined")
endif()

#############################################

function(setBar value)
    set(Bar ${value})
    set(Bar ${Bar} PARENT_SCOPE)
    message("setBar: ${Bar}")
endfunction()

setBar("Assign this value to Bar")
message("${Bar}")

if (DEFINED Bar)
    message("Bar: ${Bar}")
else()
    message("Bar is undefined")
endif()

#############################################

function(setVariable varName value)
    set(${varName} ${value})
    # deref twice to get value
    set(${varName} ${${varName}} PARENT_SCOPE)
    message("setVariable: ${varName} = ${${varName}}")
endfunction()

setVariable(Foobar "Assign this value to Foobar")
message("Foobar = ${Foobar}")

#############################################

function(myFunction foo bar)
    message("myFunction:")
    message("  foo: ${foo}, bar: ${bar}")
    message("  ARGC: ${ARGC}")
    message("  ARGV: ${ARGV}")
    message("  ARGN: ${ARGN}")

    math(EXPR indices "${ARGC} - 1")
    foreach(index RANGE ${indices})
        message("  ARGV${index}: ${ARGV${index}}")
    endforeach()
endfunction()

myFunction("Michael" "Kohlhaas" "Thomas" "Abin")
#############################################

