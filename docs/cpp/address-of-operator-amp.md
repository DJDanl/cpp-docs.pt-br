---
title: 'Operador address-of: &amp; | Microsoft Docs'
ms.custom: ''
ms.date: 11/04/2016
ms.reviewer: ''
ms.suite: ''
ms.technology:
- cpp-language
ms.tgt_pltfrm: ''
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
caps.latest.revision: 7
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: dcc5d08f75839f428b981136e4aed0402cd72868
ms.sourcegitcommit: d9ee6f777974d031570f4260c9581ea2c81ad875
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/06/2018
---
# <a name="address-of-operator-amp"></a>Operador address-of: &amp;
## <a name="syntax"></a>Sintaxe  
  
```  
& cast-expression  
```  
  
## <a name="remarks"></a>Comentários  
 O operador unário de endereço (**&**) usa o endereço do seu operando. O operando do operador de endereço pode ser um designador de função ou um l-value que designa um objeto que não é um campo de bits.  
  
 O operador address-of pode ser aplicado somente a variáveis com tipos fundamentais, de estrutura, classe ou união que são declarados no nível de escopo do arquivo, ou a referências de matriz subscrita. Nessas expressões, uma expressão constante que não inclui o operador address-of pode ser adicionada ou subtraída da expressão address-of.  
  
 Quando aplicado a funções ou valores l, o resultado da expressão será um tipo de ponteiro (um valor r) derivado do tipo do operando. Por exemplo, se o operando for do tipo `char`, o resultado da expressão será do tipo de ponteiro para `char`. O operador address-of, aplicado a **const** ou `volatile` objetos, que é avaliada como **const** `type` **\*** ou `volatile` `type` **\***, onde `type` é o tipo do objeto original.  
  
 Quando o operador address-of é aplicado a um [nome qualificado](http://msdn.microsoft.com/en-us/3fefb16d-8120-4627-8b3f-3d90fbdcd1df), o resultado depende se o *nome qualificado* Especifica um membro estático. Nesse caso, o resultado é um ponteiro para o tipo especificado na declaração do membro. Se o membro não é estático, o resultado é um ponteiro para o membro *nome* da classe indicada pelo *nome qualificado de classe*. (Consulte [expressões primárias](../cpp/primary-expressions.md) para saber mais sobre *nome qualificado de classe*.) O seguinte fragmento de código mostra como o resultado difere, dependendo se o membro for estática:  
  
```  
// expre_Address_Of_Operator.cpp  
// C2440 expected  
class PTM {  
public:  
           int   iValue;  
    static float fValue;  
};  
  
int main() {  
   int   PTM::*piValue = &PTM::iValue;  // OK: non-static  
   float PTM::*pfValue = &PTM::fValue;  // C2440 error: static  
   float *spfValue     = &PTM::fValue;  // OK  
}  
```  
  
 Neste exemplo, a expressão `&PTM::fValue` gera o tipo `float *` em vez do tipo `float PTM::*` porque `fValue` é um membro estático.  
  
 O endereço de uma função sobrecarregada pode ser obtido somente quando está claro que versão da função está sendo referenciada. Consulte [sobrecarga de função](function-overloading.md) para obter informações sobre como obter o endereço de uma determinada função sobrecarregada.  
  
 Aplicar o operador address-of a um tipo de referência fornece o mesmo resultado que aplicar o operador ao objeto ao qual a referência está associada. Por exemplo:  
  
## <a name="example"></a>Exemplo  
  
```  
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
  
```  
&d equals &rd  
```  
  
 O exemplo a seguir usa o operador address-of para passar um argumento de ponteiro para uma função:  
  
```  
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
  
```  
25  
```  
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores unários](../cpp/expressions-with-unary-operators.md)   
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Declarador de referência lvalue: &](../cpp/lvalue-reference-declarator-amp.md)   
 [Operadores de indireção e address-of](../c-language/indirection-and-address-of-operators.md)
