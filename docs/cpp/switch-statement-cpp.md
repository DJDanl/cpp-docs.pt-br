---
title: switchdeclaração (C++)
description: Referência à declaração switch Standard C++ no Microsoft Visual Studio C++.
ms.date: 04/15/2020
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
ms.assetid: 6c3f3ed3-5593-463c-8f4b-b33742b455c6
ms.openlocfilehash: 1f65d4699423d74be9c75a9be47e543a9a1256e2
ms.sourcegitcommit: 9266fc76ac2e872e35a208b4249660dfdfc87cba
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/16/2020
ms.locfileid: "81480831"
---
# <a name="opno-locswitch-statement-c"></a>switchdeclaração (C++)

Permite a seleção entre várias seções de código, dependendo do valor de uma expressão integral.

## <a name="syntax"></a>Sintaxe

> **`switch (`**\[ *inicialização* **`;`** *] expressão***`)`**\
> **`{`**\
> &nbsp;&nbsp;&nbsp;&nbsp;**`case`***constant-expression* **`:`** *declaração* de expressão constante\
> &nbsp;&nbsp;&nbsp;&nbsp;\[**`default :`***declaração*] \
> **`}`**

## <a name="remarks"></a>Comentários

A *expressão* deve ter um tipo integral, ou ser um tipo de classe que tenha uma conversão inequívoca para o tipo integral. A promoção integral ocorre conforme descrito nas [conversões Padrão](standard-conversions.md).

O **switch** corpo de declaração **case** consiste em uma **default** série de rótulos e um rótulo opcional. Coletivamente, as declarações que seguem as etiquetas são chamadas de declarações *rotuladas.* As declarações rotuladas não são requisitos **switch** sintáticos, mas a declaração não tem sentido sem elas. Nenhuma expressão constante **case** nas declarações pode avaliar com o mesmo valor. O **default** rótulo pode aparecer apenas uma vez. A **default** declaração é muitas vezes colocada no final, mas **switch** pode aparecer em qualquer lugar no corpo da declaração. Um **case** **default** rótulo ou rótulo **switch** só pode aparecer dentro de uma declaração.

A *expressão constante* **case** em cada rótulo é convertida ao tipo de *expressão*. Então, é comparado com *a expressão* para a igualdade. O controle passa **case** para a declaração cuja *expressão constante* corresponde ao valor da *expressão*. O comportamento resultante é mostrado na tabela a seguir.

### <a name="switch-statement-behavior"></a>Comportamento da declaração de switch

| Condição | Ação |
|--|--|
| O valor convertido corresponde ao da expressão de controle promovida. | O controle é transferido para a instrução após esse rótulo. |
| Nenhuma das constantes corresponde às **case** constantes nos rótulos; um **default** rótulo está presente. | O controle é **default** transferido para a etiqueta. |
| Nenhuma das constantes corresponde às **case** constantes nos rótulos; nenhum **default** rótulo está presente. | O controle é transferido **switch** para a declaração após a declaração. |

Se uma expressão correspondente for encontrada, **case** **default** a execução pode continuar através de rótulos ou rótulos posteriores. A [`break`](../cpp/break-statement-cpp.md) declaração é usada para interromper a **switch** execução e transferir o controle para a declaração após a declaração. Sem **break** uma declaração, todas **case** as declarações **switch** da etiqueta **default** combinada até o final do , incluindo o , são executadas. Por exemplo:

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

No exemplo acima, `uppercase_A` será incrementado se `c` for `'A'` maiúsculo. A **break** declaração após `uppercase_A++` o **switch** término da execução **while** do corpo de declaração e controle passa para o loop. Sem **break** a declaração, a execução "cairia" para `lowercase_a` a `other` próxima declaração rotulada, de modo que e também seria incrementada. Um propósito semelhante é **break** servido `case 'a'`pela declaração para . Se `c` for uma `'a'` `lowercase_a` minúscula, é **break** incrementada **switch** e a declaração encerra o corpo de declaração. Se `c` não for `'a'` `'A'`um **default** ou , a declaração é executada.

**Visual Studio 2017 e posterior:** (disponível com [/std:c++17](../build/reference/std-specify-language-standard-version.md)) O `[[fallthrough]]` atributo está especificado no padrão C++17. Você pode usá-lo em uma **switch** declaração. É uma dica para o compilador, ou qualquer um que leia o código, que o comportamento de queda é intencional. O compilador Microsoft C++ atualmente não avisa sobre o comportamento de transição, portanto este atributo não tem efeito sobre o comportamento do compilador. No exemplo, o atributo é aplicado a uma declaração vazia dentro da declaração rotulada não terminada. Em outras palavras, o ponto e vírgula é necessário.

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

**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std:c++17](../build/reference/std-specify-language-standard-version.md)). Uma switch declaração pode ter uma cláusula *de inicialização.* Ele introduz e inicializa uma variável cujo escopo é switch limitado ao bloco da declaração:

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

Um bloco interno **switch** de uma declaração pode conter definições com inicializações desde que sejam *acessíveis,* ou seja, não contornadas por todos os caminhos de execução possíveis. Os nomes introduzidos por meio dessas declarações têm escopo local. Por exemplo:

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

Uma **switch** declaração pode ser aninhada. Quando aninhados, os **case** rótulos **default** **switch** associam-se à declaração mais próxima que as inclui.

### <a name="microsoft-specific-behavior"></a>Comportamento específico da Microsoft

A Microsoft C não limita **case** o **switch** número de valores em uma declaração. O número é limitado somente pela memória disponível. O ANSI C requer **case** pelo menos 257 rótulos em um **switch** comunicado.

O default para microsoft C é que as extensões da Microsoft estão habilitadas. Use a opção [compilador /Za](../build/reference/za-ze-disable-language-extensions.md) para desativar essas extensões.

## <a name="see-also"></a>Confira também

[Instruções de seleção](../cpp/selection-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
