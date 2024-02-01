// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from cpp_pubsub:msg/CustomMsg.idl
// generated code does not contain a copyright notice

#ifndef CPP_PUBSUB__MSG__DETAIL__CUSTOM_MSG__STRUCT_HPP_
#define CPP_PUBSUB__MSG__DETAIL__CUSTOM_MSG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'pose_modified'
#include "geometry_msgs/msg/detail/pose_with_covariance_stamped__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__cpp_pubsub__msg__CustomMsg __attribute__((deprecated))
#else
# define DEPRECATED__cpp_pubsub__msg__CustomMsg __declspec(deprecated)
#endif

namespace cpp_pubsub
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct CustomMsg_
{
  using Type = CustomMsg_<ContainerAllocator>;

  explicit CustomMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    pose_modified(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->child_frame_id = "";
      this->custom_bool = false;
      this->custom_int = 0;
      this->custom_double = 0.0;
    }
  }

  explicit CustomMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    child_frame_id(_alloc),
    pose_modified(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->child_frame_id = "";
      this->custom_bool = false;
      this->custom_int = 0;
      this->custom_double = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _child_frame_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _child_frame_id_type child_frame_id;
  using _custom_bool_type =
    bool;
  _custom_bool_type custom_bool;
  using _custom_int_type =
    int8_t;
  _custom_int_type custom_int;
  using _custom_double_type =
    double;
  _custom_double_type custom_double;
  using _pose_modified_type =
    geometry_msgs::msg::PoseWithCovarianceStamped_<ContainerAllocator>;
  _pose_modified_type pose_modified;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__child_frame_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->child_frame_id = _arg;
    return *this;
  }
  Type & set__custom_bool(
    const bool & _arg)
  {
    this->custom_bool = _arg;
    return *this;
  }
  Type & set__custom_int(
    const int8_t & _arg)
  {
    this->custom_int = _arg;
    return *this;
  }
  Type & set__custom_double(
    const double & _arg)
  {
    this->custom_double = _arg;
    return *this;
  }
  Type & set__pose_modified(
    const geometry_msgs::msg::PoseWithCovarianceStamped_<ContainerAllocator> & _arg)
  {
    this->pose_modified = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    cpp_pubsub::msg::CustomMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const cpp_pubsub::msg::CustomMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<cpp_pubsub::msg::CustomMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<cpp_pubsub::msg::CustomMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      cpp_pubsub::msg::CustomMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<cpp_pubsub::msg::CustomMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      cpp_pubsub::msg::CustomMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<cpp_pubsub::msg::CustomMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<cpp_pubsub::msg::CustomMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<cpp_pubsub::msg::CustomMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__cpp_pubsub__msg__CustomMsg
    std::shared_ptr<cpp_pubsub::msg::CustomMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__cpp_pubsub__msg__CustomMsg
    std::shared_ptr<cpp_pubsub::msg::CustomMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CustomMsg_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->child_frame_id != other.child_frame_id) {
      return false;
    }
    if (this->custom_bool != other.custom_bool) {
      return false;
    }
    if (this->custom_int != other.custom_int) {
      return false;
    }
    if (this->custom_double != other.custom_double) {
      return false;
    }
    if (this->pose_modified != other.pose_modified) {
      return false;
    }
    return true;
  }
  bool operator!=(const CustomMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CustomMsg_

// alias to use template instance with default allocator
using CustomMsg =
  cpp_pubsub::msg::CustomMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace cpp_pubsub

#endif  // CPP_PUBSUB__MSG__DETAIL__CUSTOM_MSG__STRUCT_HPP_
