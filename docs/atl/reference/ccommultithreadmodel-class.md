---
title: "Classe de CComMultiThreadModel | Microsoft Docs"
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
  - "CComMultiThreadModel"
  - "ATL.CComMultiThreadModel"
  - "ATL::CComMultiThreadModel"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "ATL, multithreading"
  - "Classe de CComMultiThreadModel"
  - "threading [ATL]"
ms.assetid: db8f1662-2f7a-44b3-b341-ffbfb6e422a3
caps.latest.revision: 21
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComMultiThreadModel
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

`CComMultiThreadModel` fornece métodos para incrementar thread\-safe e diminuir o valor de uma variável.  
  
## Sintaxe  
  
```  
  
class CComMultiThreadModel  
  
```  
  
## Membros  
  
### Typedefs público  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComMultiThreadModel::AutoCriticalSection](../Topic/CComMultiThreadModel::AutoCriticalSection.md)|Classe [CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md)das referências.|  
|[CComMultiThreadModel::CriticalSection](../Topic/CComMultiThreadModel::CriticalSection.md)|Classe [CComCriticalSection](../Topic/CComCriticalSection%20Class.md)das referências.|  
|[CComMultiThreadModel::ThreadModelNoCS](../Topic/CComMultiThreadModel::ThreadModelNoCS.md)|Classe [CComMultiThreadModelNoCS](../Topic/CComMultiThreadModelNoCS%20Class.md)das referências.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComMultiThreadModel::Decrement](../Topic/CComMultiThreadModel::Decrement.md)|\(Estático\) Diminui o valor da variável especificada de uma maneira segura.|  
|[CComMultiThreadModel::Increment](../Topic/CComMultiThreadModel::Increment.md)|\(Static\) Incrementa o valor da variável especificada de uma maneira segura.|  
  
## Comentários  
 Normalmente, você usa `CComMultiThreadModel` com um dos dois nomes de `typedef` , [CComObjectThreadModel](../Topic/CComObjectThreadModel.md) ou [CComGlobalsThreadModel](../Topic/CComGlobalsThreadModel.md).  A classe referenciada por cada `typedef` depende do modelo de segmentação usado, conforme mostrado na tabela seguinte:  
  
|typedef|Segmentação única|Thread Apartment|Segmentação livre|  
|-------------|-----------------------|----------------------|-----------------------|  
|`CComObjectThreadModel`|S|S|M|  
|`CComGlobalsThreadModel`|S|M|M|  
  
 S\=`CComSingleThreadModel`; M\=`CComMultiThreadModel`  
  
 `CComMultiThreadModel` próprio define três nomes de `typedef` .  `AutoCriticalSection` e `CriticalSection` referenciam as classes que fornecem métodos para obter e definir a propriedade de uma seção crítica.  Classe [CComMultiThreadModelNoCS](../Topic/CComMultiThreadModelNoCS%20Class.md)de referências de`ThreadModelNoCS` .  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Classe de CComSingleThreadModel](../../atl/reference/ccomsinglethreadmodel-class.md)   
 [Classe de CComAutoCriticalSection](../../atl/reference/ccomautocriticalsection-class.md)   
 [Classe de CComCriticalSection](../Topic/CComCriticalSection%20Class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)