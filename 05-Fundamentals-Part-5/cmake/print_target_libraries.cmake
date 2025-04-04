function(PrintTargetLibraries target msg)
    get_target_property(linkedLibs ${target} LINK_LIBRARIES)
    get_target_property(interfaceLibs ${target} INTERFACE_LINK_LIBRARIES)
    message(STATUS "${msg}")
    message(STATUS "${target} LINK_LIBRARIES: ${linkedLibs}")
    message(STATUS "${target} INTERFACE_LINK_LIBRARIES: ${interfaceLibs}")
endfunction()
