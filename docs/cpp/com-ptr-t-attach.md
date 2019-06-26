---
title: _com_ptr_t::Attach
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::Attach
helpviewer_keywords:
- COM interfaces, attach pointer
- Attach method [C++]
ms.assetid: 94c18e0a-06be-4ca7-bdaf-cd54ec0a645e
ms.openlocfilehash: 4b4b7a21d12cc645c486dd93d555510c1e716563
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62154884"
---
# <a name="comptrtattach"></a>_com_ptr_t::Attach

**Seção específica da Microsoft**

Encapsula um ponteiro de interface bruto desse tipo de ponteiro inteligente.

## <a name="syntax"></a>Sintaxe

```
void Attach( Interface* pInterface ) throw( );
void Attach( Interface* pInterface, bool fAddRef ) throw( );
```

#### <a name="parameters"></a>Parâmetros

*pInterface*<br/>
Um ponteiro de interface bruto.

*fAddRef*<br/>
Se for TRUE, em seguida, `AddRef` é chamado. Se for FALSE, o `_com_ptr_t` objeto assume a propriedade do ponteiro bruto da interface sem chamar `AddRef`.

## <a name="remarks"></a>Comentários

- **Anexar (** *pInterface* **)** `AddRef` não é chamado. A propriedade da interface é transmitida a este objeto `_com_ptr_t`. `Release` é chamado para diminuir a contagem de referência para o ponteiro anteriormente encapsulado.

- **Anexar (** *pInterface* **,** *fAddRef* **)** se *fAddRef* for TRUE, `AddRef`é chamado para aumentar a contagem de referência para o ponteiro de interface encapsulado. Se *fAddRef* é FALSE, isso `_com_ptr_t` objeto assume a propriedade do ponteiro bruto da interface sem chamar `AddRef`. `Release` é chamado para diminuir a contagem de referência para o ponteiro anteriormente encapsulado.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)