---
title: "Operador Address-of: &amp; | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "address-of"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador &"
  - "Operador &, Operador address-of"
  - "Operador address-of (&)"
ms.assetid: 2828221a-15f6-4acc-87fe-25e34feebb88
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operador Address-of: &amp;
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
& cast-expression  
```  
  
## Comentários  
 O operador unário address\-of \(**&**\) obtém o endereço de seu operando.  O operando do operador address\-of pode ser um designador de função ou um valor l que designa um objeto que não é um campo de bits e não é declarado com o especificador de classe de armazenamento **register**.  
  
 O operador address\-of pode ser aplicado somente a variáveis com tipos fundamentais, de estrutura, classe ou união que são declarados no nível de escopo do arquivo, ou a referências de matriz subscrita.  Nessas expressões, uma expressão constante que não inclui o operador address\-of pode ser adicionada ou subtraída da expressão address\-of.  
  
 Quando aplicado a funções ou valores l, o resultado da expressão será um tipo de ponteiro \(um valor r\) derivado do tipo do operando.  Por exemplo, se o operando for do tipo `char`, o resultado da expressão será do tipo de ponteiro para `char`.  O operador address\-of, aplicado aos objetos **const** ou `volatile`, é avaliado em **const** `type` **\*** ou `volatile` `type` **\***, onde `type` é o tipo do objeto original.  
  
 Quando operador address\-of é aplicado a um [nome qualificado](http://msdn.microsoft.com/pt-br/3fefb16d-8120-4627-8b3f-3d90fbdcd1df), o resultado depende se o *nome qualificado* especifica um membro estático.  Nesse caso, o resultado é um ponteiro para o tipo especificado na declaração do membro.  Se o membro não for estático, o resultado será um ponteiro para o membro *name* da classe indicada por *qualified\-class\-name*. \(Consulte [Expressões primárias](../cpp/primary-expressions.md) para obter mais informações sobre *qualified\-class\-name*.\) O seguinte fragmento de código mostra como o resultado difere, dependendo se o membro for estática:  
  
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
  
 O endereço de uma função sobrecarregada pode ser obtido somente quando está claro que versão da função está sendo referenciada.  Consulte [Endereço de funções sobrecarregadas](../misc/address-of-overloaded-functions.md) para obter informações sobre como obter o endereço de uma função sobrecarregada específica.  
  
 Aplicar o operador address\-of a um tipo de referência fornece o mesmo resultado que aplicar o operador ao objeto ao qual a referência está associada.  Por exemplo:  
  
## Exemplo  
  
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
  
## Saída  
  
```  
&d equals &rd  
```  
  
 O exemplo a seguir usa o operador address\-of para passar um argumento de ponteiro para uma função:  
  
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
  
## Saída  
  
```  
25  
```  
  
## Consulte também  
 [Expressões com operadores unários](../Topic/Expressions%20with%20Unary%20Operators.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Declarador de referência Lvalue: &](../Topic/Lvalue%20Reference%20Declarator:%20&.md)   
 [Operadores de indireção e endereço de](../c-language/indirection-and-address-of-operators.md)