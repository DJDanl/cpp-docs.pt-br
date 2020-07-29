---
title: _com_ptr_t::Attach
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::Attach
helpviewer_keywords:
- COM interfaces, attach pointer
- Attach method [C++]
ms.assetid: 94c18e0a-06be-4ca7-bdaf-cd54ec0a645e
ms.openlocfilehash: cb5950e311711dd489b3cab223714b1840773f60
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87220581"
---
# <a name="_com_ptr_tattach"></a>_com_ptr_t::Attach

**Específico da Microsoft**

Encapsula um ponteiro de interface bruto desse tipo de ponteiro inteligente.

## <a name="syntax"></a>Sintaxe

```cpp
void Attach( Interface* pInterface ) throw( );
void Attach( Interface* pInterface, bool fAddRef ) throw( );
```

#### <a name="parameters"></a>parâmetros

*pInterface*<br/>
Um ponteiro de interface bruto.

*fAddRef*<br/>
Se for **`true`** , `AddRef` será chamado. Se for **`false`** , o `_com_ptr_t` objeto assumirá a propriedade do ponteiro de interface bruto sem chamar `AddRef` .

## <a name="remarks"></a>Comentários

- **Anexar (**  *pInterface*  **)** `AddRef` Não é chamado. A propriedade da interface é transmitida a este objeto `_com_ptr_t`. `Release`é chamado para diminuir a contagem de referência para o ponteiro encapsulado anteriormente.

- **Attach (**  *pInterface* **,**  *fAddRef*  **)** Se *fAddRef* for **`true`** , `AddRef` será chamado para incrementar a contagem de referência para o ponteiro de interface encapsulada. Se *fAddRef* for **`false`** , esse `_com_ptr_t` objeto assumirá a propriedade do ponteiro de interface bruto sem chamar `AddRef` . `Release`é chamado para diminuir a contagem de referência para o ponteiro encapsulado anteriormente.

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
