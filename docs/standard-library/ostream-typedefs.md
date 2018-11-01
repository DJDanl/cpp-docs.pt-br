---
title: Typedefs &lt;ostream&gt;
ms.date: 11/04/2016
f1_keywords:
- iosfwd/std::ostream
- iosfwd/std::wostream
ms.assetid: 2ec4dc52-a01f-4654-bd65-dd5288777c48
ms.openlocfilehash: 02936fdfc990ea65a99b2875cf7f482eb2ce4ebe
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50429738"
---
# <a name="ltostreamgt-typedefs"></a>Typedefs &lt;ostream&gt;

|||
|-|-|
|[ostream](#ostream)|[wostream](#wostream)|

## <a name="ostream"></a>  ostream

Cria um tipo de basic_ostream que é especializado em **char** e `char_traits` especializado em **char**.

```cpp
typedef basic_ostream<char, char_traits<char>> ostream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para a classe de modelo [basic_ostream](../standard-library/basic-ostream-class.md), especializado para elementos do tipo **char** com características de caractere padrão.

## <a name="wostream"></a>  wostream

Cria um tipo de basic_ostream que é especializado em **wchar_t** e `char_traits` especializado em **wchar_t**.

```cpp
typedef basic_ostream<wchar_t, char_traits<wchar_t>> wostream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para a classe de modelo [basic_ostream](../standard-library/basic-ostream-class.md), especializado para elementos do tipo **wchar_t** com características de caractere padrão.

## <a name="see-also"></a>Consulte também

[\<ostream>](../standard-library/ostream.md)<br/>
