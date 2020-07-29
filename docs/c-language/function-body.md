---
title: Corpo da função
ms.date: 11/04/2016
helpviewer_keywords:
- functions [C], syntax
- variables, function syntax
- function definitions, function body
- function body
ms.assetid: f7e74822-fac8-4dc8-8f3a-2b1611da4640
ms.openlocfilehash: 2ae73ab4ca91e06e3b6cd41166a8d05ae0857e4a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229695"
---
# <a name="function-body"></a>Corpo da função

Um *corpo de função* é uma instrução composta que contém as instruções que especificam o que a função faz.

## <a name="syntax"></a>Sintaxe

*função-definição*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-specifiers*<sub>opt</sub> *attribute-seq*<sub>opt</sub> *declarator* *declaration-list*<sub>opt</sub> *compound-statement*

/\**Attribute-Seq* é específico da Microsoft\*/

*instrução composta*:/ \* o corpo da função\*/<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**{** *declaração-lista*de instruções<sub>opt</sub> *-lista*<sub>opt</sub> **}**

Variáveis declaradas em um corpo de função, conhecidas como *variáveis locais*, têm **`auto`** a classe de armazenamento, a menos que especificado de outra forma. Quando a função for chamada, o armazenamento é criado para as variáveis locais e as inicializações de local são executadas. O controle de execução passa para a primeira instrução na *instrução composta* e continua até que uma **`return`** instrução seja executada ou o final do corpo da função seja encontrado. O controle então retorna para o ponto no qual a função foi chamada.

Uma **`return`** instrução que contém uma expressão deve ser executada se a função for retornar um valor. O valor de retorno de uma função será indefinido se nenhuma **`return`** instrução for executada ou se a **`return`** instrução não incluir uma expressão.

## <a name="see-also"></a>Confira também

[Definições de função C](../c-language/c-function-definitions.md)
