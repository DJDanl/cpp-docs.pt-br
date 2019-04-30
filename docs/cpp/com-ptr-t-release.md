---
title: _com_ptr_t::Release
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t.Release
- _com_ptr_t::Release
helpviewer_keywords:
- Release method [C++]
ms.assetid: db448b34-0efa-4f02-b701-ad1ca3ae6ca5
ms.openlocfilehash: cf4cea35386d1f781d6d2946c1730ba2e18dacea
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62399220"
---
# <a name="comptrtrelease"></a>_com_ptr_t::Release

**Seção específica da Microsoft**

Chamadas a **Release** função de membro de `IUnknown` no ponteiro de interface encapsulado.

## <a name="syntax"></a>Sintaxe

```
void Release( );
```

## <a name="remarks"></a>Comentários

Chamadas `IUnknown::Release` no ponteiro de interface encapsulado, gerando um `E_POINTER` erro se o ponteiro da interface é NULL.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)