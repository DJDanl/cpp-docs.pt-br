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
ms.openlocfilehash: c48da9a0ff3b9cadf0b7e228f3108277154e8417
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39402878"
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
 *pInterface*  
 Um ponteiro de interface bruto.  
  
 *faddref=false&lt;1}*  
 Se for TRUE, em seguida, `AddRef` é chamado. Se for FALSE, o `_com_ptr_t` objeto assume a propriedade do ponteiro bruto da interface sem chamar `AddRef`.  
  
## <a name="remarks"></a>Comentários  
  
-   **Anexar (***pInterface***)** `AddRef` não é chamado. A propriedade da interface é transmitida a este objeto `_com_ptr_t`. `Release` é chamado para diminuir a contagem de referência para o ponteiro anteriormente encapsulado.  
  
-   **Anexar (***pInterface* **,***fAddRef***)** se *fAddRef* for TRUE, `AddRef`é chamado para aumentar a contagem de referência para o ponteiro de interface encapsulado.       Se *fAddRef* é FALSE, isso `_com_ptr_t` objeto assume a propriedade do ponteiro bruto da interface sem chamar `AddRef`. `Release` é chamado para diminuir a contagem de referência para o ponteiro anteriormente encapsulado.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)