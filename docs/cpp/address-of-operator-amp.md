---
title: 'Operador address-of: &amp; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- '&'
dev_langs:
- C++
helpviewer_keywords:
- address-of operator (&)
- '& operator'
- '& operator [C++], address-of operator'
ms.assetid: 2828221a-15f6-4acc-87fe-25e34feebb88
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8acd615cb2f05e62019f5076a423ae0f8218815a
ms.sourcegitcommit: 2b9e8af9b7138f502ffcba64e2721f7ef52af23b
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/01/2018
ms.locfileid: "39406000"
---
# <a name="address-of-operator-amp"></a>Operador address-of: &amp;
## <a name="syntax"></a>Sintaxe  
  
```  
& cast-expression  
```  
  
## <a name="remarks"></a>Comentários  
 O operador unário address-of (**&**) usa o endereço de seu operando. O operando do operador address-of pode ser um designador de função ou um valor l que designa um objeto que não é um campo de bits.  
  
 O operador address-of pode ser aplicado somente a variáveis com tipos fundamentais, de estrutura, classe ou união que são declarados no nível de escopo do arquivo, ou a referências de matriz subscrita. Nessas expressões, uma expressão constante que não inclui o operador address-of pode ser adicionada ou subtraída da expressão address-of.  
  
 Quando aplicado a funções ou valores l, o resultado da expressão será um tipo de ponteiro (um valor r) derivado do tipo do operando. Por exemplo, se o operando for do tipo **char**, o resultado da expressão é do tipo ponteiro para **char**. O operador address-of, aplicado a **const** ou **volátil** objetos, será avaliada como `const type *` ou `volatile type *`, onde **tipo** é o tipo do original objeto.  
  
 Quando o operador address-of é aplicado a um nome qualificado, o resultado depende se o *nome qualificado* Especifica um membro estático. Nesse caso, o resultado é um ponteiro para o tipo especificado na declaração do membro. Se o membro não é estático, o resultado é um ponteiro para o membro *nome* da classe indicada por *qualified-class-name*. (Consulte [expressões primárias](../cpp/primary-expressions.md) para obter mais informações sobre *qualified-class-name*.) O seguinte fragmento de código mostra como o resultado difere, dependendo se o membro for estática:  
  
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
  
 O endereço de uma função sobrecarregada pode ser obtido somente quando está claro que versão da função está sendo referenciada. Ver [sobrecarregamento de função](function-overloading.md) para obter informações sobre como obter o endereço de uma determinada função sobrecarregada.  
  
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
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)   
 [Operadores C++ internos, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Declarador de referência lvalue: &](../cpp/lvalue-reference-declarator-amp.md)   
 [Operadores de indireção e address-of](../c-language/indirection-and-address-of-operators.md)