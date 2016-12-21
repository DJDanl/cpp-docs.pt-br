---
title: "Classe de CHeapPtrBase | Microsoft Docs"
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
  - "ATL.CHeapPtrBase"
  - "ATL::CHeapPtrBase"
  - "CHeapPtrBase"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CHeapPtrBase"
ms.assetid: 501ac1b2-fb34-4c72-b7e6-a4f1fc8fda21
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CHeapPtrBase
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta forma a classe base para várias classes espertas do ponteiro de heap.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template <  
class T,  
class Allocator= CCRTAllocator   
> class CHeapPtrBase  
```  
  
#### Parâmetros  
 `T`  
 O tipo de objeto para ser armazenado no heap.  
  
 `Allocator`  
 A classe de alocação de memória para usar.  Rotinas de CRT são usadas por padrão para atribuir e liberar memória.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHeapPtrBase::~CHeapPtrBase](../Topic/CHeapPtrBase::~CHeapPtrBase.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHeapPtrBase::AllocateBytes](../Topic/CHeapPtrBase::AllocateBytes.md)|Chamar esse método para alocar memória.|  
|[CHeapPtrBase::Attach](../Topic/CHeapPtrBase::Attach.md)|Chamar esse método para executar a propriedade de um ponteiro existente.|  
|[CHeapPtrBase::Detach](../Topic/CHeapPtrBase::Detach.md)|Chamar este método para liberar a propriedade de um ponteiro.|  
|[CHeapPtrBase::Free](../Topic/CHeapPtrBase::Free.md)|Chamar esse método para excluir um objeto apontado pela `CHeapPtrBase`.|  
|[CHeapPtrBase::ReallocateBytes](../Topic/CHeapPtrBase::ReallocateBytes.md)|Chamar esse método para realocar a memória.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHeapPtrBase::operator T\*](../Topic/CHeapPtrBase::operator%20T*.md)|o operador cast.|  
|[CHeapPtrBase::operator &](../Topic/CHeapPtrBase::operator%20&.md)|Operador &.|  
|[CHeapPtrBase::operator \- \>](../Topic/CHeapPtrBase::operator%20-%3E.md)|O operador de ponteiro\-à\- membro.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CHeapPtrBase::m\_pData](../Topic/CHeapPtrBase::m_pData.md)|A variável de membro de dados do ponteiro.|  
  
## Comentários  
 Esta forma a classe base para várias classes espertas do ponteiro de heap.  Classes derivadas, por exemplo, [CHeapPtr](../../atl/reference/cheapptr-class.md) e [CComHeapPtr](../../atl/reference/ccomheapptr-class.md), adicione seus próprios operadores e construtores.  Consulte para essas classes exemplos de implementação.  
  
## Requisitos  
 **Cabeçalho:** atlcore.h  
  
## Consulte também  
 [Classe de CHeapPtr](../../atl/reference/cheapptr-class.md)   
 [Classe de CComHeapPtr](../../atl/reference/ccomheapptr-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)