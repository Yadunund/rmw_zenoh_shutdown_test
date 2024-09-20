# rmw_zenoh_shutdown_test
Package to illustrate issue with closing Zenoh session in the Context's destructor.

For context see: https://github.com/ros2/rmw_zenoh/issues/170

As explained in [this comment](https://github.com/ros2/rmw_zenoh/issues/170#issuecomment-2362533300),
the hypothesis is that the tokio runtime in Zenoh panics when the Zenoh session is closed within
`rclcpp::Context`'s destructor that is triggered when the program terminates.
Perhaps given the order of static initialization, the `Thread Local Storage` is cleared before
the destructor runs.

To illustrate this behavior, this repo has two excutables, `main_with_shutdown` and `main_without_shutdown`,
where each creates an instance of a ROS node that does nothing before exiting.
The only difference is that `main_with_shutdown`, calls `rclcpp::shutdown()` before exiting.
The `main_without_shutdown` executable will always panic.

To test:

Start the Zenoh router.

```bash
ros2 run rmw_zenoh_cpp rmw_zenohd
```

Run `main_with_shutdown`,

```bash
export RMW_IMPLEMENTATION=rmw_zenoh_cpp
ros2 run rmw_zenoh_shutdown_test main_with_shutdown
```

Run `main_without_shutdown`,

```bash
export RMW_IMPLEMENTATION=rmw_zenoh_cpp
ros2 run rmw_zenoh_shutdown_test main_without_shutdown
```
