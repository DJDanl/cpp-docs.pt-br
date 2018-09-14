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
ms.openlocfilehash: 1ec4e92774cdec75e47c07407ee72444a7486f7f
ms.sourcegitcommit: 92dbc4b9bf82fda96da80846c9cfcdba524035af
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/05/2018
ms.locfileid: "43751329"
---
# <a name="function-call-c"></a>Chamada de função (C)

Uma *chamada de função* é uma expressão que inclui o nome da função que está sendo chamada ou o valor de um ponteiro de função e, opcionalmente, os argumentos que estão sendo passados para a função.  
  
## <a name="syntax"></a>Sintaxe

*postfix-expression*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*postfix-expression*  **(**  *argument-expression-list*<sub>opt</sub> **)**  
  
*argument-expression-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*assignment-expression*<br/> &nbsp;&nbsp;&nbsp;&nbsp;*argument-expression-list* **,** *assignment-expression*  
  
O *postfix-expression* deve ser avaliado para um endereço de função (por exemplo, um identificador de função ou o valor de um ponteiro de função) e o *argument-expression-list* é uma lista de expressões (separadas por vírgulas) cujos valores (os "argumentos") são passados para a função. O argumento *argument-expression-list* pode estar vazio.  
  
Uma expressão de chamada de função tem o valor e o tipo do valor de retorno da função. Uma função não pode retornar um objeto do tipo de matriz. Se o tipo de retorno da função for `void` (isto é, a função foi declarada para nunca retornar um valor), a expressão de chamada de função também terá o tipo `void`. (Consulte [Chamadas de função](../c-language/function-calls.md) para obter mais informações.)  
  
## <a name="see-also"></a>Consulte também

[Operador de chamada de função: ()](../cpp/function-call-operator-parens.md)