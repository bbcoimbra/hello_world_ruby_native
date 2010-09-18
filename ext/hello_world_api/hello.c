#include "ruby.h"

VALUE greeting(VALUE self, VALUE str){
  char str_hello[] = "Hello ";
	char *str_ptr;
	str_ptr =  STR2CSTR(str);
	return rb_str_new2(strcat(str_hello, str_ptr));
}

VALUE hello_world(VALUE self){
	return rb_str_new2("Hello World!\n");
}

VALUE cHello;
void Init_hello_world_api(){
	cHello = rb_define_class("HelloWorld", rb_cObject);
	rb_define_method(cHello, "greeting", greeting, 1);
	rb_define_method(cHello, "hello_world", hello_world, 0);
}