//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_TOSTRING_H
#define INC_2DGAMEFRAMEWORK_TOSTRING_H

// Since std::to_string doesn't work on MinGW we have to implement
// our own to support all platforms.
template<typename T>
std::string toString(const T &value) {
  std::stringstream stream;
  stream << value;
  return stream.str();
}

#endif //INC_2DGAMEFRAMEWORK_TOSTRING_H
