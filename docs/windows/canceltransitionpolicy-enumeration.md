---
title: "Enumera&#231;&#227;o CancelTransitionPolicy | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "module/Microsoft::WRL::CancelTransitionPolicy::TransitionFromCanceled"
  - "module/Microsoft::WRL::CancelTransitionPolicy::RemainCanceled"
  - "module/Microsoft::WRL::CancelTransitionPolicy"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Enumeração CancelTransitionPolicy"
ms.assetid: 5de49f7d-e5e3-43e9-bbca-666caf226cef
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Enumera&#231;&#227;o CancelTransitionPolicy
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Indica como a tentativa de uma operação assíncrona de transição para um estado concluído ou terminal de erro deve se comportar em relação a um estado cancelado solicitado pelo.  
  
## Sintaxe  
  
```  
enum CancelTransitionPolicy;  
```  
  
## Membros  
  
### Valores  
  
|Nome|Descrição|  
|----------|---------------|  
|`RemainCanceled`|Se a operação assíncrona está em um estado cancelado solicitado pelo, isso indicará que ficará em estado cancelado diferentemente da transição para um terminal concluído ou estado do erro.|  
|`TransitionFromCanceled`|Se a operação assíncrona está em um estado cancelado solicitado pelo, isso indicará que o estado deve fazer a transição do que o estado cancelado e estado concluído ou terminal de erro conforme determinado pela chamada que utiliza esse sinalizador.|  
  
## Requisitos  
 **Cabeçalho:** async.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)