---
title: _com_ptr_t::AddRef | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- _com_ptr_t::AddRef
dev_langs:
- C++
helpviewer_keywords:
- AddRef method [C++], interface pointers
ms.assetid: c104dac3-aad3-40bb-a298-75c6cd0e63a2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e66f5b4f490bd31a9f35b13c037f2b6cf607c40b
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="comptrtaddref"></a>_com_ptr_t::AddRef
**Seção específica da Microsoft**  
  
 Chamadas de `AddRef` função membro de **IUnknown** no ponteiro de interface encapsulado.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
void AddRef( );  
  
```  
  
## <a name="remarks"></a>Comentários  
 Chamadas `IUnknown::AddRef` no ponteiro de interface encapsulada, gerando um `E_POINTER` erro se o ponteiro for **nulo**.  
  
 **Fim da seção específica da Microsoft**  
  
## <a name="see-also"></a>Consulte também  
 [Classe _com_ptr_t](../cpp/com-ptr-t-class.md)