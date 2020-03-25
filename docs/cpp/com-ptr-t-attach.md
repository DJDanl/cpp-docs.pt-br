---
title: _com_ptr_t::Attach
ms.date: 11/04/2016
f1_keywords:
- _com_ptr_t::Attach
helpviewer_keywords:
- COM interfaces, attach pointer
- Attach method [C++]
ms.assetid: 94c18e0a-06be-4ca7-bdaf-cd54ec0a645e
ms.openlocfilehash: 870e3580ed23ce994d832f7c59b951680d725e41
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80180492"
---
# <a name="_com_ptr_tattach"></a>_com_ptr_t::Attach

**Seção específica da Microsoft**

Encapsula um ponteiro de interface bruto desse tipo de ponteiro inteligente.

## <a name="syntax"></a>Sintaxe

```
void Attach( Interface* pInterface ) throw( );
void Attach( Interface* pInterface, bool fAddRef ) throw( );
```

#### <a name="parameters"></a>parâmetros

*pInterface*<br/>
Um ponteiro de interface bruto.

*fAddRef*<br/>
Se for TRUE, `AddRef` será chamado. Se for FALSE, o objeto `_com_ptr_t` assumirá a propriedade do ponteiro de interface bruto sem chamar `AddRef`.

## <a name="remarks"></a>Comentários

- A **anexação (** *pInterface* **)** `AddRef` não é chamada. A propriedade da interface é transmitida a este objeto `_com_ptr_t`. `Release` é chamado para diminuir a contagem de referência para o ponteiro encapsulado anteriormente.

- **Attach (**  *pInterface* **,**  *fAddRef*  **)** Se *fAddRef* for TRUE, `AddRef` será chamado para incrementar a contagem de referência para o ponteiro de interface encapsulada. Se *fAddRef* for false, esse objeto `_com_ptr_t` assumirá a propriedade do ponteiro de interface bruto sem chamar `AddRef`. `Release` é chamado para diminuir a contagem de referência para o ponteiro encapsulado anteriormente.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
