---
title: "Operador HString::Operator&gt; | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HString::operator<"
dev_langs: 
  - "C++"
ms.assetid: 48a051cb-4609-42be-b48c-d35fc99d1eab
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador HString::Operator&gt;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Indica se o primeiro parâmetro for menor que o segundo parâmetro.  
  
## Sintaxe  
  
```cpp  
  
inline bool operator<(  
    const HString& lhs,   
    const HString& rhs) throw()  
  
```  
  
#### Parâmetros  
 `lhs`  
 O primeiro parâmetro a ser comparado.  `lhs` pode ser uma referência a um HString.  
  
 `rhs`  
 O segundo parâmetro a ser comparado.  `rhs` pode ser uma referência a um HString.  
  
## Valor de retorno  
 `true` se o parâmetro de `lhs` for menor que o parâmetro de `rhs` ; caso contrário, `false`.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe HString](../windows/hstring-class.md)