// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <functional>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "cpp_pubsub/msg/custom_msg.hpp"

using std::placeholders::_1;

/*******************************************************************************
*/
class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber() : Node("minimal_subscriber")
  {
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "chatter", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));

    custom_subscription_ = this->create_subscription<cpp_pubsub::msg::CustomMsg>(
      "custom_chatter", 10, std::bind(&MinimalSubscriber::topic_custom_callback, this, _1));



    //--------------------------------------------------------------------------
    subscription_2_out_to_2_in = this->create_subscription<std_msgs::msg::String>(
      "topic_2_out_to_2_in", 10, std::bind(&MinimalSubscriber::topic_callback_2_out_to_2_in, this, _1));
    subscription_1_out_to_2_in = this->create_subscription<std_msgs::msg::String>(
      "topic_1_out_to_2_in", 10, std::bind(&MinimalSubscriber::topic_callback_1_out_to_2_in, this, _1));

    //--------------------------------------------------------------------------
    std::chrono::seconds d1(1);
    std::chrono::seconds d2(1);
    publisher_2_in_to_1_out_ = this->create_publisher<std_msgs::msg::String>("topic_2_in_to_1_out", 10);
    //timer_2_in_to_1_out_ = this->create_wall_timer(
      //d1, std::bind(&MinimalSubscriber::timer_callback_2_in_to_1_out, this));

    publisher_2_in_to_2_out_ = this->create_publisher<std_msgs::msg::String>("topic_2_in_to_2_out", 10);
    //timer_2_in_to_2_out_ = this->create_wall_timer(
      //d2, std::bind(&MinimalSubscriber::timer_callback_2_in_to_2_out, this));
  }

  private:
    //--------------------------------------------------------------------------
    // https://answers.ros.org/question/400785/problem-with-subscriber-ros2/
    void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;


    //--------------------------------------------------------------------------
    // https://answers.ros.org/question/400785/problem-with-subscriber-ros2/
    void topic_custom_callback(const cpp_pubsub::msg::CustomMsg::SharedPtr msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: '%d.%d', %s, %d, %d, %f, %f",
        msg->header.stamp.sec,
        msg->header.stamp.nanosec,
        msg->child_frame_id.c_str(),
        msg->custom_bool,
        msg->custom_int,
        msg->custom_double,
        msg->pose_modified.pose.pose.position.x
        );
    }
    rclcpp::Subscription<cpp_pubsub::msg::CustomMsg>::SharedPtr custom_subscription_;







    //--------------------------------------------------------------------------
    void topic_callback_2_out_to_2_in(const std_msgs::msg::String::SharedPtr msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_2_out_to_2_in;

    void topic_callback_1_out_to_2_in(const std_msgs::msg::String::SharedPtr msg) const
    {
      RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
    }
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_1_out_to_2_in;



    //--------------------------------------------------------------------------
    void timer_callback_2_in_to_1_out()
    {
      auto message = std_msgs::msg::String();
      message.data = "2_in_to_1_out";
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_2_in_to_1_out_->publish(message);
    }
    void timer_callback_2_in_to_2_out()
    {
      auto message = std_msgs::msg::String();
      message.data = "2_in_to_2_out";
      RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
      publisher_2_in_to_2_out_->publish(message);
    }


    //--------------------------------------------------------------------------
    rclcpp::TimerBase::SharedPtr timer_2_in_to_1_out_;
    rclcpp::TimerBase::SharedPtr timer_2_in_to_2_out_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_2_in_to_1_out_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_2_in_to_2_out_;
};


/*******************************************************************************
*/
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
