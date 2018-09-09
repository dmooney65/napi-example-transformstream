#include <napi.h>
#include "napi-transformstream.h"

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    TransformStream::Init(env, exports);
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, Init)