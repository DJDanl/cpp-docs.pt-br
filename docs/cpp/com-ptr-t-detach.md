---
title: _com_ptr_t::Detach
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::Detach
helpviewer_keywords:
- Detach method [C++]
ms.assetid: 0652053e-af37-44e9-a278-2522212ebfed
ms.openlocfilehash: 8ba42f19e3474cc4a3199771f761b021221f430e
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80190008"
---
# <a name="_com_ptr_tdetach"></a>_com_ptr_t::Detach

**Seção específica da Microsoft**

Extrai e retorna o ponteiro de interface encapsulado.

## <a name="syntax"></a>Sintaxe

```
Interface* Detach( ) throw( );
```

## <a name="remarks"></a>Comentários

Extrai e retorna o ponteiro de interface encapsulado, e depois limpa o armazenamento de ponteiro encapsulado para NULL. Isso remove o ponteiro de interface do encapsulamento. Cabe a você chamar `Release` no ponteiro de interface retornado.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
