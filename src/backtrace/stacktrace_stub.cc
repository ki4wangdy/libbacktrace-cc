// Copyright (C) 2016 libbacktrace-cc authors
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//
// Author: sergey@blender.org (Sergey Sharybin)

#include "backtrace/stacktrace.h"

namespace bt {
namespace internal {

namespace {

// Stub stack trace implementation.
class StackTraceStub : public StackTrace {
 public:
  StackTraceStub() : StackTrace() {}

  size_t load(void * /*addr*/, size_t /*depth*/) {
    return 0;
  }

  size_t size() const {
    return 0;
  }

  TraceEntry operator[](size_t /*index*/) const {
    TraceEntry entry;
    return entry;
  }
};

}  // namespace

StackTrace *stacktrace_create_stub() {
  return new StackTraceStub();
}

}  // namespace internal
}  // namespace bt
