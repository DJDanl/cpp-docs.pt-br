---
title: Operadores de atribuição | Microsoft Docs
ms.custom: ''
ms.date: 03/05/2018
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- =
- '*='
- /=
- '%='
- +=
- -=
- <<=
- '>>='
- '&='
- ^=
- '|='
- '&&='
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], assignment
- assignment operators [C++], C++
- '&= operator'
- '&&= operator'
- ^= operator
- += operator
- '>>= operator'
- '|= operator'
- operator>>=
- '*= operator'
- '%= operator'
- ^= operator
- operator >>=
- = operator
- -= operator
- /= operator
- <<= operator
ms.assetid: b028cf35-2ff1-4f14-9027-fd53ebec8aa0
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 15c9efaf8dc5b9f0886a697ad2b872e24264820f
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46017892"
---
# <a name="assignment-operators"></a>Operadores de atribuição

## <a name="syntax"></a>Sintaxe

```
expression assignment-operator expression 
assignment-operator : one of
   =   *=   /=   %=   +=   -=   <<=   >>=   &=   ^=   |=  &&=
```

## <a name="remarks"></a>Comentários

Os operadores de atribuição armazenam um valor no objeto designado pelo operando à esquerda. Há três tipos de operações de atribuição:

1. atribuição simples, no qual o valor do segundo operando é armazenado no objeto especificado pelo primeiro operando. 1. atribuição composta, em que uma operação bit a bit, shift ou aritmética é realizada antes de armazenar o resultado.
1. Mova a atribuição (para tipos de classe) em quais recursos são transferidos sem copiar.


Todos os operadores de atribuição na tabela a seguir, exceto o = e & & = operadores são operadores de atribuição composta.

### <a name="assignment-operators"></a>Operadores de atribuição

|Operador|Significado|
|--------------|-------------|
|**=**|Armazena o valor do segundo operando no objeto especificado pelo primeiro operando (atribuição simples).|
|**\*=**|Multiplica o valor do primeiro operando pelo valor do segundo operando; armazena o resultado no objeto especificado pelo primeiro operando.|
|**/=**|Divide o valor do primeiro operando pelo valor do segundo operando; armazena o resultado no objeto especificado pelo primeiro operando.|
|**%=**|Obtém o módulo do primeiro operando especificado pelo valor do segundo operando; armazena o resultado no objeto especificado pelo primeiro operando.|
|**+=**|Soma o valor do segundo operando ao valor do primeiro operando; armazena o resultado no objeto especificado pelo primeiro operando.|
|**-=**|Subtrai o valor do segundo operando do valor do primeiro operando; armazena o resultado no objeto especificado pelo primeiro operando.|
|**<\<=**|Alterna o valor do primeiro operando à esquerda do número de bits especificado pelo valor do segundo operando; armazena o resultado no objeto especificado pelo primeiro operando.|
|**>>=**|Alterna o valor do primeiro operando à direita do número de bits especificado pelo valor do segundo operando; armazena o resultado no objeto especificado pelo primeiro operando.|
|**&=**|Obtém o bit a bit AND do primeiro e do segundo operandos; armazena o resultado no objeto especificado pelo primeiro operando.|
|**^=**|Obtém o bit a bit exclusivo OR do primeiro e do segundo operandos; armazena o resultado no objeto especificado pelo primeiro operando.|
|**\|=**|Obtém o bit a bit inclusivo OR do primeiro e do segundo operandos; armazena o resultado no objeto especificado pelo primeiro operando.|
|**&&=**| Operador de atribuição de movimentação (para tipos de classe apenas). Se o segundo operando for um rvalue, mova seus recursos para o primeiro operando (sem copiá-los). Ver [construtores Move e operadores de atribuição de movimentação](move-constructors-and-move-assignment-operators-cpp.md) para obter mais informações.|

**Palavras-chave do operador**

Três dos operadores de atribuição composta têm equivalentes de texto. Elas são:

|Operador|Equivalente|
|--------------|----------------|
|**&=**|`and_eq`|
|**\|=**|`or_eq`|
|**^=**|`xor_eq`|

Há duas maneiras para acessar essas palavras-chave de operador em seus programas: incluir o arquivo de cabeçalho `iso646.h`, ou compilando com o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção do compilador (desabilitar extensões de linguagem).

## <a name="example"></a>Exemplo

```cpp
// expre_Assignment_Operators.cpp
// compile with: /EHsc
// Demonstrate assignment operators
#include <iostream>
using namespace std;
int main() {
   int a = 3, b = 6, c = 10, d = 0xAAAA, e = 0x5555;

   a += b;      // a is 9
   b %= a;      // b is 6
   c >>= 1;      // c is 5
   d |= e;      // Bitwise--d is 0xFFFF

   cout  << "a = 3, b = 6, c = 10, d = 0xAAAA, e = 0x5555" << endl
         << "a += b yields " << a << endl
         << "b %= a yields " << b << endl
         << "c >>= 1 yields " << c << endl
         << "d |= e yields " << hex << d << endl;
}
```

## <a name="simple-assignment"></a>Atribuição simples

O operador de atribuição simples (=) faz com que o valor do segundo operando seja armazenado no objeto especificado pelo primeiro operando. Se os dois objetos forem de tipos aritméticos, o operando da direita será convertido no tipo da esquerda, armazenamento o valor anteriormente.

Os objetos dos tipos const e volatile podem ser atribuídos aos l-values dos tipos que são apenas volatile ou que não são const nem volatile.

A atribuição a objetos do tipo de classe (tipos struct, union e class) é executada por uma função chamada operator=. O comportamento padrão dessa função do operador é executar uma cópia bit a bit; no entanto, esse comportamento pode ser alterado usando operadores sobrecarregados. (Consulte [operadores sobrecarregados](../cpp/operator-overloading.md) para obter mais informações.)

Um objeto de qualquer classe derivada exclusiva de uma classe base pode ser atribuída a um objeto da classe base. O contrário não é válido porque existe uma conversão implícita da classe derivada para a classe base, mas não da classe base para a classe derivada. Por exemplo:

```cpp
// expre_SimpleAssignment.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;
class ABase
{
public:
    ABase() { cout << "constructing ABase\n"; }
};

class ADerived : public ABase
{
public:
    ADerived() { cout << "constructing ADerived\n"; }
};

int main()
{
    ABase aBase;
    ADerived aDerived;

    aBase = aDerived; // OK
    aDerived = aBase; // C2679
}
```

As atribuições para tipos de referência se comportam como se uma atribuição foi feita ao objeto ao qual a referência aponta.

Para objetos de tipo classe, a atribuição é diferente de inicialização. Para ilustrar como a atribuição e a inicialização podem ser diferentes, considere o código

```cpp
UserType1 A;
UserType2 B = A;
```

O código anterior mostra um inicializador; ele chama o construtor de `UserType2` que usa um argumento do tipo `UserType1`. Dado o código

```cpp
UserType1 A;
UserType2 B;

B = A;
```

a instrução de atribuição

```cpp
B = A;
```

pode ter um dos seguintes efeitos

- Chamada do operator= da função para `UserType2`, desde que o operator= seja fornecido com um argumento `UserType1`.

- Chama a função de conversão explícita `UserType1::operator UserType2`, se essa função existir.

- Chamar um construtor `UserType2::UserType2`, desde que essa construtor exista, que usa um argumento `UserType1` e copia o resultado.

## <a name="compound-assignment"></a>Atribuição composta

Os operadores de atribuição composta, mostrados na tabela [operadores de atribuição](../cpp/assignment-operators.md), são especificadas no formulário *e1* `op` =  *e2*, onde *e1* é um l-value modificável não é do tipo const e *e2* é um dos seguintes:

- Um tipo aritmético

- Um ponteiro, se `op` é + ou -

O *e1* `op` =  *e2* formulário se comporta como *e1* *= e1* `op` *e2*, mas *e1* é avaliada apenas uma vez.

A atribuição composta para um tipo enumerado gera uma mensagem de erro. Se o operando esquerdo for de um tipo ponteiro, o operando direito deverá ser do tipo ponteiro ou ser uma expressão constante avaliada como 0. Se o operando esquerdo for do tipo integral, o operando direito não deverá ser de um tipo ponteiro.

## <a name="result-of-assignment-operators"></a>Resultado dos operadores de atribuição

Os operadores de atribuição retornam o valor do objeto especificado pelo operando esquerdo após a atribuição. O tipo resultante é o tipo do operando esquerdo. O resultado de uma expressão de atribuição é sempre um l-value. Esses operadores binários possuem associatividade da direita para a esquerda. O operando esquerdo deve ser um l-value modificável.

Em ANSI C, o resultado de uma expressão de atribuição não é um l-value. Portanto, a expressão C++ válida `(a += b) += c` é inválida em C.

## <a name="see-also"></a>Consulte também

[Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)<br/>
[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores de atribuição C](../c-language/c-assignment-operators.md)