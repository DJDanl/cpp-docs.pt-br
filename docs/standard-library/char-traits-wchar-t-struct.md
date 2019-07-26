---
title: Struct char_traits&lt;wchar_t&gt;
ms.date: 11/04/2016
f1_keywords:
- char_traits<wchar_t>
- iosfwd/std::char_traits<wchar_t>
helpviewer_keywords:
- char_traits<wchar_t> class
ms.assetid: 31f34072-04d6-4871-88fe-48e17d473484
ms.openlocfilehash: a2f8a882020ddb3d87436d08b3d85ea9407b1c08
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68458973"
---
# <a name="chartraitsltwchartgt-struct"></a>Struct char_traits&lt;wchar_t&gt;

Uma classe que é uma especialização do modelo struct **char_traits\<CharType >** a um elemento do tipo **wchar_t**.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
struct char_traits<wchar_t>;
```

## <a name="remarks"></a>Comentários

A especialização permite que a estrutura Aproveite as funções de biblioteca que manipulam objetos desse tipo **wchar_t**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<string>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Struct char_traits](../standard-library/char-traits-struct.md)\
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)
