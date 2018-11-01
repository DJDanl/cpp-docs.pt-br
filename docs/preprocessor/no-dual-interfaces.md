---
title: no_dual_interfaces
ms.date: 11/04/2016
f1_keywords:
- no_dual_interfaces
helpviewer_keywords:
- no_dual_interfaces attribute
ms.assetid: 9acd5d9d-4a49-4cdc-9470-73a2c23cf512
ms.openlocfilehash: d76fe3ce6bea4c3895da9d8b40d69852f912824e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50466723"
---
# <a name="nodualinterfaces"></a>no_dual_interfaces
**Específico do C++**

Altera o modo como o compilador gerenciar funções wrapper para métodos da interface dupla.

## <a name="syntax"></a>Sintaxe

```
no_dual_interfaces
```

## <a name="remarks"></a>Comentários

Normalmente, o wrapper chamará o método por meio da tabela de funções virtuais da interface. Com o **no_dual_interfaces**, o wrapper chama `IDispatch::Invoke` para invocar o método.

**FIM de específico de C++**

## <a name="see-also"></a>Consulte também

[atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[#import diretiva](../preprocessor/hash-import-directive-cpp.md)