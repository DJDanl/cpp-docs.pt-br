---
title: _HAS_ITERATOR_DEBUGGING | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-standard-libraries
ms.tgt_pltfrm: ''
ms.topic: reference
f1_keywords:
- _HAS_ITERATOR_DEBUGGING
dev_langs:
- C++
helpviewer_keywords:
- _HAS_ITERATOR_DEBUGGING
ms.assetid: 90077dbb-8a76-4963-83a6-29f4854007a8
caps.latest.revision: 7
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: 1e6cf83c0877c351a2bf247a557f3df53e9c1f22
ms.sourcegitcommit: dd1a509526fa8bb18e97ab7bc7b91cbdb3ec7059
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/26/2018
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
