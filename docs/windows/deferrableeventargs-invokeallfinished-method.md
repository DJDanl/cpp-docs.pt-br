---
title: 'Método: Invokeallfinished | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-windows
ms.topic: reference
dev_langs:
- C++
ms.assetid: 86b45205-3edb-4134-9cd0-ed7a7b4c3b1a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
- uwp
ms.openlocfilehash: 1aaaf8c6849b30e26463810ff353234319960048
ms.sourcegitcommit: d55ac596ba8f908f5d91d228dc070dad31cb8360
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/08/2018
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
  
 **Namespace:** Microsoft::WRL  
  
## <a name="see-also"></a>Consulte também  
 [Classe DeferrableEventArgs](../windows/deferrableeventargs-class.md)   
 [Método EventSource::InvokeAll](../windows/eventsource-invokeall-method.md)