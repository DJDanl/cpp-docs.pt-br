---
title: "Estrutura InterfaceList | Microsoft Docs"
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
  - "implements/Microsoft::WRL::Details::InterfaceList"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura InterfaceList"
ms.assetid: 6ec3228d-eb3e-4b7e-aef1-7dcf17bdf61a
caps.latest.revision: 5
caps.handback.revision: 5
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura InterfaceList
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Oferece suporte à infraestrutura de WRL e não deve ser usado diretamente no seu código.  
  
## Sintaxe  
  
```  
template <  
   typename T,  
   typename U  
>  
struct InterfaceList;  
```  
  
#### Parâmetros  
 `T`  
 Um nome da interface; a primeira interface na lista recursiva.  
  
 `U`  
 Um nome da interface; permanecer interfaces na lista recursiva.  
  
## Comentários  
 Usado para criar uma lista recursiva de interfaces.  
  
## Membros  
  
### Typedefs Públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|`FirstT`|Sinônimo para o parâmetro `T`do modelo.|  
|`RestT`|Sinônimo para o parâmetro `U`do modelo.|  
  
## Hierarquia de Herança  
 `InterfaceList`  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL::Details  
  
## Consulte também  
 [Namespace Microsoft::WRL::Details](../windows/microsoft-wrl-details-namespace.md)