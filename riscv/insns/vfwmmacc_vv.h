ZVMM_INIT(2);
require_fp;

switch (P.VU.vsew) {
  case 16: {
    auto macc = [](auto a, auto b, auto c) { return f32_add(c, f32_mul(bf16_to_f32(a), bf16_to_f32(b))); };
    ZVMM_GENERIC_LOOP(bfloat16_t, float32_t, macc);
    break;
  }
  case 32: {
    auto macc = [](auto a, auto b, auto c) { return f64_add(c, f64_mul(f32_to_f64(a), f32_to_f64(b))); };
    ZVMM_GENERIC_LOOP(float32_t, float64_t, macc);
    break;
  }
  default: {
    require(false);
    break;
  }
}
