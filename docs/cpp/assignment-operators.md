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
dev_langs:
- C++
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
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1429bcb9f4002cb65cc14000d3bcf62004000566
ms.sourcegitcommit: b05cff71a8a6a8a4c7bbea1263fd0a711853f921
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/12/2018
ms.locfileid: "49307913"
---
# <a name="assignment-operators"></a>Operadores de atribuição

## <a name="syntax"></a>Sintaxe

*expressão* *operador de atribuição* *expressão*

*operador de atribuição* : um dos<br/>
&nbsp;&nbsp;&nbsp;&nbsp;<strong>= * =, / = % = =-= \< \<= >> = & = ^ =   \|=</strong>

## <a name="remarks"></a>Comentários

Os operadores de atribuição armazenam um valor no objeto designado pelo operando à esquerda. Há dois tipos de operações de atribuição:

1. *atribuição simples*, no qual o valor do segundo operando é armazenado no objeto especificado pelo primeiro operando.

1. *atribuição composta*, em que uma operação bit a bit, shift ou aritmética é realizada antes de armazenar o resultado.

Todos os operadores de atribuição na tabela a seguir, exceto o operador =, são operadores de atribuição composta.

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

O operador de atribuição simples (**=**) faz com que o valor do segundo operando a ser armazenado no objeto especificado pelo primeiro operando. Se os dois objetos forem de tipos aritméticos, o operando da direita será convertido no tipo da esquerda, armazenamento o valor anteriormente.

Objetos do **const** e **volátil** tipos podem ser atribuídos aos l-values dos tipos que são apenas **volátil** ou que não esteja **const** nem **volátil**.

Atribuição para objetos do tipo de classe (struct, union e tipos de classe) é executada por uma função chamada `operator=`. O comportamento padrão dessa função do operador é executar uma cópia bit a bit; no entanto, esse comportamento pode ser alterado usando operadores sobrecarregados. Ver [sobrecarga de operador](../cpp/operator-overloading.md) para obter mais informações. Além disso, os tipos de classe podem ter *copiar atribuição* e *atribuição de movimentação* operadores. Para obter mais informações, consulte [construtores de cópia e copie os operadores de atribuição](copy-constructors-and-copy-assignment-operators-cpp.md) e [construtores Move e operadores de atribuição de movimentação](move-constructors-and-move-assignment-operators-cpp.md).

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

- Chamar a função `operator=` para `UserType2`, fornecida `operator=` é fornecido com um `UserType1` argumento.

- Chama a função de conversão explícita `UserType1::operator UserType2`, se essa função existir.

- Chamar um construtor `UserType2::UserType2`, desde que essa construtor exista, que usa um argumento `UserType1` e copia o resultado.

## <a name="compound-assignment"></a>Atribuição composta

Os operadores de atribuição composta, mostrados na tabela [operadores de atribuição](#assignment-operators), são especificadas no formulário *e1* *op*= *e2*, onde *e1* é um l-value modificável não de **const** tipo e *e2* é um dos seguintes:

- Um tipo aritmético

- Um ponteiro, se *op* é **+** ou **-**

O *e1* *op*= *e2* formulário se comporta como *e1* **=** *e1* *op* *e2*, mas *e1* é avaliada apenas uma vez.

A atribuição composta para um tipo enumerado gera uma mensagem de erro. Se o operando esquerdo for de um tipo ponteiro, o operando direito deverá ser do tipo ponteiro ou ser uma expressão constante avaliada como 0. Se o operando esquerdo for do tipo integral, o operando direito não deverá ser de um tipo ponteiro.

## <a name="result-of-assignment-operators"></a>Resultado dos operadores de atribuição

Os operadores de atribuição retornam o valor do objeto especificado pelo operando esquerdo após a atribuição. O tipo resultante é o tipo do operando esquerdo. O resultado de uma expressão de atribuição é sempre um l-value. Esses operadores binários possuem associatividade da direita para a esquerda. O operando esquerdo deve ser um l-value modificável.

Em ANSI C, o resultado de uma expressão de atribuição não é um l-value. Portanto, a expressão C++ válida `(a += b) += c` é inválida em C.

## <a name="see-also"></a>Consulte também

[Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)<br/>
[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Operadores de atribuição C](../c-language/c-assignment-operators.md)
