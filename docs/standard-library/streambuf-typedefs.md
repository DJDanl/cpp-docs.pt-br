---
title: Typedefs &lt;streambuf&gt;
ms.date: 11/04/2016
f1_keywords:
- iosfwd/std::streambuf
- iosfwd/std::wstreambuf
ms.assetid: 2678e18f-f0f0-4995-bc53-f1bc7dfc4ec6
ms.openlocfilehash: f08c08de0d6449714f953f5a65fadd2e0279ed44
ms.sourcegitcommit: ec6dd97ef3d10b44e0fedaa8e53f41696f49ac7b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/25/2020
ms.locfileid: "88843190"
---
# <a name="ltstreambufgt-typedefs"></a>Typedefs &lt;streambuf&gt;

[streambuf](#streambuf)\
[wstreambuf](#wstreambuf)

## <a name="streambuf"></a><a name="streambuf"></a> streambuf

Uma especialização `basic_streambuf` que **`char`** o usa como parâmetros de modelo.

```cpp
typedef basic_streambuf<char, char_traits<char>> streambuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_streambuf](../standard-library/basic-streambuf-class.md), especializado para elementos do tipo **`char`** com características de caractere padrão.

## <a name="wstreambuf"></a><a name="wstreambuf"></a> wstreambuf

Uma especialização `basic_streambuf` que **`wchar_t`** o usa como parâmetros de modelo.

```cpp
typedef basic_streambuf<wchar_t, char_traits<wchar_t>> wstreambuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_streambuf](../standard-library/basic-streambuf-class.md), especializado para elementos do tipo **`wchar_t`** com características de caractere padrão.

## <a name="see-also"></a>Confira também

[\<streambuf>](../standard-library/streambuf.md)
