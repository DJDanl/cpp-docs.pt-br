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
ms.openlocfilehash: ab2de61df8c4e22b1955e9fd4798b5128a3e12be
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33845889"
---
# <a name="hasiteratordebugging"></a>_HAS_ITERATOR_DEBUGGING

Substituída por [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md), esta macro define se o recurso de depuração do iterador está habilitado em um build de depuração. Por padrão, a depuração de iterador está habilitada em compilações de depuração e desabilitado em compilações comerciais. Para saber mais, consulte [Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md).

> [!IMPORTANT]
> O uso direto da macro `_HAS_ITERATOR_DEBUGGING` foi preterido. Em vez disso, use `_ITERATOR_DEBUG_LEVEL` para controlar configurações de depuração do iterador. Para obter mais informações, consulte [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md).

## <a name="remarks"></a>Comentários

Para habilitar a depuração do iterador em compilações de depuração, defina `_ITERATOR_DEBUG_LEVEL` como 2. Isso é equivalente a configurar `_HAS_ITERATOR_DEBUGGING` como 1 ou habilitado:

```cpp
#define _ITERATOR_DEBUG_LEVEL 2
```

`_ITERATOR_DEBUG_LEVEL` não pode ser definido como 2 (e `_HAS_ITERATOR_DEBUGGING` não pode ser definido como 1) em compilações comerciais.

Para desabilitar a depuração de iteradores em compilações de depuração, defina `_ITERATOR_DEBUG_LEVEL` como 0 ou 1. Isso é equivalente a configurar `_HAS_ITERATOR_DEBUGGING` como 0 ou desabilitado:

```cpp
#define _ITERATOR_DEBUG_LEVEL 0
```

## <a name="see-also"></a>Consulte também

[_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md)<br/>
[Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md)<br/>
[Iteradores verificados](../standard-library/checked-iterators.md)<br/>
[Bibliotecas seguras: Biblioteca Padrão C++](../standard-library/safe-libraries-cpp-standard-library.md)<br/>
