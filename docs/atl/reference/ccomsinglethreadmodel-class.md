---
title: "Classe de CComSingleThreadModel | Microsoft Docs"
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
  - "ATL.CComSingleThreadModel"
  - "CComSingleThreadModel"
  - "ATL::CComSingleThreadModel"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CComSingleThreadModel"
  - "aplicativos de thread única"
  - "aplicativos de thread única, ATL"
ms.assetid: e5dc30c7-405a-4ba4-8ae9-51937243fce8
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CComSingleThreadModel
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece métodos para incrementar e diminuir o valor de uma variável.  
  
## Sintaxe  
  
```  
  
class CComSingleThreadModel  
  
```  
  
## Membros  
  
### Typedefs público  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComSingleThreadModel::AutoCriticalSection](../Topic/CComSingleThreadModel::AutoCriticalSection.md)|Classe [CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md)das referências.|  
|[CComSingleThreadModel::CriticalSection](../Topic/CComSingleThreadModel::CriticalSection.md)|Classe `CComFakeCriticalSection`das referências.|  
|[CComSingleThreadModel::ThreadModelNoCS](../Topic/CComSingleThreadModel::ThreadModelNoCS.md)|Referencia `CComSingleThreadModel`.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CComSingleThreadModel::Decrement](../Topic/CComSingleThreadModel::Decrement.md)|Diminui o valor da variável especificada.  Essa implementação não é segura.|  
|[CComSingleThreadModel::Increment](../Topic/CComSingleThreadModel::Increment.md)|Incrementa o valor da variável especificada.  Essa implementação não é segura.|  
  
## Comentários  
 `CComSingleThreadModel` fornece métodos para incrementar e diminuir o valor de uma variável.  A o contrário de [CComMultiThreadModel](../../atl/reference/ccommultithreadmodel-class.md) e de [CComMultiThreadModelNoCS](../Topic/CComMultiThreadModelNoCS%20Class.md), esses métodos não são thread\-safe.  
  
 Normalmente, você usa `CComSingleThreadModel` com um dos dois nomes de `typedef` , [CComObjectThreadModel](../Topic/CComObjectThreadModel.md) ou [CComGlobalsThreadModel](../Topic/CComGlobalsThreadModel.md).  A classe referenciada por cada `typedef` depende do modelo de segmentação usado, conforme mostrado na tabela seguinte:  
  
|typedef|Único modelo de threads|Modelo de threads Apartment|Modelo de segmentação livre|  
|-------------|-----------------------------|---------------------------------|---------------------------------|  
|`CComObjectThreadModel`|S|S|M|  
|`CComGlobalsThreadModel`|S|M|M|  
  
 S\=`CComSingleThreadModel`; M\=`CComMultiThreadModel`  
  
 `CComSingleThreadModel` próprio define três nomes de `typedef` .  Referências `CComSingleThreadModel`de`ThreadModelNoCS` .  `AutoCriticalSection` e a referência de `CriticalSection`[CComFakeCriticalSection](../../atl/reference/ccomfakecriticalsection-class.md)classe, que fornece os métodos vazios associados a obtenção e liberar a propriedade de uma seção crítica.  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)