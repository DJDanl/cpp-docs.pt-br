---
title: Operadores multiplicativos e o operador de módulo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- '%'
- /
dev_langs:
- C++
helpviewer_keywords:
- operators [C++], multiplicative
- arithmetic operators [C++], multiplicative operators
- modulus operator [C++]
- '* operator'
- division operator [C++], multiplicative operators
- '% operator'
- multiplication operator [C++], multiplicative operators
- multiplicative operators [C++]
- division operator
ms.assetid: b53ea5da-d0b4-40dc-98f3-0aa52d548293
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: a51544f1e367e1db0b5ae72948af68fbedfa7504
ms.sourcegitcommit: 9a0905c03a73c904014ec9fd3d6e59e4fa7813cd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 08/29/2018
ms.locfileid: "43209722"
---
# <a name="multiplicative-operators-and-the-modulus-operator"></a>Operadores multiplicativos e o operador de módulo
## <a name="syntax"></a>Sintaxe  
  
```  
expression * expression   
expression / expression   
expression % expression  
```  
  
## <a name="remarks"></a>Comentários  
 Os operadores de multiplicação são:  
  
-   Multiplicação (<strong>\*</strong>)  
  
-   Divisão (**/**)  
  
-   Módulo (resto da divisão) (**%**)  
  
 Esses operadores binários possuem associatividade da esquerda para a direita.  
  
 Os operadores de multiplicação usam operandos de tipos aritméticos. O operador de módulo (**%**) tem um requisito mais rígido que seus operandos devem ser do tipo integral. (Para obter o resto de uma divisão de ponto flutuante, use a função de tempo de execução [fmod](../c-runtime-library/reference/fmod-fmodf.md).) As conversões abordadas em [conversões padrão](standard-conversions.md) são aplicadas aos operandos, e o resultado é do tipo convertido.  
  
 O operador de multiplicação gera o resultado da multiplicação do primeiro operando pelo segundo.  
  
 O operador de divisão gera o resultado da divisão do primeiro operando pelo segundo.  
  
 O operador de módulo produz o resto fornecido pela expressão a seguir, onde *e1* é o primeiro operando e *e2* é o segundo: *e1* -(*e1*  /  *e2*) \* *e2*, em que ambos os operandos forem de tipos integrais.  
  
 A divisão por 0 em uma divisão ou em uma expressão de módulo é indefinida e gera um erro de tempo de execução. Desse modo, as expressões a seguir geram resultados indefinidos e errôneos:  
  
```cpp 
i % 0  
f / 0.0  
```  
  
 Se ambos os operandos em uma expressão de multiplicação, divisão ou módulo tiverem o mesmo sinal, o resultado será positivo. Caso contrário, o resultado será negativo. O resultado do sinal de uma operação de módulo é definido pela implementação.  
  
> [!NOTE]
>  Uma vez que as conversões executadas pelos operadores de multiplicação não fornecem condições de estouro ou estouro negativo, as informações poderão ser perdidas se o resultado de uma operação de multiplicação não puder ser representado no tipo dos operandos após a conversão.  
  
## <a name="microsoft-specific"></a>Específico da Microsoft  
 No Microsoft C++, o resultado de uma expressão de módulo sempre é igual ao sinal do primeiro operando.  
  
**Fim da seção específica da Microsoft**  
 Se a divisão calculada de dois inteiros for inexata e apenas um operando for negativo, o resultado será o interior maior (em magnitude, independentemente do sinal), que é menor que o valor exato que seria gerado pela operação de divisão. Por exemplo, o valor calculado de -11 / 3 é-3.666666666. O resultado dessa divisão integral é -3.  
  
 A relação entre os operadores de multiplicação é fornecida pela identidade (*e1* / *e2*) \* *e2*  +  *e1* % *e2* == *e1*.  
  
## <a name="example"></a>Exemplo  
 O programa a seguir demonstra os operadores de multiplicação. Observe que ambos os operandos de `10 / 3` deve ser explicitamente convertido no tipo **float** para impedir o truncamento para que ambos os operandos forem do tipo **float** antes da divisão.  
  
```cpp 
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
  
## <a name="see-also"></a>Consulte também  
 [Expressões com operadores binários](../cpp/expressions-with-binary-operators.md)   
 [Operadores C++ internos, precedência e associatividade](../cpp/cpp-built-in-operators-precedence-and-associativity.md)   
 [Operadores multiplicativos C](../c-language/c-multiplicative-operators.md)