---
title: _com_ptr_t::AddRef
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::AddRef
helpviewer_keywords:
- AddRef method [C++], interface pointers
ms.assetid: c104dac3-aad3-40bb-a298-75c6cd0e63a2
ms.openlocfilehash: 51182b461aeac83c12bb18a573a49b2d4347a190
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80189917"
---
# <a name="_com_ptr_taddref"></a>_com_ptr_t::AddRef

**Seção específica da Microsoft**

Chama a função membro `AddRef` de `IUnknown` no ponteiro de interface encapsulado.

## <a name="syntax"></a>Sintaxe

```
void AddRef( );
```

## <a name="remarks"></a>Comentários

Chama `IUnknown::AddRef` no ponteiro de interface encapsulada, gerando um erro de `E_POINTER` se o ponteiro for nulo.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
