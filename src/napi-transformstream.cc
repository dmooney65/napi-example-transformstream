#include <chrono>
#include <thread>
#include <iostream>
#include <math.h>

#include "napi-transformstream.h"

Napi::FunctionReference TransformStream::constructor;

Napi::Object TransformStream::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);
    Napi::Function transform = DefineClass(env, "TransformStream",
                                           {InstanceMethod("transform", &TransformStream::Transform)});

    constructor = Napi::Persistent(transform);
    constructor.SuppressDestruct();

    exports.Set("TransformStream", transform);
    return exports;
}


TransformStream::TransformStream(const Napi::CallbackInfo &info)
    : Napi::ObjectWrap<TransformStream>(info)
{

    Napi::Env env = info.Env();
    Napi::Object inProps = info[0].As<Napi::Object>();
    Napi::Array propNames = inProps.GetPropertyNames();
    int len = propNames.Length();

    Napi::Object props = info.This().As<Napi::Object>();
    for (int i = 0; i < len; i++)
    {
        napi_value e;
        napi_get_element(env, propNames, i, &e);
        std::string key = Napi::String(env, e).Utf8Value();
        uint32_t value = inProps.Get(key).As<Napi::Number>().Uint32Value();
        props.Set(Napi::String::New(env, key), value);
    }
}

Napi::Value TransformStream::Transform(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    void *inputBuffer;
    size_t lengthIn;
    napi_get_buffer_info(env, info[0].As<Napi::Buffer<char>>(), &inputBuffer, &lengthIn);

    Napi::Object props = info.This().As<Napi::Object>();

    uint option1 = props.Get("optionNum").As<Napi::Number>().Uint32Value();
    
    return Napi::Buffer<void>::New(env, inputBuffer, lengthIn);
}
