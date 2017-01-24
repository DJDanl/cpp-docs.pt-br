---
title: "Classe de CComAutoCriticalSection | Microsoft Docs"
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
  - "ATL.CComAutoCriticalSection"
  - "ATL::CComAutoCriticalSection"
  - "CComAutoCriticalSection"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComAutoCriticalSection"
ms.assetid: 491a9d90-3398-4f90-88f5-fd2172a46b30
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComAutoCriticalSection
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

`CComAutoCriticalSection` fornece métodos para obter e definir a propriedade de um objeto de seção crítica.  
  
## Sintaxe  
  
```  
  
class CComAutoCriticalSection : public CComCriticalSection  
  
```  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComAutoCriticalSection::CComAutoCriticalSection](../Topic/CComAutoCriticalSection::CComAutoCriticalSection.md)|o construtor.|  
|[CComAutoCriticalSection::~CComAutoCriticalSection](../Topic/CComAutoCriticalSection::~CComAutoCriticalSection.md)|O destrutor.|  
  
## Comentários  
 `CComAutoCriticalSection` é semelhante [CComCriticalSection](../Topic/CComCriticalSection%20Class.md)classificar, a não ser que `CComAutoCriticalSection` automaticamente inicializar o objeto da seção crítica no construtor.  
  
 Normalmente, você usa `CComAutoCriticalSection` com o nome [AutoCriticalSection](../Topic/CComMultiThreadModel::AutoCriticalSection.md)de `typedef` .  Este referências de nome `CComAutoCriticalSection` quando [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) é usado.  
  
 Os métodos de `Init` e de `Term` de [CComCriticalSection](../Topic/CComCriticalSection%20Class.md) não estão disponíveis para usar esta classe.  
  
## Hierarquia de herança  
 [CComCriticalSection](../Topic/CComCriticalSection%20Class.md)  
  
 `CComAutoCriticalSection`  
  
## Requisitos  
 **Cabeçalho:** atlcore.h  
  
## Consulte também  
 [Classe de CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)   
 [Classe de CComCriticalSection](../Topic/CComCriticalSection%20Class.md)