---
title: Operador sizeof
ms.date: 11/04/2016
f1_keywords:
- sizeof_cpp
helpviewer_keywords:
- sizeof operator
ms.assetid: 8bc3b6fb-54a1-4eb7-ada0-05f8c5efc532
ms.openlocfilehash: 13e181bf84e359d433fbe951b1aa69320a1f0013
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87186289"
---
# <a name="sizeof-operator"></a>Operador sizeof

Produz o tamanho de seu operando em relação ao tamanho do tipo **`char`** .

> [!NOTE]
> Para obter informações sobre o `sizeof ...` operador, consulte [reticências and Variadic templates](../cpp/ellipses-and-variadic-templates.md).

## <a name="syntax"></a>Sintaxe

```
sizeof unary-expression
sizeof  ( type-name )
```

## <a name="remarks"></a>Comentários

O resultado do **`sizeof`** operador é do tipo `size_t` , um tipo integral definido no arquivo de inclusão \<stddef.h> . Esse operador permite que você evite especificar tamanhos de dados dependentes do computador em seus programas.

O operando **`sizeof`** pode ser um dos seguintes:

- O nome de um tipo. Para usar **`sizeof`** com um nome de tipo, o nome deve ser colocado entre parênteses.

- Uma expressão. Quando usado com uma expressão, **`sizeof`** pode ser especificado com ou sem os parênteses. A expressão não é avaliada.

Quando o **`sizeof`** operador é aplicado a um objeto do tipo **`char`** , ele resulta em 1. Quando o **`sizeof`** operador é aplicado a uma matriz, ele gera o número total de bytes nessa matriz, não o tamanho do ponteiro representado pelo identificador da matriz. Para obter o tamanho do ponteiro representado pelo identificador de matriz, passe-o como um parâmetro para uma função que usa **`sizeof`** . Por exemplo:

## <a name="example"></a>Exemplo

```cpp
#include <iostream>
using namespace std;

size_t getPtrSize( char *ptr )
{
   return sizeof( ptr );
}

int main()
{
   char szHello[] = "Hello, world!";

   cout  << "The size of a char is: "
         << sizeof( char )
         << "\nThe length of " << szHello << " is: "
         << sizeof szHello
         << "\nThe size of the pointer is "
         << getPtrSize( szHello ) << endl;
}
```

## <a name="sample-output"></a>Saída de exemplo

```Output
The size of a char is: 1
The length of Hello, world! is: 14
The size of the pointer is 4
```

Quando o **`sizeof`** operador é aplicado a um **`class`** **`struct`** tipo,, ou **`union`** , o resultado é o número de bytes em um objeto desse tipo, além de qualquer preenchimento adicionado para alinhar Membros em limites de palavras. O resultado não corresponde necessariamente ao tamanho calculado pela adição dos requisitos de armazenamento dos membros individuais. A opção do compilador [/ZP](../build/reference/zp-struct-member-alignment.md) e o pragma do [pacote](../preprocessor/pack.md) afetam os limites de alinhamento dos membros.

O **`sizeof`** operador nunca produz 0, mesmo para uma classe vazia.

O **`sizeof`** operador não pode ser usado com os seguintes operandos:

- Funções. (No entanto, **`sizeof`** pode ser aplicado a ponteiros para funções.)

- Campos de bits.

- Classes indefinidas.

- O tipo **`void`** .

- Matrizes alocadas dinamicamente.

- Matrizes externas.

- Tipos incompletos.

- Nomes entre parênteses de tipos incompletos.

Quando o **`sizeof`** operador é aplicado a uma referência, o resultado é o mesmo que se **`sizeof`** tivesse sido aplicado ao próprio objeto.

Se uma matriz sem tamanho for o último elemento de uma estrutura, o **`sizeof`** operador retornará o tamanho da estrutura sem a matriz.

O **`sizeof`** operador geralmente é usado para calcular o número de elementos em uma matriz usando uma expressão do formulário:

```cpp
sizeof array / sizeof array[0]
```

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
