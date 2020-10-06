---
title: 'Operador de endereço: &amp;'
description: O operador address-of na linguagem C++.
ms.date: 10/02/2020
f1_keywords:
- '&'
helpviewer_keywords:
- address-of operator (&)
- '& operator'
- '& operator [C++], address-of operator'
ms.assetid: 2828221a-15f6-4acc-87fe-25e34feebb88
ms.openlocfilehash: 8ef7ad065281e4de58ddbdebea25950f8eb9dd06
ms.sourcegitcommit: 30792632548d1c71894f9fecbe2f554294b86020
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/06/2020
ms.locfileid: "91765289"
---
# <a name="address-of-operator-amp"></a>Operador de endereço: &amp;

## <a name="syntax"></a>Sintaxe

> **`&`** *`cast-expression`*

## <a name="remarks"></a>Comentários

O operador address-of unário ( **`&`** ) Obtém o endereço de seu operando. O operando do operador address-of pode ser um designador de função ou um l-Value que designa um objeto que não é um campo de bits.

O operador address-of só pode ser aplicado a variáveis de tipos fundamentais, de estrutura, de classe ou de União que são declarados no nível de escopo de arquivo ou a referências de matriz com assinaturas. Nessas expressões, uma expressão constante que não inclui o operador address-of pode ser adicionada ou subtraída da expressão address-of.

Quando aplicado a funções ou valores l, o resultado da expressão será um tipo de ponteiro (um valor r) derivado do tipo do operando. Por exemplo, se o operando for do tipo **`char`** , o resultado da expressão será do tipo ponteiro para **`char`** . O operador address-of, aplicado a **`const`** ou **`volatile`** Objects, é avaliado `const type *` como `volatile type *` ou, onde `type` é o tipo do objeto original.

O endereço de uma função sobrecarregada pode ser obtido somente quando está claro qual versão da função está sendo referenciada. Consulte [sobrecarga de função](function-overloading.md) para obter informações sobre como obter o endereço de uma função sobrecarregada específica.

Quando o operador address-of é aplicado a um nome qualificado, o resultado depende se o *nome qualificado* especifica um membro estático. Nesse caso, o resultado é um ponteiro para o tipo especificado na declaração do membro. Para um membro que não é estático, o resultado é um ponteiro para o *nome* do membro da classe indicada por *nome de classe qualificado*. Para obter mais informações sobre o *nome de classe qualificado*, consulte [expressões primárias](../cpp/primary-expressions.md).

## <a name="example-address-of-static-member"></a>Exemplo: endereço de membro estático

O fragmento de código a seguir mostra como o resultado do operador address-of é diferente, dependendo se um membro de classe é estático:

```cpp
// expre_Address_Of_Operator.cpp
// C2440 expected
class PTM {
public:
    int iValue;
    static float fValue;
};

int main() {
   int   PTM::*piValue = &PTM::iValue;  // OK: non-static
   float PTM::*pfValue = &PTM::fValue;  // C2440 error: static
   float *spfValue     = &PTM::fValue;  // OK
}
```

Neste exemplo, a expressão `&PTM::fValue` gera o tipo `float *` em vez do tipo `float PTM::*` porque `fValue` é um membro estático.

## <a name="example-address-of-a-reference-type"></a>Exemplo: endereço de um tipo de referência

Aplicar o operador address-of a um tipo de referência fornece o mesmo resultado que aplicar o operador ao objeto ao qual a referência está associada. Por exemplo:

```cpp
// expre_Address_Of_Operator2.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;
int main() {
   double d;        // Define an object of type double.
   double& rd = d;  // Define a reference to the object.

   // Obtain and compare their addresses
   if( &d == &rd )
      cout << "&d equals &rd" << endl;
}
```

```Output
&d equals &rd
```

## <a name="example-function-address-as-parameter"></a>Exemplo: endereço de função como parâmetro

O exemplo a seguir usa o operador address-of para passar um argumento de ponteiro para uma função:

```cpp
// expre_Address_Of_Operator3.cpp
// compile with: /EHsc
// Demonstrate address-of operator &

#include <iostream>
using namespace std;

// Function argument is pointer to type int
int square( int *n ) {
   return (*n) * (*n);
}

int main() {
   int mynum = 5;
   cout << square( &mynum ) << endl;   // pass address of int
}
```

```Output
25
```

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Operadores, precedência e Associação internos do C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Declarador de referência Lvalue: &](../cpp/lvalue-reference-declarator-amp.md)<br/>
[Operadores de endereço e de indireção](../c-language/indirection-and-address-of-operators.md)
