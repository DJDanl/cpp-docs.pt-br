---
title: Typedefs &lt;ostream&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- iosfwd/std::ostream
- iosfwd/std::wostream
ms.assetid: 2ec4dc52-a01f-4654-bd65-dd5288777c48
ms.openlocfilehash: 3f5511cfbf73ddf74fa12954e1a108d8accf875e
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33852573"
---
# <a name="ltostreamgt-typedefs"></a>Typedefs &lt;ostream&gt;

|||
|-|-|
|[ostream](#ostream)|[wostream](#wostream)|

## <a name="ostream"></a>  ostream

Cria um tipo de basic_ostream que é especializado em `char` e `char_traits` é especializado em `char`.

```cpp
typedef basic_ostream<char, char_traits<char>> ostream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo da classe de modelo [basic_ostream](../standard-library/basic-ostream-class.md), especializado para elementos do tipo `char` com características de caractere padrão.

## <a name="wostream"></a>  wostream

Cria um tipo de basic_ostream que é especializado em `wchar_t` e `char_traits` é especializado em `wchar_t`.

```cpp
typedef basic_ostream<wchar_t, char_traits<wchar_t>> wostream;
```

### <a name="remarks"></a>Comentários

O tipo é um sinônimo da classe de modelo [basic_ostream](../standard-library/basic-ostream-class.md), especializado para elementos do tipo `wchar_t` com características de caractere padrão.

## <a name="see-also"></a>Consulte também

[\<ostream>](../standard-library/ostream.md)<br/>
