find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)
target_include_directories(CALC_PROJECT PRIVATE ${GTK4_INCLUDE_DIRS})
target_link_libraries(CALC_PROJECT ${GTK4_LIBRARIES})