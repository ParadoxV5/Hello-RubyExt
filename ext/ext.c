#include <ruby.h>

static const char MyExt_greeting[] = "Hello from Ruby Extension!\n";

static VALUE MyExt_rb_hello(__attribute__((unused)) VALUE klass) {
  fputs(MyExt_greeting, stderr);
  return rb_str_new_cstr(MyExt_greeting);
}

void Init_ext(void) {
  rb_define_global_function("hello", MyExt_rb_hello, 0);
}
