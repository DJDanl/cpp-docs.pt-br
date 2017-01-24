---
title: "Classe de CSimpleMapEqualHelper | Microsoft Docs"
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
  - "CSimpleMapEqualHelper"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSimpleMapEqualHelper"
ms.assetid: 9bb2968a-d609-405c-8272-ff3b42df6164
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSimpleMapEqualHelper
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é um auxiliar para a classe de [CSimpleMap](../../atl/reference/csimplemap-class.md) .  
  
## Sintaxe  
  
```  
  
      template <  
   class TKey,  
   class TVal   
>  
class CSimpleMapEqualHelper  
```  
  
#### Parâmetros  
 `TKey`  
 o elemento chave.  
  
 `TVal`  
 O elemento de valor.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleMapEqualHelper::IsEqualKey](../Topic/CSimpleMapEqualHelper::IsEqualKey.md)|\(Static\) Testa duas chaves para igualdade.|  
|[CSimpleMapEqualHelper::IsEqualValue](../Topic/CSimpleMapEqualHelper::IsEqualValue.md)|\(Static\) Testa dois valores para igualdade.|  
  
## Comentários  
 Essa classe é um dos traços suplemento a classe de `CSimpleMap` .  Fornece métodos para comparar dois elementos de objeto de `CSimpleMap` \(especificamente, a chave e componentes de valor\) para igualdade.  Por padrão, as chaves e valores são comparados usando `operator==()`, mas se o mapa contém os tipos de dados complexos que não possui seu próprio operador de igualdade, essa classe pode ser substituída para fornecer funcionalidade adicional necessário.  
  
## Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
## Consulte também  
 [Classe de CSimpleMapEqualHelperFalse](../../atl/reference/csimplemapequalhelperfalse-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)