#pragma once

#ifndef UTILS_MISCCPP_COMPILETIMEHASH_HPP
#define UTILS_MISCCPP_COMPILETIMEHASH_HPP

// compile time hash
#include "al2o3_tinystl/string.hpp"
#include "al2o3_tinystl/string_view.hpp"

namespace Utils
{
	// FNV-1a 32bit hashing algorithm.
	constexpr uint32_t CompileTimeHash(char const* s, size_t count)
	{
		return ((count > 1 ? CompileTimeHash(s, count - 1) : 2166136261ull) ^ s[count-1]) * 16777619ull;
	}
	constexpr uint32_t CompileTimeHash(tinystl::string_view s)
	{
		return CompileTimeHash(s.data(), s.size());
	}

	inline uint32_t CompileTimeHash(tinystl::string s)
	{
		return CompileTimeHash(s.c_str(), s.size());
	}
}

constexpr uint32_t operator"" _hash(char const* s, size_t count)
{
	return Utils::CompileTimeHash(s, count);
}

#endif //UTILS_MISCCPP_COMPILETIMEHASH_HPP
