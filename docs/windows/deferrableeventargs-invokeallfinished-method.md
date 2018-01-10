---
title: "Método: Invokeallfinished | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: reference
dev_langs: C++
ms.assetid: 86b45205-3edb-4134-9cd0-ed7a7b4c3b1a
caps.latest.revision: "3"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 0ca021d66c615bfec84b8f08df8474eeb20709e0
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="deferrableeventargsinvokeallfinished-method"></a>Método DeferrableEventArgs::InvokeAllFinished
Chamado para indicar que todo o processamento para manipular um evento adiado foi concluída.  
  
## <a name="syntax"></a>Sintaxe  
  
```cpp  
void InvokeAllFinished()  
```  
  
## <a name="remarks"></a>Comentários  
 Você deve chamar esse método após as chamadas de origem do evento [InvokeAll](../windows/eventsource-invokeall-method.md). Chamar esse método impede que mais adiamentos da e força a execução se nenhum adiamentos foram realizados do manipulador de conclusão.  
  
 Para obter um exemplo de código, consulte [classe DeferrableEventArgs](../windows/deferrableeventargs-class.md).  
  
## <a name="requirements"></a>Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft:: wrl  
  
## <a name="see-also"></a>Consulte também  
 [Classe DeferrableEventArgs](../windows/deferrableeventargs-class.md)   
 [Método EventSource::InvokeAll](../windows/eventsource-invokeall-method.md)