---
title: Struct char_traits&lt;wchar_t&gt;
ms.date: 11/04/2016
f1_keywords:
- char_traits<wchar_t>
- iosfwd/std::char_traits<wchar_t>
helpviewer_keywords:
- char_traits<wchar_t> class
ms.assetid: 31f34072-04d6-4871-88fe-48e17d473484
ms.openlocfilehash: ef40a34b5aa874c8bdf48aeb7657ae3496160eec
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62379214"
---
# <a name="chartraitsltwchartgt-struct"></a>Struct char_traits&lt;wchar_t&gt;

Uma classe que é uma especialização da struct de modelo **char_traits\<CharType >** a um elemento do tipo **wchar_t**.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
struct char_traits<wchar_t>;
```

## <a name="remarks"></a>Comentários

A especialização permite que a struct aproveite funções de biblioteca que manipulam objetos desse tipo de **wchar_t**.

## <a name="requirements"></a>Requisitos

**Cabeçalho:** \<string>

**Namespace:** std

## <a name="see-also"></a>Consulte também

[Struct char_traits](../standard-library/char-traits-struct.md)<br/>
[Acesso Thread-Safe na Biblioteca Padrão C++](../standard-library/thread-safety-in-the-cpp-standard-library.md)<br/>
