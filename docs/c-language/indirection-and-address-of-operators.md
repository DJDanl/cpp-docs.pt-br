---
title: Operadores de indireção e endereço de
ms.date: 02/16/2018
helpviewer_keywords:
- address-of operator (&)
- '* operator'
- operators [C++], address-of
- ampersand operator (&)
- '* operator, indirection operator'
- addresses [C++], indirection
- addresses [C++]
- indirection operator
- '& operator, address-of operator'
- null pointers [C++]
- '* operator, address-of operator'
- operators [C++], indirection
ms.assetid: 10d62b00-12ba-4ea9-a2d5-09ac29ca2232
ms.openlocfilehash: 146f84c90aa56b5abf6ae5212c1729022cb7e4dc
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64343892"
---
# <a name="indirection-and-address-of-operators"></a>Operadores de indireção e endereço de

O operador unário de indireção (__&#42;__) acessa um valor indiretamente, por meio de um ponteiro. O operando deve ser um tipo de ponteiro. O resultado da operação é o valor resolvido pelo operando; isto é, o valor no endereço para o qual o operando aponta. O tipo do resultado é o tipo endereçado pelo operando.

O resultado do operador de indireção será *tipo* se o operando for do tipo *ponteiro para tipo*. Se o operando apontar para uma função, o resultado será um designador de função. Se ele apontar para um objeto, o resultado será um lvalue que designa o objeto.

Se o valor do ponteiro não for válido, o resultado do operador de indireção será indefinido. Estas são algumas das condições mais comuns que invalidam um valor de ponteiro:

- O ponteiro é um ponteiro nulo.

- O ponteiro especifica o endereço de um objeto após o fim de seu tempo de vida (como um objeto fora do escopo ou desalocado) no momento da referência.

- O ponteiro especifica um endereço que está alinhado de forma inadequada para o tipo do objeto apontado.

- O ponteiro especifica um endereço não usado pelo programa em execução.

O operador address-of unário**&**() fornece o endereço de seu operando. O operando precisa ser um lvalue que designa um objeto não declarado como __registro__ e não seja um campo de bits, ou o resultado de um operador unário __&#42;__, ou um operador de desreferenciação de matriz (__&#91;&#93;__), ou um designador de função. O resultado é do tipo *ponteiro para tipo* para um operando do tipo *tipo*.

Se o operando for o resultado de um operador unário __&#42;__, o operador não será avaliado e o resultado omitirá ambos. O resultado não é um lvalue e as restrições ainda se aplicam aos operadores. Se o operando for o resultado de um operador __&#91;&#93;__, o operador __&__ e o operador unário __&#42;__ implícito no __&#91;&#93;__ não serão avaliados. O resultado tem o mesmo efeito que remover o __&__ operador e alterar o operador de __&#91;&#93;__ para __+__ um operador. Caso contrário, o resultado será um ponteiro para o objeto ou função designado pelo operando.

## <a name="examples"></a>Exemplos

Os exemplos a seguir usam estas declarações comuns:

```C
int *pa, x;
int a[20];
double d;
```

Essa instrução usa o operador address-of (**&**) para obter o endereço do sexto elemento da matriz `a`. O resultado é armazenado na variável de ponteiro `pa`:

```C
pa = &a[5];
```

O operador de indireção (__&#42;__) é usado neste exemplo para acessar o valor `int` no endereço armazenado em `pa`. O valor é atribuído à variável de inteiro `x`:

```C
x = *pa;
```

Este exemplo demonstra que o resultado da aplicação do operador de indireção ao endereço de `x` é o mesmo que `x`:

```C
assert( x == *&x );
```

Este exemplo mostra as formas semelhantes de declarar um ponteiro para uma função:

```C
int roundup( void );     /* Function declaration */

int  *proundup  = roundup;
int  *pround  = &roundup;
assert( pround == proundup );
```

Uma vez que a função `roundup` é declarada, dois ponteiros para `roundup` são declarados e inicializados. O primeiro ponteiro, `proundup`, é inicializado usando apenas o nome da função, enquanto o segundo, `pround`, usa o operador address-of na inicialização. As inicializações são equivalentes.

## <a name="see-also"></a>Confira também

[Operador de indireção: &#42;](../cpp/indirection-operator-star.md)<br/>
[Operador address-of: &](../cpp/address-of-operator-amp.md)
