/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkString.h"
#include "include/effects/SkLumaColorFilter.h"
#include "include/effects/SkRuntimeEffect.h"
#include "src/core/SkRuntimeEffectPriv.h"

sk_sp<SkColorFilter> SkLumaColorFilter::Make() {
    const char* code =
        "half4 main(half4 inColor) {"
            "return saturate(dot(half3(0.2126, 0.7152, 0.0722), inColor.rgb)).000r;"
        "}";
    sk_sp<SkRuntimeEffect> effect = SkMakeCachedRuntimeEffect(code);
    SkASSERT(effect);

    return effect->makeColorFilter(SkData::MakeEmpty());
}
