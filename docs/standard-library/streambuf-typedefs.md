---
title: Typedefs &lt;streambuf&gt;
ms.date: 11/04/2016
f1_keywords:
- iosfwd/std::streambuf
- iosfwd/std::wstreambuf
ms.assetid: 2678e18f-f0f0-4995-bc53-f1bc7dfc4ec6
ms.openlocfilehash: 8eb058f161a9f30ccf5e9d49307b50c215f79c22
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81376692"
---
# <a name="ltstreambufgt-typedefs"></a>Typedefs &lt;streambuf&gt;

|||
|-|-|
|[streambuf](#streambuf)|[wstreambuf](#wstreambuf)|

## <a name="streambuf"></a><a name="streambuf"></a>streambuf

Uma especialização `basic_streambuf` disso usa **char** como parâmetros de modelo.

```cpp
typedef basic_streambuf<char, char_traits<char>> streambuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_streambuf,](../standard-library/basic-streambuf-class.md)especializado para elementos de **tipo char** com traços de caractere padrão.

## <a name="wstreambuf"></a><a name="wstreambuf"></a>wstreambuf

Uma especialização `basic_streambuf` disso usa **wchar_t** como parâmetros de modelo.

```cpp
typedef basic_streambuf<wchar_t, char_traits<wchar_t>> wstreambuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo para o modelo de classe [basic_streambuf,](../standard-library/basic-streambuf-class.md)especializado para elementos de tipo **wchar_t** com traços de caractere padrão.

## <a name="see-also"></a>Confira também

[\<streambuf>](../standard-library/streambuf.md)
