---
title: "restrict | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "restrict"
  - "restrict_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __declspec [C++], restrict"
  - "palavra-chave restrict __declspec"
ms.assetid: f39cf632-68d8-4362-a497-2d4c15693689
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# restrict
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

**Específico da Microsoft**  
  
 Aplicado a uma declaração ou a uma definição de função que retorna um tipo de ponteiro e diz ao compilador que a função retorna um objeto sem alias com nenhum outro ponteiro.  
  
## Sintaxe  
  
```  
__declspec(restrict) return_type f();  
```  
  
## Comentários  
 O compilador propagará `__declspec(restrict)`.  Por exemplo, a função de CRT `malloc` é decorada com `__declspec(restrict)` e, como consequência, os ponteiros inicializados para locais de memória com `malloc` também são pressupostos como sem alias.  
  
 O compilador não verifica se o ponteiro realmente não possui alias.  É responsabilidade do desenvolvedor assegurar que o programa não coloque alias em um ponteiro com o modificador `restrict __declspec`.  
  
 Para a semântica semelhante em variáveis, consulte [\_\_restrict](../cpp/extension-restrict.md).  
  
## Exemplo  
 Consulte [noalias](../cpp/noalias.md) para obter um exemplo usando `restrict`.  
  
 Para obter informações sobre a palavra\-chave restrita que é parte do C\+\+ AMP, consulte [restrita \(C\+\+ AMP\)](../cpp/restrict-cpp-amp.md).  
  
 **FIM de Específico da Microsoft**  
  
## Consulte também  
 [\_\_declspec](../cpp/declspec.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)