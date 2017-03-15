---
title: "Tempo de tratamento de exce&#231;&#245;es: um resumo | Microsoft Docs"
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
  - "tratamento de exceção, timing"
  - "manipuladores, ordem de execução"
  - "sequência"
  - "sequência, de manipuladores"
  - "SETJMP.H"
  - "SETJMPEX.H"
  - "tratamento estruturado de exceções, timing"
  - "manipuladores de encerramento, timing"
ms.assetid: 5d1da546-73fd-4673-aa1a-7ac0f776c420
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Tempo de tratamento de exce&#231;&#245;es: um resumo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Um manipulador de término é executado não importa como o bloco de instruções `__try` é terminado.  Entre as causas estão: saltar para fora do bloco `__try`, uma instrução `longjmp` que transfere o controle para fora do bloco e desenrolar a pilha devido à manipulação de exceções.  
  
> [!NOTE]
>  O Visual C\+\+ oferece suporte a dois formatos das instruções `setjmp` e `longjmp`.  A versão rápida ignora a manipulação de término, mas é mais eficiente.  Para usar essa versão, inclua o arquivo SETJMP.H.  A outra versão oferece suporte à manipulação de término conforme descrito no parágrafo anterior.  Para usar essa versão, inclua o arquivo SETJMPEX.H.  O aumento no desempenho da versão rápida depende da configuração de hardware.  
  
 O sistema operacional executa todos os manipuladores de término na ordem apropriada antes que qualquer outro código possa ser executado, incluindo o corpo de um manipulador de exceção.  
  
 Quando a causa da interrupção é uma exceção, o sistema deve primeiro executar a parte de filtro de um ou mais manipuladores de exceções antes de decidir o que terminar.  A ordem de eventos é:  
  
1.  Uma exceção é acionada.  
  
2.  O sistema verifica a hierarquia dos manipuladores de exceções ativas e executa o filtro do manipulador com a precedência mais alta, ou seja, o manipulador de exceção instalado mais recentemente e aninhado mais profundamente, em termos de blocos e chamadas de funções.  
  
3.  Se esse filtro passar o controle \(retornar 0\), o processo continuará até que seja encontrado um filtro que não passe o controle.  
  
4.  Se esse filtro retornar –1, a execução continuará onde a exceção foi acionada, e não ocorrerá término.  
  
5.  Se o filtro retornar 1, ocorrerão os seguintes eventos:  
  
    -   O sistema desenrola a pilha, limpando todos os quadros de pilha entre o código atualmente em execução \(onde a exceção foi acionada\) e o quadro de pilha que contém o manipulador de exceção que está recebendo o controle.  
  
    -   À medida que a pilha é desenrolada, cada manipulador de término na pilha é executado.  
  
    -   O próprio manipulador de exceção é executado.  
  
    -   O controle passa para a linha de código após o final desse manipulador de exceção.  
  
## Consulte também  
 [Escrevendo um manipulador de término](../cpp/writing-a-termination-handler.md)   
 [Tratamento de exceções estruturado](../cpp/structured-exception-handling-c-cpp.md)