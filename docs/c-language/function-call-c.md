---
title: Chamada de função (C) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- function calls, C functions
- functions [C], calling
- function calls
ms.assetid: 35c66719-3f15-4d3b-97da-4e19dc97b308
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 49c9483cb6e556d5a8b174377c0dad666834c9e5
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="function-call-c"></a>Chamada de função (C)
Uma “chamada de função” é uma expressão que inclui o nome da função que está sendo chamada ou o valor de um ponteiro de função e, opcionalmente, os argumentos que estão sendo passados para a função.  
  
## <a name="syntax"></a>Sintaxe  
 *postfix-expression*:  
 *postfix-expression*  **(**  *argument-expression-list* opt **)**  
  
 *argument-expression-list*:  
 *assignment-expression*  
  
 *argument-expression-list*  **,**  *assignment-expression*  
  
 O *postfix-expression* deve ser avaliado para um endereço de função (por exemplo, um identificador de função ou o valor de um ponteiro de função) e o *argument-expression-list* é uma lista de expressões (separadas por vírgulas) cujos valores (os "argumentos") são passados para a função. O argumento *argument-expression-list* pode estar vazio.  
  
 Uma expressão de chamada de função tem o valor e o tipo do valor de retorno da função. Uma função não pode retornar um objeto do tipo de matriz. Se o tipo de retorno da função for `void` (isto é, a função foi declarada para nunca retornar um valor), a expressão de chamada de função também terá o tipo `void`. (Consulte [Chamadas de função](../c-language/function-calls.md) para obter mais informações.)  
  
## <a name="see-also"></a>Consulte também  
 [Operador de chamada de função: ()](../cpp/function-call-operator-parens.md)