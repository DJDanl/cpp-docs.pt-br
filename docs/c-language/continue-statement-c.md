---
title: "Instrução continue (C) | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-language
ms.tgt_pltfrm: 
ms.topic: article
f1_keywords:
- continue
dev_langs:
- C++
helpviewer_keywords:
- loop structures, continue keyword
- continue keyword [C]
ms.assetid: 969f293a-45fe-48a7-b4c6-287ba27a631d
caps.latest.revision: 7
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
ms.openlocfilehash: d440b10fe77a5cf79efc660b2be6cbe548375015
ms.contentlocale: pt-br
ms.lasthandoff: 02/25/2017

---
# <a name="continue-statement-c"></a>Instrução continue (C)
A instrução `continue` transmite o controle para a próxima iteração da instrução `do`, `for` ou `while` delimitadora mais próxima em que aparece, ignorando qualquer instrução restante no corpo da instrução `do`, `for` ou `while`.  
  
## <a name="syntax"></a>Sintaxe  
 `jump-statement`:  
 `continue;`  
  
 A próxima iteração de uma instrução `do`, `for` ou `while` é determinada da seguinte maneira:  
  
-   Em uma instrução `do` ou `while`, a próxima iteração começa com a reavaliação da expressão da instrução `do` ou `while`.  
  
-   Uma instrução `continue` em uma instrução `for` causa a avaliação da expressão de loop da instrução `for`. Então, o compilador reavalia a expressão condicional e, dependendo do resultado, finaliza ou itera o corpo da instrução. Consulte [A instrução for](../c-language/for-statement-c.md) para obter mais informações sobre a instrução `for` e seus não terminais.  
  
 Esse é um exemplo da instrução `continue`:  
  
```  
while ( i-- > 0 )   
{  
    x = f( i );  
    if ( x == 1 )  
        continue;  
    y += x * x;  
}  
```  
  
 Nesse exemplo, o corpo da instrução é executado enquanto `i` é maior que 0. Primeiro, `f(i)` é atribuído a `x`; então, se `x` for igual a 1, a instrução `continue` será executada. O restante das instruções no corpo é ignorado, e a execução será retomada na parte superior do loop com a avaliação do teste de loop.  
  
## <a name="see-also"></a>Consulte também  
 [Instrução continue](../cpp/continue-statement-cpp.md)
