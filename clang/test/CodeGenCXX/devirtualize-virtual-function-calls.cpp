// RUN: clang-cc %s -emit-llvm -o - | FileCheck %s

struct A {
  virtual void f();
};

void f(A a, A *ap, A& ar) {
  // This should not be a virtual function call.
  
  // CHECK: call void @_ZN1A1fEv(%struct.A* %a)
  a.f();

  // CHECK: call void %  
  ap->f();

  // CHECK: call void %  
  ar.f();
}
