---
title: Classe allocator&lt;void&gt;
ms.date: 11/04/2016
f1_keywords:
- memory/std::allocator<void>
- allocator<void>
helpviewer_keywords:
- allocator<void> class
ms.assetid: abfb40f5-c600-46a6-b130-f42c6535b2bd
ms.openlocfilehash: b6ca3f8b994756a21d85860fd8aff429ee38e58b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87204924"
---
# <a name="allocatorltvoidgt-class"></a>Classe allocator&lt;void&gt;

Uma especialização do alocador de modelo de classe a ser digitada **`void`** , definindo os tipos que fazem sentido neste contexto.

## <a name="syntax"></a>Sintaxe

```cpp
template <>
class allocator<void> {
    typedef void *pointer;
    typedef const void *const_pointer;
    typedef void value_type;
    template <class Other>
    struct rebind;
    allocator();
    allocator(const allocator<void>&);

    template <class Other>
    allocator(const allocator<Other>&);

    template <class Other>
    allocator<void>& operator=(const allocator<Other>&);
};
```

## <a name="remarks"></a>Comentários

A classe especializada explicitamente o [alocador](allocator-class.md) de modelo de classe para o tipo **`void`** . Seus construtores e operador de atribuição se comportam da mesma forma que para o modelo de classe, mas definem apenas os seguintes tipos:

- [const_pointer](allocator-class.md#const_pointer).

- [ponteiro](allocator-class.md#pointer).

- [value_type](allocator-class.md#value_type).

- [reassocie](allocator-class.md#rebind), um modelo de classe aninhado.
