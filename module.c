static Janet cfun(int32_t argc, Janet *argv) {
          janet_fixarity(argc, 1);

          const Janet *argv2 = janet_tuple_n(argv, argc);
  
      
          JanetKV *dolt_item = janet_struct_begin(6);
      
          janet_struct_put(dolt_item, janet_ckeywordv(""),
                         janet_wrap_number((double) view->size));
          janet_struct_put(dolt_item, janet_ckeywordv(""),
                         janet_wrap_pointer();
          janet_struct_put(dolt_item, janet_ckeywordv(""),
                         janet_wrap_pointer();
        

          return janet_wrap_struct(janet_struct_end(dolt_item));

}
