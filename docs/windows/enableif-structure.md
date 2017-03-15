---
title: "Estrutura EnableIf | Microsoft Docs"
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
  - "internal/Microsoft::WRL::Details::EnableIf"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura EnableIf"
ms.assetid: 7825b283-e6b2-4f39-a4b9-c03bcd431b8e
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura EnableIf
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
template <  
   bool b,  
   typename T = void  
>  
  
struct EnableIf;  
template <  
   typename T  
>  
struct EnableIf<true, T>;  
```  
  
#### Parâmetros  
 `T`  
 Um tipo.  
  
 `b`  
 Uma expressão booliana.  
  
## Comentários  
 Define um membro de dados do tipo especificado por segundo parâmetro de modelo se o primeiro parâmetro do modelo avalia a `true`.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`type`|Se o parâmetro `b` do modelo avalia a `true`, a especialização parcial define o membro de dados `type` do tipo `T`.|  
  
## Hierarquia de Herança  
 `EnableIf`  
  
## Requisitos  
 **Cabeçalho:** internal.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)