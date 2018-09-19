---
title: _com_ptr_t::Attach | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- _com_ptr_t::Attach
dev_langs:
- C++
helpviewer_keywords:
- COM interfaces, attach pointer
- Attach method [C++]
ms.assetid: 94c18e0a-06be-4ca7-bdaf-cd54ec0a645e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f2fbedb2bbfba16abf1196d1dba377f7589c916b
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46099610"
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

*faddref=false&lt;1}*<br/>
Se for TRUE, em seguida, `AddRef` é chamado. Se for FALSE, o `_com_ptr_t` objeto assume a propriedade do ponteiro bruto da interface sem chamar `AddRef`.

## <a name="remarks"></a>Comentários

- **Anexar (***pInterface***)** `AddRef` não é chamado. A propriedade da interface é transmitida a este objeto `_com_ptr_t`. `Release` é chamado para diminuir a contagem de referência para o ponteiro anteriormente encapsulado.

- **Anexar (***pInterface* **,***fAddRef***)** se *fAddRef* for TRUE, `AddRef`é chamado para aumentar a contagem de referência para o ponteiro de interface encapsulado. Se *fAddRef* é FALSE, isso `_com_ptr_t` objeto assume a propriedade do ponteiro bruto da interface sem chamar `AddRef`. `Release` é chamado para diminuir a contagem de referência para o ponteiro anteriormente encapsulado.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Classe _com_ptr_t](../cpp/com-ptr-t-class.md)