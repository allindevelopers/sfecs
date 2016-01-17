cmake_minimum_required( VERSION 3.3 )

function( build_example SAMPLE_NAME SOURCES )
    add_executable( ${SAMPLE_NAME} ${SOURCES} )
    target_link_libraries( ${SAMPLE_NAME} SFECS ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${OPENGL_gl_LIBRARY} )

    install(
            TARGETS ${SAMPLE_NAME}
            RUNTIME DESTINATION "${SHARE_PATH}/examples" COMPONENT examples
    )

    install(
            FILES ${SOURCES}
            DESTINATION "${SHARE_PATH}/examples" COMPONENT examples
    )
endfunction()

build_example( "HelloWorld" "HelloWorld.cpp" )

# Copy data directory to build cache directory to be able to run examples from
# there. Useful for testing stuff.
# Don't try to copy if the directories are the same.
#if( NOT ( "${PROJECT_SOURCE_DIR}" STREQUAL "${PROJECT_BINARY_DIR}" ) )
#    add_custom_command(
#            TARGET "SFECS-Test"
#            COMMAND "${CMAKE_COMMAND}"
#            ARGS -E copy_directory "${PROJECT_SOURCE_DIR}/examples/data" "${PROJECT_BINARY_DIR}/examples/data"
#    )
#
#    add_custom_command(
#            TARGET "Image"
#            COMMAND "${CMAKE_COMMAND}"
#            ARGS -E copy_directory "${PROJECT_SOURCE_DIR}/examples/data" "${PROJECT_BINARY_DIR}/examples/data"
#    )
#
#    add_custom_command(
#            TARGET "Canvas"
#            COMMAND "${CMAKE_COMMAND}"
#            ARGS -E copy_directory "${PROJECT_SOURCE_DIR}/examples/data" "${PROJECT_BINARY_DIR}/examples/data"
#    )
#endif()

#install(
#        DIRECTORY data
#        DESTINATION "${SHARE_PATH}/examples"
#)