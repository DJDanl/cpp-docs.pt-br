---
title: "Erro do Compilador C3532 | Microsoft Docs"
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
  - "C3532"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3532"
ms.assetid: 51067853-eda8-4f59-86e8-8924e16d3a95
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3532
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“tipo”: uso incorreto de “automóvel”  
  
 O tipo indicado não pode ser declarado com a palavra\-chave de `auto` .  Por exemplo, você não pode usar a palavra\-chave de `auto` para declarar uma matriz ou um tipo de retorno do método.  
  
### Para corrigir este erro  
  
1.  Verifique se a expressão de inicialização gerencie um tipo válido.  
  
2.  Certifique\-se de que você não declara uma matriz ou um tipo de retorno do método.  
  
## Exemplo  
 O exemplo a seguir gerencie C3532 como a palavra\-chave de `auto` não pode declarar um tipo de retorno do método.  
  
```  
// C3532a.cpp  
// Compile with /Zc:auto  
auto f(){}   // C3532  
```  
  
## Exemplo  
 O exemplo a seguir gerencie C3532 como a palavra\-chave de `auto` não pode declarar uma matriz.  
  
```  
// C3532b.cpp  
// Compile with /Zc:auto  
int main()  
{  
   int x[5];  
   auto a[5];            // C3532  
   auto b[1][2];         // C3532  
   auto y[5] = x;        // C3532  
   auto z[] = {1, 2, 3}; // C3532  
   auto w[] = x;         // C3532  
   return 0;  
}  
```  
  
## Consulte também  
 [Palavra\-chave auto](../../cpp/auto-keyword.md)