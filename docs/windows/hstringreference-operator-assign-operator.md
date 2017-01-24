---
title: "Operador HStringReference::Operator= | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HStringReference::operator="
dev_langs: 
  - "C++"
ms.assetid: ea100ed3-e566-4c9e-b6a8-f296088dea9c
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador HStringReference::Operator=
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Move o valor de outro objeto HStringReference para o objeto HStringReference atual.  
  
## Sintaxe  
  
```cpp  
HStringReference& operator=(HStringReference&& other) throw()  
```  
  
#### Parâmetros  
 `other`  
 Um objeto existente de HStringReference.  
  
## Comentários  
 O valor do objeto existente de `other` é copiado para o objeto atual de HStringReference, e o objeto de `other` é destruído em.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe HStringReference](../windows/hstringreference-class.md)