---
title: "Classe de CComSimpleThreadAllocator | Microsoft Docs"
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
  - "CComSimpleThreadAllocator"
  - "ATL::CComSimpleThreadAllocator"
  - "ATL.CComSimpleThreadAllocator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Segmentos de ATL"
  - "Segmentos de ATL, alocando"
  - "Classe de CComSimpleThreadAllocator"
  - "threading [ATL], selecionando segmentos"
ms.assetid: 66b2166a-8c50-49fd-b8e4-7f293470327d
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComSimpleThreadAllocator
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe gerencia a seleção da thread para a classe `CComAutoThreadModule`.  
  
## Sintaxe  
  
```  
  
class CComSimpleThreadAllocator  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComSimpleThreadAllocator::GetThread](../Topic/CComSimpleThreadAllocator::GetThread.md)|Seleciona um segmento.|  
  
## Comentários  
 `CComSimpleThreadAllocator` gerencia a seleção da thread para [CComAutoThreadModule](../../atl/reference/ccomautothreadmodule-class.md).  `CComSimpleThreadAllocator::GetThread` fornece um ciclo simplesmente através de cada segmento e retorna a seguir na seqüência.  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Classe de CComApartment](../../atl/reference/ccomapartment-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)