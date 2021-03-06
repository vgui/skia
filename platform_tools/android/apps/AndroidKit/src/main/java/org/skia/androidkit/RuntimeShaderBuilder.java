/*
 * Copyright 2021 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

package org.skia.androidkit;

import java.lang.String;
import org.skia.androidkit.Shader;

public class RuntimeShaderBuilder {
    private long mNativeInstance;

    public RuntimeShaderBuilder(String sksl) {
        mNativeInstance = nCreate(sksl);
    }

    public RuntimeShaderBuilder setUniform(String name, float val) {
        nSetUniform(mNativeInstance, name, val);
        return this;
    }

    public Shader makeShader() {
        return new Shader(nMakeShader(mNativeInstance));
    }

    /**
     * Releases any resources associated with this RuntimeShaderBuilder.
     */
    public void release() {
        nRelease(mNativeInstance);
        mNativeInstance = 0;
    }

    @Override
    protected void finalize() throws Throwable {
        release();
    }

    private static native long nCreate(String sksl);
    private static native void nRelease(long nativeInstance);

    private static native void nSetUniform(long nativeInstance, String name, float val);
    private static native long nMakeShader(long nativeInstance);
}
