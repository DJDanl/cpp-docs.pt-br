---
title: "alloc_text | Microsoft Docs"
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
  - "vc-pragma.alloc_text"
  - "alloc_text_CPP"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "alloc_text (pragma)"
  - "pragmas, alloc_text"
ms.assetid: 1fd7be18-e4f7-4f70-b079-6326f72b871a
caps.latest.revision: 6
caps.handback.revision: 6
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# alloc_text
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Nomeia a seção de código onde as definições de função especificadas devem residir.  O pragma deve estar entre um declarador de função e a definição de função para as funções nomeadas.  
  
## Sintaxe  
  
```  
  
#pragma alloc_text( "  
textsection  
", function1, ... )  
```  
  
## Comentários  
 O pragma **alloc\_text** não trata funções de membro C\+\+ ou funções sobrecarregadas.  É aplicável somente a funções declaradas com vinculação C – ou seja, funções declaradas com a especificação de vínculo **extern "C"**.  Se você tentar usar esse pragma em uma função com vinculação C\+\+, um erro do compilador será gerado.  
  
 Como o tratamento de função usando `__based` não tem suporte, especificar locais de seção requer o uso do pragma **alloc\_text**.  O nome especificado por *textsection* deve ser colocado entre aspas duplas.  
  
 O pragma **alloc\_text** deve aparecer depois que as declarações de qualquer uma das funções especificadas e antes das definições dessas funções.  
  
 As funções referenciadas em um pragma **alloc\_text** devem ser definidas no mesmo módulo do pragma.  Se isso não for feito e uma função indefinida for compilada posteriormente em uma seção de texto diferente, o erro poderá ou não ser detectado.  Embora o programa seja executado corretamente no geral, a função não será alocada nas seções desejadas.  
  
 Outras limitações de **alloc\_text** são:  
  
-   Não pode ser usado dentro de uma função.  
  
-   Deve ser usado depois que a função é declarada, mas antes de a função ser definida.  
  
## Consulte também  
 [Diretivas Pragma e a palavra\-chave \_\_Pragma](../preprocessor/pragma-directives-and-the-pragma-keyword.md)