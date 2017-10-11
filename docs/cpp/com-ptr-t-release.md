---
title: _com_ptr_t::Release | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_ptr_t.Release
- _com_ptr_t::Release
dev_langs:
- C++
helpviewer_keywords:
- Release method [C++]
ms.assetid: db448b34-0efa-4f02-b701-ad1ca3ae6ca5
caps.latest.revision: 6
author: mikeblome
ms.author: mblome
manager: ghogen
ms.translationtype: HT
ms.sourcegitcommit: 6ffef5f51e57cf36d5984bfc43d023abc8bc5c62
ms.openlocfilehash: 6f3875a48977b047dfd8706369d448838626e5c6
ms.contentlocale: pt-br
ms.lasthandoff: 09/25/2017

---
# <a name="comptrtrelease"></a>_com_ptr_t::Release
**Seção específica da Microsoft**  
  
 Chamadas de **versão** função membro de **IUnknown** no ponteiro de interface encapsulado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
void Release( );  
  
```  
  
## <a name="remarks"></a>Comentários  
 Chamadas `IUnknown::Release` no ponteiro de interface encapsulada, gerando um `E_POINTER` erro se o ponteiro de interface é **nulo**.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)
