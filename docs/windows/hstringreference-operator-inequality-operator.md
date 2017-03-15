---
title: "Operador HStringReference::Operator!= | Microsoft Docs"
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
  - "corewrappers/Microsoft::WRL::Wrappers::HStringReference::operator!="
dev_langs: 
  - "C++"
ms.assetid: 01ab6691-1fc7-4feb-85f0-fe795593a160
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador HStringReference::Operator!=
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Indica se os dois parâmetros não são iguais.  
  
## Sintaxe  
  
```cpp  
  
inline bool operator==(  
               const HStringReference& lhs,   
               const HSTRING& rhs) throw()  
  
inline bool operator!=(  
               const HStringReference& lhs,   
               const HStringReference& rhs) throw()  
  
inline bool operator!=(  
               const HSTRING& lhs,   
               const HStringReference& rhs) throw()  
  
inline bool operator!=(  
               const HStringReference& lhs,   
               const HSTRING& rhs) throw()  
  
```  
  
#### Parâmetros  
 `lhs`  
 O primeiro parâmetro a ser comparado.  `lhs` pode ser um objeto de HStringReference ou um identificador de HSTRING.  
  
 `rhs`  
 O segundo parâmetro a ser comparado.  `rhs` pode ser um objeto de HStringReference ou um identificador de HSTRING.  
  
## Valor de retorno  
 `true` se os parâmetros de `lhs` e de `rhs` não forem iguais; caso contrário, `false`.  
  
## Requisitos  
 **Cabeçalho:** corewrappers.h  
  
 **Namespace:** Microsoft::WRL::Wrappers  
  
## Consulte também  
 [Classe HStringReference](../windows/hstringreference-class.md)