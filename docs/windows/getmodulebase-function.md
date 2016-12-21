---
title: "Fun&#231;&#227;o GetModuleBase | Microsoft Docs"
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
  - "implements/Microsoft::WRL::GetModuleBase"
dev_langs: 
  - "C++"
ms.assetid: 123d3b14-2eaf-4e02-8dcd-b6567917c6a6
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Fun&#231;&#227;o GetModuleBase
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Recupera um ponteiro de [ModuleBase](../windows/modulebase-class.md) que permite que aumenta e decrescendo a contagem de referência de um objeto de [RuntimeClass](../windows/runtimeclass-class.md) .  
  
## Sintaxe  
  
```cpp  
inline Details::ModuleBase* GetModuleBase() throw()  
```  
  
## Valor de retorno  
 Um ponteiro para um objeto de `ModuleBase` .  
  
## Comentários  
 Essa função é usada internamente para aumentar e diminuir contagens de referência do objeto.  
  
 Você pode usar essa função para controlar contagens de referência e chamando [ModuleBase::IncrementObjectCount](../windows/modulebase-incrementobjectcount-method.md)[ModuleBase::DecrementObjectCount](../Topic/ModuleBase::DecrementObjectCount%20Method.md).  
  
## Requisitos  
 **Cabeçalho:** implements.h  
  
 **Namespace:** Microsoft::WRL  
  
## Consulte também  
 [Namespace Microsoft::WRL](../windows/microsoft-wrl-namespace.md)