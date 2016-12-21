---
title: "Classe de CHeapPtr | Microsoft Docs"
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
  - "ATL::CHeapPtr"
  - "CHeapPtr"
  - "ATL.CHeapPtr"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CHeapPtr"
ms.assetid: e5c5bfd4-9bf1-4164-8a83-8155fe253454
caps.latest.revision: 20
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CHeapPtr
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma classe inteligente do ponteiro para gerenciar ponteiros da heap.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template<  
typename T,  
class Allocator= CCRTAllocator  
> class CHeapPtr :  
public CHeapPtrBase< T, Allocator>  
```  
  
#### Parâmetros  
 `T`  
 O tipo de objeto para ser armazenado no heap.  
  
 `Allocator`  
 A classe de alocação de memória para usar.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHeapPtr::CHeapPtr](../Topic/CHeapPtr::CHeapPtr.md)|o construtor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHeapPtr::Allocate](../Topic/CHeapPtr::Allocate.md)|Chamar esse método para alocar memória no heap para armazenar objetos.|  
|[CHeapPtr::Reallocate](../Topic/CHeapPtr::Reallocate.md)|Chamar esse método para realocar a memória no heap.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHeapPtr::operator \=](../Topic/CHeapPtr::operator%20=.md)|o operador de atribuição.|  
  
## Comentários  
 `CHeapPtr` é derivado de [CHeapPtrBase](../../atl/reference/cheapptrbase-class.md) e usa por padrão rotinas de CRT \(em [CCRTAllocator](../../atl/reference/ccrtallocator-class.md)\) para atribuir e liberar memória.  A classe [CHeapPtrList](../../atl/reference/cheapptrlist-class.md) pode ser usada para construir uma lista de ponteiros da heap.  Consulte também [CComHeapPtr](../../atl/reference/ccomheapptr-class.md), que usa rotinas de alocação de memória COM.  
  
## Hierarquia de herança  
 [CHeapPtrBase](../../atl/reference/cheapptrbase-class.md)  
  
 `CHeapPtr`  
  
## Requisitos  
 **Cabeçalho:** atlcore.h  
  
## Consulte também  
 [Classe de CHeapPtrBase](../../atl/reference/cheapptrbase-class.md)   
 [Classe de CCRTAllocator](../../atl/reference/ccrtallocator-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)