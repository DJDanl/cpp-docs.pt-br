---
title: Sobrecarga de operador | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
f1_keywords:
- operator_cpp
- operator
dev_langs:
- C++
helpviewer_keywords:
- redefinable operators [C++]
- non-redefinable operators [C++]
- operator keyword [C++]
- operators [C++], overloading
- operator overloading
ms.assetid: 56ad4c4f-dd0c-45e0-adaa-08fe98cb1f8e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ff6be1e24371692c53621cf6583677cc97d631b4
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46059180"
---
# <a name="operator-overloading"></a>Sobrecarga de operador

O **operador** palavra-chave declara uma função especificando quais *símbolo do operador* significa quando aplicado às instâncias de uma classe. Isso confere ao operador mais de um significado, ou seja, o "sobrecarrega". O compilador distingue entre os diversos significados de um operador examinando os tipos de seus operandos.

## <a name="syntax"></a>Sintaxe

> *tipo de* **operador** *símbolo do operador* **(** *lista de parâmetros* **)**

## <a name="remarks"></a>Comentários

Você pode redefinir a função da maioria dos operadores internos globalmente ou em uma classe de cada vez. Os operadores sobrecarregados são implementados como funções.

É o nome de um operador sobrecarregado **operador** *x*, onde *x* é o operador como ele aparece na tabela a seguir. Por exemplo, para sobrecarregar o operador de adição, você define uma função chamada **operador +**. Da mesma forma, para sobrecarregar o operador de adição/atribuição **+=**, define uma função chamada **operator + =**.

### <a name="redefinable-operators"></a>Operadores redefiníveis

|Operador|Nome|Tipo|
|--------------|----------|----------|
|**,**|Vírgula|Binário|
|**!**|NOT lógico|Unário|
|**\!=**|Desigualdade|Binário|
|**%**|Módulo|Binário|
|**%=**|Atribuição de módulo|Binário|
|**&**|AND bit a bit|Binário|
|**&**|Address-of|Unário|
|**&&**|AND lógico|Binário|
|**&=**|Atribuição AND de bit a bit|Binário|
|**( )**|Chamada de função|—|
|**( )**|Operador cast|Unário|
|**&#42;**|Multiplicação|Binário|
|**&#42;**|Desreferência de ponteiro|Unário|
|**&#42;=**|Atribuição de multiplicação|Binário|
|**+**|Adição|Binário|
|**+**|Mais unário|Unário|
|**++**|Incremento <sup>1</sup>|Unário|
|**+=**|Atribuição de adição|Binário|
|**-**|Subtração|Binário|
|**-**|Negação unária|Unário|
|**--**|Decremento <sup>1</sup>|Unário|
|**-=**|Atribuição de subtração|Binário|
|**->**|Seleção de membro|Binário|
|**->&#42;**|Seleção de ponteiro para membro|Binário|
|**/**|Divisão|Binário|
|**/=**|Atribuição de divisão|Binário|
|**\<**|Menor que|Binário|
|**<<**|Shift esquerda|Binário|
|**<<=**|Atribuição de deslocamento para a esquerda|Binário|
|**<=**|Menor que ou igual a|Binário|
|**=**|Atribuição|Binário|
|**==**|Igualdade|Binário|
|**>**|Maior que|Binário|
|**>=**|Maior que ou igual a|Binário|
|**>>**|Shift direita|Binário|
|**>>=**|Atribuição de deslocamento para a direita|Binário|
|**[ ]**|Subscrito de matriz|—|
|**^**|OR exclusivo|Binário|
|**^=**|Atribuição de OR exclusivo|Binário|
|**&#124;**|OR inclusivo de bit a bit|Binário|
|**&#124;=**|Atribuição OR inclusivo de bit a bit|Binário|
|**&#124;&#124;**|OR lógico|Binário|
|**~**|Complemento de um|Unário|
|**delete**|Excluir|—|
|**new**|Novo|—|
|operadores de conversão|operadores de conversão|Unário|

<sup>1</sup> as duas versões da unária aumentam e operadores de decremento: pré-incremento e pós-incremento.

Ver [regras gerais para sobrecarga de operador](../cpp/general-rules-for-operator-overloading.md) para obter mais informações. As restrições nas diversas categorias de operadores sobrecarregados são descritas nos tópicos a seguir:

- [Operadores unários](../cpp/overloading-unary-operators.md)

- [Operadores binários](../cpp/binary-operators.md)

- [Atribuição](../cpp/assignment.md)

- [Chamada de função](../cpp/function-call-cpp.md)

- [Subscrito](../cpp/subscripting.md)

- [Acesso de membro de classe](../cpp/member-access.md)

- [Incremento e decremento](../cpp/increment-and-decrement-operator-overloading-cpp.md).

- [Conversões de tipo definido pelo usuário](../cpp/user-defined-type-conversions-cpp.md)

Os operadores mostrados na tabela a seguir não podem ser sobrecarregados. A tabela inclui os símbolos do pré-processador **#** e **##**.

### <a name="nonredefinable-operators"></a>Operadores não redefiníveis

|Operador|Nome|
|-|-|
|**.**|Seleção de membro|
|**.&#42;**|Seleção de ponteiro para membro|
|**::**|Resolução do escopo|
|**? :**|Condicional|
|**#**|Conversão de pré-processador em cadeia de caracteres|
|**##**|Concatenação de pré-processador|

Embora, de modo geral, os operadores sobrecarregados sejam chamados implicitamente pelo compilador quando são encontrados no código, eles podem ser invocados explicitamente da mesma maneira que qualquer função de membro ou de não membro é chamada:

```cpp
Point pt;
pt.operator+( 3 );  // Call addition operator to add 3 to pt.
```

## <a name="example"></a>Exemplo

A exemplo a seguir sobrecarrega o **+** operador para adicionar dois números complexos e retornam o resultado.

```cpp
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

```Output
6.8, 11.2
```

## <a name="in-this-section"></a>Nesta seção

- [Regras gerais para sobrecarga de operador](../cpp/general-rules-for-operator-overloading.md)

- [Sobrecarga de operadores unários](../cpp/overloading-unary-operators.md)

- [Operadores binários](../cpp/binary-operators.md)

- [Atribuição](../cpp/assignment.md)

- [Chamada de função](../cpp/function-call-cpp.md)

- [Subscrito](../cpp/subscripting.md)

- [Acesso de membro](../cpp/member-access.md)

## <a name="see-also"></a>Consulte também

[Operadores internos, precedência e associatividade C++](../cpp/cpp-built-in-operators-precedence-and-associativity.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)