---
title: Typedefs &lt;streambuf&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- iosfwd/std::streambuf
- iosfwd/std::wstreambuf
ms.assetid: 2678e18f-f0f0-4995-bc53-f1bc7dfc4ec6
ms.openlocfilehash: 81c7cd875c6083ee77701116f6b1179760373ec0
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38953986"
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
