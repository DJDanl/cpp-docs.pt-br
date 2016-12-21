---
title: "Estrutura MixIn | Microsoft Docs"
ms.custom: ""
ms.date: "12/16/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "reference"
f1_keywords: 
  - "implements/Microsoft::WRL::MixIn"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura MixIn"
ms.assetid: 47e2df9b-3a2e-4ae8-8ba3-b1fd3aa73566
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura MixIn
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Assegura que uma classe de tempo de execução deriva das interfaces de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] , se houver, e COM clássico interfaces.  
  
## Sintaxe  
  
```  
template<  
   typename Derived,  
   typename MixInType,  
   bool hasImplements = __is_base_of(Details::ImplementsBase,  
   MixInType)  
>  
struct MixIn;  
```  
  
#### Parâmetros  
 `Derived`  
 Um tipo derivado da estrutura de [Implementa](../Topic/Implements%20Structure.md) .  
  
 `MixInType`  
 Um tipo base.  
  
 `hasImplements`  
 `true` se `MixInType` é derivado da implementação atual o tipo de base; `false` de outra forma.  
  
## Comentários  
 Se uma classe é derivada do [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e a classe COM interfaces, a lista de declaração de classe deve primeiro listar as interfaces de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] e em qualquer COM clássico interfaces.  MixIn garante que as interfaces são especificadas na ordem correta.  
  
## Hierarquia de Herança  
 `MixIn`  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)