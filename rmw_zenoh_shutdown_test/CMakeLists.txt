cmake_minimum_required(VERSION 3.8)
project(rmw_zenoh_shutdown_test)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include(GNUInstallDirs)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

# Add executable with rclcpp::shutdown()
add_executable(main_with_shutdown src/main_with_shutdown.cpp)
target_link_libraries(main_with_shutdown
  rclcpp::rclcpp
)
install(
  TARGETS main_with_shutdown
  DESTINATION lib/${PROJECT_NAME}
)

# Add executable without rclcpp::shutdown()
add_executable(main_without_shutdown src/main_without_shutdown.cpp)
target_link_libraries(main_without_shutdown
  rclcpp::rclcpp
)
install(
  TARGETS main_without_shutdown
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
