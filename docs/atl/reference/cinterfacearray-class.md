---
title: "Classe de CInterfaceArray | Microsoft Docs"
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
  - "ATL.CInterfaceArray"
  - "CInterfaceArray"
  - "ATL::CInterfaceArray"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CInterfaceArray"
ms.assetid: 1f29cf66-a086-4a7b-b6a8-64f73da39f79
caps.latest.revision: 18
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CInterfaceArray
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Essa classe fornece os métodos úteis quando construir uma matriz de ponteiros da interface COM.  
  
## Sintaxe  
  
```  
  
      template<  
   class I,  
   const IID* piid = & __uuidof( I )  
>  
class CInterfaceArray : public CAtlArray<  
   ATL::CComQIPtr< I, piid >,  
   CComQIPtrElementTraits< I, piid >  
>  
```  
  
#### Parâmetros  
 `I`  
 Uma interface COM que especifica o tipo de ponteiro para ser armazenado.  
  
 `piid`  
 Um ponteiro para o IID de `I`.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CInterfaceArray::CInterfaceArray](../Topic/CInterfaceArray::CInterfaceArray.md)|O construtor para a matriz da interface.|  
  
## Comentários  
 Essa classe fornece um construtor e métodos derivados para criar uma matriz de ponteiros da interface COM.  Use [CInterfaceList](../Topic/CInterfaceList%20Class.md) quando uma lista é necessária.  
  
 Para obter mais informações, consulte [Classes de coleção de ATL](../../atl/atl-collection-classes.md).  
  
## Hierarquia de herança  
 `CAtlArray`  
  
 `CInterfaceArray`  
  
## Requisitos  
 **Cabeçalho:** atlcoll.h  
  
## Consulte também  
 [Classe de CAtlArray](../../atl/reference/catlarray-class.md)   
 [Classe de CComQIPtr](../../atl/reference/ccomqiptr-class.md)   
 [Classe de CComQIPtrElementTraits](../Topic/CComQIPtrElementTraits%20Class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)