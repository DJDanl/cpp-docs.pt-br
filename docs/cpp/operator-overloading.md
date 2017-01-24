---
title: "Sobrecarga de operador | Microsoft Docs"
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
  - "operator_cpp"
  - "operator"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "operadores não redefiníveis"
  - "palavra-chave operator [C++]"
  - "sobrecarga de operador"
  - "operadores [C++], sobrecarga"
  - "operadores redefiníveis"
ms.assetid: 56ad4c4f-dd0c-45e0-adaa-08fe98cb1f8e
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Sobrecarga de operador
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A palavra\-chave `operator` declara uma função especificando o que `operator-symbol` significa quando aplicado às instâncias de uma classe.  Isso confere ao operador mais de um significado, ou seja, o "sobrecarrega".  O compilador distingue entre os diversos significados de um operador examinando os tipos de seus operandos.  
  
## Sintaxe  
  
```  
  
type operator operator-symbol ( parameter-list )  
```  
  
## Comentários  
 Você pode redefinir a função da maioria dos operadores internos globalmente ou em uma classe de cada vez.  Os operadores sobrecarregados são implementados como funções.  
  
 O nome de um operador sobrecarregado é `operator``x`, onde `x` é o operador conforme aparece na tabela a seguir.  Por exemplo, para sobrecarregar o operador de adição, você define uma função chamada `operator+`.  Da mesma forma, para sobrecarregar o operador de adição\/atribuição, `+=`, você define uma função chamada `operator+=`.  
  
### Operadores redefiníveis  
  
|Operador|Nome|Tipo|  
|--------------|----------|----------|  
|`,`|Vírgula|Binário|  
|`!`|NOT lógico|Unário|  
|`!=`|Desigualdade|Binário|  
|`%`|Módulo|Binário|  
|`%=`|Atribuição de módulo|Binário|  
|`&`|AND bit a bit|Binário|  
|`&`|Address\-of|Unário|  
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
|`–`|Subtração|Binário|  
|`–`|Negação unária|Unário|  
|`––`|Decremento <sup>1</sup>|Unário|  
|`–=`|Atribuição de subtração|Binário|  
|`–>`|Seleção de membro|Binário|  
|`–>*`|Seleção de ponteiro para membro|Binário|  
|`/`|Divisão|Binário|  
|`/=`|Atribuição de divisão|Binário|  
|`<`|Menor que|Binário|  
|`<<`|Shift esquerda|Binário|  
|`<<=`|Atribuição de deslocamento para a esquerda|Binário|  
|`<=`|Menor ou igual a|Binário|  
|`=`|Atribuição|Binário|  
|`==`|Igualdade|Binário|  
|`>`|Maior que|Binário|  
|`>=`|Maior ou igual a|Binário|  
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
  
 1 Existem duas versões dos operadores unários de incremento e decremento: pré\-incremento e pós\-incremento.  
  
 Consulte o tópico sobre [regras gerais do sobrecarregamento de operadores](../cpp/general-rules-for-operator-overloading.md) para obter mais informações.  As restrições nas diversas categorias de operadores sobrecarregados são descritas nos tópicos a seguir:  
  
-   [Operadores unários](../cpp/overloading-unary-operators.md)  
  
-   [Operadores binários](../cpp/binary-operators.md)  
  
-   [Atribuição](../cpp/assignment.md)  
  
-   [Chamada de função](../Topic/Function%20Call%20\(C++\).md)  
  
-   [Subscrito](../cpp/subscripting.md)  
  
-   [Acesso de membros de classe](../Topic/Member%20Access.md)  
  
-   [Incremento e decremento](../Topic/Increment%20and%20Decrement%20Operator%20Overloading%20\(C++\).md).  
  
-   [Conversões](../cpp/user-defined-type-conversions-cpp.md)  
  
 Os operadores mostrados na tabela a seguir não podem ser sobrecarregados.  A tabela inclui os símbolos de pré\-processador `#` e `##`.  
  
### Operadores não redefiníveis  
  
|||  
|-|-|  
|`Operator`|`Name`|  
|`.`|Seleção de membro|  
|`.*`|Seleção de ponteiro para membro|  
|`::`|Resolução do escopo|  
|`?  :`|Condicional|  
|`#`|Conversão de pré\-processador em cadeia de caracteres|  
|`##`|Concatenação de pré\-processador|  
  
 Embora, de modo geral, os operadores sobrecarregados sejam chamados implicitamente pelo compilador quando são encontrados no código, eles podem ser invocados explicitamente da mesma maneira que qualquer função de membro ou de não membro é chamada:  
  
```  
Point pt;  
pt.operator+( 3 );  // Call addition operator to add 3 to pt.  
```  
  
## Exemplo  
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
  
## Saída  
  
```  
6.8, 11.2  
```  
  
## Nesta seção  
  
1.  [Regras gerais para sobrecarga de operador](../cpp/general-rules-for-operator-overloading.md)  
  
2.  [Operadores unários de sobrecarga](../cpp/overloading-unary-operators.md)  
  
3.  [Operadores binários](../cpp/binary-operators.md)  
  
4.  [Atribuição](../cpp/assignment.md)  
  
5.  [Chamada de função](../Topic/Function%20Call%20\(C++\).md)  
  
6.  [Subscripting](../cpp/subscripting.md)  
  
7.  [Acesso de membro](../Topic/Member%20Access.md)  
  
## Consulte também  
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)