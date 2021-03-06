#include <metal_stdlib>
#include <simd/simd.h>
using namespace metal;
struct Uniforms {
    float4 testInputs;
    float4 colorGreen;
    float4 colorRed;
};
struct Inputs {
};
struct Outputs {
    float4 sk_FragColor [[color(0)]];
};

fragment Outputs fragmentMain(Inputs _in [[stage_in]], constant Uniforms& _uniforms [[buffer(0)]], bool _frontFacing [[front_facing]], float4 _fragCoord [[position]]) {
    Outputs _out;
    (void)_out;
    int4 expectedA = int4(-100, 0, 75, 100);
    int4 intValues = int4(_uniforms.testInputs * 100.0);
    int4 clampLow = int4(-100, -200, -200, 100);
    int4 expectedB = int4(-100, 0, 50, 225);
    int4 clampHigh = int4(100, 200, 50, 300);
    _out.sk_FragColor = ((((((clamp(intValues.x, -100, 100) == expectedA.x && all(clamp(intValues.xy, -100, 100) == expectedA.xy)) && all(clamp(intValues.xyz, -100, 100) == expectedA.xyz)) && all(clamp(intValues, -100, 100) == expectedA)) && clamp(intValues.x, clampLow.x, clampHigh.x) == expectedB.x) && all(clamp(intValues.xy, clampLow.xy, clampHigh.xy) == expectedB.xy)) && all(clamp(intValues.xyz, clampLow.xyz, clampHigh.xyz) == expectedB.xyz)) && all(clamp(intValues, clampLow, clampHigh) == expectedB) ? _uniforms.colorGreen : _uniforms.colorRed;
    return _out;
}
