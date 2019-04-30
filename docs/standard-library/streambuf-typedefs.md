---
title: Typedefs &lt;streambuf&gt;
ms.date: 11/04/2016
f1_keywords:
- iosfwd/std::streambuf
- iosfwd/std::wstreambuf
ms.assetid: 2678e18f-f0f0-4995-bc53-f1bc7dfc4ec6
ms.openlocfilehash: 505739861771a05dd39741f432579a6e9b2d0c26
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62412378"
---
# <a name="ltstreambufgt-typedefs"></a>Typedefs &lt;streambuf&gt;

|||
|-|-|
|[streambuf](#streambuf)|[wstreambuf](#wstreambuf)|

## <a name="streambuf"></a>  streambuf

Uma especialização da `basic_streambuf` que usa **char** como os parâmetros de modelo.

```cpp
typedef basic_streambuf<char, char_traits<char>> streambuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para a classe de modelo [basic_streambuf](../standard-library/basic-streambuf-class.md), especializado para elementos do tipo **char** com características de caractere padrão.

## <a name="wstreambuf"></a>  wstreambuf

Uma especialização da `basic_streambuf` que usa **wchar_t** como os parâmetros de modelo.

```cpp
typedef basic_streambuf<wchar_t, char_traits<wchar_t>> wstreambuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para a classe de modelo [basic_streambuf](../standard-library/basic-streambuf-class.md), especializado para elementos do tipo **wchar_t** com características de caractere padrão.

## <a name="see-also"></a>Consulte também

[\<streambuf>](../standard-library/streambuf.md)<br/>
