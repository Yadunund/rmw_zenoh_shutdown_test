#include "dummy_node.hpp"

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  auto dumy_node = std::make_shared<DummyNode>();

  // Do not call rclcpp::shutdown() so that rmw_shutdown() is invoked in rclcpp::~Context().
  return 0;
}
