#include <napi.h>

class TransformStream : public Napi::ObjectWrap<TransformStream> {
    public:
        static Napi::Object Init(Napi::Env env, Napi::Object exports);
        static void Destructor(Napi::Env env, void* nativeObject, void* finalize_hint);
        TransformStream(const Napi::CallbackInfo& info);

    private:
        static Napi::FunctionReference constructor;
        Napi::Value Transform(const Napi::CallbackInfo& info);
};
