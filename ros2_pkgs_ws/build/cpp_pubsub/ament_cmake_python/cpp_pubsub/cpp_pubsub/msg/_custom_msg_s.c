// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from cpp_pubsub:msg/CustomMsg.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "cpp_pubsub/msg/detail/custom_msg__struct.h"
#include "cpp_pubsub/msg/detail/custom_msg__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose_with_covariance_stamped__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose_with_covariance_stamped__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool cpp_pubsub__msg__custom_msg__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[37];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("cpp_pubsub.msg._custom_msg.CustomMsg", full_classname_dest, 36) == 0);
  }
  cpp_pubsub__msg__CustomMsg * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // child_frame_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "child_frame_id");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->child_frame_id, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // custom_bool
    PyObject * field = PyObject_GetAttrString(_pymsg, "custom_bool");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->custom_bool = (Py_True == field);
    Py_DECREF(field);
  }
  {  // custom_int
    PyObject * field = PyObject_GetAttrString(_pymsg, "custom_int");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->custom_int = (int8_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // custom_double
    PyObject * field = PyObject_GetAttrString(_pymsg, "custom_double");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->custom_double = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // pose_modified
    PyObject * field = PyObject_GetAttrString(_pymsg, "pose_modified");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose_with_covariance_stamped__convert_from_py(field, &ros_message->pose_modified)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * cpp_pubsub__msg__custom_msg__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of CustomMsg */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("cpp_pubsub.msg._custom_msg");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "CustomMsg");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  cpp_pubsub__msg__CustomMsg * ros_message = (cpp_pubsub__msg__CustomMsg *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // child_frame_id
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->child_frame_id.data,
      strlen(ros_message->child_frame_id.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "child_frame_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // custom_bool
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->custom_bool ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "custom_bool", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // custom_int
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->custom_int);
    {
      int rc = PyObject_SetAttrString(_pymessage, "custom_int", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // custom_double
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->custom_double);
    {
      int rc = PyObject_SetAttrString(_pymessage, "custom_double", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pose_modified
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose_with_covariance_stamped__convert_to_py(&ros_message->pose_modified);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "pose_modified", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
