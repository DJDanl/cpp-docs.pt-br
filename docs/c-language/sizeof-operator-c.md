---
title: Operador sizeof (C)
ms.date: 11/04/2016
f1_keywords:
- sizeof
helpviewer_keywords:
- sizeof operator
ms.assetid: 70826d03-3451-41e4-bebb-a820ae66d53f
ms.openlocfilehash: 0bc0de5481cade10f89634d9e4ec78f4ec7b09f6
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62158119"
---
# <a name="sizeof-operator-c"></a>Operador sizeof (C)

O operador `sizeof` indica a quantidade de armazenamento, em bytes, necessária para armazenar um objeto do tipo do operando. Esse operador permite que você evite especificar tamanhos de dados dependentes do computador em seus programas.

## <a name="syntax"></a>Sintaxe

```
sizeof unary-expression
sizeof ( type-name )
```

## <a name="remarks"></a>Comentários

O operando é um identificador que é uma *unary-expression* ou uma expressão de conversão de tipo (ou seja, um especificador de tipo incluído entre parênteses). A *unary-expression* não pode representar um objeto de campo de bits, um tipo incompleto ou um designador de função. O resultado é uma constante integral sem sinal. O cabeçalho padrão STDDEF.H define esse tipo como **size_t**.

Quando você aplica o operador `sizeof` a um identificador de matriz, o resultado é o tamanho da matriz inteira, não o tamanho do ponteiro representado pelo identificador de matriz.

Quando você aplica o operador `sizeof` a um nome de tipo de estrutura ou união, ou a um identificador de tipo de estrutura ou união, o resultado é o número de bytes na estrutura ou união, incluindo o preenchimento interno e à direita. Esse tamanho pode incluir o preenchimento interno e à direita usado para alinhar os membros da estrutura ou união nos limites de memória. Assim, o resultado pode não corresponder ao tamanho calculado pela adição dos requisitos de armazenamento dos membros individuais.

Se uma matriz não dimensionada é o último elemento de uma estrutura, o operador `sizeof` retorna o tamanho da estrutura sem a matriz.

```
buffer = calloc(100, sizeof (int) );
```

Esse exemplo usa o operador `sizeof` para passar o tamanho de um `int`, que varia de um computador para outro, como um argumento para uma função em tempo de execução nomeada `calloc`. O valor retornado pela função é armazenado em `buffer`.

```
static char *strings[] = {
      "this is string one",
      "this is string two",
      "this is string three",
   };
const int string_no = ( sizeof strings ) / ( sizeof strings[0] );
```

Nesse exemplo, `strings` é uma matriz de ponteiros para `char`. O número de ponteiros é o número de elementos na matriz, mas não é especificado. É fácil determinar o número de ponteiros usando o operador `sizeof` para calcular o número de elementos na matriz. O valor inteiro **const**`string_no` é inicializado nesse número. Como se trata de um valor **const**, `string_no` não pode ser modificado.

## <a name="see-also"></a>Confira também

[Operadores de C](c-operators.md)<br/>
[Operadores internos C++, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)
