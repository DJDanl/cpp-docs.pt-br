---
title: Funções &lt;sstream&gt; | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- sstream/std::swap
ms.assetid: bc9607e8-7c6b-44ef-949b-19e917b450ad
ms.openlocfilehash: f98e5fc9521165d5599f904975e348276f346ea4
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
ms.locfileid: "33853281"
---
# <a name="ltsstreamgt-functions"></a>Funções &lt;sstream&gt;

||
|-|
|[swap](#sstream_swap)|

## <a name="sstream_swap"></a>  swap

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

|Parâmetro|Descrição|
|---------------|-----------------|
|`left`|Referência para um objeto `sstream`.|
|`right`|Referência para um objeto `sstream`.|

### <a name="remarks"></a>Comentários

A função de modelo executa `left.swap(right)`.

## <a name="see-also"></a>Consulte também

[\<sstream>](../standard-library/sstream.md)<br/>
