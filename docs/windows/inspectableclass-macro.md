---
title: "Macro InspectableClass | Microsoft Docs"
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
  - "implements/Microsoft::WRL::InspectableClass"
dev_langs: 
  - "C++"
ms.assetid: ff390b26-58cc-424f-87ac-1fe3cc692b59
caps.latest.revision: 4
caps.handback.revision: 4
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Macro InspectableClass
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Defina o nível de confiança e o nome de classe de tempo de execução.  
  
## Sintaxe  
  
```cpp  
  
InspectableClass(  
   runtimeClassName,   
   trustLevel)  
  
```  
  
#### Parâmetros  
 `runtimeClassName`  
 O nome completo da classe textual de tempo de execução.  
  
 `trustLevel`  
 Um [TrustLevel](http://msdn.microsoft.com/library/br224625.aspx) dos valores enumerados.  
  
## Comentários  
 A macro de `InspectableClass` pode ser usada somente com tipos de [!INCLUDE[wrt](../atl/reference/includes/wrt_md.md)] .  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Classe RuntimeClass](../windows/runtimeclass-class.md)