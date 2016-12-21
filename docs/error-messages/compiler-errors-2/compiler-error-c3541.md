---
title: "Erro do Compilador C3541 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C3541"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3541"
ms.assetid: 252cfd4c-5fd2-415e-a17d-6b0c254350db
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3541
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo”: o typeid não pode ser aplicado a um tipo que contém o “automóvel”  
  
 O operador de [typeid](../Topic/typeid%20%20\(C++%20Component%20Extensions\).md) não pode ser aplicado ao tipo indicado porque contém o especificador de `auto` .  
  
## Exemplo  
 O exemplo a seguir gerencie C3541.  
  
```  
// C3541.cpp  
// Compile with /Zc:auto  
#include <typeinfo>  
int main() {  
    auto x = 123;  
    typeid(x);    // OK  
    typeid(auto); // C3541  
    return 0;  
}  
```  
  
## Consulte também  
 [Palavra\-chave auto](../../cpp/auto-keyword.md)   
 [\/Zc:auto \(deduzir tipo variável\)](../../build/reference/zc-auto-deduce-variable-type.md)   
 [typeid](../Topic/typeid%20%20\(C++%20Component%20Extensions\).md)