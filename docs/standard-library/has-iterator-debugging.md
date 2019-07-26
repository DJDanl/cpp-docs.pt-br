---
title: _HAS_ITERATOR_DEBUGGING
ms.date: 11/04/2016
f1_keywords:
- _HAS_ITERATOR_DEBUGGING
helpviewer_keywords:
- _HAS_ITERATOR_DEBUGGING
ms.assetid: 90077dbb-8a76-4963-83a6-29f4854007a8
ms.openlocfilehash: a1e3017ed7c6def18ce02d99dc8253b69c11ab58
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68448826"
---
# <a name="hasiteratordebugging"></a>_HAS_ITERATOR_DEBUGGING

Substituída por [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md), esta macro define se o recurso de depuração do iterador está habilitado em um build de depuração. Por padrão, a depuração de iterador está habilitada em compilações de depuração e desabilitado em compilações comerciais. Para saber mais, consulte [Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md).

> [!IMPORTANT]
> O uso direto da macro _HAS_ITERATOR_DEBUGGING foi preterido. Em vez disso, use _ITERATOR_DEBUG_LEVEL para controlar as configurações de depuração do iterador. Para obter mais informações, consulte [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md).

## <a name="remarks"></a>Comentários

Para habilitar a depuração do iterador em compilações de depuração, defina _ITERATOR_DEBUG_LEVEL como 2. Isso é equivalente a uma configuração de _HAS_ITERATOR_DEBUGGING de 1, ou habilitado:

```cpp
#define _ITERATOR_DEBUG_LEVEL 2
```

_ITERATOR_DEBUG_LEVEL não pode ser definido como 2 (e _HAS_ITERATOR_DEBUGGING não pode ser definido como 1) em compilações de varejo.

Para desabilitar os iteradores de depuração em compilações de depuração, defina _ITERATOR_DEBUG_LEVEL como 0 ou 1. Isso é equivalente a uma configuração de _HAS_ITERATOR_DEBUGGING de 0 ou desabilitado:

```cpp
#define _ITERATOR_DEBUG_LEVEL 0
```

## <a name="see-also"></a>Consulte também

[_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md)\
[Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md)\
[Iteradores verificados](../standard-library/checked-iterators.md)\
[Bibliotecas seguras: Biblioteca Padrão C++](../standard-library/safe-libraries-cpp-standard-library.md)
