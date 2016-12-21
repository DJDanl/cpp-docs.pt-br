---
title: "Operador HString::Operator!= | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HString::operator!="
dev_langs: 
  - "C++"
ms.assetid: dcdd2aca-e7d6-4bf1-b2de-03efbb430a93
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador HString::Operator!=
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Indica se os dois parâmetros não são iguais.  
  
## Sintaxe  
  
```cpp  
  
   inline bool operator!=(  
                  const HString& lhs,   
                  const HString& rhs) throw()  
  
inline bool operator!=(  
                  const HStringReference& lhs,   
                  const HString& rhs) throw()  
  
inline bool operator!=(  
                  const HString& lhs,   
                  const HStringReference& rhs) throw()  
  
inline bool operator!=(  
                  const HSTRING& lhs,   
                  const HString& rhs) throw()  
  
inline bool operator!=(  
                  const HString& lhs,   
                  const HSTRING& rhs) throw()  
  
```  
  
#### Parâmetros  
 `lhs`  
 O primeiro parâmetro a ser comparado.  `lhs` pode ser um objeto de HString ou de HStringReference, ou um identificador de HSTRING.  
  
 `rhs`  
 O segundo parâmetro a ser comparado.`rhs` pode ser um objeto de HString ou de HStringReference, ou um identificador de HSTRING.  
  
## Valor de retorno  
 `true` se os parâmetros de `lhs` e de `rhs` não forem iguais; caso contrário, `false`.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe HString](../windows/hstring-class.md)