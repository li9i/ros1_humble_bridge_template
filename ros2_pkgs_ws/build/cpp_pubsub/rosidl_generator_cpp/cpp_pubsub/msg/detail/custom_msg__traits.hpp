// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from cpp_pubsub:msg/CustomMsg.idl
// generated code does not contain a copyright notice

#ifndef CPP_PUBSUB__MSG__DETAIL__CUSTOM_MSG__TRAITS_HPP_
#define CPP_PUBSUB__MSG__DETAIL__CUSTOM_MSG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "cpp_pubsub/msg/detail/custom_msg__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'pose_modified'
#include "geometry_msgs/msg/detail/pose_with_covariance_stamped__traits.hpp"

namespace cpp_pubsub
{

namespace msg
{

inline void to_flow_style_yaml(
  const CustomMsg & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: child_frame_id
  {
    out << "child_frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.child_frame_id, out);
    out << ", ";
  }

  // member: custom_bool
  {
    out << "custom_bool: ";
    rosidl_generator_traits::value_to_yaml(msg.custom_bool, out);
    out << ", ";
  }

  // member: custom_int
  {
    out << "custom_int: ";
    rosidl_generator_traits::value_to_yaml(msg.custom_int, out);
    out << ", ";
  }

  // member: custom_double
  {
    out << "custom_double: ";
    rosidl_generator_traits::value_to_yaml(msg.custom_double, out);
    out << ", ";
  }

  // member: pose_modified
  {
    out << "pose_modified: ";
    to_flow_style_yaml(msg.pose_modified, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const CustomMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: child_frame_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "child_frame_id: ";
    rosidl_generator_traits::value_to_yaml(msg.child_frame_id, out);
    out << "\n";
  }

  // member: custom_bool
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "custom_bool: ";
    rosidl_generator_traits::value_to_yaml(msg.custom_bool, out);
    out << "\n";
  }

  // member: custom_int
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "custom_int: ";
    rosidl_generator_traits::value_to_yaml(msg.custom_int, out);
    out << "\n";
  }

  // member: custom_double
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "custom_double: ";
    rosidl_generator_traits::value_to_yaml(msg.custom_double, out);
    out << "\n";
  }

  // member: pose_modified
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pose_modified:\n";
    to_block_style_yaml(msg.pose_modified, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const CustomMsg & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace cpp_pubsub

namespace rosidl_generator_traits
{

[[deprecated("use cpp_pubsub::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const cpp_pubsub::msg::CustomMsg & msg,
  std::ostream & out, size_t indentation = 0)
{
  cpp_pubsub::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use cpp_pubsub::msg::to_yaml() instead")]]
inline std::string to_yaml(const cpp_pubsub::msg::CustomMsg & msg)
{
  return cpp_pubsub::msg::to_yaml(msg);
}

template<>
inline const char * data_type<cpp_pubsub::msg::CustomMsg>()
{
  return "cpp_pubsub::msg::CustomMsg";
}

template<>
inline const char * name<cpp_pubsub::msg::CustomMsg>()
{
  return "cpp_pubsub/msg/CustomMsg";
}

template<>
struct has_fixed_size<cpp_pubsub::msg::CustomMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<cpp_pubsub::msg::CustomMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<cpp_pubsub::msg::CustomMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // CPP_PUBSUB__MSG__DETAIL__CUSTOM_MSG__TRAITS_HPP_
