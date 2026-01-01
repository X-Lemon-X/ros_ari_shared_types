/*
Copyright (c) 2025 Patryk Dudziński

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/*
 * Authors: Patryk Dudziński
 */

#pragma once
#include "status.hpp"



/**
 * @file status_hardware.hpp
 * @brief  Status class macros for hardware interface.
 */

namespace ari {

class Status;

#define ARI_HW_RETURN_ON_ERROR(x)                     \
  do {                                                  \
    Status _x = x;                                      \
    if(!_x.ok()) {                                      \
      return hardware_interface::CallbackReturn::ERROR; \
    }                                                   \
  } while(false)

#define ARI_HW_RETURN_ON_ERROR_MSG(x, name, msg)        \
  do {                                                    \
    Status _x = x;                                        \
    if(!_x.ok()) {                                        \
      RCLCPP_ERROR_STREAM(rclcpp::get_logger(name), msg); \
      return hardware_interface::CallbackReturn::ERROR;   \
    }                                                     \
  } while(false)

#define ARI_HW_RETURN_ON_ERROR_NAM(x, name)                        \
  do {                                                               \
    Status _x = x;                                                   \
    if(!_x.ok()) {                                                   \
      RCLCPP_ERROR_STREAM(rclcpp::get_logger(name), _x.to_string()); \
      return hardware_interface::CallbackReturn::ERROR;              \
    }                                                                \
  } while(false)

#define ARI_HW_ASSING_OR_RETURN(assign, result)       \
  auto _xsar##assign = result;                          \
  do {                                                  \
    if(!_xsar##assign.ok()) {                           \
      return hardware_interface::CallbackReturn::ERROR; \
    }                                                   \
  } while(false);                                       \
  auto assign = std::move(_xsar##assign.valueOrDie());


#define ARI_HW_ASSING_TO_OR_RETURN(assign, result)    \
  do {                                                  \
    auto _xsar##assign = result;                        \
    if(!_xsar##assign.ok())                             \
      return hardware_interface::CallbackReturn::ERROR; \
    assign = std::move(_xsar##assign.valueOrDie());     \
  } while(false);


#define ARI_HW_ASSIGN_OR_RETURN_MSG(assign, result, name, msg) \
  do {                                                           \
    auto _xsar##assign = result;                                 \
    if(!_xsar##assign.ok()) {                                    \
      RCLCPP_ERROR_STREAM(rclcpp::get_logger(name), msg);        \
      return hardware_interface::CallbackReturn::ERROR;          \
    }                                                            \
    assign = std::move(_xsar##assign.valueOrDie());              \
  } while(false);

#define ARI_HW_ASSIGN_OR_RETURN_NAM(assign, result, name)                     \
  do {                                                                          \
    auto _xsar##assign = result;                                                \
    if(!_xsar##assign.ok()) {                                                   \
      RCLCPP_ERROR_STREAM(rclcpp::get_logger(name), _xsar##assign.to_string()); \
      return hardware_interface::CallbackReturn::ERROR;                         \
    }                                                                           \
    assign = std::move(_xsar##assign.valueOrDie());                             \
  } while(false);

#define ARI_HW_ASSIGN_TO_OR_RETURN_MSG(assign, result, name, msg) \
  do {                                                              \
    auto _xsar##assign = result;                                    \
    if(!_xsar##assign.ok()) {                                       \
      RCLCPP_ERROR_STREAM(rclcpp::get_logger(name), msg);           \
      return hardware_interface::CallbackReturn::ERROR;             \
    }                                                               \
    assign = std::move(_xsar##assign.valueOrDie());                 \
  } while(false);

#define ARI_HW_ASSIGN_TO_OR_RETURN_NAM(assign, result, name)                  \
  do {                                                                          \
    auto _xsar##assign = result;                                                \
    if(!_xsar##assign.ok()) {                                                   \
      RCLCPP_ERROR_STREAM(rclcpp::get_logger(name), _xsar##assign.to_string()); \
      return hardware_interface::CallbackReturn::ERROR;                         \
    }                                                                           \
    assign = std::move(_xsar##assign.valueOrDie());                             \
  } while(false);

}  // namespace ari