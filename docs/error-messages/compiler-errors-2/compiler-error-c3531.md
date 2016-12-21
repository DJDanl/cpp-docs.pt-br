---
title: "Erro do Compilador C3531 | Microsoft Docs"
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
  - "C3531"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3531"
ms.assetid: 2bdb9fdc-9ddf-403e-8b92-02763d434487
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3531
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

símbolo “”: um símbolo cujo tipo contém o “automóvel” deve ter um inicializador  
  
 A variável especificada não tiver uma expressão de inicializador.  
  
### Para corrigir este erro  
  
1.  Especifique uma expressão de inicializador, como uma atribuição simples que usa a sintaxe do sinal de igual, quando declara a variável.  
  
## Exemplo  
 O exemplo a seguir gerencie C3531 como as variáveis `x1`, `y1, y2, y3`, e `z2` não são inicializados.  
  
```  
// C3531.cpp  
// Compile with /Zc:auto  
int main()  
{  
   auto x1;                  // C3531  
   auto y1, y2, y3;          // C3531  
   auto z1 = 1, z2, z3 = -1; // C3531  
   return 0;  
}  
```  
  
## Consulte também  
 [Palavra\-chave auto](../../cpp/auto-keyword.md)