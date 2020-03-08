---
title: funções de&gt; de lista de &lt;| Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.topic: reference
f1_keywords:
- list/std::swap
ms.openlocfilehash: 04f00a9274018432cd03917ae5485f2d395649e4
ms.sourcegitcommit: 3e8fa01f323bc5043a48a0c18b855d38af3648d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/06/2020
ms.locfileid: "78874337"
---
# <a name="ltlistgt-functions"></a>funções de&gt; de lista de &lt;

## <a name="swap"></a>permuta

Troca os elementos das duas listas.

```cpp
template <class T, class Allocator>
    void swap(list<T, Allocator>& left, list<T, Allocator>& right)
```

### <a name="parameters"></a>parâmetros

\ *à esquerda*
Um objeto do tipo `list`.

\ *à direita*
Um objeto do tipo `list`.

### <a name="remarks"></a>Comentários

Esta função de modelo executa `left.swap(right)`.
