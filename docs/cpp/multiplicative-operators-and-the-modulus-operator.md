---
title: "Operadores multiplicativos e o operador de m&#243;dulo | Microsoft Docs"
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
  - "%"
  - "/"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Operador %"
  - "Operador *"
  - "operadores aritméticos [C++], operadores de multiplicação"
  - "Operador de divisão"
  - "Operador de divisão, operadores de multiplicação"
  - "Operador de módulo, C+"
  - "Operador de multiplicação [C++], operadores de multiplicação"
  - "operadores de multiplicação [C++]"
  - "operadores [C++], de multiplicação"
ms.assetid: b53ea5da-d0b4-40dc-98f3-0aa52d548293
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores multiplicativos e o operador de m&#243;dulo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
expression * expression   
expression / expression   
expression % expression  
```  
  
## Comentários  
 Os operadores de multiplicação são:  
  
-   Multiplicação \(**\***\)  
  
-   Divisão \(**\/**\)  
  
-   Módulo \(resto da divisão\) \(`%`\)  
  
 Esses operadores binários possuem associatividade da esquerda para a direita.  
  
 Os operadores de multiplicação usam operandos de tipos aritméticos.  O operador de módulo \(`%`\) tem um requisito mais restrito, já que seus operandos devem ser do tipo integral. \(Para obter o resto de uma divisão de ponto flutuante, use a função de tempo de execução, [fmod](../Topic/fmod,%20fmodf.md).\) As conversões abordadas em [Conversões aritméticas](../misc/arithmetic-conversions.md) são aplicadas aos operandos, e o resultado é do tipo convertido.  
  
 O operador de multiplicação gera o resultado da multiplicação do primeiro operando pelo segundo.  
  
 O operador de divisão gera o resultado da divisão do primeiro operando pelo segundo.  
  
 O operador de módulo gera o resto fornecido pela expressão a seguir, em que *e1* é o primeiro operando e *e2* é o segundo: *e1* – \(*e1* \/ *e2*\) \* *e2*, em que ambos os operandos são de tipos integral.  
  
 A divisão por 0 em uma divisão ou em uma expressão de módulo é indefinida e gera um erro de tempo de execução.  Desse modo, as expressões a seguir geram resultados indefinidos e errôneos:  
  
```  
i % 0  
f / 0.0  
```  
  
 Se ambos os operandos em uma expressão de multiplicação, divisão ou módulo tiverem o mesmo sinal, o resultado será positivo.  Caso contrário, o resultado será negativo.  O resultado do sinal de uma operação de módulo é definido pela implementação.  
  
> [!NOTE]
>  Uma vez que as conversões executadas pelos operadores de multiplicação não fornecem condições de estouro ou estouro negativo, as informações poderão ser perdidas se o resultado de uma operação de multiplicação não puder ser representado no tipo dos operandos após a conversão.  
  
## Específico da Microsoft  
 No Microsoft C\+\+, o resultado de uma expressão de módulo sempre é igual ao sinal do primeiro operando.  
  
## FIM de Específico da Microsoft  
 Se a divisão calculada de dois inteiros for inexata e apenas um operando for negativo, o resultado será o interior maior \(em magnitude, independentemente do sinal\), que é menor que o valor exato que seria gerado pela operação de divisão.  Por exemplo, o valor calculado de –11 \/ 3 é –3.666666666.  O resultado dessa divisão integral é – 3.  
  
 A relação entre os operadores de multiplicação é fornecida pela identidade \(*e1* \/ *e2*\) \* *e2* \+ *e1* % *e2* \=\= *e1*.  
  
## Exemplo  
 O programa a seguir demonstra os operadores de multiplicação.  Observe que qualquer que seja o operando de `10 / 3`, ele deve ser explicitamente convertido no tipo `float` para evitar truncamento, de modo que ambos os operandos sejam do tipo `float` antes da divisão.  
  
```  
// expre_Multiplicative_Operators.cpp  
// compile with: /EHsc  
#include <iostream>  
using namespace std;  
int main() {  
   int x = 3, y = 6, z = 10;  
   cout  << "3 * 6 is " << x * y << endl  
         << "6 / 3 is " << y / x << endl  
         << "10 % 3 is " << z % x << endl  
         << "10 / 3 is " << (float) z / x << endl;  
}  
```  
  
## Consulte também  
 [Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)   
 [Operadores C\+\+](../misc/cpp-operators.md)   
 [Operadores, precedência e associatividade C\+\+](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores multiplicativos C](../c-language/c-multiplicative-operators.md)