---
title: Classe allocator&lt;void&gt;
ms.date: 11/04/2016
f1_keywords:
- memory/std::allocator<void>
- allocator<void>
helpviewer_keywords:
- allocator<void> class
ms.assetid: abfb40f5-c600-46a6-b130-f42c6535b2bd
ms.openlocfilehash: af29c70dca56b1e68eef3614357269c587a77ec9
ms.sourcegitcommit: c21b05042debc97d14875e019ee9d698691ffc0b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 06/09/2020
ms.locfileid: "84623676"
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

A classe especializada explicitamente o [alocador](allocator-class.md) de modelo de classe para o tipo **void**. Seus construtores e operador de atribuição se comportam da mesma forma que para o modelo de classe, mas definem apenas os seguintes tipos:

- [const_pointer](allocator-class.md#const_pointer).

- [ponteiro](allocator-class.md#pointer).

- [value_type](allocator-class.md#value_type).

- [reassocie](allocator-class.md#rebind), um modelo de classe aninhado.
