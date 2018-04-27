---
title: Typedefs &lt;ostream&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- iosfwd/std::ostream
- iosfwd/std::wostream
ms.assetid: 2ec4dc52-a01f-4654-bd65-dd5288777c48
caps.latest.revision: 11
manager: ghogen
ms.openlocfilehash: 8c451b16a581ab13f87c7bcca793efe3a0f07bf5
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
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
