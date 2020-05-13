---
title: Typedefs &lt;ostream&gt;
ms.date: 11/04/2016
f1_keywords:
- iosfwd/std::ostream
- iosfwd/std::wostream
ms.assetid: 2ec4dc52-a01f-4654-bd65-dd5288777c48
ms.openlocfilehash: 82539a3fdadf10d340ca957756e235e8ae00b267
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81373577"
---
# <a name="ltostreamgt-typedefs"></a>Typedefs &lt;ostream&gt;

|||
|-|-|
|[ostream](#ostream)|[wostream](#wostream)|

## <a name="ostream"></a><a name="ostream"></a>ostream

Cria um tipo de basic_ostream **char** especializada `char_traits` em char e especializada em **char**.

```cpp
typedef basic_ostream<char, char_traits<char>> ostream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para modelo de classe [basic_ostream,](../standard-library/basic-ostream-class.md)especializado para elementos de **tipo char** com traços de caractere padrão.

## <a name="wostream"></a><a name="wostream"></a>wostream

Cria um tipo a partir **wchar_t** de `char_traits` basic_ostream especializada em wchar_t e especializada em **wchar_t.**

```cpp
typedef basic_ostream<wchar_t, char_traits<wchar_t>> wostream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo de modelo de classe [basic_ostream,](../standard-library/basic-ostream-class.md)especializado para elementos de tipo **wchar_t** com traços de caractere padrão.

## <a name="see-also"></a>Confira também

[\<ostream>](../standard-library/ostream.md)
