---
title: Expressões primárias
description: Expressões primárias na linguagem de programação C++.
ms.date: 10/02/2020
helpviewer_keywords:
- primary expressions
- expressions [C++], name
- expressions [C++], literal
- expressions [C++], primary
- expressions [C++], qualified names
ms.assetid: 8ef9a814-6058-4b93-9b6e-e8eb8350b1ca
ms.openlocfilehash: 4c52992071453bc189a3078db9592b02dfb8ba9b
ms.sourcegitcommit: 30792632548d1c71894f9fecbe2f554294b86020
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/06/2020
ms.locfileid: "91765328"
---
# <a name="primary-expressions"></a>Expressões primárias

As expressões primárias são os blocos de construção de expressões mais complexas. Eles podem ser literais, nomes e nomes qualificados pelo operador de resolução de escopo ( `::` ). Uma expressão primária pode ter qualquer uma das seguintes formas:

*`primary-expression`*\
&emsp;*`literal`*\
&emsp;**`this`**\
&emsp;*`name`*\
&emsp;**`::`** *`name`* **`(`** *`expression`* **`)`**

Uma *`literal`* é uma expressão principal constante. Seu tipo depende da forma de sua especificação. Para obter informações completas sobre como especificar literais, consulte [literais](../cpp/numeric-boolean-and-pointer-literals-cpp.md) .

A **`this`** palavra-chave é um ponteiro para um objeto de classe. Ele está disponível em funções de membros não estáticos. Ele aponta para a instância da classe para a qual a função foi invocada. A **`this`** palavra-chave não pode ser usada fora do corpo de uma função de membro de classe.

O tipo do **`this`** ponteiro é `type * const` (em que `type` é o nome da classe) em funções que não modificam especificamente o **`this`** ponteiro. O exemplo a seguir mostra declarações de função de membro e os tipos de **`this`** :

```cpp
// expre_Primary_Expressions.cpp
// compile with: /LD
class Example
{
public:
    void Func();          //  * const this
    void Func() const;    //  const * const this
    void Func() volatile; //  volatile * const this
};
```

Para obter mais informações sobre como modificar o tipo do **`this`** ponteiro, consulte [ `this` pointer](this-pointer.md).

O operador de resolução de escopo ( **`::`** ) seguido por um nome é uma expressão primária.  Tais nomes devem estar no escopo global, não em nomes de membro. O tipo da expressão é determinado pela declaração do nome. É um l-Value (ou seja, pode aparecer no lado esquerdo de uma expressão de atribuição) se o nome declarativo for um valor l. O operador de resolução de escopo permite que um nome global seja referenciado, mesmo se esse nome estiver oculto no escopo atual. Consulte [escopo](../cpp/scope-visual-cpp.md) para obter um exemplo de como usar o operador de resolução de escopo.

Uma expressão entre parênteses é uma expressão primária. Seu tipo e valor são idênticos ao tipo e ao valor da expressão não entre parênteses. É um l-value se a expressão não entre parênteses for um valor l.

Os exemplos de expressões primárias incluem:

```cpp
100 // literal
'c' // literal
this // in a member function, a pointer to the class instance
::func // a global function
::operator + // a global operator function
::A::B // a global qualified name
( i + 1 ) // a parenthesized expression
```

Esses exemplos são todos considerados *nomes*e, por exemplo, expressões primárias, em várias formas:

```cpp
MyClass // an identifier
MyClass::f // a qualified name
operator = // an operator function name
operator char* // a conversion operator function name
~MyClass // a destructor name
A::B   // a qualified name
A<int> // a template id
```

## <a name="see-also"></a>Confira também

[Tipos de expressões](../cpp/types-of-expressions.md)
