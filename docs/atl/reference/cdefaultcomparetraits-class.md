---
title: "Classe de CDefaultCompareTraits | Microsoft Docs"
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
  - "ATL.CDefaultCompareTraits<T>"
  - "ATL::CDefaultCompareTraits"
  - "ATL.CDefaultCompareTraits"
  - "ATL::CDefaultCompareTraits<T>"
  - "CDefaultCompareTraits"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CDefaultCompareTraits"
ms.assetid: a17e2740-e7b4-48f2-aeb7-c80ce84b63f7
caps.latest.revision: 19
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CDefaultCompareTraits
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece funções padrão de comparação do elemento.  
  
## Sintaxe  
  
```  
  
      template<  
   typename T  
>  
class CDefaultCompareTraits  
```  
  
#### Parâmetros  
 `T`  
 O tipo de dados a serem armazenados na coleção.  
  
## Membros  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CDefaultCompareTraits::CompareElements](../Topic/CDefaultCompareTraits::CompareElements.md)|\(Static\) Chamar essa função para comparar dois elementos para igualdade.|  
|[CDefaultCompareTraits::CompareElementsOrdered](../Topic/CDefaultCompareTraits::CompareElementsOrdered.md)|\(Static\) Chamar essa função para determinar o maior elemento e vez.|  
  
## Comentários  
 Essa classe contém duas funções estáticas para comparar elementos armazenados em um objeto da classe de coleção.  Essa classe é utilizada por [classe de CDefaultElementTraits](../../atl/reference/cdefaultelementtraits-class.md).  
  
 Para obter mais informações, consulte [Classes de coleção de ATL](../../atl/atl-collection-classes.md).  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [Visão geral de classe](../../atl/atl-class-overview.md)