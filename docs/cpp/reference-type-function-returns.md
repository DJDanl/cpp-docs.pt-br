---
title: Retornos de funções de tipo de referência
ms.date: 11/04/2016
helpviewer_keywords:
- function return types [C++], reference type
- data types [C++], function return types
- functions [C++], return types
ms.assetid: 5b73be1d-2dc7-41df-ab0a-adcba36f2ad1
ms.openlocfilehash: 5e84643713dcbcb278fe7ce07c5d55f3593ec2ef
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188292"
---
# <a name="reference-type-function-returns"></a>Retornos de funções de tipo de referência

As funções podem ser declaradas para retornar um tipo de referência. Há duas razões para fazer tal declaração:

- As informações retornadas são um objeto tão grande que retornar uma referência é mais eficiente do que retornar uma cópia.

- O tipo da função deve ser um l-value.

- O objeto referenciado não ficará fora do escopo quando a função retornar.

Assim como pode ser mais eficiente para passar objetos grandes *para* funções por referência, também pode ser mais eficiente retornar objetos grandes *de* funções por referência. O protocolo de retorno de referência elimina a necessidade de copiar o objeto em um local temporário antes de retornar.

Os tipos de retorno de referência também podem ser úteis quando a função deve ser avaliada como um l-value. A maioria dos operadores sobrecarregados entra nessa categoria, particularmente o operador de atribuição. Operadores sobrecarregados são abordados em [operadores sobrecarregados](../cpp/operator-overloading.md).

## <a name="example"></a>Exemplo

Considere o exemplo de `Point`:

```cpp
// refType_function_returns.cpp
// compile with: /EHsc

#include <iostream>
using namespace std;

class Point
{
public:
// Define "accessor" functions as
//  reference types.
unsigned& x();
unsigned& y();
private:
// Note that these are declared at class scope:
unsigned obj_x;
unsigned obj_y;
};

unsigned& Point :: x()
{
return obj_x;
}
unsigned& Point :: y()
{
return obj_y;
}

int main()
{
Point ThePoint;
// Use x() and y() as l-values.
ThePoint.x() = 7;
ThePoint.y() = 9;

// Use x() and y() as r-values.
cout << "x = " << ThePoint.x() << "\n"
<< "y = " << ThePoint.y() << "\n";
}
```

## <a name="output"></a>Saída

```Output
x = 7
y = 9
```

Observe que as funções `x` e `y` são declaradas como tipos de referência de retorno. Essas funções podem ser usadas em ambos os lados de uma instrução de atribuição.

Observe também que, em Main, o objeto Point permanece no escopo e, portanto, seus membros de referência ainda estão ativos e podem ser acessados com segurança.

As declarações de tipos de referência devem conter inicializadores, exceto nos seguintes casos:

- Declaração **extern** explícita

- Declaração de um membro de classe

- Declaração em uma classe

- Declaração de um argumento para uma função ou o tipo de retorno para uma função

## <a name="caution-returning-address-of-local"></a>Cuidado ao retornar o endereço do local

Se você declarar um objeto no escopo local, esse objeto será destruído quando a função retornar. Se a função retornar uma referência a esse objeto, essa referência provavelmente causará uma violação de acesso em tempo de execução se o chamador tentar usar a referência nula.

```cpp
// C4172 means Don’t do this!!!
Foo& GetFoo()
{
    Foo f;
    ...
    return f;
} // f is destroyed here
```

O compilador emite um aviso nesse caso: `warning C4172: returning address of local variable or temporary`. Em programas simples, é possível que, ocasionalmente, nenhuma violação de acesso ocorra se a referência for acessada pelo chamador antes de o local da memória ser substituído. Isso ocorre devido à simples sorte. Preste atenção ao aviso.

## <a name="see-also"></a>Confira também

[Referências](../cpp/references-cpp.md)
