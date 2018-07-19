---
title: _HAS_ITERATOR_DEBUGGING | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-standard-libraries
ms.topic: reference
f1_keywords:
- _HAS_ITERATOR_DEBUGGING
dev_langs:
- C++
helpviewer_keywords:
- _HAS_ITERATOR_DEBUGGING
ms.assetid: 90077dbb-8a76-4963-83a6-29f4854007a8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 81f0509c6230020b586c0341e1de608981c05476
ms.sourcegitcommit: 3614b52b28c24f70d90b20d781d548ef74ef7082
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/11/2018
ms.locfileid: "38965972"
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
