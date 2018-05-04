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
ms.openlocfilehash: 7341695ad0cbc8384da859b80a72a63d8d52215f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
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
  
-   **Anexar (**`pInterface`**)** `AddRef` não é chamado.     A propriedade da interface é transmitida a este objeto `_com_ptr_t`. **Versão** é chamado para diminuir a contagem de referência para o ponteiro anteriormente encapsulado.  
  
-   **Anexar (** `pInterface` **,**`fAddRef`**)** se `fAddRef` é **true**, `AddRef` é chamado para incrementar a referência contagem para o ponteiro de interface encapsulado.       Se `fAddRef` é **false**, esse `_com_ptr_t` objeto apropria-se de que o ponteiro de interface bruto sem chamar `AddRef`. **Versão** é chamado para diminuir a contagem de referência para o ponteiro anteriormente encapsulado.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)