---
title: Funções &lt;sstream&gt;
ms.date: 11/04/2016
f1_keywords:
- sstream/std::swap
ms.assetid: bc9607e8-7c6b-44ef-949b-19e917b450ad
ms.openlocfilehash: 43fcffe12afe50a94f06a18e7ee06729bc85854e
ms.sourcegitcommit: 6280a4c629de0f638ebc2edd446de2a9b11f0406
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/12/2020
ms.locfileid: "90039892"
---
# <a name="ltsstreamgt-functions"></a>Funções &lt;sstream&gt;

[permuta](#sstream_swap)

## <a name="swap"></a><a name="sstream_swap"></a> permuta

Troca os valores de dois objetos `sstream`.

```cpp
template <class Elem, class Tr, class Alloc>
void swap(
    basic_stringbuf<Elem, Tr, Alloc>& left,
    basic_stringbuf<Elem, Tr, Alloc>& right);

template <class Elem, class Tr, class Alloc>
void swap(
    basic_istringstream<Elem, Tr, Alloc>& left,
    basic_istringstream<Elem, Tr, Alloc>& right);

template <class Elem, class Tr, class Alloc>
void swap(
    basic_ostringstream<Elem, Tr, Alloc>& left,
    basic_ostringstream<Elem, Tr, Alloc>& right);

template <class Elem, class Tr, class Alloc>
void swap(
    basic_stringstream<Elem, Tr, Alloc>& left,
    basic_stringstream<Elem, Tr, Alloc>& right);
```

### <a name="parameters"></a>Parâmetros

*mantida*\
Referência para um objeto `sstream`.

*Certo*\
Referência para um objeto `sstream`.

### <a name="remarks"></a>Comentários

A função de modelo executa `left.swap(right)`.

## <a name="see-also"></a>Confira também

[\<sstream>](../standard-library/sstream.md)
