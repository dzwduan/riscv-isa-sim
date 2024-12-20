ZVMM_INIT(4);

switch (P.VU.vsew) {
  case 8: {
    ZVMM_SIMPLE_LOOP(uint8_t, uint32_t);
    break;
  }
  default: {
    require(false);
    break;
  }
}
