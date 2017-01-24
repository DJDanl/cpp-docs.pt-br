---
title: "Estrutura RuntimeClassFlags | Microsoft Docs"
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
  - "implements/Microsoft::WRL::RuntimeClassFlags"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Estrutura RuntimeClassFlags"
ms.assetid: 7098d605-bd14-4d51-82f4-3def8296a938
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Estrutura RuntimeClassFlags
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Contém o tipo de uma instância de [RuntimeClass](../windows/runtimeclass-class.md).  
  
## Sintaxe  
  
```  
template <  
   unsigned int flags  
>  
struct RuntimeClassFlags;  
```  
  
#### Parâmetros  
 `flags`  
 Um valor [Enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md).  
  
## Membros  
  
### Constantes públicas  
  
|Nome|Descrição|  
|----------|---------------|  
|[Constante RuntimeClassFlags::value](../windows/runtimeclassflags-value-constant.md)|Contém um valor de [Enumeração RuntimeClassType](../windows/runtimeclasstype-enumeration.md) .|  
  
## Hierarquia de Herança  
 `RuntimeClassFlags`  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)