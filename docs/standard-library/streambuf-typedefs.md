---
title: Typedefs &lt;streambuf&gt;
ms.date: 11/04/2016
f1_keywords:
- iosfwd/std::streambuf
- iosfwd/std::wstreambuf
ms.assetid: 2678e18f-f0f0-4995-bc53-f1bc7dfc4ec6
ms.openlocfilehash: 3c5dbefba8e2106c6e3e678002bce26fffd26a62
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87215615"
---
# <a name="ltstreambufgt-typedefs"></a>Typedefs &lt;streambuf&gt;

|||
|-|-|
|[streambuf](#streambuf)|[wstreambuf](#wstreambuf)|

## <a name="streambuf"></a><a name="streambuf"></a>streambuf

Uma especialização `basic_streambuf` que **`char`** o usa como parâmetros de modelo.

```cpp
typedef basic_streambuf<char, char_traits<char>> streambuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_streambuf](../standard-library/basic-streambuf-class.md), especializado para elementos do tipo **`char`** com características de caractere padrão.

## <a name="wstreambuf"></a><a name="wstreambuf"></a>wstreambuf

Uma especialização `basic_streambuf` que **`wchar_t`** o usa como parâmetros de modelo.

```cpp
typedef basic_streambuf<wchar_t, char_traits<wchar_t>> wstreambuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_streambuf](../standard-library/basic-streambuf-class.md), especializado para elementos do tipo **`wchar_t`** com características de caractere padrão.

## <a name="see-also"></a>Confira também

[\<streambuf>](../standard-library/streambuf.md)
