---
title: "Classe de CAutoPtrArray | Microsoft Docs"
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
  - "ATL::CAutoPtrArray<E>"
  - "CAutoPtrArray"
  - "ATL::CAutoPtrArray"
  - "ATL.CAutoPtrArray<E>"
  - "ATL.CAutoPtrArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAutoPtrArray"
ms.assetid: 880a70da-8c81-4427-8ac6-49aa8d424244
caps.latest.revision: 21
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAutoPtrArray
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece os métodos úteis quando construir uma matriz de ponteiros inteligentes.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template<  
typename E  
>  
class CAutoPtrArray : public CAtlArray<  
ATL::CAutoPtr< E>,  
CAutoPtrElementTraits< E>  
>  
```  
  
#### Parâmetros  
 `E`  
 O tipo ponteiro.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAutoPtrArray::CAutoPtrArray](../Topic/CAutoPtrArray::CAutoPtrArray.md)|o construtor.|  
  
## Comentários  
 Essa classe fornece um construtor e derivado de [CAtlArray](../../atl/reference/catlarray-class.md) métodos e de [CAutoPtrElementTraits](../Topic/CAutoPtrElementTraits%20Class.md) para ajudar à criação de um objeto da classe de coleção que armazena ponteiros inteligentes.  
  
 Para obter mais informações, consulte [Classes de coleção de ATL](../../atl/atl-collection-classes.md).  
  
## Hierarquia de herança  
 `CAtlArray`  
  
 `CAutoPtrArray`  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [Classe de CAtlArray](../../atl/reference/catlarray-class.md)   
 [Classe de CAutoPtrElementTraits](../Topic/CAutoPtrElementTraits%20Class.md)   
 [Classe de CAutoPtrList](../../atl/reference/cautoptrlist-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)