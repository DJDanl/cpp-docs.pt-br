---
title: Operador sizeof
ms.date: 11/04/2016
f1_keywords:
- sizeof_cpp
helpviewer_keywords:
- sizeof operator
ms.assetid: 8bc3b6fb-54a1-4eb7-ada0-05f8c5efc532
ms.openlocfilehash: 8789bb5e0e363458edffa7207ea1e138aae4d284
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81365576"
---
# <a name="sizeof-operator"></a>Operador sizeof

Rende o tamanho de seu operand em relação ao tamanho do tipo **char**.

> [!NOTE]
> Para obter `sizeof ...` informações sobre o operador, consulte [Ellipses e Modelos Variadic](../cpp/ellipses-and-variadic-templates.md).

## <a name="syntax"></a>Sintaxe

```
sizeof unary-expression
sizeof  ( type-name )
```

## <a name="remarks"></a>Comentários

O resultado do **tamanho** do `size_t`operador é do tipo , \<um tipo integral definido no arquivo incluir stddef.h>. Esse operador permite que você evite especificar tamanhos de dados dependentes do computador em seus programas.

O operand para **tamanho pode** ser um dos seguintes:

- O nome de um tipo. Para usar **tamanhos** com um nome de tipo, o nome deve ser incluído entre parênteses.

- Uma expressão. Quando usado com uma expressão, **tamanhos** podem ser especificados com ou sem parênteses. A expressão não é avaliada.

Quando o **tamanho do operador** é aplicado a um objeto de tipo **char,** ele produz 1. Quando o **tamanho do** operador é aplicado a uma matriz, ele produz o número total de bytes nessa matriz, não o tamanho do ponteiro representado pelo identificador de matriz. Para obter o tamanho do ponteiro representado pelo identificador de matriz, passe-o como um parâmetro para uma função que usa **tamanho de**. Por exemplo:

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

Quando o **tamanho do** operador é aplicado a uma **classe,** **estruturaou**ou tipo **de união,** o resultado é o número de bytes em um objeto desse tipo, além de qualquer preenchimento adicionado para alinhar os membros nos limites da palavra. O resultado não corresponde necessariamente ao tamanho calculado pela adição dos requisitos de armazenamento dos membros individuais. A opção [/Zp](../build/reference/zp-struct-member-alignment.md) compilação e o pragma de [pacote](../preprocessor/pack.md) afetam os limites de alinhamento para membros.

O **tamanho do operador** nunca rende 0, mesmo para uma classe vazia.

O **tamanho do operador** não pode ser usado com os seguintes operands:

- Funções. (No entanto, **tamanhos** podem ser aplicados a ponteiros para funções.)

- Campos de bits.

- Classes indefinidas.

- O **vazio**do tipo.

- Matrizes alocadas dinamicamente.

- Matrizes externas.

- Tipos incompletos.

- Nomes entre parênteses de tipos incompletos.

Quando o **tamanho do** operador é aplicado a uma referência, o resultado é o mesmo que se **o tamanho** tivesse sido aplicado ao objeto em si.

Se uma matriz não dimensionada for o último elemento de uma estrutura, o **tamanho do** operador retorna o tamanho da estrutura sem a matriz.

O **tamanho do operador** é frequentemente usado para calcular o número de elementos em uma matriz usando uma expressão do formulário:

```cpp
sizeof array / sizeof array[0]
```

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
