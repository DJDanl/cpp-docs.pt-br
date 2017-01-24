---
title: "inline_recursion | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "inline_recursion_CPP"
  - "vc-pragma.inline_recursion"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "inline_recursion (pragma)"
  - "pragmas, inline_recursion"
ms.assetid: cfef5791-63b7-45ac-9574-623747b9b9c9
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# inline_recursion
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Controla a expansão embutida das chamadas de função diretas ou mutuamente recursivas.  
  
## Sintaxe  
  
```  
  
#pragma inline_recursion( [{on | off}] )  
```  
  
## Comentários  
 Use este pragma para controlar as funções marcadas como [embutida](../misc/inline-inline-forceinline.md) e [\_\_inline](../misc/inline-inline-forceinline.md) ou as funções que o compilador expandirá automaticamente sob a opção \/Ob2.  O uso desse pragma requer configuração da opção de compilador [\/Ob](../build/reference/ob-inline-function-expansion.md) de 1 ou 2.  O estado padrão para `inline_recursion` é desativado.  Este pragma entra em vigor na primeira chamada de função após o pragma ser percebido e não afeta a definição da função.  
  
 O pragma `inline_recursion` controla como as funções recursivas são expandidas.  Se `inline_recursion` está desativado e se uma chamada de função embutida chama a si mesma \(direta ou indiretamente\), a função será expandida apenas uma vez.  Se `inline_recursion` estiver ativado, a função será expandida várias vezes até atingir o valor definido com o pragma [inline\_depth](../preprocessor/inline-depth.md), o valor padrão para as funções recursivas que é definido pelo pragma `inline_depth` ou um limite de capacidade.  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)   
 [inline\_depth](../preprocessor/inline-depth.md)   
 [\/Ob \(expansão de função embutida\)](../build/reference/ob-inline-function-expansion.md)