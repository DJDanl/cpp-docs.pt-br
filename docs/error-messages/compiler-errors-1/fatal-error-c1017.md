---
title: Erro fatal C1017 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C1017
dev_langs:
- C++
helpviewer_keywords:
- C1017
ms.assetid: 5542e604-599d-4e36-8f83-1d454c5753c9
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 08433109a959b324621e9c837e67cf529d9f6fdb
ms.sourcegitcommit: 76b7653ae443a2b8eb1186b789f8503609d6453e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/04/2018
---
# <a name="fatal-error-c1017"></a>Erro fatal C1017
expressão constante inteira inválida  
  
 A expressão em um `#if` diretiva não existe ou não foi avaliada como uma constante.  
  
 Constantes definidas usando `#define` devem ter valores que são avaliadas como uma constante inteira se eles são usados em uma `#if`, `#elif`, ou `#else` diretiva.  
  
 O exemplo a seguir gera C1017:  
  
```  
// C1017.cpp  
#define CONSTANT_NAME "YES"  
#if CONSTANT_NAME   // C1017  
#endif  
```  
  
 Possível solução:  
  
```  
// C1017b.cpp  
// compile with: /c  
#define CONSTANT_NAME 1  
#if CONSTANT_NAME  
#endif  
```  
  
 Porque `CONSTANT_NAME` for avaliada como uma cadeia de caracteres e não um número inteiro, o `#if` diretiva gera um erro fatal C1017.  
  
 Em outros casos, o pré-processador avalia uma constante não definida como zero. Isso pode causar resultados não intencionais, conforme mostrado no exemplo a seguir. `YES` não está definida, portanto, ele será avaliado como zero. A expressão `#if` `CONSTANT_NAME` for avaliada como false e o código a ser usado em `YES` é removido do pré-processador. `NO` também é indefinido (zero), portanto `#elif` `CONSTANT_NAME==NO` for avaliada como true (`0 == 0`), fazendo com que o pré-processador deixar o código o `#elif` parte da instrução — exatamente o oposto do comportamento pretendido.  
  
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
  
 Para ver exatamente como o compilador trata as diretivas de pré-processador, use [/p](../../build/reference/p-preprocess-to-a-file.md), [/E](../../build/reference/e-preprocess-to-stdout.md), ou [/EP](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md).