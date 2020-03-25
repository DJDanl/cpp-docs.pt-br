---
title: Instrução switch (C++)
ms.date: 05/06/2019
f1_keywords:
- default_cpp
- switch_cpp
- case_cpp
helpviewer_keywords:
- switch keyword [C++]
- case keyword [C++], in switch statements
- default keyword [C++]
ms.assetid: 6c3f3ed3-5593-463c-8f4b-b33742b455c6
ms.openlocfilehash: 6b09c0eac939f7ca6a12b68ce5deb3fb83ad27c6
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80160808"
---
# <a name="switch-statement-c"></a>Instrução switch (C++)

Permite a seleção entre várias seções de código, dependendo do valor de uma expressão integral.

## <a name="syntax"></a>Sintaxe

```
   switch ( init; expression )
   case constant-expression : statement
   [default  : statement]
```

## <a name="remarks"></a>Comentários

A *expressão* deve ser de um tipo integral ou de um tipo de classe para o qual haja uma conversão não ambígua para o tipo integral. A promoção integral é executada conforme descrito em [conversões padrão](standard-conversions.md).

O corpo da instrução **switch** consiste em uma série de rótulos **Case** e um rótulo **padrão** opcional. Não há duas expressões constantes em instruções **Case** que podem ser avaliadas com o mesmo valor. O rótulo **padrão** pode aparecer apenas uma vez. As instruções rotuladas não são requisitos sintáticos, mas a instrução **switch** não faz sentido sem elas.   A instrução default não precisa vir no final; ela pode aparecer em qualquer lugar no corpo da instrução switch. Um rótulo case ou default só pode aparecer dentro de uma instrução switch.

A *expressão de constante* em cada rótulo de **caso** é convertida para o tipo de *expressão* e comparada com a *expressão* de igualdade. O controle passa para a instrução cuja *expressão constante* **Case** corresponde ao valor de *expression*. O comportamento resultante é mostrado na tabela a seguir.

### <a name="switch-statement-behavior"></a>Comportamento da instrução switch

|Condição|Ação|
|---------------|------------|
|O valor convertido corresponde ao da expressão de controle promovida.|O controle é transferido para a instrução após esse rótulo.|
|Nenhuma das constantes corresponde às constantes nos rótulos de **caso** ; um rótulo **padrão** está presente.|O controle é transferido para o rótulo **padrão** .|
|Nenhuma das constantes corresponde às constantes nos rótulos de **caso** ; o rótulo **padrão** não está presente.|O controle é transferido para a instrução após a instrução **switch** .|

Se uma expressão correspondente for encontrada, o controle não será impedido por rótulos de **caso** ou **padrão** subsequentes. A instrução [Break](../cpp/break-statement-cpp.md) é usada para interromper a execução e transferir o controle para a instrução após a instrução **switch** . Sem uma instrução **Break** , todas as instruções do rótulo **Case** correspondente ao final do **comutador**, incluindo o **padrão**, são executadas. Por exemplo:

```cpp
// switch_statement1.cpp
#include <stdio.h>

int main() {
   char *buffer = "Any character stream";
   int capa, lettera, nota;
   char c;
   capa = lettera = nota = 0;

   while ( c = *buffer++ )   // Walks buffer until NULL
   {
      switch ( c )
      {
         case 'A':
            capa++;
            break;
         case 'a':
            lettera++;
            break;
         default:
            nota++;
      }
   }
   printf_s( "\nUppercase a: %d\nLowercase a: %d\nTotal: %d\n",
      capa, lettera, (capa + lettera + nota) );
}
```

No exemplo acima, `capa` será incrementado se `c` for `A` maiúsculo. A instrução **Break** após `capa++` encerra a execução do corpo da instrução **switch** e o controle passa para o loop **while** . Sem a instrução **Break** , a execução "passa" para a próxima instrução rotulada, de modo que `lettera` e `nota` também seriam incrementadas. Uma finalidade semelhante é servida pela instrução **Break** para `case 'a'`. Se `c` for uma `a`minúscula, `lettera` será incrementado e a instrução **Break** terminará o corpo da instrução **switch** . Se `c` não for um `a` ou `A`, a instrução **padrão** será executada.

**Visual Studio 2017 e posterior:** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)) o atributo `[[fallthrough]]` é especificado no padrão c++ 17. Ele pode ser usado em uma instrução **switch** como uma dica ao compilador (ou a qualquer pessoa que leia o código) que o comportamento de passagem é pretendido. O compilador C++ da Microsoft atualmente não avisa sobre o comportamento do fallthrough, portanto, esse atributo não tem nenhum efeito sobre o comportamento do compilador. Observe que o atributo é aplicado a uma instrução vazia dentro da instrução rotulada; em outras palavras, o ponto e vírgula é necessário.

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

**Visual Studio 2017 versão 15,3 e posterior** (disponível com [/std: c++ 17](../build/reference/std-specify-language-standard-version.md)): uma instrução switch pode introduzir e inicializar uma variável cujo escopo é limitado ao bloco da instrução switch:

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

Um bloco interno de uma instrução **switch** pode conter definições com inicializações, desde que elas estejam acessíveis, ou seja, não ignoradas por todos os caminhos de execução possíveis. Os nomes introduzidos por meio dessas declarações têm escopo local. Por exemplo:

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

Uma instrução **switch** pode ser aninhada. Nesses casos, os rótulos de **caso** ou **padrão** são associados à instrução de **comutador** mais próxima que os coloca.

**Seção específica da Microsoft**

O Microsoft C não limita o número de valores case em uma instrução **switch** . O número é limitado somente pela memória disponível. ANSI C requer pelo menos 257 rótulos de caso sejam permitidos em uma instrução **switch** .

O padrão do Microsoft C é que as extensões da Microsoft sejam habilitadas. Use a opção de compilador [/za](../build/reference/za-ze-disable-language-extensions.md) para desabilitar essas extensões.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Instruções de seleção](../cpp/selection-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
