---
title: "Operador HStringReference::Operator&gt; | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HStringReference::operator<"
dev_langs: 
  - "C++"
ms.assetid: 55aa48e8-7c96-4123-9ebe-42b4cd8b9377
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador HStringReference::Operator&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Indica se o primeiro parâmetro for menor que o segundo parâmetro.  
  
## Sintaxe  
  
```cpp  
  
inline bool operator<(  
    const HStringReference& lhs,   
    const HStringReference& rhs) throw()  
  
```  
  
#### Parâmetros  
 `lhs`  
 O primeiro parâmetro a ser comparado.  `lhs` pode ser uma referência a um HStringReference.  
  
 `rhs`  
 O segundo parâmetro a ser comparado.  `rhs` pode ser uma referência a um HStringReference.  
  
## Valor de retorno  
 `true` se o parâmetro de `lhs` for menor que o parâmetro de `rhs` ; caso contrário, `false`.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe HStringReference](../windows/hstringreference-class.md)