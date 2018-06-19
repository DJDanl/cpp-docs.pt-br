---
title: Typedefs &lt;streambuf&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- iosfwd/std::streambuf
- iosfwd/std::wstreambuf
ms.assetid: 2678e18f-f0f0-4995-bc53-f1bc7dfc4ec6
ms.openlocfilehash: 8fb1713dfbc2d9766c488f21d324d801a4886d68
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33854204"
---
# <a name="ltstreambufgt-typedefs"></a>Typedefs &lt;streambuf&gt;

|||
|-|-|
|[streambuf](#streambuf)|[wstreambuf](#wstreambuf)|

## <a name="streambuf"></a>  streambuf

Uma especialização de `basic_streambuf` que usa `char` como os parâmetros do modelo.

```cpp
typedef basic_streambuf<char, char_traits<char>> streambuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo da classe de modelo [basic_streambuf](../standard-library/basic-streambuf-class.md), especializado para elementos do tipo `char` com características de caractere padrão.

## <a name="wstreambuf"></a>  wstreambuf

Uma especialização de `basic_streambuf` que usa `wchar_t` como os parâmetros do modelo.

```cpp
typedef basic_streambuf<wchar_t, char_traits<wchar_t>> wstreambuf;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo da classe de modelo [basic_streambuf](../standard-library/basic-streambuf-class.md), especializado para elementos do tipo `wchar_t` com características de caractere padrão.

## <a name="see-also"></a>Consulte também

[\<streambuf>](../standard-library/streambuf.md)<br/>
