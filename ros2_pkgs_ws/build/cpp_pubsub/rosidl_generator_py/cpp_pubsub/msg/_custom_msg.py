# generated from rosidl_generator_py/resource/_idl.py.em
# with input from cpp_pubsub:msg/CustomMsg.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_CustomMsg(type):
    """Metaclass of message 'CustomMsg'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('cpp_pubsub')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'cpp_pubsub.msg.CustomMsg')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__custom_msg
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__custom_msg
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__custom_msg
            cls._TYPE_SUPPORT = module.type_support_msg__msg__custom_msg
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__custom_msg

            from geometry_msgs.msg import PoseWithCovarianceStamped
            if PoseWithCovarianceStamped.__class__._TYPE_SUPPORT is None:
                PoseWithCovarianceStamped.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class CustomMsg(metaclass=Metaclass_CustomMsg):
    """Message class 'CustomMsg'."""

    __slots__ = [
        '_header',
        '_child_frame_id',
        '_custom_bool',
        '_custom_int',
        '_custom_double',
        '_pose_modified',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'child_frame_id': 'string',
        'custom_bool': 'boolean',
        'custom_int': 'int8',
        'custom_double': 'double',
        'pose_modified': 'geometry_msgs/PoseWithCovarianceStamped',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'PoseWithCovarianceStamped'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.child_frame_id = kwargs.get('child_frame_id', str())
        self.custom_bool = kwargs.get('custom_bool', bool())
        self.custom_int = kwargs.get('custom_int', int())
        self.custom_double = kwargs.get('custom_double', float())
        from geometry_msgs.msg import PoseWithCovarianceStamped
        self.pose_modified = kwargs.get('pose_modified', PoseWithCovarianceStamped())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.child_frame_id != other.child_frame_id:
            return False
        if self.custom_bool != other.custom_bool:
            return False
        if self.custom_int != other.custom_int:
            return False
        if self.custom_double != other.custom_double:
            return False
        if self.pose_modified != other.pose_modified:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def child_frame_id(self):
        """Message field 'child_frame_id'."""
        return self._child_frame_id

    @child_frame_id.setter
    def child_frame_id(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'child_frame_id' field must be of type 'str'"
        self._child_frame_id = value

    @builtins.property
    def custom_bool(self):
        """Message field 'custom_bool'."""
        return self._custom_bool

    @custom_bool.setter
    def custom_bool(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'custom_bool' field must be of type 'bool'"
        self._custom_bool = value

    @builtins.property
    def custom_int(self):
        """Message field 'custom_int'."""
        return self._custom_int

    @custom_int.setter
    def custom_int(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'custom_int' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'custom_int' field must be an integer in [-128, 127]"
        self._custom_int = value

    @builtins.property
    def custom_double(self):
        """Message field 'custom_double'."""
        return self._custom_double

    @custom_double.setter
    def custom_double(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'custom_double' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'custom_double' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._custom_double = value

    @builtins.property
    def pose_modified(self):
        """Message field 'pose_modified'."""
        return self._pose_modified

    @pose_modified.setter
    def pose_modified(self, value):
        if __debug__:
            from geometry_msgs.msg import PoseWithCovarianceStamped
            assert \
                isinstance(value, PoseWithCovarianceStamped), \
                "The 'pose_modified' field must be a sub message of type 'PoseWithCovarianceStamped'"
        self._pose_modified = value
