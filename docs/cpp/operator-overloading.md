---
title: Sobrecarga de operador | Microsoft Docs
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: language-reference
f1_keywords:
- operator_cpp
- operator
dev_langs: C++
helpviewer_keywords:
- redefinable operators [C++]
- non-redefinable operators [C++]
- operator keyword [C++]
- operators [C++], overloading
- operator overloading
ms.assetid: 56ad4c4f-dd0c-45e0-adaa-08fe98cb1f8e
caps.latest.revision: "13"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 617236d30f3c4473f6c7785db97789105d6cd565
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="operator-overloading"></a>Sobrecarga de operador
A palavra-chave `operator` declara uma função especificando o que `operator-symbol` significa quando aplicado às instâncias de uma classe. Isso confere ao operador mais de um significado, ou seja, o "sobrecarrega". O compilador distingue entre os diversos significados de um operador examinando os tipos de seus operandos.  
  
## <a name="syntax"></a>Sintaxe  
  
```  
  
type operator operator-symbol ( parameter-list )  
```  
  
## <a name="remarks"></a>Comentários  
 Você pode redefinir a função da maioria dos operadores internos globalmente ou em uma classe de cada vez. Os operadores sobrecarregados são implementados como funções.  
  
 É o nome de um operador sobrecarregado `operator x`, onde `x` é o operador como ele aparece na tabela a seguir. Por exemplo, para sobrecarregar o operador de adição, você define uma função chamada `operator+`. Da mesma forma, para sobrecarregar o operador de adição/atribuição, `+=`, você define uma função chamada `operator+=`.  
  
### <a name="redefinable-operators"></a>Operadores redefiníveis  
  
|Operador|Nome|Tipo|  
|--------------|----------|----------|  
|`,`|Vírgula|Binário|  
|`!`|NOT lógico|Unário|  
|`!=`|Desigualdade|Binário|  
|`%`|Módulo|Binário|  
|`%=`|Atribuição de módulo|Binário|  
|`&`|AND bit a bit|Binário|  
|`&`|Address-of|Unário|  
|`&&`|AND lógico|Binário|  
|`&=`|Atribuição AND de bit a bit|Binário|  
|`( )`|Chamada de função|—|  
|`( )`|Operador cast|Unário|  
|`*`|Multiplicação|Binário|  
|`*`|Desreferência de ponteiro|Unário|  
|`*=`|Atribuição de multiplicação|Binário|  
|`+`|Adição|Binário|  
|`+`|Mais unário|Unário|  
|`++`|Incremento <sup>1</sup>|Unário|  
|`+=`|Atribuição de adição|Binário|  
|`-`|Subtração|Binário|  
|`-`|Negação unária|Unário|  
|`--`|Decremento <sup>1</sup>|Unário|  
|`-=`|Atribuição de subtração|Binário|  
|`->`|Seleção de membro|Binário|  
|`->*`|Seleção de ponteiro para membro|Binário|  
|`/`|Divisão|Binário|  
|`/=`|Atribuição de divisão|Binário|  
|`<`|Menor que|Binário|  
|`<<`|Shift esquerda|Binário|  
|`<<=`|Atribuição de deslocamento para a esquerda|Binário|  
|`<=`|Menor que ou igual a|Binário|  
|`=`|Atribuição|Binário|  
|`==`|Igualdade|Binário|  
|`>`|Maior que|Binário|  
|`>=`|Maior que ou igual a|Binário|  
|`>>`|Shift direita|Binário|  
|`>>=`|Atribuição de deslocamento para a direita|Binário|  
|`[ ]`|Subscrito de matriz|—|  
|`^`|OR exclusivo|Binário|  
|`^=`|Atribuição de OR exclusivo|Binário|  
|`&#124;`|OR inclusivo de bit a bit|Binário|  
|`&#124;=`|Atribuição OR inclusivo de bit a bit|Binário|  
|`&#124;&#124;`|OR lógico|Binário|  
|`~`|Complemento de um|Unário|  
|`delete`|`Delete`|—|  
|`new`|`New`|—|  
|`conversion operators`|operadores de conversão|Unário|  
  
 1 duas versões da unária incrementam e operadores de decremento existir: preincrement e postincrement.  
  
 Consulte [regras gerais para sobrecarga de operador](../cpp/general-rules-for-operator-overloading.md) para obter mais informações. As restrições nas diversas categorias de operadores sobrecarregados são descritas nos tópicos a seguir:  
  
-   [Operadores unários](../cpp/overloading-unary-operators.md)  
  
-   [Operadores binários](../cpp/binary-operators.md)  
  
-   [Atribuição](../cpp/assignment.md)  
  
-   [Chamada de função](../cpp/function-call-cpp.md)  
  
-   [Subscrito](../cpp/subscripting.md)  
  
-   [Acesso de membro de classe](../cpp/member-access.md)  
  
-   [Incremento e decremento](../cpp/increment-and-decrement-operator-overloading-cpp.md).  
  
-   [Conversões de tipo definido pelo usuário](../cpp/user-defined-type-conversions-cpp.md)  
  
 Os operadores mostrados na tabela a seguir não podem ser sobrecarregados. A tabela inclui os símbolos de pré-processador `#` e `##`.  
  
### <a name="nonredefinable-operators"></a>Operadores não redefiníveis  
  
|||  
|-|-|  
|`Operator`|`Name`|  
|`.`|Seleção de membro|  
|`.*`|Seleção de ponteiro para membro|  
|`::`|Resolução do escopo|  
|`? :`|Condicional|  
|`#`|Conversão de pré-processador em cadeia de caracteres|  
|`##`|Concatenação de pré-processador|  
  
 Embora, de modo geral, os operadores sobrecarregados sejam chamados implicitamente pelo compilador quando são encontrados no código, eles podem ser invocados explicitamente da mesma maneira que qualquer função de membro ou de não membro é chamada:  
  
```  
Point pt;  
pt.operator+( 3 );  // Call addition operator to add 3 to pt.  
```  
  
## <a name="example"></a>Exemplo  
 O exemplo a seguir sobrecarrega o operador `+` para adicionar dois números complexos e retorna o resultado.  
  
```  
// operator_overloading.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
  
struct Complex {  
   Complex( double r, double i ) : re(r), im(i) {}  
   Complex operator+( Complex &other );  
   void Display( ) {   cout << re << ", " << im << endl; }  
private:  
   double re, im;  
};  
  
// Operator overloaded using a member function  
Complex Complex::operator+( Complex &other ) {  
   return Complex( re + other.re, im + other.im );  
}  
  
int main() {  
   Complex a = Complex( 1.2, 3.4 );  
   Complex b = Complex( 5.6, 7.8 );  
   Complex c = Complex( 0.0, 0.0 );  
  
   c = a + b;  
   c.Display();  
}  
```  
  
## <a name="output"></a>Saída  
  
```  
6.8, 11.2  
```  
  
## <a name="in-this-section"></a>Nesta seção  
  
1.  [Regras gerais para sobrecarga de operador](../cpp/general-rules-for-operator-overloading.md)  
  
2.  [Sobrecarga de operadores unários](../cpp/overloading-unary-operators.md)  
  
3.  [Operadores binários](../cpp/binary-operators.md)  
  
4.  [Atribuição](../cpp/assignment.md)  
  
5.  [Chamada de função](../cpp/function-call-cpp.md)  
  
6.  [Subscrito](../cpp/subscripting.md)  
  
7.  [Acesso de membro](../cpp/member-access.md)  
  
## <a name="see-also"></a>Consulte também  
 [Operadores C++ internos, precedência e capacidade de associação](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Palavras-chave](../cpp/keywords-cpp.md)