---
title: "M&#233;todo DeferrableEventArgs::InvokeAllFinished | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
dev_langs: 
  - "C++"
ms.assetid: 86b45205-3edb-4134-9cd0-ed7a7b4c3b1a
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# M&#233;todo DeferrableEventArgs::InvokeAllFinished
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Chamado para indicar que todo o processamento para manipular um evento adiado foi concluído.  
  
## Sintaxe  
  
```cpp  
void InvokeAllFinished()  
```  
  
## Comentários  
 Você deve chamar esse método após as chamadas de código\-fonte do evento [InvokeAll](../windows/eventsource-invokeall-method.md).  Chamar esse método impede que outros adiamentos de que está sendo feito e força o manipulador de conclusão para executar se nenhuma adiamentos foram realizados.  
  
 Para obter um exemplo de código, consulte [Classe DeferrableEventArgs](../windows/deferrableeventargs-class.md).  
  
## Requisitos  
 **Cabeçalho:** event.h  
  
 **Namespace:** Microsoft:: wrl  
  
## Consulte também  
 [Classe DeferrableEventArgs](../windows/deferrableeventargs-class.md)   
 [Método EventSource::InvokeAll](../windows/eventsource-invokeall-method.md)