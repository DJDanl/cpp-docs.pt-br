---
title: Chamada de função (C)
ms.date: 11/04/2016
helpviewer_keywords:
- function calls, C functions
- functions [C], calling
- function calls
ms.assetid: 35c66719-3f15-4d3b-97da-4e19dc97b308
ms.openlocfilehash: d22bdebc8fa832afb14a2cc09e6a441b7b9e8a5a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62233292"
---
# <a name="function-call-c"></a>Chamada de função (C)

Uma *chamada de função* é uma expressão que inclui o nome da função que está sendo chamada ou o valor de um ponteiro de função e, opcionalmente, os argumentos que estão sendo passados para a função.

## <a name="syntax"></a>Sintaxe

*expressão de sufixo*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*sufixo-expressão***(***opção de expressão de argumento-lista*<sub>opt</sub> **)**    

*argument-expression-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*expressão de atribuição*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*argumento-expressão-lista* **,** *expressão de atribuição*

O *postfix-expression* deve ser avaliado para um endereço de função (por exemplo, um identificador de função ou o valor de um ponteiro de função) e o *argument-expression-list* é uma lista de expressões (separadas por vírgulas) cujos valores (os "argumentos") são passados para a função. O argumento *argument-expression-list* pode estar vazio.

Uma expressão de chamada de função tem o valor e o tipo do valor de retorno da função. Uma função não pode retornar um objeto do tipo de matriz. Se o tipo de retorno da função for `void` (isto é, a função foi declarada para nunca retornar um valor), a expressão de chamada de função também terá o tipo `void`. (Consulte [Chamadas de função](../c-language/function-calls.md) para obter mais informações.)

## <a name="see-also"></a>Confira também

[Operador de chamada da função: ()](../cpp/function-call-operator-parens.md)
