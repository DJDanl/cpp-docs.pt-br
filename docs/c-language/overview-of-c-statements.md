---
title: "Visão geral de instruções de C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
helpviewer_keywords:
- semicolon, in C statements
- statements, C
- semicolon
- statements, about statements
- Visual C, statements
ms.assetid: 0d49837a-5399-4881-b60c-af5f4e9720de
caps.latest.revision: 8
author: mikeblome
ms.author: mblome
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
ms.translationtype: Human Translation
ms.sourcegitcommit: a937c9d083a7e4331af63323a19fb207142604a0
ms.openlocfilehash: c47620477da286e8592c6742ceee6efb90143ec2
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="overview-of-c-statements"></a>Visão geral de instruções C
As instruções C consistem em tokens, expressões e outras instruções. Uma instrução que forma um componente de outra instrução chama-se o “corpo” da instrução pertinente. Cada tipo de instrução fornecido pela sintaxe a seguir será discutido nesta seção.  
  
## <a name="syntax"></a>Sintaxe  
 *statement*:  
 [labeled-statement](../c-language/goto-and-labeled-statements-c.md)  
  
 [compound-statement](../c-language/compound-statement-c.md)  
  
 [expression-statement](../c-language/expression-statement-c.md)  
  
 [selection-statement](../c-language/if-statement-c.md)  
  
 [iteration-statement](../c-language/do-while-statement-c.md)  
  
 [jump-statement](../c-language/break-statement-c.md)  
  
 [try-except-statement](../c-language/try-except-statement-c.md)  
  
 /* Específico da Microsoft \*/[try-finally-statement](../c-language/try-finally-statement-c.md) /\* Específico da Microsoft \*/  
  
 Geralmente, o corpo da instrução é uma “instrução composta”. Uma instrução composta consiste em outras instruções que podem incluir palavras-chave. A instrução compound é delimitada por chaves (**{ }**). Todas as outras instruções C terminam com ponto-e-vírgula (**;**). O ponto-e-vírgula é um terminador de instrução.  
  
 A instrução da expressão contém a expressão C que pode conter operadores aritméticos ou lógicos introduzidos em [Expressões e atribuições](../c-language/expressions-and-assignments.md). A instrução null é uma instrução vazia.  
  
 Qualquer instrução C pode começar com um rótulo de identificação que consiste em um nome e dois-pontos. Como apenas a instrução `goto` reconhece rótulos de instrução, os rótulos de instrução são explicados com `goto`. Consulte [as instruções goto e labeled](../c-language/goto-and-labeled-statements-c.md) para obter mais informações.  
  
## <a name="see-also"></a>Consulte também  
 [Instruções](../c-language/statements-c.md)
