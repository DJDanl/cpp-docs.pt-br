---
title: Instrução switch (C++)
ms.date: 11/04/2016
f1_keywords:
- default_cpp
- switch_cpp
- case_cpp
helpviewer_keywords:
- switch keyword [C++]
- case keyword [C++], in switch statements
- default keyword [C++]
ms.assetid: 6c3f3ed3-5593-463c-8f4b-b33742b455c6
ms.openlocfilehash: 67918b7df747d3bee923da500729e60b4fe04336
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62267083"
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

O *expressão* deve ser do tipo integral ou de um tipo de classe para o qual há uma conversão inequívoca para tipo integral. Promoção de integral é executada conforme descrito em [conversões padrão](standard-conversions.md).

O **alternar** corpo da instrução consiste em uma série de **caso** rótulos e um opcional **padrão** rótulo. Não há duas expressões de constantes em **caso** instruções podem ser avaliada como o mesmo valor. O **padrão** rótulo pode aparecer apenas uma vez. As instruções rotuladas não são requisitos sintáticos, mas o **alternar** instrução não faz sentida sem elas.   A instrução default não precisa vir no final; ela pode aparecer em qualquer lugar no corpo da instrução switch. Um rótulo case ou default só pode aparecer dentro de uma instrução switch.

O *expressão-constante* em cada **caso** rótulo é convertido para o tipo de *expressão* e em comparação com *expressão* para igualdade. Controle passa para a instrução cuja **caso** *expressão de constante* corresponde ao valor de *expressão*. O comportamento resultante é mostrado na tabela a seguir.

### <a name="switch-statement-behavior"></a>Comportamento da instrução switch

|Condição|Ação|
|---------------|------------|
|O valor convertido corresponde ao da expressão de controle promovida.|O controle é transferido para a instrução após esse rótulo.|
|Nenhuma das constantes corresponde às constantes na **caso** rotula; um **padrão** rótulo estiver presente.|O controle é transferido para o **padrão** rótulo.|
|Nenhuma das constantes corresponde às constantes na **caso** rótulos; **padrão** rótulo não está presente.|O controle é transferido para a instrução após o **alternar** instrução.|

Se uma expressão correspondente for encontrada, o controle não será impedido pelos subsequentes **caso** ou **padrão** rótulos. O [quebra](../cpp/break-statement-cpp.md) instrução é usada para interromper a execução e transferir o controle para a instrução após a **alternar** instrução. Sem um **quebra** instrução, cada instrução do correspondente **caso** rótulo ao final dos **alternar**, incluindo o **padrão**, é executado. Por exemplo:

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

No exemplo acima, `capa` será incrementado se `c` for `A` maiúsculo. O **quebra** instrução após `capa++` finaliza a execução do **alternar** corpo da instrução e o controle passa para o **enquanto** loop. Sem o **quebra** instrução, execução seria "passar" para a próxima instrução rotulada, para que `lettera` e `nota` também seriam incrementados. Uma finalidade similar é atendida pela **quebra** instrução para `case 'a'`. Se `c` está em letras minúsculas `a`, `lettera` é incrementado e a **quebra** instrução finaliza a **alternar** corpo da instrução. Se `c` não é um `a` ou `A`, o **padrão** instrução é executada.

**Visual Studio 2017 e posterior:** (disponível com [/std:c++17 + + 17](../build/reference/std-specify-language-standard-version.md)) o `[[fallthrough]]` atributo é especificado no C++ 17 standard. Ele pode ser usado em uma **alternar** instrução como uma dica para o compilador (ou para qualquer pessoa que leia o código) destina-se que o comportamento fall-through. O compilador do Visual C++ no momento não avisa sobre o comportamento de fallthrough, para que esse atributo não tem nenhum efeito no comportamento do compilador. Observe que o atributo é aplicado a uma instrução vazia dentro da instrução rotulada; em outras palavras, o ponto e vírgula é necessário.

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

**Visual Studio 2017 versão 15.3 e posterior** (disponível com [/std: c + + 17](../build/reference/std-specify-language-standard-version.md)):  Uma instrução switch pode introduzir e inicializar uma variável cujo escopo esteja limitado para o bloco de instrução switch:

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

Um bloco interno de um **alternar** instrução pode conter definições com inicializações, desde que elas sejam acessíveis — ou seja, não sejam ignoradas por todos os possíveis caminhos de execução. Os nomes introduzidos por meio dessas declarações têm escopo local. Por exemplo:

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

Um **alternar** instrução pode ser aninhada. Nesses casos, **caso** ou **padrão** rótulos associar com o mais próximo **alternar** instrução que inclui-los.

**Seção específica da Microsoft**

O Microsoft C não limita o número de valores de case em uma **alternar** instrução. O número é limitado somente pela memória disponível. ANSI C requer pelo menos 257 rótulos case sejam permitidos em uma **alternar** instrução.

O padrão do Microsoft C é que as extensões da Microsoft sejam habilitadas. Use o [/Za](../build/reference/za-ze-disable-language-extensions.md) opção de compilador para desabilitar essas extensões.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Instruções de seleção](../cpp/selection-statements-cpp.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)