---
title: Struct char_traits&lt;wchar_t&gt;
ms.date: 11/04/2016
f1_keywords:
- char_traits<wchar_t>
- iosfwd/std::char_traits<wchar_t>
helpviewer_keywords:
- char_traits<wchar_t> class
ms.assetid: 31f34072-04d6-4871-88fe-48e17d473484
ms.openlocfilehash: 3b2504dbb124ccca7f9b27619585abb2b5795f92
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87219164"
---
# <a name="char_traitsltwchar_tgt-struct"></a>Struct char_traits&lt;wchar_t&gt;

Uma classe que é uma especialização da estrutura do **modelo \<CharType> char_traits** a um elemento do tipo **`wchar_t`** .

## <a name="syntax"></a>Sintaxe

```cpp
template <>
struct char_traits<wchar_t>;
```

## <a name="remarks"></a>Comentários

A especialização permite que a estrutura Aproveite as funções de biblioteca que manipulam objetos desse tipo **`wchar_t`** .

## <a name="requirements"></a>Requisitos

**Cabeçalho:**\<string>

**Namespace:** std

## <a name="see-also"></a>Confira também

[char_traits struct](../standard-library/char-traits-struct.md)\
[Segurança de thread na biblioteca padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
