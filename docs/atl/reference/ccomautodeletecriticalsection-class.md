---
title: "Classe de CComAutoDeleteCriticalSection | Microsoft Docs"
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
  - "ATL.CComAutoDeleteCriticalSection"
  - "CComAutoDeleteCriticalSection"
  - "ATL::CComAutoDeleteCriticalSection"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComAutoDeleteCriticalSection"
ms.assetid: 2396dbea-1c60-4841-b50e-c4e18af311a3
caps.latest.revision: 17
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComAutoDeleteCriticalSection
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para obter e definir a propriedade de um objeto de seção crítica.  
  
## Sintaxe  
  
```  
  
class CComAutoDeleteCriticalSection : public CComSafeDeleteCriticalSection  
  
```  
  
## Comentários  
 `CComAutoDeleteCriticalSection` deriva da classe [CComSafeDeleteCriticalSection](../Topic/CComSafeDeleteCriticalSection%20Class.md).  Em o entanto, `CComAutoDeleteCriticalSection` substitui o método de [termo](../Topic/CComSafeDeleteCriticalSection::Term.md) acesso de `private` , que força a limpeza de memória interna para ocorrer apenas quando as instâncias da classe sai do escopo são excluídas ou explicitamente de memória.  
  
 Esta classe não apresenta nenhum método adicional sobre sua classe base.  Consulte [CComSafeDeleteCriticalSection](../Topic/CComSafeDeleteCriticalSection%20Class.md) e [CComCriticalSection](../Topic/CComCriticalSection%20Class.md) para obter mais informações sobre classes auxiliares de seção crítica.  
  
## Hierarquia de herança  
 [CComCriticalSection](../Topic/CComCriticalSection%20Class.md)  
  
 [CComSafeDeleteCriticalSection](../Topic/CComSafeDeleteCriticalSection%20Class.md)  
  
 `CComAutoDeleteCriticalSection`  
  
## Requisitos  
 **Cabeçalho:** atlcore.h  
  
## Consulte também  
 [Classe de CComSafeDeleteCriticalSection](../Topic/CComSafeDeleteCriticalSection%20Class.md)   
 [Classe de CComCriticalSection](../Topic/CComCriticalSection%20Class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)