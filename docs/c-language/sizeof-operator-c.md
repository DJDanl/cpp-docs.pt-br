---
title: Operador sizeof (C)
ms.date: 11/04/2016
f1_keywords:
- sizeof
helpviewer_keywords:
- sizeof operator
ms.assetid: 70826d03-3451-41e4-bebb-a820ae66d53f
ms.openlocfilehash: 1d06fc8b541cbce3771a485c8f71953be8f7d552
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229513"
---
# <a name="sizeof-operator-c"></a>Operador sizeof (C)

O **`sizeof`** operador fornece a quantidade de armazenamento, em bytes, necessária para armazenar um objeto do tipo do operando. Esse operador permite que você evite especificar tamanhos de dados dependentes do computador em seus programas.

## <a name="syntax"></a>Sintaxe

```
sizeof unary-expression
sizeof ( type-name )
```

## <a name="remarks"></a>Comentários

O operando é um identificador que é uma *unary-expression* ou uma expressão de conversão de tipo (ou seja, um especificador de tipo incluído entre parênteses). A *unary-expression* não pode representar um objeto de campo de bits, um tipo incompleto ou um designador de função. O resultado é uma constante integral sem sinal. O cabeçalho padrão STDDEF.H define esse tipo como **size_t**.

Quando você aplica o **`sizeof`** operador a um identificador de matriz, o resultado é o tamanho de toda a matriz, em vez do tamanho do ponteiro representado pelo identificador de matriz.

Quando você aplica o **`sizeof`** operador a um nome de tipo de estrutura ou de União, ou a um identificador de estrutura ou tipo de União, o resultado é o número de bytes na estrutura ou União, incluindo preenchimento interno e à direita. Esse tamanho pode incluir o preenchimento interno e à direita usado para alinhar os membros da estrutura ou união nos limites de memória. Assim, o resultado pode não corresponder ao tamanho calculado pela adição dos requisitos de armazenamento dos membros individuais.

Se uma matriz sem tamanho for o último elemento de uma estrutura, o **`sizeof`** operador retornará o tamanho da estrutura sem a matriz.

```
buffer = calloc(100, sizeof (int) );
```

Este exemplo usa o **`sizeof`** operador para passar o tamanho de um **`int`** , que varia entre computadores, como um argumento para uma função de tempo de execução chamada `calloc` . O valor retornado pela função é armazenado em `buffer`.

```
static char *strings[] = {
      "this is string one",
      "this is string two",
      "this is string three",
   };
const int string_no = ( sizeof strings ) / ( sizeof strings[0] );
```

Neste exemplo, `strings` é uma matriz de ponteiros para **`char`** . O número de ponteiros é o número de elementos na matriz, mas não é especificado. É fácil determinar o número de ponteiros usando o **`sizeof`** operador para calcular o número de elementos na matriz. O **`const`** valor inteiro `string_no` é inicializado para esse número. Porque é um **`const`** valor, `string_no` não pode ser modificado.

## <a name="see-also"></a>Confira também

[Operadores de C](c-operators.md)<br/>
[Operadores internos C++, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)
