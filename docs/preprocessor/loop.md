---
title: "loop | Microsoft Docs"
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
  - "loop_CPP"
  - "vc-pragma.loop"
dev_langs: 
  - "C++"
ms.assetid: 6d5bb428-cead-47e7-941d-7513bbb162c7
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# loop
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Controla como o código de loop deverá ser considerado pelo paralelizador automático, e\/ou exclui um loop de ser considerado pelo vetorizador automático.  
  
## Sintaxe  
  
```  
  
#pragma loop( hint_parallel(n) )  
```  
  
```  
  
#pragma loop( no_vector )  
```  
  
```  
  
#pragma loop( ivdep )  
```  
  
#### Parâmetros  
 `hint_parallel(` `n` `)`  
 Indica para o compilador que esse loop deverá ser paralelizado por `n` threads, onde `n` é uma literal de inteiro positivo ou zero.  Se `n` for zero, o número máximo de threads será usado em tempo de execução.  Esta é uma dica para o compilador, não um comando, e não há nenhuma garantia de que o loop será paralelizado.  Se o loop tiver dependências de dados ou problemas estruturais \- por exemplo, se o loop for armazenado em um escalar usado além do corpo do loop \-, o loop não será paralelizado.  
  
 O compilador ignorará esta opção, a não ser que a opção de compilador [\/Qpar](../Topic/-Qpar%20\(Auto-Parallelizer\).md) seja especificada.  
  
 `no_vector`  
 Por padrão, o vetorizador automático está ativo e tentará vetorizar todos os loops que, em sua avaliação, beneficiam\-se disso.  Especifique este pragma para desabilitar o vetorizador automático para o loop que se segue a ele.  
  
 `ivdep`  
 Indica que o compilador deverá ignorar as dependências de vetor para esse loop.  Use isto em conjunto com `hint_parallel`.  
  
## Comentários  
 Para usar o pragma `loop`, coloque\-o imediatamente antes de uma definição de loop, não dentro dela.  O pragma entra em vigor para o escopo do loop que se segue a ele.  Você pode aplicar vários pragmas a um loop, em qualquer ordem, mas deve declarar cada um em uma instrução pragma separada.  
  
## Consulte também  
 [Paralelização automática e vetorização automática](../parallel/auto-parallelization-and-auto-vectorization.md)   
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)