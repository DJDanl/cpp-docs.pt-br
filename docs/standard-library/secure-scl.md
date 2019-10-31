---
title: _SECURE_SCL
ms.date: 11/04/2016
f1_keywords:
- _SECURE_SCL
helpviewer_keywords:
- _SECURE_SCL
ms.assetid: 4ffbc788-cc12-4c6a-8cd7-490081675086
ms.openlocfilehash: 1af084363fc0d6d1723a9af7b633779f92ed2b38
ms.sourcegitcommit: 0dcab746c49f13946b0a7317fc9769130969e76d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/24/2019
ms.locfileid: "68450536"
---
# <a name="_secure_scl"></a>_SECURE_SCL

Substituído por [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md), essa macro define se os [Iteradores verificados](../standard-library/checked-iterators.md) estão habilitados. Por padrão, a depuração de iterador está habilitada em builds de depuração e desabilitado em builds de varejo.

> [!IMPORTANT]
> O uso direto da macro _SECURE_SCL foi preterido. Em vez disso, use _ITERATOR_DEBUG_LEVEL para controlar as configurações de iterador verificadas. Para obter mais informações, consulte [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md).

## <a name="remarks"></a>Comentários

Quando iteradores verificados estão habilitados, o uso de um iterador não seguro causa um erro em tempo de execução e o programa é encerrado. Para habilitar iteradores selecionados, defina _ITERATOR_DEBUG_LEVEL como 1 ou 2. Isso é equivalente a uma configuração de _SECURE_SCL de 1, ou habilitado:

```cpp
#define _ITERATOR_DEBUG_LEVEL 1
```

Para desabilitar iteradores selecionados, defina _ITERATOR_DEBUG_LEVEL como 0. Isso é equivalente a uma configuração de _SECURE_SCL de 0 ou desabilitado:

```cpp
#define _ITERATOR_DEBUG_LEVEL 0
```

Para obter informações sobre como desabilitar avisos sobre iteradores verificados, consulte [_SCL_SECURE_NO_WARNINGS](../standard-library/scl-secure-no-warnings.md).

## <a name="see-also"></a>Consulte também

[_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md)\
[Iteradores verificados](../standard-library/checked-iterators.md)\
[Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md)\
[Bibliotecas seguras: Biblioteca Padrão C++](../standard-library/safe-libraries-cpp-standard-library.md)
