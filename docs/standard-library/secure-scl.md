---
title: _SECURE_SCL
ms.date: 11/04/2016
f1_keywords:
- _SECURE_SCL
helpviewer_keywords:
- _SECURE_SCL
ms.assetid: 4ffbc788-cc12-4c6a-8cd7-490081675086
ms.openlocfilehash: dcfaee2906136dffbe79a49f089a079104112e78
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50559153"
---
# <a name="securescl"></a>_SECURE_SCL

Substituído por [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md), essa macro define se os [Iteradores verificados](../standard-library/checked-iterators.md) estão habilitados. Por padrão, a depuração de iterador está habilitada em builds de depuração e desabilitado em builds de varejo.

> [!IMPORTANT]
> Uso direto da macro secure_scl foi preterido. Em vez disso, use iterator_debug_level às configurações de iterador verificado de controle. Para obter mais informações, consulte [_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md).

## <a name="remarks"></a>Comentários

Quando iteradores verificados estão habilitados, o uso de um iterador não seguro causa um erro em tempo de execução e o programa é encerrado. Para habilitar os iteradores verificados, defina iterator_debug_level como 1 ou 2. Isso é equivalente a uma configuração de secure_scl 1 ou habilitado:

```cpp
#define _ITERATOR_DEBUG_LEVEL 1
```

Para desabilitar os iteradores verificados, defina iterator_debug_level como 0. Isso é equivalente a uma configuração de secure_scl de 0 ou desabilitado:

```cpp
#define _ITERATOR_DEBUG_LEVEL 0
```

Para obter informações sobre como desabilitar avisos sobre iteradores verificados, consulte [_SCL_SECURE_NO_WARNINGS](../standard-library/scl-secure-no-warnings.md).

## <a name="see-also"></a>Consulte também

[_ITERATOR_DEBUG_LEVEL](../standard-library/iterator-debug-level.md)<br/>
[Iteradores verificados](../standard-library/checked-iterators.md)<br/>
[Suporte ao iterador de depuração](../standard-library/debug-iterator-support.md)<br/>
[Bibliotecas seguras: Biblioteca Padrão C++](../standard-library/safe-libraries-cpp-standard-library.md)<br/>
