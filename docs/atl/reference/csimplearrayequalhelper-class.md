---
title: "Classe de CSimpleArrayEqualHelper | Microsoft Docs"
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
  - "CSimpleArrayEqualHelper"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CSimpleArrayEqualHelper"
ms.assetid: a2b55d89-78c9-42ef-842c-5304c6d20ad6
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CSimpleArrayEqualHelper
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe é um auxiliar para a classe de [CSimpleArray](../../atl/reference/csimplearray-class.md) .  
  
## Sintaxe  
  
```  
  
      template <  
   class T   
>  
class CSimpleArrayEqualHelper  
```  
  
#### Parâmetros  
 `T`  
 Uma classe derivada.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CSimpleArrayEqualHelper::IsEqual](../Topic/CSimpleArrayEqualHelper::IsEqual.md)|Teste \(estático\) dois elementos de objeto de `CSimpleArray` para igualdade.|  
  
## Comentários  
 Essa classe é um dos traços suplemento a classe de `CSimpleArray` .  Fornece um método para comparar dois elementos armazenados em um objeto de `CSimpleArray` .  Por padrão, os elementos são comparados usando **operator\=\(\)**, mas se a matriz contém os tipos de dados complexos que não possui seu próprio operador de igualdade, você precisará substituir essa classe.  
  
## Requisitos  
 **Cabeçalho:** atlsimpcoll.h  
  
## Consulte também  
 [Classe de CSimpleArray](../../atl/reference/csimplearray-class.md)   
 [Classe de CSimpleArrayEqualHelperFalse](../Topic/CSimpleArrayEqualHelperFalse%20Class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)