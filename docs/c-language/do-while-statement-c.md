---
title: Instrução do-while (C) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- do
- while
dev_langs:
- C++
helpviewer_keywords:
- do-while keyword [C]
ms.assetid: f2ac20a6-10c7-4a08-b5e3-c3b3639dbeaf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 0638e10d87ed52de49b027aea1e06bee838867d3
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="do-while-statement-c"></a>Instrução do-while (C)
A instrução `do-while` permite que você repita uma instrução ou instrução composta até que uma expressão especificada seja falsa.  
  
## <a name="syntax"></a>Sintaxe  
 *iteration-statement*:  
 **do**  *statement*  **while (**  *expression*  **) ;**  
  
 A *expressão* em uma instrução `do-while` é avaliada depois que o corpo do loop é executado. Portanto, o corpo do loop é sempre executado ao menos uma vez.  
  
 A *expressão* deve ter o tipo aritmético ou ponteiro. A execução procede da seguinte maneira:  
  
1.  O corpo da instrução é executado.  
  
2.  Em seguida, a *expressão* é avaliada. Se a *expressão* for falsa, a instrução `do-while` será finalizada e o controle será passado para a próxima instrução no programa. Se a *expressão* for verdadeira (diferente de zero), o processo será repetido, começando da etapa 1.  
  
 A instrução `do-while` também pode terminar quando uma instrução **break**, `goto` ou `return` for executada dentro do corpo da instrução.  
  
 Esse é um exemplo da instrução `do-while`:  
  
```  
do   
{  
    y = f( x );  
    x--;  
} while ( x > 0 );  
```  
  
 Nesta instrução `do-while`, as duas instruções `y = f( x );` e `x--;` são executadas, independente do valor inicial de `x`. Em seguida, `x > 0` é avaliado. Se `x` for maior que 0, o corpo da instrução é executado novamente e `x > 0` é reavaliado. O corpo da instrução é executado repetidamente, enquanto `x` permanece maior que 0. A execução da instrução `do-while` termina quando `x` se torna 0 ou negativo. O corpo do loop é executado ao menos uma vez.  
  
## <a name="see-also"></a>Consulte também  
 [Instrução do-while (C++)](../cpp/do-while-statement-cpp.md)