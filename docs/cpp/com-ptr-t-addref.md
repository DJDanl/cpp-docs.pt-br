---
title: _com_ptr_t::AddRef
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::AddRef
helpviewer_keywords:
- AddRef method [C++], interface pointers
ms.assetid: c104dac3-aad3-40bb-a298-75c6cd0e63a2
ms.openlocfilehash: 7408b5c174f76673b56caffd56aaa87895bd08d4
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62154936"
---
# <a name="comptrtaddref"></a>_com_ptr_t::AddRef

**Seção específica da Microsoft**

Chamadas a `AddRef` função de membro de `IUnknown` no ponteiro de interface encapsulado.

## <a name="syntax"></a>Sintaxe

```
void AddRef( );
```

## <a name="remarks"></a>Comentários

Chamadas `IUnknown::AddRef` no ponteiro de interface encapsulado, gerando um `E_POINTER` erro se o ponteiro é NULL.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)