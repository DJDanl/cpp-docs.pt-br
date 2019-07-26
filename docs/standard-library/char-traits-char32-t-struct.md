---
title: Struct char_traits&lt;char32_t&gt;
ms.date: 11/04/2016
f1_keywords:
- iosfwd/std::char_traits<char_32t>
- char_traits<char32_t>
helpviewer_keywords:
- char_traits<char32_t> class
ms.assetid: c0315466-45d0-4a99-b83e-3b1dbfbfbbc3
ms.openlocfilehash: 9a5cf2eb7734a20d04ec5c47ae71e80180a7b29d
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68459047"
---
# <a name="chartraitsltchar32tgt-struct"></a>Struct char_traits&lt;char32_t&gt;

Uma struct é uma especialização da struct de modelo **char_traits\<CharType>** para um elemento do tipo `char32_t`.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
struct char_traits<char32_t>;
```

## <a name="remarks"></a>Comentários

A especialização permite que a struct aproveite funções de biblioteca que manipulam objetos desse tipo `char32_t`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<string>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<string>](../standard-library/string.md)\
[Struct char_traits](../standard-library/char-traits-struct.md)
