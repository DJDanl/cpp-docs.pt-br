---
title: "C3851 de erro do compilador | Microsoft Docs"
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
  - "C3851"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3851"
ms.assetid: da30c21c-33aa-4439-8fb3-2f5021ea4985
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C3851 de erro do compilador
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'char': nome universal\-caracteres não é possível designar um caractere no conjunto de caracteres básicas  
  
 No código compilado c\+\+, você não pode usar um nome universal de caracteres que representa um caractere no conjunto de caracteres de origem básico fora de uma cadeia de caracteres ou literal de caractere. Para obter mais informações, consulte [Conjuntos de caracteres](../../cpp/character-sets2.md). No código compilado como C, você não pode usar um nome universal de caracteres para caracteres no intervalo 0x20\-0x7f, inclusive, exceto 0x24 \('$'\), 0x40 \(' @'\), ou 0x60 \(' '\).  
  
 Os exemplos a seguir geram C3851 e mostram como corrigi\-lo:  
  
```cpp  
// C3851.cpp  
int main()  
{  
   int test1_\u0041 = 0;   // C3851, \u0041 = 'A' in basic character set  
   int test2_A = 0;        // OK  
}  
```