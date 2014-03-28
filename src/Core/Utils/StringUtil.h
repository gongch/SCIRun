/*
 For more information, please see: http://software.sci.utah.edu

 The MIT License

 Copyright (c) 2013 Scientific Computing and Imaging Institute,
 University of Utah.


 Permission is hereby granted, free of charge, to any person obtaining a
 copy of this software and associated documentation files (the "Software"),
 to deal in the Software without restriction, including without limitation
 the rights to use, copy, modify, merge, publish, distribute, sublicense,
 and/or sell copies of the Software, and to permit persons to whom the
 Software is furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included
 in all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 DEALINGS IN THE SOFTWARE.
 */

/// @todo Documentation

#ifndef CORE_UTILS_STRINGUTIL_H
#define CORE_UTILS_STRINGUTIL_H 1

#include <sstream>
#include <Core/Utils/share.h>

namespace SCIRun 
{
namespace Core
{
    

template <typename T>
std::string to_string(const T& t)
{
  std::ostringstream o;
  o << t;
  return o.str();
}

template <typename T>
std::vector<T> parseLineOfNumbers(const std::string& line)
{
  std::istringstream stream(line);
  std::vector<T> numbers((std::istream_iterator<T>(stream)), (std::istream_iterator<T>()));
  
  return numbers;
}

}}

#endif
