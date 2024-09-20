#include "dummy_node.hpp"

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto dumy_node = std::make_shared<DummyNode>();

  // Call rclcpp::shutdown() so that rmw_shutdown() is invoked before rclcpp::~Context().
  rclcpp::shutdown();

  return 0;
}
