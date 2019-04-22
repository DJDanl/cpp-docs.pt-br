---
title: Operador typeid
ms.date: 11/04/2016
helpviewer_keywords:
- typeid operator
ms.assetid: 8871cee6-d6b9-4301-a5cb-bf3dc9798d61
ms.openlocfilehash: b1185f48df4a941eb2a5d81bfa67d07cdf4387d0
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "58780880"
---
# <a name="typeid-operator"></a>Operador typeid

## <a name="syntax"></a>Sintaxe

```
typeid(type-id)
typeid(expression)
```

## <a name="remarks"></a>Comentários

O **typeid** operador permite que o tipo de um objeto seja determinado em tempo de execução.

O resultado de **typeid** é um `const type_info&`. O valor é uma referência a um `type_info` objeto que representa um o *id do tipo* ou o tipo dos *expressão*, dependendo de qual forma de **typeid** é usado. Ver [classe type_info](../cpp/type-info-class.md) para obter mais informações.

O **typeid** operador não funciona com tipos gerenciados (declarators abstratos ou instâncias), consulte [typeid](../extensions/typeid-cpp-component-extensions.md) para obter informações sobre o <xref:System.Type> de um tipo especificado.

O **typeid** operador faz uma verificação de tempo de execução quando aplicado a um l-value de um tipo de classe polimórfica, onde o verdadeiro tipo do objeto não pode ser determinado pelas informações estáticas fornecidas. Tais casos são:

- Uma referência à classe

- Um ponteiro, desreferenciado com \*

- Um ponteiro subscrito (isto é, []). (Geralmente, não é seguro usar um subscrito com um ponteiro para um tipo polimórfico.)

Se o *expressão* aponta para um tipo de classe base, mas na verdade, o objeto é de um tipo derivado dessa classe base, um `type_info` de referência para a classe derivada é o resultado. O *expressão* deve apontar para um tipo polimórfico (uma classe com funções virtuais). Caso contrário, o resultado é o `type_info` para a classe estática referenciada na *expressão*. Além disso, o ponteiro deve ser desreferenciado de forma que o objeto para o qual ele aponta seja usado. Sem desreferenciar o ponteiro, o resultado será o `type_info` para o ponteiro não que ele aponta. Por exemplo:

```cpp
// expre_typeid_Operator.cpp
// compile with: /GR /EHsc
#include <iostream>
#include <typeinfo.h>

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

Se o *expressão* estiver desreferenciando um ponteiro, e o valor do ponteiro for zero, **typeid** gera um [exceção bad_typeid](../cpp/bad-typeid-exception.md). Se o ponteiro não apontar para um objeto válido, um `__non_rtti_object` exceção for lançada, indicando uma tentativa de analisar o RTTI que acionou uma falha (como violação de acesso), porque o objeto de alguma forma, é inválido (ponteiro incorreto ou o código não foram compilado com [/GR](../build/reference/gr-enable-run-time-type-information.md)).

Se o *expressão* não é um ponteiro nem uma referência a uma classe base do objeto, o resultado é um `type_info` referência que representa o tipo estático dos *expressão*. O *tipo estático* de uma expressão se refere ao tipo de uma expressão como é conhecido no tempo de compilação. A semântica da execução é ignorada ao avaliar o tipo estático de uma expressão. Além disso, as referências são ignoradas quando possível para determinar o tipo estático de uma expressão:

```cpp
// expre_typeid_Operator_2.cpp
#include <typeinfo>

int main()
{
   typeid(int) == typeid(int&); // evaluates to true
}
```

**TypeId** também pode ser usado em modelos para determinar o tipo de um parâmetro de modelo:

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

[Informações de tipo em tempo de execução](../cpp/run-time-type-information.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)