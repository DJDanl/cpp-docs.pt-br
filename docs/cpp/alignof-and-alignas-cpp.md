---
title: "alignof e alignas (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
ms.assetid: 1d18aa8a-9621-4fb5-86e5-4cc86d5187f4
caps.latest.revision: 2
caps.handback.revision: 2
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# alignof e alignas (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O `alignas` especificador de tipo é uma maneira padrão de C\+\+ portátil, para especificar um alinhamento personalizado de variáveis e tipos definidos pelo usuário.  O `alignof` operador da mesma forma é uma forma padrão e portátil para obter o alinhamento de um tipo especificado ou uma variável.  
  
## Exemplo  
 Você pode usar `alignas` em uma classe, fez sua investida ou união, ou em membros individuais.  Quando vários `alignas` especificadores forem encontrados, o compilador escolherá aquela mais rígida, \(aquele com o maior valor\).  
  
```  
struct alignas(16) Bar  
{      
    int i;       // 4 bytes  
    int n;      // 4 bytes  
    alignas(4) char arr[3];  
    short s;          // 2 bytes  
};  
…  
cout << alignof(Bar) << endl; // output: 16  
  
```  
  
## Consulte também  
 [Alinhamento](../cpp/alignment-cpp-declarations.md)