---
title: Operador typeid
ms.date: 10/04/2019
helpviewer_keywords:
- typeid operator
ms.assetid: 8871cee6-d6b9-4301-a5cb-bf3dc9798d61
ms.openlocfilehash: 93a2d3c494cd5aadafedcaaae9ec72809d633a4a
ms.sourcegitcommit: c51b2c665849479fa995bc3323a22ebe79d9d7ce
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/07/2019
ms.locfileid: "71998755"
---
# <a name="typeid-operator"></a>Operador typeid

## <a name="syntax"></a>Sintaxe

```
typeid(type-id)
typeid(expression)
```

## <a name="remarks"></a>Comentários

O operador **typeid** permite que o tipo de um objeto seja determinado em tempo de execução.

O resultado de **typeid** é um `const type_info&`. O valor é uma referência a um objeto `type_info` que representa o *tipo-ID* ou o tipo da *expressão*, dependendo de qual forma de **typeid** é usada. Para obter mais informações, consulte [classe type_info](../cpp/type-info-class.md).

O operador **typeid** não funciona com tipos gerenciados (declaradores abstratos ou instâncias). Para obter informações sobre como obter o <xref:System.Type> de um tipo especificado, consulte [typeid](../extensions/typeid-cpp-component-extensions.md).

O operador **typeid** faz uma verificação de tempo de execução quando aplicado a um l-Value de um tipo de classe polimórfico, em que o tipo true do objeto não pode ser determinado pelas informações estáticas fornecidas. Tais casos são:

- Uma referência à classe

- Um ponteiro, com a referência de `*`

- Um ponteiro subscrito (`[ ]`). (Não é seguro usar um subscrito com um ponteiro para um tipo polimórfico.)

Se a *expressão* aponta para um tipo de classe base, mas o objeto é realmente de um tipo derivado dessa classe base, uma referência `type_info` para a classe derivada é o resultado. A *expressão* deve apontar para um tipo polimórfico (uma classe com funções virtuais). Caso contrário, o resultado será o `type_info` para a classe estática referenciada na *expressão*. Além disso, o ponteiro deve ser desreferenciado para que o objeto usado seja aquele para o qual ele aponta. Sem desreferenciar o ponteiro, o resultado será o `type_info` para o ponteiro, não para o que ele aponta. Por exemplo:

```cpp
// expre_typeid_Operator.cpp
// compile with: /GR /EHsc
#include <iostream>
#include <typeinfo>

class Base {
public:
   virtual void vvfunc() {}
};

class Derived : public Base {};

using namespace std;
int main() {
   Derived* pd = new Derived;
   Base* pb = pd;
   cout << typeid( pb ).name() << endl;   //prints "class Base *"
   cout << typeid( *pb ).name() << endl;   //prints "class Derived"
   cout << typeid( pd ).name() << endl;   //prints "class Derived *"
   cout << typeid( *pd ).name() << endl;   //prints "class Derived"
   delete pd;
}
```

Se a *expressão* estiver desreferenciando um ponteiro e o valor do ponteiro for zero, **typeid** lançará uma [exceção bad_typeid](../cpp/bad-typeid-exception.md). Se o ponteiro não apontar para um objeto válido, uma exceção `__non_rtti_object` será lançada. Indica uma tentativa de analisar o RTTI que disparou uma falha porque o objeto é de alguma forma inválido. (Por exemplo, é um ponteiro incorreto ou o código não foi compilado com [/gr](../build/reference/gr-enable-run-time-type-information.md)).

Se a *expressão* não for um ponteiro, e não uma referência a uma classe base do objeto, o resultado será uma referência `type_info` representando o tipo estático da *expressão*. O *tipo estático* de uma expressão refere-se ao tipo de uma expressão como é conhecido no momento da compilação. A semântica da execução é ignorada ao avaliar o tipo estático de uma expressão. Além disso, as referências são ignoradas quando possível para determinar o tipo estático de uma expressão:

```cpp
// expre_typeid_Operator_2.cpp
#include <typeinfo>

int main()
{
   typeid(int) == typeid(int&); // evaluates to true
}
```

**typeid** também pode ser usado em modelos para determinar o tipo de um parâmetro de modelo:

```cpp
// expre_typeid_Operator_3.cpp
// compile with: /c
#include <typeinfo>
template < typename T >
T max( T arg1, T arg2 ) {
   cout << typeid( T ).name() << "s compared." << endl;
   return ( arg1 > arg2 ? arg1 : arg2 );
}
```

## <a name="see-also"></a>Consulte também

[Informações de tipo em tempo de execução](../cpp/run-time-type-information.md)\
[Palavras-chave](../cpp/keywords-cpp.md)
