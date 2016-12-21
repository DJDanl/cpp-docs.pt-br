---
title: "Classe MakeAllocator | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Details::MakeAllocator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Classe MakeAllocator"
ms.assetid: a1114615-abd7-4a56-9bc3-750c118f0fa1
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Classe MakeAllocator
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
  
template<  
   typename T,  
   bool hasWeakReferenceSupport =   
         !__is_base_of(RuntimeClassFlags<InhibitWeakReference>,   
   T)> , T)> class MakeAllocator;  
  
template<  
   typename T  
>  
class MakeAllocator<T, false>;  
  
template<  
   typename T  
>  
class MakeAllocator<T, true>;  
```  
  
#### Parâmetros  
 `T`  
 Um nome de tipo.  
  
 `hasWeakReferenceSupport`  
 `true` para alocar memória para um objeto que da suporte a referências fracas; `false` para alocar memória para um objeto que não oferece suporte a referências fracas.  
  
## Comentários  
 Aloca memória para uma classe activatable, com ou sem suporte fraco de referência.  
  
 Substitua a classe de MakeAllocator para implementar um modelo de alocação de memória definido pelo usuário.  
  
 MakeAllocator normalmente é usado para evitar possíveis vazamentos de memória se lançar de um objeto durante a compilação.  
  
## Membros  
  
### Construtores Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Construtor MakeAllocator::MakeAllocator](../windows/makeallocator-makeallocator-constructor.md)|Inicializa uma nova instância da classe de MakeAllocator.|  
|[Destruidor MakeAllocator::~MakeAllocator](../Topic/MakeAllocator::~MakeAllocator%20Destructor.md)|Deinitializes a instância atual da classe de MakeAllocator.|  
  
### Métodos Públicos  
  
|Nome|Descrição|  
|----------|---------------|  
|[Método MakeAllocator::Allocate](../Topic/MakeAllocator::Allocate%20Method.md)|Aloca memória e a associa ao objeto atual de MakeAllocator.|  
|[Método MakeAllocator::Detach](../windows/makeallocator-detach-method.md)|Desassocia a memória alocada pelo método de [Aloque](../Topic/MakeAllocator::Allocate%20Method.md) do objeto atual de MakeAllocator.|  
  
## Hierarquia de Herança  
 `MakeAllocator`  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)