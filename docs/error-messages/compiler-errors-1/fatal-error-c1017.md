---
title: "Erro fatal C1017 | Microsoft Docs"
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
  - "C1017"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C1017"
ms.assetid: 5542e604-599d-4e36-8f83-1d454c5753c9
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro fatal C1017
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

expressão de inteiro constante inválido  
  
 A expressão em uma política de `#if` não existia nem avaliada como uma constante.  
  
 Constantes definidas usando `#define` devem ter os valores que são avaliadas como uma constante inteira se forem usadas em `#if`, em `#elif`, ou na política de `#else` .  
  
 O seguinte exemplo gera C1017:  
  
```  
// C1017.cpp  
#define CONSTANT_NAME "YES"  
#if CONSTANT_NAME   // C1017  
#endif  
```  
  
 Solução possível:  
  
```  
// C1017b.cpp  
// compile with: /c  
#define CONSTANT_NAME 1  
#if CONSTANT_NAME  
#endif  
```  
  
 Como `CONSTANT_NAME` for avaliada como uma cadeia de caracteres e não em um inteiro, a política de `#if` gerencia o erro fatal C1017.  
  
 Em outros casos, o pré\-processador avalia uma constante não como zero.  Isso pode causar resultados não intencionais, conforme mostrado no exemplo a seguir.  `YES` é indefinido, o que é avaliada como zero.  A expressão `#if` `CONSTANT_NAME` for avaliada como false e o código a ser usada em `YES` é removido por pré\-processador.  `NO` também é indefinido \(zero\), portanto `#elif` `CONSTANT_NAME==NO` avalia para retificar \(`0 == 0`\), fazendo com que o pré\-processador deixe o código na parte de `#elif` da instrução — exatamente o oposto de comportamento pretendido.  
  
```  
// C1017c.cpp  
// compile with: /c  
#define CONSTANT_NAME YES  
#if CONSTANT_NAME  
   // Code to use on YES...  
#elif CONSTANT_NAME==NO  
   // Code to use on NO...  
#endif  
```  
  
 Para ver exatamente como o compilador trata políticas de pré\-processador, use [\/P](../../build/reference/p-preprocess-to-a-file.md), [\/E](../../build/reference/e-preprocess-to-stdout.md), ou [\/EP](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md).