#ifndef STLEMITTER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
#define STLEMITTER_H_62B23520_7C8E_11DE_8A39_0800200C9A66

#if defined(_MSC_VER) ||                                            \
    (defined(__GNUC__) && (__GNUC__ == 3 && __GNUC_MINOR__ >= 4) || \
     (__GNUC__ >= 4))  // GCC supports "pragma once" correctly since 3.4
#pragma once
#endif

#include <list>
#include <map>
#include <set>
#include <vector>

namespace YAML {
template <typename Seq>
inline Emitter& EmitSeq(Emitter& emitter, const Seq& seq) {
  emitter << BeginSeq;
  for (const auto& v : seq)
    emitter << v;
  emitter << EndSeq;
  return emitter;
}

template <typename T, typename Alloc>
inline Emitter& operator<<(Emitter& emitter, const std::vector<T, Alloc>& v) {
  return EmitSeq(emitter, v);
}

template <typename T, typename Alloc>
inline Emitter& operator<<(Emitter& emitter, const std::list<T, Alloc>& v) {
  return EmitSeq(emitter, v);
}

template <typename T, typename Alloc>
inline Emitter& operator<<(Emitter& emitter,
                           const std::set<T, std::less<T>, Alloc>& v) {
  return EmitSeq(emitter, v);
}

template <typename K, typename V, typename Alloc>
inline Emitter& operator<<(Emitter& emitter,
                           const std::map<K, V, std::less<K>, Alloc>& m) {
  emitter << BeginMap;
  for (const auto& v : m)
    emitter << Key << v.first << Value << v.second;
  emitter << EndMap;
  return emitter;
}
}  // namespace YAML

#endif  // STLEMITTER_H_62B23520_7C8E_11DE_8A39_0800200C9A66
