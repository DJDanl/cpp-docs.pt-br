---
title: "Usando setjmp/longjmp | Microsoft Docs"
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
  - "longjmp"
  - "setjmp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "tratamento de exceção de C++, funções setjmp/longjmp"
  - "função longjmp em programas C++"
  - "Função setjmp"
  - "Função setjmp, programas C++"
  - "SETJMP.H"
  - "SETJMPEX.H"
ms.assetid: 96be8816-f6f4-4567-9a9c-0c3c720e37c5
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Usando setjmp/longjmp
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Quando [setjmp](../c-runtime-library/reference/setjmp.md) e [longjmp](../c-runtime-library/reference/longjmp.md) são usados juntos, eles fornecem uma maneira de executar um `goto` não local.  Normalmente, eles são usados para transmitir o controle de execução para o código de recuperação ou de tratamento de erros em uma rotina anteriormente chamada anteriormente sem usar as convenções padrão de chamada ou de retorno.  
  
> [!CAUTION]
>  No entanto, como `setjmp` e `longjmp` não suportam semânticas de objeto de C\+\+ e como podem prejudicar o desempenho evitando a otimização em variáveis locais, recomendamos que você não os utilize nos programas do C\+\+.  Recomendamos que você use construções `try`\/`catch` em vez disso.  
  
 Se você decidir usar `setjmp`\/`longjmp` em um programa de C\+\+, inclua também SETJMP.H ou SETJMPEX.H para garantir a interação correta entre as funções e a manipulação de exceção do C\+\+.  Se você usar [\/EH](../build/reference/eh-exception-handling-model.md) para compilar, os destruidores de objetos locais serão chamados durante o desenrolamento da pilha.  Se você usar **\/EHs** para compilar e uma das funções chamar uma função que usa [nothrow](../Topic/nothrow%20\(C++\).md) e a função que usa `nothrow` chamar `longjmp`, o desenrolamento do destruidor poderá não ocorrer, dependendo do otimizador.  
  
 No código portátil, quando um `goto` não local que chama `longjmp` é executado, a destruição correta dos objetos baseados em quadro pode não ser confiável.  
  
## Consulte também  
 [Combinando C \(estrutura\) e exceções de C\+\+](../Topic/Mixing%20C%20\(Structured\)%20and%20C++%20Exceptions.md)