#include "py/dynruntime.h"

mp_obj_t test(mp_obj_t fun){
  /*mp_obj_t uargs[]= {
    mp_obj_new_bytes((const unsigned char *) "abc", 3)
  };
  return mp_call_function_n_kw(fun, 1, 0, uargs);*/
  return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(test_obj, test);

mp_obj_t mpy_init(mp_obj_fun_bc_t *self, size_t n_args, size_t n_kw, mp_obj_t *args) {
  MP_DYNRUNTIME_INIT_ENTRY

  mp_printf(&mp_plat_print, "initialising module\n");

  mp_store_global(MP_QSTR_test, MP_OBJ_FROM_PTR(&test_obj));

  MP_DYNRUNTIME_INIT_EXIT
}
