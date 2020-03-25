---
title: _com_ptr_t::Release
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t.Release
- _com_ptr_t::Release
helpviewer_keywords:
- Release method [C++]
ms.assetid: db448b34-0efa-4f02-b701-ad1ca3ae6ca5
ms.openlocfilehash: f455e855e782a939e79898ee46e445f65d25d37a
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80170586"
---
# <a name="_com_ptr_trelease"></a>_com_ptr_t::Release

**Seção específica da Microsoft**

Chama a função de membro de **liberação** de `IUnknown` no ponteiro de interface encapsulada.

## <a name="syntax"></a>Sintaxe

```
void Release( );
```

## <a name="remarks"></a>Comentários

Chama `IUnknown::Release` no ponteiro de interface encapsulada, gerando um erro de `E_POINTER` se esse ponteiro de interface for nulo.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
