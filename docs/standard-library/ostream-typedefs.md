---
title: Typedefs &lt;ostream&gt;
ms.date: 11/04/2016
f1_keywords:
- iosfwd/std::ostream
- iosfwd/std::wostream
ms.assetid: 2ec4dc52-a01f-4654-bd65-dd5288777c48
ms.openlocfilehash: ff9f19f56c8d8fdb9e469e6361a5419468fe7e67
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88846401"
---
# <a name="ltostreamgt-typedefs"></a>Typedefs &lt;ostream&gt;

[ostream](#ostream)\
[wostream](#wostream)

## <a name="ostream"></a><a name="ostream"></a> ostream

Cria um tipo de basic_ostream que é especializado em **`char`** e `char_traits` especializado em **`char`** .

```cpp
typedef basic_ostream<char, char_traits<char>> ostream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_ostream](../standard-library/basic-ostream-class.md), especializado para elementos do tipo **`char`** com características de caractere padrão.

## <a name="wostream"></a><a name="wostream"></a> wostream

Cria um tipo de basic_ostream que é especializado em **`wchar_t`** e `char_traits` especializado em **`wchar_t`** .

```cpp
typedef basic_ostream<wchar_t, char_traits<wchar_t>> wostream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_ostream](../standard-library/basic-ostream-class.md), especializado para elementos do tipo **`wchar_t`** com características de caractere padrão.

## <a name="see-also"></a>Confira também

[\<ostream>](../standard-library/ostream.md)
