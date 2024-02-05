// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from cpp_pubsub:msg/CustomMsg.idl
// generated code does not contain a copyright notice
#include "cpp_pubsub/msg/detail/custom_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `child_frame_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `pose_modified`
#include "geometry_msgs/msg/detail/pose_with_covariance_stamped__functions.h"

bool
cpp_pubsub__msg__CustomMsg__init(cpp_pubsub__msg__CustomMsg * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    cpp_pubsub__msg__CustomMsg__fini(msg);
    return false;
  }
  // child_frame_id
  if (!rosidl_runtime_c__String__init(&msg->child_frame_id)) {
    cpp_pubsub__msg__CustomMsg__fini(msg);
    return false;
  }
  // custom_bool
  // custom_int
  // custom_double
  // pose_modified
  if (!geometry_msgs__msg__PoseWithCovarianceStamped__init(&msg->pose_modified)) {
    cpp_pubsub__msg__CustomMsg__fini(msg);
    return false;
  }
  return true;
}

void
cpp_pubsub__msg__CustomMsg__fini(cpp_pubsub__msg__CustomMsg * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // child_frame_id
  rosidl_runtime_c__String__fini(&msg->child_frame_id);
  // custom_bool
  // custom_int
  // custom_double
  // pose_modified
  geometry_msgs__msg__PoseWithCovarianceStamped__fini(&msg->pose_modified);
}

bool
cpp_pubsub__msg__CustomMsg__are_equal(const cpp_pubsub__msg__CustomMsg * lhs, const cpp_pubsub__msg__CustomMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // child_frame_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->child_frame_id), &(rhs->child_frame_id)))
  {
    return false;
  }
  // custom_bool
  if (lhs->custom_bool != rhs->custom_bool) {
    return false;
  }
  // custom_int
  if (lhs->custom_int != rhs->custom_int) {
    return false;
  }
  // custom_double
  if (lhs->custom_double != rhs->custom_double) {
    return false;
  }
  // pose_modified
  if (!geometry_msgs__msg__PoseWithCovarianceStamped__are_equal(
      &(lhs->pose_modified), &(rhs->pose_modified)))
  {
    return false;
  }
  return true;
}

bool
cpp_pubsub__msg__CustomMsg__copy(
  const cpp_pubsub__msg__CustomMsg * input,
  cpp_pubsub__msg__CustomMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // child_frame_id
  if (!rosidl_runtime_c__String__copy(
      &(input->child_frame_id), &(output->child_frame_id)))
  {
    return false;
  }
  // custom_bool
  output->custom_bool = input->custom_bool;
  // custom_int
  output->custom_int = input->custom_int;
  // custom_double
  output->custom_double = input->custom_double;
  // pose_modified
  if (!geometry_msgs__msg__PoseWithCovarianceStamped__copy(
      &(input->pose_modified), &(output->pose_modified)))
  {
    return false;
  }
  return true;
}

cpp_pubsub__msg__CustomMsg *
cpp_pubsub__msg__CustomMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_pubsub__msg__CustomMsg * msg = (cpp_pubsub__msg__CustomMsg *)allocator.allocate(sizeof(cpp_pubsub__msg__CustomMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(cpp_pubsub__msg__CustomMsg));
  bool success = cpp_pubsub__msg__CustomMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
cpp_pubsub__msg__CustomMsg__destroy(cpp_pubsub__msg__CustomMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    cpp_pubsub__msg__CustomMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
cpp_pubsub__msg__CustomMsg__Sequence__init(cpp_pubsub__msg__CustomMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_pubsub__msg__CustomMsg * data = NULL;

  if (size) {
    data = (cpp_pubsub__msg__CustomMsg *)allocator.zero_allocate(size, sizeof(cpp_pubsub__msg__CustomMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = cpp_pubsub__msg__CustomMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        cpp_pubsub__msg__CustomMsg__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
cpp_pubsub__msg__CustomMsg__Sequence__fini(cpp_pubsub__msg__CustomMsg__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      cpp_pubsub__msg__CustomMsg__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

cpp_pubsub__msg__CustomMsg__Sequence *
cpp_pubsub__msg__CustomMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  cpp_pubsub__msg__CustomMsg__Sequence * array = (cpp_pubsub__msg__CustomMsg__Sequence *)allocator.allocate(sizeof(cpp_pubsub__msg__CustomMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = cpp_pubsub__msg__CustomMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
cpp_pubsub__msg__CustomMsg__Sequence__destroy(cpp_pubsub__msg__CustomMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    cpp_pubsub__msg__CustomMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
cpp_pubsub__msg__CustomMsg__Sequence__are_equal(const cpp_pubsub__msg__CustomMsg__Sequence * lhs, const cpp_pubsub__msg__CustomMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!cpp_pubsub__msg__CustomMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
cpp_pubsub__msg__CustomMsg__Sequence__copy(
  const cpp_pubsub__msg__CustomMsg__Sequence * input,
  cpp_pubsub__msg__CustomMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(cpp_pubsub__msg__CustomMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    cpp_pubsub__msg__CustomMsg * data =
      (cpp_pubsub__msg__CustomMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!cpp_pubsub__msg__CustomMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          cpp_pubsub__msg__CustomMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!cpp_pubsub__msg__CustomMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
