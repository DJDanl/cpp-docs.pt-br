---
title: "Chamadas com um n&#250;mero vari&#225;vel de argumentos | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "reticências ..."
  - "argumentos [C++], Função "
  - "argumentos [C++], número variável de"
  - "reticências (...), número variável de argumentos"
  - "chamadas de função, argumentos"
  - "chamadas de função, número variável de argumentos"
  - "STDARGS.H"
  - "VARARGS.H"
ms.assetid: 8808fb26-4822-42f5-aba3-ac64b54e151b
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Chamadas com um n&#250;mero vari&#225;vel de argumentos
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma lista de parâmetros parcial pode ser finalizada pela notação de reticências, uma vírgula seguida de três pontos \(**, ...**\), para indicar que pode haver mais argumentos transmitidos à função, mas não são mais fornecidas informações sobre eles.  A verificação de tipo não é executada nesses argumentos.  Pelo menos um parâmetro deve preceder a notação de reticências, e a notação de reticências deve ser o token mais recente na lista de parâmetros.  Sem a notação de reticências, o comportamento de uma função é indefinido se receber parâmetros além daqueles declarados na lista de parâmetros.  
  
 Para chamar uma função com um número variável de argumentos, basta especificar qualquer número de argumentos na chamada de função.  Um exemplo é a função `printf` da biblioteca em tempo de execução C.  A chamada de função deve incluir um argumento para cada nome do tipo declarado na lista de parâmetros ou na lista de tipos de argumento.  
  
 Todos os argumentos especificados na chamada de função são colocados na pilha, a menos que a convenção de chamada `__fastcall` seja especificada.  O número de parâmetros declarados para a função determina quantos dos argumentos são obtidos da pilha e atribuídos aos parâmetros.  Você é responsável por recuperar todos os argumentos adicionais da pilha e por determinar quantos argumentos estão presentes.  O arquivo STDARG.H contém macros estilo ANSI para acessar argumentos das funções que possuem um número variável de argumentos.  Além disso, macros de estilo XENIX em VARARGS.H têm suporte.  
  
 Esse exemplo de declaração é para uma função que chama um número variável de argumentos:  
  
```  
int average( int first, ...);  
```  
  
## Consulte também  
 [Chamadas de função](../c-language/function-calls.md)