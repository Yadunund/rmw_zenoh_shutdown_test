#include "rclcpp/rclcpp.hpp"

class DummyNode : public rclcpp::Node
{
public:
  explicit DummyNode(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("dummy_node", options)
  {
    // Do nothing.
  }
};
