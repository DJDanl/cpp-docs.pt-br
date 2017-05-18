---
title: Erro fatal C1017 | Documentos do Microsoft
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-tools
ms.tgt_pltfrm: 
ms.topic: error-reference
f1_keywords:
- C1017
dev_langs:
- C++
helpviewer_keywords:
- C1017
ms.assetid: 5542e604-599d-4e36-8f83-1d454c5753c9
caps.latest.revision: 8
author: corob-msft
ms.author: corob
manager: ghogen
translation.priority.ht:
- cs-cz
- de-de
- es-es
- fr-fr
- it-it
- ja-jp
- ko-kr
- pl-pl
- pt-br
- ru-ru
- tr-tr
- zh-cn
- zh-tw
ms.translationtype: Machine Translation
ms.sourcegitcommit: 3168772cbb7e8127523bc2fc2da5cc9b4f59beb8
ms.openlocfilehash: 40ec8c04960e091198cb2a81605f377273c3de45
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="fatal-error-c1017"></a>Erro fatal C1017
expressão de constante inteira inválida  
  
 A expressão em um `#if` diretiva não existe ou não avaliada como uma constante.  
  
 Constantes definidas usando `#define` devem ter valores que são avaliadas como uma constante de inteiro se eles forem usados em uma `#if`, `#elif`, ou `#else` diretiva.  
  
 O exemplo a seguir gera C1017:  
  
```  
// C1017.cpp  
#define CONSTANT_NAME "YES"  
#if CONSTANT_NAME   // C1017  
#endif  
```  
  
 Resolução possível:  
  
```  
// C1017b.cpp  
// compile with: /c  
#define CONSTANT_NAME 1  
#if CONSTANT_NAME  
#endif  
```  
  
 Porque `CONSTANT_NAME` for avaliada como uma cadeia de caracteres e não um inteiro, o `#if` diretiva gera erro fatal C1017.  
  
 Em outros casos, o pré-processador avalia uma constante não definida como zero. Isso pode causar resultados inesperados, como mostrado no exemplo a seguir. `YES`é indefinido, portanto, ela é avaliada como zero. A expressão `#if` `CONSTANT_NAME` for avaliada como false e o código a ser usado em `YES` é removido pelo pré-processador. `NO`também é indefinido (zero), então `#elif` `CONSTANT_NAME==NO` for avaliada como true (`0 == 0`), fazendo com que o pré-processador deixar o código o `#elif` parte da instrução — exatamente o oposto do comportamento pretendido.  
  
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
  
 Para ver exatamente como o compilador trata as diretivas do pré-processador, use [/p](../../build/reference/p-preprocess-to-a-file.md), [/E](../../build/reference/e-preprocess-to-stdout.md), ou [/EP](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md).
