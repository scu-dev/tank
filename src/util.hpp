#pragma once

#define CJK(ch) reinterpret_cast<const char*>(ch)

#define IS(obj, Type) dynamic_cast<Type*>(obj.get()) != nullptr