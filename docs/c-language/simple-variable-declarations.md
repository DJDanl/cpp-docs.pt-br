---
title: Declarações de variável simples
ms.date: 11/04/2016
helpviewer_keywords:
- untyped variables
- declaring variables, simple
ms.assetid: b07adf9d-9e79-4b64-8a34-e6fe1c7eccec
ms.openlocfilehash: 27710dabe512332564ee557a9d022457d9fddc5c
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62158230"
---
# <a name="simple-variable-declarations"></a>Declarações de variável simples

A declaração de uma variável simples, a forma mais simples de um declarador direto, especifica o nome e o tipo da variável. Ela também especifica a classe e o tipo de dados de armazenamento da variável.

Classes ou tipos de armazenamento (ou ambos) são necessários em declarações de variável. As variáveis sem tipo (como `var;`) geram avisos.

## <a name="syntax"></a>Sintaxe

*Declarador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*pointer*<sub>opt</sub> *direct-declarator*

*Declarador direto*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*ID*

*identificador*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*Não dígito*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identifier* *nondigit*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*identifier* *digit*

Para tipos de aritmética, de estrutura, de união, enumerações e tipos nulos, e para os tipos representados por nomes `typedef`, os declaradores simples podem ser usados em uma declaração desde que o especificador de tipo forneça todas as informações de tipo. Tipos de ponteiro, matriz e função requerem declaradores mais complicados.

Você pode usar uma lista de identificadores separados por vírgulas (**,**) para especificar diversas variáveis na mesma declaração. Todas as variáveis definidas na declaração têm o mesmo tipo base. Por exemplo: 

```C
int x, y;        /* Declares two simple variables of type int */
int const z = 1; /* Declares a constant value of type int */
```

As variáveis `x` e `y` podem conter qualquer valor no conjunto definido pelo tipo `int` para uma implementação específica. O objeto simples `z` é inicializado com o valor 1 e não pode ser modificado.

Se a declaração de `z` fosse para uma variável estática não inicializada ou estava no escopo do arquivo, ela receberia um valor inicial de 0, e esse valor não seria modificável.

```C
unsigned long reply, flag; /* Declares two variables
                              named reply and flag     */
```

Neste exemplo, as duas variáveis, `reply` e `flag`, têm o tipo `unsigned long` e valores integrais não assinados.

## <a name="see-also"></a>Confira também

[Declaradores e declarações variáveis](../c-language/declarators-and-variable-declarations.md)
