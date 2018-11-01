---
title: Struct char_traits&lt;char16_t&gt;
ms.date: 11/04/2016
f1_keywords:
- char_traits<char16_t>
- iosfwd/std::char_traits<char16_t>
helpviewer_keywords:
- char_traits<char16_t> class
ms.assetid: 5daf3b62-dd6e-451f-b189-0350a04ff966
ms.openlocfilehash: def0023b259a7b4816bdda29684c1dd9853d5f5b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50619096"
---
# <a name="chartraitsltchar16tgt-struct"></a>Struct char_traits&lt;char16_t&gt;

Uma struct é uma especialização da struct de modelo **char_traits\<CharType>** para um elemento do tipo `char16_t`.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
struct char_traits<char16_t>;
```

## <a name="remarks"></a>Comentários

A especialização permite que a struct aproveite funções de biblioteca que manipulam objetos do tipo `char16_t`.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<string>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[\<string>](../standard-library/string.md)<br/>
[Struct char_traits](../standard-library/char-traits-struct.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
