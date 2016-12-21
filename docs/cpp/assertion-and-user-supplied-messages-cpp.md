---
title: "Asser&#231;&#227;o e mensagens fornecidas pelo usu&#225;rio (C++) | Microsoft Docs"
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
helpviewer_keywords: 
  - "#error%2C assert%2C static_assert [C++]"
  - "mensagens fornecidas pelo usuário [C++], tempo de compilação"
  - "mensagens fornecidas pelo usuário [C++], tempo de pré-processador"
  - "mensagens fornecidas pelo usuário [C++], tempo de execução"
ms.assetid: ebf7d885-61c8-4233-b0ae-1c9a38e0f385
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Asser&#231;&#227;o e mensagens fornecidas pelo usu&#225;rio (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A linguagem C\+\+ dá suporte a três mecanismos de tratamento de erro que o ajudam a depurar seu aplicativo: [a política \#error](../preprocessor/hash-error-directive-c-cpp.md), a palavra\-chave [static\_assert](../cpp/static-assert.md) e a macro [Macro Assert, \_wassert de declaração](../c-runtime-library/reference/assert-macro-assert-wassert.md).  Todos os três mecanismos emitem mensagens de erro e dois também testam asserções de software.  Uma asserção de software especifica uma condição que você espera ser verdadeira \(true\) em um ponto específico de seu programa.  Se uma asserção de tempo de compilação falhar, o compilador emite uma mensagem de diagnóstico e um erro de compilação.  Se uma asserção de tempo de execução falhar, o sistema operacional emite uma mensagem de diagnóstico e fecha seu aplicativo.  
  
## Comentários  
 O tempo de vida do seu aplicativo consiste de uma fase de pré\-processamento, compilação e de tempo de execução.  Cada mecanismo de tratamento de erro acessa as informações de depuração disponíveis durante uma dessas fases.  Para depurar efetivamente, selecione o mecanismo que fornece as informações adequadas sobre essa fase:  
  
-   A [política \#error](../preprocessor/hash-error-directive-c-cpp.md) entra em vigor no momento de pré\-processamento.  Ela incondicionalmente emite uma mensagem especificada pelo usuário e causa a falha da compilação com um erro.  A mensagem pode conter texto que é manipulado pelas políticas do pré\-processador, mas nenhuma expressão resultante é avaliada.  
  
-   A declaração [static\_assert](../cpp/static-assert.md) é aplicada no tempo de compilação.  Ela testa uma asserção de software que é representada por uma expressão integral especificada pelo usuário que possa ser convertida em Booliano.  Se a expressão for avaliada como zero \(false\), o compilador emitirá uma mensagem especificada pelo usuário e a compilação falhará com um erro.  
  
     A declaração `static_assert` é especialmente útil para depuração de modelos porque os argumentos de modelo podem ser incluídos na expressão especificada pelo usuário.  
  
-   A macro [Macro Assert, \_wassert de declaração](../c-runtime-library/reference/assert-macro-assert-wassert.md) é aplicada no tempo de execução.  Ela avalia uma expressão especificada pelo usuário e se o resultado for zero, o sistema emitirá uma mensagem de diagnóstico e fechará seu aplicativo.  Muitas outras macros, como[\_ASSERT](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md) e `_ASSERTE` lembram a esta macro mas emitem mensagens de diagnóstico definidas pelo sistema ou pelo usuário diferentes.  
  
## Consulte também  
 [Diretiva \#error](../preprocessor/hash-error-directive-c-cpp.md)   
 [Macro Assert, \_wassert de declaração](../c-runtime-library/reference/assert-macro-assert-wassert.md)   
 [Assert, asserte, \_ASSERT\_EXPR macros](../Topic/_ASSERT,%20_ASSERTE,%20_ASSERT_EXPR%20Macros.md)   
 [static\_assert](../cpp/static-assert.md)   
 [Macro \_STATIC\_ASSERT](../c-runtime-library/reference/static-assert-macro.md)   
 [Modelos](../Topic/Templates%20\(C++\).md)