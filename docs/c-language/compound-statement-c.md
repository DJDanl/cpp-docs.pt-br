---
title: Instrução composta (C)
ms.date: 11/04/2016
helpviewer_keywords:
- compound statements
- statements, compound
ms.assetid: 32d1bf86-cbbc-42a9-ba3a-1be1c6c7754c
ms.openlocfilehash: 93f7fd24049c744874fb0ab3bda37eedef3a139a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87200576"
---
# <a name="compound-statement-c"></a>Instrução composta (C)

Uma instrução composta (também chamada de "bloquear") normalmente aparece como o corpo de outra instrução, como a **`if`** instrução. [Declarações e tipos](../c-language/declarations-and-types.md) descreve o formato e o significado das declarações que podem aparecer no cabeçalho de uma instrução composta.

## <a name="syntax"></a>Sintaxe

*instrução composta*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;**{** *declaração-lista*de instruções<sub>opt</sub> *-lista*<sub>opt</sub> **}**

*declaration-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*mesma*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*declaration-list* *declaration*

*statement-list*:<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*privacidade*<br/>
&nbsp;&nbsp;&nbsp;&nbsp;*statement-list* *statement*

Se houver declarações, elas deverão vir antes de todas as instruções. O escopo de cada identificador declarado no início de uma instrução composta estende-se de seu ponto de declaração ao fim do bloco. É visível em todo o bloco a menos que uma declaração do mesmo identificador exista em um bloco interno.

Os identificadores em uma instrução composta são presumidos, **`auto`** a menos que sejam declarados explicitamente de outra forma com **`register`** **`static`** as funções,, ou, **`extern`** exceto, que só podem ser **`extern`** . Você pode deixar o **`extern`** especificador em declarações de função e a função ainda será **`extern`** .

O armazenamento não é alocado e a inicialização não é permitida se uma variável ou função é declarada em uma instrução composta com classe de armazenamento **`extern`** . A declaração se refere a uma variável ou função externa definida em outro lugar.

As variáveis declaradas em um bloco com a **`auto`** **`register`** palavra-chave ou são realocadas e, se necessário, são inicializadas sempre que a instrução composta é inserida. Essas variáveis não são definidas depois que a instrução composta é encerrada. Se uma variável declarada dentro de um bloco tiver o **`static`** atributo, a variável será inicializada quando a execução do programa for iniciada e manterá seu valor em todo o programa. Consulte [classes de armazenamento](../c-language/c-storage-classes.md) para obter informações sobre o **`static`** .

Este exemplo ilustra uma instrução composta:

```
if ( i > 0 )
{
    line[i] = x;
    x++;
    i--;
}
```

Neste exemplo, se `i` for maior que 0, todas as instruções na instrução composta serão executadas na ordem.

## <a name="see-also"></a>Confira também

[Instruções](../c-language/statements-c.md)
