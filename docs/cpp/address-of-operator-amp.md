---
title: Operador de endereço:&amp;
ms.date: 11/04/2016
f1_keywords:
- '&'
helpviewer_keywords:
- address-of operator (&)
- '& operator'
- '& operator [C++], address-of operator'
ms.assetid: 2828221a-15f6-4acc-87fe-25e34feebb88
ms.openlocfilehash: 836802684e24c721f97dc4c5558d87b9a5e69bc8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227680"
---
# <a name="address-of-operator-amp"></a>Operador de endereço:&amp;

## <a name="syntax"></a>Sintaxe

```
& cast-expression
```

## <a name="remarks"></a>Comentários

O operador address-of unário ( **&** ) Obtém o endereço de seu operando. O operando do operador address-of pode ser um designador de função ou um l-Value que designa um objeto que não seja um campo de bits.

O operador address-of pode ser aplicado somente a variáveis com tipos fundamentais, de estrutura, classe ou união que são declarados no nível de escopo do arquivo, ou a referências de matriz subscrita. Nessas expressões, uma expressão constante que não inclui o operador address-of pode ser adicionada ou subtraída da expressão address-of.

Quando aplicado a funções ou valores l, o resultado da expressão será um tipo de ponteiro (um valor r) derivado do tipo do operando. Por exemplo, se o operando for do tipo **`char`** , o resultado da expressão será do tipo ponteiro para **`char`** . O operador address-of, aplicado a **`const`** ou **`volatile`** Objects, é avaliado `const type *` como `volatile type *` ou, onde **Type** é o tipo do objeto original.

Quando o operador address-of é aplicado a um nome qualificado, o resultado depende se o *nome qualificado* especifica um membro estático. Nesse caso, o resultado é um ponteiro para o tipo especificado na declaração do membro. Se o membro não for estático, o resultado será um ponteiro para o *nome* do membro da classe indicada por *nome de classe qualificado*. (Consulte as [expressões primárias](../cpp/primary-expressions.md) para obter mais informações sobre *nome de classe qualificado*.) O fragmento de código a seguir mostra como o resultado difere, dependendo se o membro é estático:

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

O endereço de uma função sobrecarregada pode ser obtido somente quando está claro que versão da função está sendo referenciada. Consulte [sobrecarga de função](function-overloading.md) para obter informações sobre como obter o endereço de uma função sobrecarregada específica.

Aplicar o operador address-of a um tipo de referência fornece o mesmo resultado que aplicar o operador ao objeto ao qual a referência está associada. Por exemplo:

## <a name="example"></a>Exemplo

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

## <a name="output"></a>Saída

```Output
&d equals &rd
```

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

## <a name="output"></a>Saída

```Output
25
```

## <a name="see-also"></a>Confira também

[Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)<br/>
[Operadores internos C++, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Declarador de referência Lvalue: &](../cpp/lvalue-reference-declarator-amp.md)<br/>
[Operadores de endereço e de indireção](../c-language/indirection-and-address-of-operators.md)
