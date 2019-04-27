---
title: _com_ptr_t::Detach
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::Detach
helpviewer_keywords:
- Detach method [C++]
ms.assetid: 0652053e-af37-44e9-a278-2522212ebfed
ms.openlocfilehash: affaefd8af4802836733587af62977171ba01410
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62154951"
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