---
title: no_auto_exclude
ms.date: 11/04/2016
f1_keywords:
- no_auto_exclude
helpviewer_keywords:
- no_auto_exclude attribute
ms.assetid: 3241ef9c-758a-4e86-bdc5-37da6072430f
ms.openlocfilehash: 04e3b261e24bbe9870a6d3fc428cd68e8c1a8132
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50537625"
---
# <a name="noautoexclude"></a>no_auto_exclude
**Específico do C++**

Desabilita a exclusão automática.

## <a name="syntax"></a>Sintaxe

```
no_auto_exclude
```

## <a name="remarks"></a>Comentários

As bibliotecas de tipos podem conter definições dos itens definidos em cabeçalhos do sistema ou em outras bibliotecas de tipos. `#import` tenta impedir vários erros de definição excluindo automaticamente esses itens. Quando isso for feito, [aviso do compilador (nível 3) C4192](../error-messages/compiler-warnings/compiler-warning-level-3-c4192.md) será emitido para cada item a ser excluído. Você pode desabilitar essa exclusão automática usando esse atributo.

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)