---
title: Operador sizeof
ms.date: 11/04/2016
f1_keywords:
- sizeof_cpp
helpviewer_keywords:
- sizeof operator
ms.assetid: 8bc3b6fb-54a1-4eb7-ada0-05f8c5efc532
ms.openlocfilehash: 9edd6420193fbc1ff6013c545b294851ce105848
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50628794"
---
# <a name="sizeof-operator"></a>Operador sizeof

Retorna o tamanho do seu operando em relação ao tamanho do tipo **char**.

> [!NOTE]
>  Para obter informações sobre o `sizeof ...` operador, consulte [reticências e modelos Variadic](../cpp/ellipses-and-variadic-templates.md).

## <a name="syntax"></a>Sintaxe

```
sizeof unary-expression
sizeof  ( type-name )
```

## <a name="remarks"></a>Comentários

O resultado do **sizeof** operador é do tipo `size_t`, um tipo integral definido no arquivo de inclusão \<stddef. h >. Esse operador permite que você evite especificar tamanhos de dados dependentes do computador em seus programas.

O operando **sizeof** pode ser uma das seguintes opções:

- O nome de um tipo. Para usar **sizeof** com um nome de tipo, o nome deve ser colocado entre parênteses.

- Uma expressão. Quando usado com uma expressão **sizeof** pode ser especificado com ou sem os parênteses. A expressão não é avaliada.

Quando o **sizeof** operador é aplicado a um objeto do tipo **char**, ele resulta em 1. Quando o **sizeof** operador é aplicado a uma matriz, ele produz o número total de bytes na matriz, não o tamanho do ponteiro representado pelo identificador de matriz. Para obter o tamanho do ponteiro representado pelo identificador de matriz, passá-lo como um parâmetro para uma função que usa **sizeof**. Por exemplo:

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

## <a name="sample-output"></a>Saída de Exemplo

```Output
The size of a char is: 1
The length of Hello, world! is: 14
The size of the pointer is 4
```

Quando o **sizeof** operador é aplicado a um **classe**, **struct**, ou **união** tipo, o resultado é o número de bytes em um objeto que tipo, além de todos os preenchimentos adicionados para alinhar os membros em limites de palavra. O resultado não corresponde necessariamente ao tamanho calculado pela adição dos requisitos de armazenamento dos membros individuais. O [/Zp](../build/reference/zp-struct-member-alignment.md) opção de compilador e o [pack](../preprocessor/pack.md) pragma afetam os limites de alinhamento de membros.

O **sizeof** operador nunca resulta em 0, mesmo para uma classe vazia.

O **sizeof** operador não pode ser usado com os seguintes operandos:

- Funções. (No entanto, **sizeof** podem ser aplicados a ponteiros para funções.)

- Campos de bits.

- Classes indefinidas.

- O tipo **void**.

- Matrizes alocadas dinamicamente.

- Matrizes externas.

- Tipos incompletos.

- Nomes entre parênteses de tipos incompletos.

Quando o **sizeof** operador é aplicado a uma referência, o resultado é o mesmo como se **sizeof** tivesse sido aplicado ao próprio objeto.

Se uma matriz não dimensionada é o último elemento de uma estrutura, o **sizeof** operador retorna o tamanho da estrutura sem a matriz.

O **sizeof** é frequentemente usado para calcular o número de elementos em uma matriz usando uma expressão do formulário:

```cpp
sizeof array / sizeof array[0]
```

## <a name="see-also"></a>Consulte também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)