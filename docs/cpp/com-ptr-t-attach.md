---
title: _com_ptr_t::Attach
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::Attach
helpviewer_keywords:
- COM interfaces, attach pointer
- Attach method [C++]
ms.assetid: 94c18e0a-06be-4ca7-bdaf-cd54ec0a645e
ms.openlocfilehash: 057d784bb495aefaeec1b86697a7421f6464cbd7
ms.sourcegitcommit: 7a6116e48c3c11b97371b8ae4ecc23adce1f092d
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/22/2020
ms.locfileid: "81745074"
---
# <a name="_com_ptr_tattach"></a>_com_ptr_t::Attach

**Específico da Microsoft**

Encapsula um ponteiro de interface bruto desse tipo de ponteiro inteligente.

## <a name="syntax"></a>Sintaxe

```cpp
void Attach( Interface* pInterface ) throw( );
void Attach( Interface* pInterface, bool fAddRef ) throw( );
```

#### <a name="parameters"></a>Parâmetros

*pInterface*<br/>
Um ponteiro de interface bruto.

*fAddRef*<br/>
Se é VERDADE, `AddRef` então é chamado. Se for FALSO, `_com_ptr_t` o objeto se apropria do `AddRef`ponteiro de interface bruto sem chamar .

## <a name="remarks"></a>Comentários

- **O attach***(pInterface)***)** `AddRef` não é chamado.     A propriedade da interface é transmitida a este objeto `_com_ptr_t`. `Release`é chamado para diminuir a contagem de referência para o ponteiro previamente encapsulado.

- **Anexar***(pInterface* **,***fAddRef)***)** Se *fAddRef* for `AddRef` TRUE, será chamada para incrementar a contagem de referência para o ponteiro de interface encapsulado.       Se *fAddRef* for `_com_ptr_t` FALSE, este objeto assumirá `AddRef`a propriedade do ponteiro de interface bruto sem chamar . `Release`é chamado para diminuir a contagem de referência para o ponteiro previamente encapsulado.

**Fim específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
