---
title: "Estrutura CloakedIid | Microsoft Docs"
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
  - "implements/Microsoft::WRL::CloakedIid"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura CloakedIid"
ms.assetid: 82e0e377-ca3a-46bc-b850-ae2c46c15bb5
caps.latest.revision: 3
caps.handback.revision: 3
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura CloakedIid
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Indica a modelos de RuntimeClass, de e de ChainInterfaces que implementa a interface especificada não está acessível na lista de IID.  
  
## Sintaxe  
  
```  
template<  
   typename T  
>  
struct CloakedIid : T;  
```  
  
#### Parâmetros  
 `T`  
 A interface que é oculta \(cloaked\).  
  
## Comentários  
 O seguinte é um exemplo de como CloakedIid é usado: `struct MyRuntimeClass : RuntimeClass<CloakedIid<IMyCloakedInterface>> {}`.  
  
## Hierarquia de Herança  
 `T`  
  
 `CloakedIid`  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)