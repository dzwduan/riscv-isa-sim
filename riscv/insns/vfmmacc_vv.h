ZVMM_INIT(1);
require_fp;

switch (P.VU.vsew) {
  case 32: {
    auto macc = [](auto a, auto b, auto c) { return f32_add(c, f32_mul(a, b)); };
    ZVMM_GENERIC_LOOP(float32_t, float32_t, macc);
    break;
  }
  case 64: {
    auto macc = [](auto a, auto b, auto c) { return f64_add(c, f64_mul(a, b)); };
    ZVMM_GENERIC_LOOP(float64_t, float64_t, macc);
    break;
  }
  default: {
    require(false);
    break;
  }
}
