cmake_minimum_required(VERSION 3.12)

project(Registration_test)

# FF temporarily deactivated InertiaAlign_test, as well as add_executable since it does not accept 0 parameter
set(SOURCE_FILES
    # InertiaAlign_test.cpp
    GroupwiseRegistrationEngine_test.cpp
)

if(image_FOUND)
    list(APPEND SOURCE_FILES IntensityProfileCreator_test.cpp)
    list(APPEND SOURCE_FILES IntensityProfileRegistrationForceField_test.cpp)
endif()

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} Registration Sofa.Testing)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
