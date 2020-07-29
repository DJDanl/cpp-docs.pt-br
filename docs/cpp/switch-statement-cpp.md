---
title: :::no-loc(switch):::instrução (C++)
description: 'Referência à instrução C++ padrão :::no-loc(switch)::: no Microsoft Visual Studio C++.'
ms.date: 04/25/2020
f1_keywords:
- :::no-loc(default):::_cpp
- :::no-loc(switch):::_cpp
- :::no-loc(case):::_cpp
helpviewer_keywords:
- ':::no-loc(switch)::: keyword [C++]'
- ':::no-loc(case)::: keyword [C++], in :::no-loc(switch)::: statements'
- ':::no-loc(default)::: keyword [C++]'
no-loc:
- ':::no-loc(switch):::'
- ':::no-loc(case):::'
- ':::no-loc(default):::'
- ':::no-loc(break):::'
- ':::no-loc(while):::'
- ':::no-loc(opt):::'
ms.assetid: 6c3f3ed3-5593-463c-8f4b-b33742b455c6
ms.openlocfilehash: d71989b6d8af0213c4cd6d4fbd8d5a84b318701a
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223584"
---
# <a name="no-locswitch-statement-c"></a>`:::no-loc(switch):::`instrução (C++)

Permite a seleção entre várias seções de código, dependendo do valor de uma expressão integral.

## <a name="syntax"></a>Sintaxe

> *`selection-statement`*:\
> &nbsp;&nbsp;&nbsp;&nbsp;**`:::no-loc(switch):::`**&nbsp;**`(`**&nbsp;*`init-statement`*<sub>:::no-loc(opt):::</sub> <sup>C++ 17</sup>&nbsp;*`condition`*&nbsp;**`)`**&nbsp;*`statement`*

> *`init-statement`*:\
> &nbsp;&nbsp;&nbsp;&nbsp; *`expression-statement`*\
> &nbsp;&nbsp;&nbsp;&nbsp; *`simple-declaration`*

> *`condition`*:\
> &nbsp;&nbsp;&nbsp;&nbsp; *`expression`*\
> &nbsp;&nbsp;&nbsp;&nbsp; *`attribute-specifier-seq`*<sub>:::no-loc(opt):::</sub>&nbsp;*`decl-specifier-seq`*&nbsp;*`declarator`*&nbsp;*`brace-or-equal-initializer`*

> *`labeled-statement`*:\
> &nbsp;&nbsp;&nbsp;&nbsp; **`:::no-loc(case):::`**&nbsp;*`constant-expression`*&nbsp;**`:`**&nbsp;*`statement`*\
> &nbsp;&nbsp;&nbsp;&nbsp; **`:::no-loc(default):::`**&nbsp;**`:`**&nbsp;*`statement`*

## <a name="remarks"></a>Comentários

Uma **`:::no-loc(switch):::`** instrução faz com que o controle seja transferido para um *`labeled-statement`* em seu corpo de instrução, dependendo do valor de *`condition`* .

O *`condition`* deve ter um tipo integral ou ser um tipo de classe que tenha uma conversão não ambígua para o tipo integral. A promoção integral ocorre conforme descrito em [conversões padrão](standard-conversions.md).

O **`:::no-loc(switch):::`** corpo da instrução consiste em uma série de **`:::no-loc(case):::`** rótulos e um :::no-loc(opt)::: rótulo de ional **`:::no-loc(default):::`** . Um *`labeled-statement`* é um desses rótulos e as instruções a seguir. As instruções rotuladas não são requisitos sintáticos, mas a **`:::no-loc(switch):::`** instrução não faz sentido sem elas. Dois *`constant-expression`* valores em **`:::no-loc(case):::`** instruções podem ser avaliados com o mesmo valor. O **`:::no-loc(default):::`** rótulo pode aparecer apenas uma vez. A **`:::no-loc(default):::`** instrução geralmente é colocada no final, mas pode aparecer em qualquer lugar no **`:::no-loc(switch):::`** corpo da instrução. Um **`:::no-loc(case):::`** **`:::no-loc(default):::`** rótulo ou só pode aparecer dentro de uma **`:::no-loc(switch):::`** instrução.

O *`constant-expression`* em cada **`:::no-loc(case):::`** rótulo é convertido em um valor constante que é do mesmo tipo que *`condition`* . Em seguida, ele é comparado com a *`condition`* igualdade. O controle passa para a primeira instrução após o **`:::no-loc(case):::`** *`constant-expression`* valor que corresponde ao valor de *`condition`* . O comportamento resultante é mostrado na tabela a seguir.

### <a name="no-locswitch-statement-behavior"></a>`:::no-loc(switch):::`comportamento da instrução

| Condição | Ação |
|--|--|
| O valor convertido corresponde ao da expressão de controle promovida. | O controle é transferido para a instrução após esse rótulo. |
| Nenhuma das constantes corresponde às constantes nos **`:::no-loc(case):::`** Rótulos; um **`:::no-loc(default):::`** rótulo está presente. | O controle é transferido para o **`:::no-loc(default):::`** rótulo. |
| Nenhuma das constantes corresponde às constantes nos **`:::no-loc(case):::`** Rótulos; nenhum **`:::no-loc(default):::`** rótulo está presente. | O controle é transferido para a instrução após a **`:::no-loc(switch):::`** instrução. |

Se uma expressão correspondente for encontrada, a execução poderá continuar mais tarde **`:::no-loc(case):::`** ou **`:::no-loc(default):::`** Rótulos. A [`:::no-loc(break):::`](../cpp/:::no-loc(break):::-statement-cpp.md) instrução é usada para interromper a execução e transferir o controle para a instrução após a **`:::no-loc(switch):::`** instrução. Sem uma **`:::no-loc(break):::`** instrução, todas as instruções do **`:::no-loc(case):::`** rótulo correspondente ao final do **`:::no-loc(switch):::`** , incluindo o **`:::no-loc(default):::`** , são executadas. Por exemplo:

```cpp
// :::no-loc(switch):::_statement1.cpp
#include <stdio.h>

int main() {
   const char *buffer = "Any character stream";
   int upper:::no-loc(case):::_A, lower:::no-loc(case):::_a, other;
   char c;
   upper:::no-loc(case):::_A = lower:::no-loc(case):::_a = other = 0;

   :::no-loc(while)::: ( c = *buffer++ )   // Walks buffer until NULL
   {
      :::no-loc(switch)::: ( c )
      {
         :::no-loc(case)::: 'A':
            upper:::no-loc(case):::_A++;
            :::no-loc(break):::;
         :::no-loc(case)::: 'a':
            lower:::no-loc(case):::_a++;
            :::no-loc(break):::;
         :::no-loc(default)::::
            other++;
      }
   }
   printf_s( "\nUpper:::no-loc(case)::: A: %d\nLower:::no-loc(case)::: a: %d\nTotal: %d\n",
      upper:::no-loc(case):::_A, lower:::no-loc(case):::_a, (upper:::no-loc(case):::_A + lower:::no-loc(case):::_a + other) );
}
```

No exemplo acima, `upper:::no-loc(case):::_A` será incrementado se `c` for um Upper :::no-loc(case)::: `'A'` . A **`:::no-loc(break):::`** instrução depois `upper:::no-loc(case):::_A++` encerra a execução do **`:::no-loc(switch):::`** corpo da instrução e o controle passa para o **`:::no-loc(while):::`** loop. Sem a **`:::no-loc(break):::`** instrução, a execução "passa" para a próxima instrução rotulada, de modo que `lower:::no-loc(case):::_a` e `other` também seria incrementada. Uma finalidade semelhante é servida pela **`:::no-loc(break):::`** instrução para `:::no-loc(case)::: 'a'` . Se `c` for um menor :::no-loc(case)::: `'a'` , `lower:::no-loc(case):::_a` será incrementado e a **`:::no-loc(break):::`** instrução terminará o **`:::no-loc(switch):::`** corpo da instrução. Se `c` não for um `'a'` ou `'A'` , a **`:::no-loc(default):::`** instrução será executada.

**Visual Studio 2017 e posterior:** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)) o `[[fallthrough]]` atributo é especificado no padrão c++ 17. Você pode usá-lo em uma **`:::no-loc(switch):::`** instrução. É uma dica para o compilador, ou qualquer pessoa que lê o código, o comportamento de passagem é intencional. O compilador do Microsoft C++ atualmente não avisa sobre o comportamento do fallthrough, portanto, esse atributo não tem nenhum efeito sobre o comportamento do compilador. No exemplo, o atributo é aplicado a uma instrução vazia dentro da instrução rotulada não finalizada. Em outras palavras, o ponto e vírgula é necessário.

```cpp
int main()
{
    int n = 5;
    :::no-loc(switch)::: (n)
    {

    :::no-loc(case)::: 1:
        a();
        :::no-loc(break):::;
    :::no-loc(case)::: 2:
        b();
        d();
        [[fallthrough]]; // I meant to do this!
    :::no-loc(case)::: 3:
        c();
        :::no-loc(break):::;
    :::no-loc(default)::::
        d();
        :::no-loc(break):::;
    }

    return 0;
}
```

**Visual Studio 2017 versão 15,3 e posterior** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)). Uma **`:::no-loc(switch):::`** instrução pode ter uma *`init-statement`* cláusula, que termina com um ponto e vírgula. Ele apresenta e Inicializa uma variável cujo escopo é limitado ao bloco da **`:::no-loc(switch):::`** instrução:

```cpp
    :::no-loc(switch)::: (Gadget gadget(args); auto s = gadget.get_status())
    {
    :::no-loc(case)::: status::good:
        gadget.zip();
        :::no-loc(break):::;
    :::no-loc(case)::: status::bad:
        throw BadGadget();
    };
```

Um bloco interno de uma **`:::no-loc(switch):::`** instrução pode conter definições com inicializadores, desde que eles estejam *acessíveis*, ou seja, não sejam ignorados por todos os caminhos de execução possíveis. Os nomes introduzidos por meio dessas declarações têm escopo local. Por exemplo:

```cpp
// :::no-loc(switch):::_statement2.cpp
// C2360 expected
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    :::no-loc(switch):::( tolower( *argv[1] ) )
    {
        // Error. Unreachable declaration.
        char szChEntered[] = "Character entered was: ";

    :::no-loc(case)::: 'a' :
        {
        // Declaration of szChEntered OK. Local scope.
        char szChEntered[] = "Character entered was: ";
        cout << szChEntered << "a\n";
        }
        :::no-loc(break):::;

    :::no-loc(case)::: 'b' :
        // Value of szChEntered undefined.
        cout << szChEntered << "b\n";
        :::no-loc(break):::;

    :::no-loc(default)::::
        // Value of szChEntered undefined.
        cout << szChEntered << "neither a nor b\n";
        :::no-loc(break):::;
    }
}
```

Uma **`:::no-loc(switch):::`** instrução pode ser aninhada. Quando aninhados, **`:::no-loc(case):::`** os **`:::no-loc(default):::`** rótulos ou se associam à **`:::no-loc(switch):::`** instrução mais próxima que os coloca.

### <a name="microsoft-specific-behavior"></a>Comportamento específico da Microsoft

O Microsoft C++ não limita o número de **`:::no-loc(case):::`** valores em uma **`:::no-loc(switch):::`** instrução. O número é limitado somente pela memória disponível.

## <a name="see-also"></a>Confira também

[Instruções de seleção](../cpp/selection-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
