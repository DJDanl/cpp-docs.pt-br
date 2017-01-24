---
title: "Estrutura ImplementsHelper | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Details::ImplementsHelper"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura ImplementsHelper"
ms.assetid: b857ba80-81bd-4e53-92b6-210991954243
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura ImplementsHelper
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
template <  
   typename RuntimeClassFlagsT,  
   typename ILst,  
   bool IsDelegateToClass  
>  
friend struct Details::ImplementsHelper;  
```  
  
#### Parâmetros  
 `RuntimeClassFlagsT`  
 Um campo dos sinalizadores que especifica um ou vários enumeradores de [RuntimeClassType](../windows/runtimeclasstype-enumeration.md) .  
  
 `ILst`  
 Uma lista de IDs da interface.  
  
 `IsDelegateToClass`  
 Especifique `true` se a instância atual das ferramentas é uma classe base da primeira ID de interface em `ILst`; caso contrário, `false`.  
  
## Comentários  
 Ajuda implementam a estrutura de [Implementa](../Topic/Implements%20Structure.md) .  
  
 Este modelo passa por uma lista de interfaces e adicioná\-las como classes base, e como as informações necessárias para habilitar QueryInterface.  
  
## Membros  
  
## Hierarquia de Herança  
 `ImplementsHelper`  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Reference \(Windows Runtime Library\)](http://msdn.microsoft.com/pt-br/00000000-0000-0000-0000-000000000000)   
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)