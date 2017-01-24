---
title: "Classe de CAutoVectorPtr | Microsoft Docs"
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
  - "ATL::CAutoVectorPtr"
  - "ATL.CAutoVectorPtr"
  - "ATL.CAutoVectorPtr<T>"
  - "CAutoVectorPtr"
  - "ATL::CAutoVectorPtr<T>"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe de CAutoVectorPtr"
ms.assetid: 0030362b-6bc4-4a47-9b5b-3c3899dceab4
caps.latest.revision: 20
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe de CAutoVectorPtr
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Esta classe representa um objeto inteligente do ponteiro usando o vetor novo os operadores e delete.  
  
> [!IMPORTANT]
>  Essa classe e seus membros não podem ser usados em aplicativos executados em tempo de execução do windows.  
  
## Sintaxe  
  
```  
  
      template<  
typename T  
> class CAutoVectorPtr  
```  
  
#### Parâmetros  
 `T`  
 O tipo ponteiro.  
  
## Membros  
  
### Construtores public  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAutoVectorPtr::CAutoVectorPtr](../Topic/CAutoVectorPtr::CAutoVectorPtr.md)|o construtor.|  
|[CAutoVectorPtr::~CAutoVectorPtr](../Topic/CAutoVectorPtr::~CAutoVectorPtr.md)|O destrutor.|  
  
### Métodos públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAutoVectorPtr::Allocate](../Topic/CAutoVectorPtr::Allocate.md)|Chamar esse método para alocar memória exigida pela matriz de objetos apontados por `CAutoVectorPtr`.|  
|[CAutoVectorPtr::Attach](../Topic/CAutoVectorPtr::Attach.md)|Chamar esse método para executar a propriedade de um ponteiro existente.|  
|[CAutoVectorPtr::Detach](../Topic/CAutoVectorPtr::Detach.md)|Chamar este método para liberar a propriedade de um ponteiro.|  
|[CAutoVectorPtr::Free](../Topic/CAutoVectorPtr::Free.md)|Chamar esse método para excluir um objeto apontado pela `CAutoVectorPtr`.|  
  
### Operadores públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAutoVectorPtr::operator T \*](../Topic/CAutoVectorPtr::operator%20T%20*.md)|o operador cast.|  
|[CAutoVectorPtr::operator \=](../Topic/CAutoVectorPtr::operator%20=.md)|o operador de atribuição.|  
  
### Membros públicos de dados  
  
|Nome|Descrição|  
|----------|---------------|  
|[CAutoVectorPtr::m\_p](../Topic/CAutoVectorPtr::m_p.md)|A variável de membro de dados do ponteiro.|  
  
## Comentários  
 Essa classe fornece métodos para criar e gerenciar um ponteiro inteligente, que ajuda a proteger contra vazamentos de memória automaticamente liberando recursos quando ele está fora do escopo.  `CAutoVectorPtr` é semelhante a `CAutoPtr`, a única diferença é que que usa [vetor novo &#91;&#93;](../Topic/operator%20new\(%3Cnew%3E\).md) e [excluir vetorial &#91;&#93;](../Topic/operator%20delete\(%3Cnew%3E\).md) de `CAutoVectorPtr` atribuir e liberar a memória em vez de **new** C\+\+ e os operadores de **delete** .  Consulte [CAutoVectorPtrElementTraits](../../atl/reference/cautovectorptrelementtraits-class.md) se as classes de coleção de `CAutoVectorPtr` são necessárias.  
  
 [CAutoPtr](../../atl/reference/cautoptr-class.md) consulte para um exemplo de uso de uma classe inteligente do ponteiro.  
  
## Requisitos  
 **Cabeçalho:** atlbase.h  
  
## Consulte também  
 [Classe de CAutoPtr](../../atl/reference/cautoptr-class.md)   
 [Visão geral de classe](../../atl/atl-class-overview.md)