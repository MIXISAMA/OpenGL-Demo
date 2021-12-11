cmake_minimum_required(VERSION 3.12)
project(OpenGL_Demo)

set(CMAKE_CXX_STANDARD 17)


# ==========================

add_subdirectory(3rdparty)

find_package(gflags REQUIRED)
find_package(glog REQUIRED)
find_package(glfw3 REQUIRED)

aux_source_directory(src MAIN_SRC_DIR)
aux_source_directory(src/app APP_SRC_DIR)

# ==========================

file(GLOB_RECURSE SOURCE_LIST CONFIGURE_DEPENDS "src/*.cpp")

file(GLOB_RECURSE RES_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/resource/*")

if(APPLE)
    add_executable(${PROJECT_NAME} MACOSX_BUNDLE
        ${SOURCE_LIST}
        ${RES_SOURCES}
    )
    # set_target_properties(${PROJECT_NAME} PROPERTIES
    #     BUNDLE True
    #     MACOSX_BUNDLE_GUI_IDENTIFIER my.domain.style.identifier.${PROJECT_NAME}
    #     MACOSX_BUNDLE_BUNDLE_NAME ${PROJECT_NAME}
    #     MACOSX_BUNDLE_BUNDLE_VERSION "0.1"
    #     MACOSX_BUNDLE_SHORT_VERSION_STRING "0.1"
    #     MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/MacOSXBundleInfo.plist.in
    # )

    # file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.app/Contents/Resources/log)

    # Individually set the file's path properties.
    # foreach (FILE ${RES_SOURCES})

    #     message(FILE)
    #     # Get the relative path from the data-folder to the particular file.
    #     file(RELATIVE_PATH NEW_FILE "${CMAKE_CURRENT_SOURCE_DIR}/resource" ${FILE})

    #     # Get the relative path to the file.
    #     get_filename_component(NEW_FILE_PATH ${NEW_FILE} DIRECTORY)

    #     # Set it's location inside the app package (under Resources).
    #     set_property(SOURCE ${FILE} PROPERTY MACOSX_PACKAGE_LOCATION "Resources/${NEW_FILE_PATH}")

    #     # Optional: Add the file to the 'Resources' folder group in Xcode.
    #     #           This also preserves folder structure.
    #     source_group("Resources/${NEW_FILE_PATH}" FILES "${FILE}")
    # endforeach ()

else()
    add_executable(${PROJECT_NAME}
        ${SOURCE_LIST}
    )
endif()


target_include_directories(${PROJECT_NAME}
    PUBLIC 3rdparty/glad/include
    PUBLIC 3rdparty/glm
    PUBLIC include
    PUBLIC ${gflags_INCLUDE_DIR}
)


target_link_directories(${PROJECT_NAME}
    PUBLIC build/3rdparty/glad
    PUBLIC build/3rdparty/imgui
)

target_link_libraries(${PROJECT_NAME}
    glad
    glfw3
    imgui
    glog
    ${gflags_LIBRARIES}
)

if (APPLE)
  target_link_libraries(${PROJECT_NAME} "-framework Cocoa -framework IOKit")
endif()

