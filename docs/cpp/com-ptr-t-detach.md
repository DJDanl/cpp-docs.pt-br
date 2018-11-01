---
title: _com_ptr_t::Detach
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::Detach
helpviewer_keywords:
- Detach method [C++]
ms.assetid: 0652053e-af37-44e9-a278-2522212ebfed
ms.openlocfilehash: affaefd8af4802836733587af62977171ba01410
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50537794"
---
# <a name="comptrtdetach"></a>_com_ptr_t::Detach

**Seção específica da Microsoft**

Extrai e retorna o ponteiro de interface encapsulado.

## <a name="syntax"></a>Sintaxe

```
Interface* Detach( ) throw( );
```

## <a name="remarks"></a>Comentários

Extrai e retorna o ponteiro de interface encapsulado e, em seguida, limpa o armazenamento de ponteiro encapsulado como NULL. Isso remove o ponteiro de interface do encapsulamento. Cabe a você chamar `Release` no ponteiro de interface retornado.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)