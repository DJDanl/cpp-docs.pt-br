---
title: "Classe accelerator_view_removed | Microsoft Docs"
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
  - "amprt/Concurrency::accelerator_view_removed"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe amprt/Concurrency::accelerator_view_removed"
ms.assetid: 262446de-311c-454e-a5ed-e2aaced0d88a
caps.latest.revision: 6
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe accelerator_view_removed
[!INCLUDE[vs2017banner](../../../assembler/inline/includes/vs2017banner.md)]

A exceção que é lançada quando uma chamada subjacente de DirectX falha devido ao mecanismo de detecção e de recuperação de tempo limite do Windows.  
  
## Sintaxe  
  
```  
class accelerator_view_removed : public runtime_exception;  
```  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor accelerator\_view\_removed::accelerator\_view\_removed](../Topic/accelerator_view_removed::accelerator_view_removed%20Constructor.md)|Inicializa uma nova instância da classe `accelerator_view_removed`.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método accelerator\_view\_removed::get\_view\_removed\_reason](../Topic/accelerator_view_removed::get_view_removed_reason%20Method.md)|Retorna um código de erro HRESULT que indica a causa da remoção do objeto `accelerator_view`.|  
  
## Hierarquia de Herança  
 `exception`  
  
 `runtime_exception`  
  
 `out_of_memory`  
  
## Requisitos  
 **Cabeçalho:** amprt.h  
  
 **Namespace:** Simultaneidade  
  
## Consulte também  
 [Namespace Concurrency \(C\+\+ AMP\)](../../../parallel/amp/reference/concurrency-namespace-cpp-amp.md)