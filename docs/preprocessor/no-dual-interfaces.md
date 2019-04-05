---
title: no_dual_interfaces
ms.date: 11/04/2016
f1_keywords:
- no_dual_interfaces
helpviewer_keywords:
- no_dual_interfaces attribute
ms.assetid: 9acd5d9d-4a49-4cdc-9470-73a2c23cf512
ms.openlocfilehash: ae75bc2e974f374768f1a9e5a0e1ced61e9904b0
ms.sourcegitcommit: c7f90df497e6261764893f9cc04b5d1f1bf0b64b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/05/2019
ms.locfileid: "59023796"
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

**FIM de Específico do C++**

## <a name="see-also"></a>Consulte também

[Atributos de #import](../preprocessor/hash-import-attributes-cpp.md)<br/>
[Diretiva #import](../preprocessor/hash-import-directive-cpp.md)