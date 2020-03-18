---
title: Typedefs &lt;streambuf&gt;
ms.date: 11/04/2016
f1_keywords:
- iosfwd/std::streambuf
- iosfwd/std::wstreambuf
ms.assetid: 2678e18f-f0f0-4995-bc53-f1bc7dfc4ec6
ms.openlocfilehash: 1c9850ad7d7ec9b9c3554e6806f4790ef3613b08
ms.sourcegitcommit: 7ecd91d8ce18088a956917cdaf3a3565bd128510
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/16/2020
ms.locfileid: "79419423"
---
# <a name="ltstreambufgt-typedefs"></a>Typedefs &lt;streambuf&gt;

|||
|-|-|
|[streambuf](#streambuf)|[wstreambuf](#wstreambuf)|

## <a name="streambuf"></a>  streambuf

Uma especialização de `basic_streambuf` que usa **Char** como parâmetros de modelo.

```cpp
typedef basic_streambuf<char, char_traits<char>> streambuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_streambuf](../standard-library/basic-streambuf-class.md), especializado para elementos do tipo **Char** com características de caractere padrão.

## <a name="wstreambuf"></a>  wstreambuf

Uma especialização de `basic_streambuf` que usa **wchar_t** como parâmetros de modelo.

```cpp
typedef basic_streambuf<wchar_t, char_traits<wchar_t>> wstreambuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_streambuf](../standard-library/basic-streambuf-class.md), especializado para elementos do tipo **wchar_t** com características de caractere padrão.

## <a name="see-also"></a>Confira também

[\<streambuf>](../standard-library/streambuf.md)
