---
title: Operadores de atribuição
description: A sintaxe e o uso dos operadores de atribuição de linguagem padrão C++.
ms.date: 07/24/2020
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
helpviewer_keywords:
- operators [C++], assignment
- assignment operators [C++], C++
- '&= operator'
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
ms.openlocfilehash: 91346d06c6fab4f3cd83c5318c88e738daf8d249
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87229214"
---
# <a name="assignment-operators"></a>Operadores de atribuição

## <a name="syntax"></a>Sintaxe

*expression* *atribuição de expressão-* *expressão* do operador

*assignment-operator*: one of<br/>
&emsp;**`=`**&emsp;**`*=`**&emsp;**`/=`**&emsp;**`%=`**&emsp;**`+=`**&emsp;**`-=`**&emsp;**`<<=`**&emsp;**`>>=`**&emsp;**`&=`**&emsp;**`^=`**&emsp;**`|=`**

## <a name="remarks"></a>Comentários

Operadores de atribuição armazenam um valor no objeto especificado pelo operando esquerdo. Há dois tipos de operações de atribuição:

- *atribuição simples*, na qual o valor do segundo operando é armazenado no objeto especificado pelo primeiro operando.

- *atribuição composta*, na qual uma operação aritmética, de deslocamento ou bit-de-bits é executada antes de armazenar o resultado.

Todos os operadores de atribuição na tabela a seguir, exceto o **`=`** operador, são operadores de atribuição compostos.

### <a name="assignment-operators-table"></a>Tabela de operadores de atribuição

| Operador | Significado |
|--|--|
| **`=`** | Armazena o valor do segundo operando no objeto especificado pelo primeiro operando (atribuição simples). |
| **`*=`** | Multiplica o valor do primeiro operando pelo valor do segundo operando; armazena o resultado no objeto especificado pelo primeiro operando. |
| **`/=`** | Divide o valor do primeiro operando pelo valor do segundo operando; armazena o resultado no objeto especificado pelo primeiro operando. |
| **`%=`** | Obtém o módulo do primeiro operando especificado pelo valor do segundo operando; armazena o resultado no objeto especificado pelo primeiro operando. |
| **`+=`** | Soma o valor do segundo operando ao valor do primeiro operando; armazena o resultado no objeto especificado pelo primeiro operando. |
| **`-=`** | Subtrai o valor do segundo operando do valor do primeiro operando; armazena o resultado no objeto especificado pelo primeiro operando. |
| **`<<=`** | Alterna o valor do primeiro operando à esquerda do número de bits especificado pelo valor do segundo operando; armazena o resultado no objeto especificado pelo primeiro operando. |
| **`>>=`** | Alterna o valor do primeiro operando à direita do número de bits especificado pelo valor do segundo operando; armazena o resultado no objeto especificado pelo primeiro operando. |
| **`&=`** | Obtém o bit a bit AND do primeiro e do segundo operandos; armazena o resultado no objeto especificado pelo primeiro operando. |
| **`^=`** | Obtém o bit a bit exclusivo OR do primeiro e do segundo operandos; armazena o resultado no objeto especificado pelo primeiro operando. |
| **`|=`** | Obtém o bit a bit inclusivo OR do primeiro e do segundo operandos; armazena o resultado no objeto especificado pelo primeiro operando. |

### <a name="operator-keywords"></a>Palavras-chave do operador

Três dos operadores de atribuição compostos têm equivalentes de palavra-chave. Eles são:

| Operador | Equivalente |
|--|--|
| **`&=`** | **`and_eq`** |
| **`|=`** | **`or_eq`** |
| **`^=`** | **`xor_eq`** |

O C++ especifica essas palavras-chave de operador como grafias alternativas para os operadores de atribuição compostos. Em C, as grafias alternativas são fornecidas como macros no \<iso646.h> cabeçalho. Em C++, as grafias alternativas são palavras-chave; o uso do \<iso646.h> ou o equivalente em C++ \<ciso646> é preterido. No Microsoft C++, a [`/permissive-`](../build/reference/permissive-standards-conformance.md) opção ou do [`/Za`](../build/reference/za-ze-disable-language-extensions.md) compilador é necessária para habilitar a grafia alternativa.

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

O operador de atribuição simples ( **`=`** ) faz com que o valor do segundo operando seja armazenado no objeto especificado pelo primeiro operando. Se ambos os objetos forem de tipos aritméticos, o operando à direita será convertido no tipo da esquerda, antes de armazenar o valor.

Os objetos **`const`** e **`volatile`** tipos podem ser atribuídos a valores l de tipos que são apenas **`volatile`** , ou que não são **`const`** ou **`volatile`** .

A atribuição a objetos do tipo de classe ( **`struct`** , **`union`** e **`class`** tipos) é executada por uma função chamada `operator=` . O comportamento padrão dessa função do operador é executar uma cópia bit a bit; no entanto, esse comportamento pode ser alterado usando operadores sobrecarregados. Para obter mais informações, consulte [Sobrecarga de operador](../cpp/operator-overloading.md). Os tipos de classe também podem ter operadores de atribuição de *cópia* e de *movimentação* . Para obter mais informações, consulte [copiar construtores e copiar operadores de atribuição](copy-constructors-and-copy-assignment-operators-cpp.md) e [mover construtores e mover operadores de atribuição](move-constructors-and-move-assignment-operators-cpp.md).

Um objeto de qualquer classe derivada exclusiva de uma classe base pode ser atribuída a um objeto da classe base. O inverso não é verdadeiro porque há uma conversão implícita da classe derivada para a classe base, mas não da classe base para a classe derivada. Por exemplo:

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

- Chame a função `operator=` para `UserType2` , fornecida `operator=` é fornecida com um `UserType1` argumento.

- Chama a função de conversão explícita `UserType1::operator UserType2`, se essa função existir.

- Chamar um construtor `UserType2::UserType2`, desde que essa construtor exista, que usa um argumento `UserType1` e copia o resultado.

## <a name="compound-assignment"></a>Atribuição composta

Os operadores de atribuição compostos são mostrados na [tabela operadores de atribuição](#assignment-operators-table). Esses operadores têm a forma *E1* *op* =  *E2*, em que *E1* é um **`const`** l-value não modificável e *E2* é:

- um tipo aritmético

- um ponteiro, se *op* for **`+`** ou**`-`**

O formulário *E1* *op* =  *E2* se comporta como *E1* **`=`** *E1* *op* *E2*, mas o *E1* é avaliado apenas uma vez.

A atribuição composta para um tipo enumerado gera uma mensagem de erro. Se o operando esquerdo for de um tipo de ponteiro, o operando à direita deverá ser de um tipo de ponteiro ou deve ser uma expressão constante que seja avaliada como 0. Quando o operando esquerdo é de um tipo integral, o operando direito não deve ser de um tipo de ponteiro.

## <a name="result-of-assignment-operators"></a>Resultado de operadores de atribuição

Os operadores de atribuição retornam o valor do objeto especificado pelo operando esquerdo após a atribuição. O tipo resultante é o tipo do operando esquerdo. O resultado de uma expressão de atribuição é sempre um l-value. Esses operadores binários possuem associatividade da direita para a esquerda. O operando esquerdo deve ser um l-value modificável.

No ANSI C, o resultado de uma expressão de atribuição não é um l-Value. Isso significa que a expressão de C++ legal `(a += b) += c` não é permitida em C.

## <a name="see-also"></a>Confira também

[Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)<br/>
[Operadores, precedência e Associação internos do C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[operadores de atribuição C](../c-language/c-assignment-operators.md)
