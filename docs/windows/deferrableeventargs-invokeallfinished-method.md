---
title: 'Método deferrableeventargs:: Invokeallfinished | Microsoft Docs'
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
ms.openlocfilehash: 23d521b8373969abdd739b6e4f48eb334284664d
ms.sourcegitcommit: 6f8dd98de57bb80bf4c9852abafef1c35a7600f1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/22/2018
ms.locfileid: "42605167"
---
# <a name="deferrableeventargsinvokeallfinished-method"></a>Método DeferrableEventArgs::InvokeAllFinished
Chamado para indicar que todo o processamento para manipular um evento adiado foi concluída.
  
## <a name="syntax"></a>Sintaxe
  
```cpp
void InvokeAllFinished()  
```
  
## <a name="remarks"></a>Comentários
 Você deve chamar esse método após as chamadas de código-fonte do evento [InvokeAll](../windows/eventsource-invokeall-method.md). Chamar esse método impede que mais adiamentos de que está sendo feito e força a execução se nenhum adiamentos foram realizados do manipulador de conclusão.
  
 Para obter um exemplo de código, consulte [classe DeferrableEventArgs](../windows/deferrableeventargs-class.md).
  
## <a name="requirements"></a>Requisitos
 **Cabeçalho:** Event. h
  
 **Namespace:** Microsoft::WRL
  
## <a name="see-also"></a>Consulte também
 [Classe DeferrableEventArgs](../windows/deferrableeventargs-class.md)  
 [Método EventSource::InvokeAll](../windows/eventsource-invokeall-method.md)