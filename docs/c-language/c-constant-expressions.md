---
title: "Expressões de constante C | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- constant expressions, syntax
- constant expressions
- expressions [C++], constant
ms.assetid: d48a6c47-e44c-4be2-9c8b-7944c7ef8de7
caps.latest.revision: "10"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: e7b9beac4d87e0580279190cca005fc56c951af8
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="c-constant-expressions"></a>Expressões de constante C
Uma expressão constante é avaliada em tempo de compilação, não o tempo de execução, e pode ser usada em qualquer local em que uma constante pode ser usada. A expressão constante deve ser avaliada como uma constante que está no intervalo de valores representáveis para esse tipo. Os operandos de uma expressão constante podem ser constantes de inteiro, constantes de caractere, constantes de ponto flutuante, constantes de enumeração, conversões de tipos, expressões `sizeof` e outras expressões constantes.  
  
## <a name="syntax"></a>Sintaxe  
 *constant-expression*:  
 *conditional-expression*  
  
 *conditional-expression*:  
 *logical-OR-expression*  
  
 *logical-OR-expression* **?**  *expression* **:**  *conditional-expression*  
  
 *expression*:  
 *assignment-expression*  
  
 *expression* **,**  *assignment-expression*  
  
 *assignment-expression*:  
 *conditional-expression*  
  
 *unary-expression assignment-operator assignment-expression*  
  
 *assignment-operator*: one of  
 **= \*= /= %= += -= <\<= >>= &= ^= &#124;=**  
  
 Os não terminais para struct declarator, enumerator, direct declarator, direct-abstract declarator, and labeled statement contêm não terminais *constant-expression*.  
  
 Uma expressão constante integral deve ser usada para especificar o tamanho de um membro de campo de bit de uma estrutura, o valor de uma constante de enumeração, o tamanho de uma matriz ou o valor de uma constante **case**.  
  
 As expressões constantes usadas em políticas de pré-processador estão sujeitas às restrições adicionais. Em virtude disso, elas são conhecidas como “expressões constantes restritas.” Uma expressão constante restrita não pode conter expressões `sizeof`, constantes de enumeração, conversões de tipos para qualquer tipo ou constantes do tipo flutuantes. No entanto, ela pode conter a expressão constante especial `defined (`*identifier*`)`.  
  
## <a name="see-also"></a>Consulte também  
 [Operandos e expressões](../c-language/operands-and-expressions.md)