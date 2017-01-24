---
title: "Classe de CSimpleMapEqualHelperFalse | Microsoft Docs"
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
  - "ATL::CSimpleMapEqualHelperFalse"
  - "CSimpleMapEqualHelperFalse"
  - "ATL.CSimpleMapEqualHelperFalse"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSimpleMapEqualHelperFalse"
ms.assetid: a873eea3-e130-45cc-a476-61ee79511c3b
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSimpleMapEqualHelperFalse
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é um auxiliar para a classe de [CSimpleMap](../../atl/reference/csimplemap-class.md) .  
  
## Sintaxe  
  
```  
  
template < class TKey, class TVal > class CSimpleMapEqualHelperFalse  
  
```  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleMapEqualHelperFalse::IsEqualKey](../Topic/CSimpleMapEqualHelperFalse::IsEqualKey.md)|\(Static\) Testa duas chaves para igualdade.|  
|[CSimpleMapEqualHelperFalse::IsEqualValue](../Topic/CSimpleMapEqualHelperFalse::IsEqualValue.md)|\(Estático\) Retorna falso.|  
  
## Comentários  
 Essa classe é um dos traços suplemento a classe de `CSimpleMap` .  Fornece um método para comparar dois elementos contidos no objeto de `CSimpleMap` , especificamente dois elementos de valor ou dois elementos chaves.  
  
 A comparação de valores sempre retornará falso, e além, chamará `ATLASSERT` com um argumento de falso se é referenciado nunca.  Em situações onde o teste de igualdade não é definido, suficientemente esta classe permite um mapa que contém pares chave\/valor para que funcionem corretamente para a maioria dos métodos mas falhar em para uma maneira muito definida para os métodos que dependem das comparações como [CSimpleMap::FindVal](../Topic/CSimpleMap::FindVal.md).  
  
## Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
## Consulte também  
 [Classe de CSimpleMapEqualHelper](../../atl/reference/csimplemapequalhelper-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)