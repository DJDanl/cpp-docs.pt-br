---
title: _com_ptr_t::AddRef
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::AddRef
helpviewer_keywords:
- AddRef method [C++], interface pointers
ms.assetid: c104dac3-aad3-40bb-a298-75c6cd0e63a2
ms.openlocfilehash: 4dcf643357c9b368d4b2ea3bc51e6567acf45a44
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81745096"
---
# <a name="_com_ptr_taddref"></a>_com_ptr_t::AddRef

**Específico da Microsoft**

Chama `AddRef` a função `IUnknown` de membro do ponteiro de interface encapsulado.

## <a name="syntax"></a>Sintaxe

```cpp
void AddRef( );
```

## <a name="remarks"></a>Comentários

Chama `IUnknown::AddRef` o ponteiro de interface `E_POINTER` encapsulado, levantando um erro se o ponteiro for NULO.

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
