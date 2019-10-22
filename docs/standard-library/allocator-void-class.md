---
title: Classe allocator&lt;void&gt;
ms.date: 11/04/2016
f1_keywords:
- memory/std::allocator<void>
- allocator<void>
helpviewer_keywords:
- allocator<void> class
ms.assetid: abfb40f5-c600-46a6-b130-f42c6535b2bd
ms.openlocfilehash: c8d787fe03dfe6f67fb8e228308ec74b6e7f620a
ms.sourcegitcommit: 590e488e51389066a4da4aa06d32d4c362c23393
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/21/2019
ms.locfileid: "72688524"
---
# <a name="allocatorltvoidgt-class"></a>Classe allocator&lt;void&gt;

Uma especialização do alocador de modelo de classe para digitar **void**, definindo os tipos que fazem sentido neste contexto.

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

A classe especializada explicitamente o [alocador](../standard-library/allocator-class.md) de modelo de classe para o tipo **void**. Seus construtores e operador de atribuição se comportam da mesma forma que para o modelo de classe, mas definem apenas os seguintes tipos:

- [const_pointer](../standard-library/allocator-class.md#const_pointer).

- [pointer](../standard-library/allocator-class.md#pointer).

- [value_type](../standard-library/allocator-class.md#value_type).

- [reassocie](../standard-library/allocator-class.md#rebind), um modelo de classe aninhado.
