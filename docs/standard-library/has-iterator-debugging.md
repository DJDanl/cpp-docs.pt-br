---
title: _HAS_ITERATOR_DEBUGGING
ms.date: 11/04/2016
f1_keywords:
- _HAS_ITERATOR_DEBUGGING
helpviewer_keywords:
- _HAS_ITERATOR_DEBUGGING
ms.assetid: 90077dbb-8a76-4963-83a6-29f4854007a8
ms.openlocfilehash: 339c32f9b487db2e318f8763ac01a0d155fc1dc1
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50575871"
---
# <a name="hasiteratordebugging"></a>_HAS_ITERATOR_DEBUGGING

Substituída por [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md), esta macro define se o recurso de depuração do iterador está habilitado em um build de depuração. Por padrão, a depuração de iterador está habilitada em compilações de depuração e desabilitado em compilações comerciais. Para saber mais, consulte [Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md).

> [!IMPORTANT]
> Uso direto da macro has_iterator_debugging foi preterido. Em vez disso, use iterator_debug_level para controlar as configurações de depuração do iterador. Para obter mais informações, consulte [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md).

## <a name="remarks"></a>Comentários

Para habilitar a depuração do iterador em compilações de depuração, defina iterator_debug_level como 2. Isso é equivalente a uma configuração de has_iterator_debugging de 1 ou habilitado:

```cpp
#define _ITERATOR_DEBUG_LEVEL 2
```

Iterator_debug_level não pode ser definido como 2 (e has_iterator_debugging não pode ser definido como 1) em compilações comerciais.

Para desabilitar a depuração de iteradores em compilações de depuração, defina iterator_debug_level como 0 ou 1. Isso é equivalente a uma configuração de has_iterator_debugging de 0 ou desabilitado:

```cpp
#define _ITERATOR_DEBUG_LEVEL 0
```

## <a name="see-also"></a>Consulte também

[_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md)<br/>
[Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md)<br/>
[Iteradores verificados](../standard-library/checked-iterators.md)<br/>
[Bibliotecas seguras: Biblioteca Padrão C++](../standard-library/safe-libraries-cpp-standard-library.md)<br/>
