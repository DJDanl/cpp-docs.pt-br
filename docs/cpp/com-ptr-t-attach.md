---
title: _com_ptr_t::Attach | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
ms.topic: language-reference
f1_keywords:
- _com_ptr_t::Attach
dev_langs:
- C++
helpviewer_keywords:
- COM interfaces, attach pointer
- Attach method [C++]
ms.assetid: 94c18e0a-06be-4ca7-bdaf-cd54ec0a645e
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: d8b9eac88c9387c6aeedd140159bb24482c829dd
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="comptrtattach"></a>_com_ptr_t::Attach
**Seção específica da Microsoft**  
  
 Encapsula um ponteiro de interface bruto desse tipo de ponteiro inteligente.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
      void Attach(  
   Interface* pInterface   
) throw( );  
void Attach(  
   Interface* pInterface,  
   bool fAddRef   
) throw( );  
```  
  
#### <a name="parameters"></a>Parâmetros  
 `pInterface`  
 Um ponteiro de interface bruto.  
  
 `fAddRef`  
 Se for **true**, em seguida, `AddRef` é chamado. Se for **false**, o `_com_ptr_t` objeto apropria-se de que o ponteiro de interface bruto sem chamar `AddRef`.  
  
## <a name="remarks"></a>Comentários  
  
-   **Anexar (**`pInterface`**)** `AddRef` não é chamado. A propriedade da interface é transmitida a este objeto `_com_ptr_t`. **Versão** é chamado para diminuir a contagem de referência para o ponteiro anteriormente encapsulado.  
  
-   **Anexar (** `pInterface` **,**`fAddRef`**)** se `fAddRef` é **true**, `AddRef` é chamado para incrementar a referência contagem para o ponteiro de interface encapsulado. Se `fAddRef` é **false**, esse `_com_ptr_t` objeto apropria-se de que o ponteiro de interface bruto sem chamar `AddRef`. **Versão** é chamado para diminuir a contagem de referência para o ponteiro anteriormente encapsulado.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)