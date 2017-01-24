---
title: "Enumera&#231;&#227;o queuing_mode | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "amprt/Concurrency::queuing_mode"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Enumeração queuing_mode"
ms.assetid: 8c641054-906d-40b3-bbb4-f62af9356a14
caps.latest.revision: 12
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Enumera&#231;&#227;o queuing_mode
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

Especifica os modos de fila que são suportados no acelerador.  
  
## Sintaxe  
  
```  
enum queuing_mode;  
```  
  
## Membros  
  
### Valores  
  
|Nome|Descrição|  
|----------|---------------|  
|`queuing_mode_immediate`|Um modo de fila que especifica que todos os comandos, por exemplo, [Função parallel\_for\_each \(C\+\+ AMP\)](../Topic/parallel_for_each%20Function%20\(C++%20AMP\).md), sejam enviados para o dispositivo do acelerador correspondente assim que retornarem para o chamador.|  
|`queuing_mode_automatic`|Um modo de fila que especifica que os comandos sejam colocados em fila acima em uma fila de comando que corresponde ao objeto [accelerator\_view](../Topic/accelerator_view%20Class.md).  Os comandos são enviados para o dispositivo quando [accelerator\_view::flush](../Topic/accelerator_view::flush%20Method.md) é chamado.|  
  
## Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Simultaneidade  
  
## Consulte também  
 [Namespace Concurrency \(C\+\+ AMP\)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)