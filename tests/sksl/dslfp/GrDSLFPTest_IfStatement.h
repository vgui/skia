

/**************************************************************************************************
 *** This file was autogenerated from GrDSLFPTest_IfStatement.fp; do not modify.
 **************************************************************************************************/
#ifndef GrDSLFPTest_IfStatement_DEFINED
#define GrDSLFPTest_IfStatement_DEFINED

#include "include/core/SkM44.h"
#include "include/core/SkTypes.h"


#include "src/gpu/GrFragmentProcessor.h"

class GrDSLFPTest_IfStatement : public GrFragmentProcessor {
public:
    static std::unique_ptr<GrFragmentProcessor> Make(float one) {
        return std::unique_ptr<GrFragmentProcessor>(new GrDSLFPTest_IfStatement(one));
    }
    GrDSLFPTest_IfStatement(const GrDSLFPTest_IfStatement& src);
    std::unique_ptr<GrFragmentProcessor> clone() const override;
    const char* name() const override { return "DSLFPTest_IfStatement"; }
    float one;
private:
    GrDSLFPTest_IfStatement(float one)
    : INHERITED(kGrDSLFPTest_IfStatement_ClassID, kNone_OptimizationFlags)
    , one(one) {
    }
    std::unique_ptr<GrGLSLFragmentProcessor> onMakeProgramImpl() const override;
    void onGetGLSLProcessorKey(const GrShaderCaps&, GrProcessorKeyBuilder*) const override;
    bool onIsEqual(const GrFragmentProcessor&) const override;
#if GR_TEST_UTILS
    SkString onDumpInfo() const override;
#endif
    GR_DECLARE_FRAGMENT_PROCESSOR_TEST
    using INHERITED = GrFragmentProcessor;
};
#endif
