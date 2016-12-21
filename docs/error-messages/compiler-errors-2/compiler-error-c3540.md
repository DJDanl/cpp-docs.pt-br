---
title: "Erro do Compilador C3540 | Microsoft Docs"
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
  - "C3540"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3540"
ms.assetid: 3c0c959c-e3b7-40eb-b922-ccac44bd9d85
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3540
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo”: o sizeof não pode ser aplicado a um tipo que contém o “automóvel”  
  
 O operador de [sizeof](../../cpp/sizeof-operator.md) não pode ser aplicado ao tipo indicado porque contém o especificador de `auto` .  
  
## Exemplo  
 O exemplo a seguir gerencie C3540.  
  
```  
// C3540.cpp  
// Compile with /Zc:auto  
int main() {  
    auto x = 123;  
    sizeof(x);    // OK  
    sizeof(auto); // C3540  
    return 0;  
}  
```  
  
## Consulte também  
 [Palavra\-chave auto](../../cpp/auto-keyword.md)   
 [\/Zc:auto \(deduzir tipo variável\)](../../build/reference/zc-auto-deduce-variable-type.md)   
 [Operador sizeof](../../cpp/sizeof-operator.md)