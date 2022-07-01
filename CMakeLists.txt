cmake_minimum_required(VERSION 3.12)
project(Registration VERSION 0.1)

find_package(Sofa.GL REQUIRED)
sofa_find_package(Sofa.Component.IO.Mesh REQUIRED)
sofa_find_package(Sofa.Component.Engine.Generate REQUIRED)
sofa_find_package(Sofa.Component.Collision.Response.Mapper REQUIRED)
sofa_find_package(SofaDistanceGrid QUIET)
sofa_find_package(image QUIET)

set(REGISTRATION_SRC "src/${PROJECT_NAME}")

set(HEADER_FILES
    ${REGISTRATION_SRC}/config.h.in
    ${REGISTRATION_SRC}/ClosestPointRegistrationForceField.h
    ${REGISTRATION_SRC}/ClosestPointRegistrationForceField.inl
    ${REGISTRATION_SRC}/GroupwiseRegistrationEngine.h
    ${REGISTRATION_SRC}/InertiaAlign.h
    ${REGISTRATION_SRC}/RegistrationContact.h
    ${REGISTRATION_SRC}/RegistrationContact.inl
    ${REGISTRATION_SRC}/RegistrationContactForceField.h
    ${REGISTRATION_SRC}/RegistrationContactForceField.inl
    ${REGISTRATION_SRC}/RegistrationExporter.h
)

set(SOURCE_FILES
    ${REGISTRATION_SRC}/ClosestPointRegistrationForceField.cpp
    ${REGISTRATION_SRC}/GroupwiseRegistrationEngine.cpp
    ${REGISTRATION_SRC}/InertiaAlign.cpp
    ${REGISTRATION_SRC}/RegistrationContact.cpp
    ${REGISTRATION_SRC}/RegistrationContactForceField.cpp
    ${REGISTRATION_SRC}/RegistrationExporter.cpp
    ${REGISTRATION_SRC}/initRegistration.cpp
)

set(PYTHON_FILES

    python/Registration/__init__.py
    python/Registration/sml.py

)

set(README_FILES README.md)

if(image_FOUND)
    list(APPEND HEADER_FILES ${REGISTRATION_SRC}/IntensityProfileRegistrationForceField.h)
    list(APPEND HEADER_FILES ${REGISTRATION_SRC}/IntensityProfileRegistrationForceField.inl)
    list(APPEND SOURCE_FILES ${REGISTRATION_SRC}/IntensityProfileRegistrationForceField.cpp)
    list(APPEND HEADER_FILES ${REGISTRATION_SRC}/IntensityProfileCreator.h)
    list(APPEND SOURCE_FILES ${REGISTRATION_SRC}/IntensityProfileCreator.cpp)
else()
    message(STATUS "Registration: could not find image, won't build IntensityProfileRegistrationForceField")
endif()

# Config files and install rules for pythons scripts
sofa_install_pythonscripts(
    PLUGIN_NAME ${PROJECT_NAME}
    PYTHONSCRIPTS_SOURCE_DIR "python"
)

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES} ${README_FILES} ${PYTHON_FILES})
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.Component.IO.Mesh Sofa.Component.Collision.Response.Mapper Sofa.Component.Engine.Generate)
target_link_libraries(${PROJECT_NAME} PUBLIC Sofa.GL)

if(image_FOUND)
    target_link_libraries(${PROJECT_NAME} PUBLIC image)
endif()

if(SofaDistanceGrid_FOUND)
    target_link_libraries(${PROJECT_NAME} PUBLIC SofaDistanceGrid)
else()
    message(STATUS "Registration: could not find SofaDistanceGrid, won't build RegistrationContact for RigidDistanceGridCollisionModel.")
endif()


find_package(SofaTest QUIET)
if(SofaTest_FOUND)
    add_subdirectory(Registration_test)
endif()

## Install rules for the library; CMake package configurations files
sofa_create_package_with_targets(

    PACKAGE_NAME ${PROJECT_NAME}
    PACKAGE_VERSION ${Sofa_VERSION}
    TARGETS ${PROJECT_NAME} AUTO_SET_TARGET_PROPERTIES
    INCLUDE_SOURCE_DIR "src"
    INCLUDE_INSTALL_DIR "${PROJECT_NAME}"
    RELOCATABLE "plugins"
)
