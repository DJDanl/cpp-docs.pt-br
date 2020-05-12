---
title: switchinstrução (C++)
description: Referência à instrução C++ padrão switch no Microsoft Visual Studio C++.
ms.date: 04/25/2020
f1_keywords:
- default_cpp
- switch_cpp
- case_cpp
helpviewer_keywords:
- switch keyword [C++]
- case keyword [C++], in switch statements
- default keyword [C++]
no-loc:
- switch
- case
- default
- break
- while
- opt
ms.assetid: 6c3f3ed3-5593-463c-8f4b-b33742b455c6
ms.openlocfilehash: d43a7a64b5a74f00833093ae8999d73edd7f5753
ms.sourcegitcommit: c4cf8976939dd0e13e25b82930221323ba6f15d4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/12/2020
ms.locfileid: "83204157"
---
# <a name="switch-statement-c"></a>`switch`instrução (C++)

Permite a seleção entre várias seções de código, dependendo do valor de uma expressão integral.

## <a name="syntax"></a>Sintaxe

> *`selection-statement`*:\
> &nbsp;&nbsp;&nbsp;&nbsp;__`switch`__&nbsp;__`(`__&nbsp;*`init-statement`*<sub>opt</sub> <sup>C++ 17</sup>&nbsp;*`condition`*&nbsp;__`)`__&nbsp;*`statement`*

> *`init-statement`*:\
> &nbsp;&nbsp;&nbsp;&nbsp; *`expression-statement`*\
> &nbsp;&nbsp;&nbsp;&nbsp; *`simple-declaration`*

> *`condition`*:\
> &nbsp;&nbsp;&nbsp;&nbsp; *`expression`*\
> &nbsp;&nbsp;&nbsp;&nbsp; *`attribute-specifier-seq`*<sub>opt</sub>&nbsp;*`decl-specifier-seq`*&nbsp;*`declarator`*&nbsp;*`brace-or-equal-initializer`*

> *`labeled-statement`*:\
> &nbsp;&nbsp;&nbsp;&nbsp; __`case`__&nbsp;*`constant-expression`*&nbsp;__`:`__&nbsp;*`statement`*\
> &nbsp;&nbsp;&nbsp;&nbsp; __`default`__&nbsp;__`:`__&nbsp;*`statement`*

## <a name="remarks"></a>Comentários

Uma __`switch`__ instrução faz com que o controle seja transferido para um *`labeled-statement`* em seu corpo de instrução, dependendo do valor de *`condition`* .

O *`condition`* deve ter um tipo integral ou ser um tipo de classe que tenha uma conversão não ambígua para o tipo integral. A promoção integral ocorre conforme descrito em [conversões padrão](standard-conversions.md).

O __`switch`__ corpo da instrução consiste em uma série de __`case`__ rótulos e um __`default`__ rótulo opcional. Um *`labeled-statement`* é um desses rótulos e as instruções a seguir. As instruções rotuladas não são requisitos sintáticos, mas a __`switch`__ instrução não faz sentido sem elas. Dois *`constant-expression`* valores em __`case`__ instruções podem ser avaliados com o mesmo valor. O __`default`__ rótulo pode aparecer apenas uma vez. A __`default`__ instrução geralmente é colocada no final, mas pode aparecer em qualquer lugar no __`switch`__ corpo da instrução. Um __`case`__ __`default`__ rótulo ou só pode aparecer dentro de uma __`switch`__ instrução.

O *`constant-expression`* em cada __`case`__ rótulo é convertido em um valor constante que é do mesmo tipo que *`condition`* . Em seguida, ele é comparado com a *`condition`* igualdade. O controle passa para a primeira instrução após o __`case`__ *`constant-expression`* valor que corresponde ao valor de *`condition`* . O comportamento resultante é mostrado na tabela a seguir.

### <a name="switch-statement-behavior"></a>`switch`comportamento da instrução

| Condição | Ação |
|--|--|
| O valor convertido corresponde ao da expressão de controle promovida. | O controle é transferido para a instrução após esse rótulo. |
| Nenhuma das constantes corresponde às constantes nos __`case`__ Rótulos; um __`default`__ rótulo está presente. | O controle é transferido para o __`default`__ rótulo. |
| Nenhuma das constantes corresponde às constantes nos __`case`__ Rótulos; nenhum __`default`__ rótulo está presente. | O controle é transferido para a instrução após a __`switch`__ instrução. |

Se uma expressão correspondente for encontrada, a execução poderá continuar mais tarde __`case`__ ou __`default`__ Rótulos. A [`break`](../cpp/break-statement-cpp.md) instrução é usada para interromper a execução e transferir o controle para a instrução após a __`switch`__ instrução. Sem uma __`break`__ instrução, todas as instruções do __`case`__ rótulo correspondente ao final do __`switch`__ , incluindo o __`default`__ , são executadas. Por exemplo:

```cpp
// switch_statement1.cpp
#include <stdio.h>

int main() {
   const char *buffer = "Any character stream";
   int uppercase_A, lowercase_a, other;
   char c;
   uppercase_A = lowercase_a = other = 0;

   while ( c = *buffer++ )   // Walks buffer until NULL
   {
      switch ( c )
      {
         case 'A':
            uppercase_A++;
            break;
         case 'a':
            lowercase_a++;
            break;
         default:
            other++;
      }
   }
   printf_s( "\nUppercase A: %d\nLowercase a: %d\nTotal: %d\n",
      uppercase_A, lowercase_a, (uppercase_A + lowercase_a + other) );
}
```

No exemplo acima, `uppercase_A` será incrementado se `c` for `'A'` maiúsculo. A __`break`__ instrução depois `uppercase_A++` encerra a execução do __`switch`__ corpo da instrução e o controle passa para o __`while`__ loop. Sem a __`break`__ instrução, a execução "passa" para a próxima instrução rotulada, de modo que `lowercase_a` e `other` também seria incrementada. Uma finalidade semelhante é servida pela __`break`__ instrução para `case 'a'` . Se `c` for uma letra minúscula `'a'` , `lowercase_a` será incrementado e a __`break`__ instrução terminará o __`switch`__ corpo da instrução. Se `c` não for um `'a'` ou `'A'` , a __`default`__ instrução será executada.

**Visual Studio 2017 e posterior:** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)) o `[[fallthrough]]` atributo é especificado no padrão c++ 17. Você pode usá-lo em uma __`switch`__ instrução. É uma dica para o compilador, ou qualquer pessoa que lê o código, o comportamento de passagem é intencional. O compilador do Microsoft C++ atualmente não avisa sobre o comportamento do fallthrough, portanto, esse atributo não tem nenhum efeito sobre o comportamento do compilador. No exemplo, o atributo é aplicado a uma instrução vazia dentro da instrução rotulada não finalizada. Em outras palavras, o ponto e vírgula é necessário.

```cpp
int main()
{
    int n = 5;
    switch (n)
    {

    case 1:
        a();
        break;
    case 2:
        b();
        d();
        [[fallthrough]]; // I meant to do this!
    case 3:
        c();
        break;
    default:
        d();
        break;
    }

    return 0;
}
```

**Visual Studio 2017 versão 15,3 e posterior** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)). Uma __`switch`__ instrução pode ter uma *`init-statement`* cláusula, que termina com um ponto e vírgula. Ele apresenta e Inicializa uma variável cujo escopo é limitado ao bloco da __`switch`__ instrução:

```cpp
    switch (Gadget gadget(args); auto s = gadget.get_status())
    {
    case status::good:
        gadget.zip();
        break;
    case status::bad:
        throw BadGadget();
    };
```

Um bloco interno de uma __`switch`__ instrução pode conter definições com inicializadores, desde que eles estejam *acessíveis*, ou seja, não sejam ignorados por todos os caminhos de execução possíveis. Os nomes introduzidos por meio dessas declarações têm escopo local. Por exemplo:

```cpp
// switch_statement2.cpp
// C2360 expected
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    switch( tolower( *argv[1] ) )
    {
        // Error. Unreachable declaration.
        char szChEntered[] = "Character entered was: ";

    case 'a' :
        {
        // Declaration of szChEntered OK. Local scope.
        char szChEntered[] = "Character entered was: ";
        cout << szChEntered << "a\n";
        }
        break;

    case 'b' :
        // Value of szChEntered undefined.
        cout << szChEntered << "b\n";
        break;

    default:
        // Value of szChEntered undefined.
        cout << szChEntered << "neither a nor b\n";
        break;
    }
}
```

Uma __`switch`__ instrução pode ser aninhada. Quando aninhados, __`case`__ os __`default`__ rótulos ou se associam à __`switch`__ instrução mais próxima que os coloca.

### <a name="microsoft-specific-behavior"></a>Comportamento específico da Microsoft

O Microsoft C++ não limita o número de __`case`__ valores em uma __`switch`__ instrução. O número é limitado somente pela memória disponível.

## <a name="see-also"></a>Veja também

[Instruções de seleção](../cpp/selection-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
