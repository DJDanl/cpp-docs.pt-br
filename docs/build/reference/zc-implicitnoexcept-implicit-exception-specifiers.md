---
title: /Zc:implicitNoexcept (especificadores de exceção implícitos)
ms.date: 03/06/2018
f1_keywords:
- /Zc:implicitNoexcept
helpviewer_keywords:
- /Zc:implicitNoexcept
- Zc:implicitNoexcept
- -Zc:implicitNoexcept
ms.assetid: 71807652-6f9d-436b-899e-f52daa6f500b
ms.openlocfilehash: bb1a632ffe684ac0777d0089a2edfd514bf66d0b
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87223792"
---
# <a name="zcimplicitnoexcept-implicit-exception-specifiers"></a>/Zc:implicitNoexcept (especificadores de exceção implícitos)

Quando a opção **/Zc: implicitNoexcept** é especificada, o compilador adiciona um especificador de exceção [noexcept](../../cpp/noexcept-cpp.md) implícito às funções de membro especial definidas pelo compilador e aos destruidores e desalocadores definidos pelo usuário. Por padrão, **/Zc: implicitNoexcept** está habilitado para estar em conformidade com o padrão ISO c++ 11. Desativar essa opção desabilita o implícito **`noexcept`** em destruidores definidos pelo usuário e dealloacators e funções de membro especiais definidas pelo compilador.

## <a name="syntax"></a>Sintaxe

> **/Zc: implicitNoexcept**[ **-** ]

## <a name="remarks"></a>Comentários

**/Zc: implicitNoexcept** informa o compilador para seguir a seção 15,4 do padrão ISO c++ 11. Ele adiciona implicitamente um **`noexcept`** especificador de exceção a cada função de membro especial implicitamente declarada ou explicitamente padronizada — o construtor padrão, o construtor de cópia, o construtor de movimentação, o destruidor, o operador de atribuição de cópia ou o operador de atribuição de movimento — e cada função de desalocador ou destruidor definido pelo usuário. Um desalocador definido pelo usuário tem um `noexcept(true)` especificador de exceção implícito. Para destruidores definidos pelo usuário, o especificador de exceção implícita é `noexcept(true)` a menos que uma classe de membro independente ou classe base tenha um destruidor que não é `noexcept(true)` . Para funções de membro especiais geradas pelo compilador, se qualquer função invocada diretamente por essa função for efetivamente `noexcept(false)` , o especificador de exceção implícita será `noexcept(false)` . Caso contrário, o especificador de exceção implícita será `noexcept(true)` .

O compilador não gera um especificador de exceção implícito para funções declaradas usando explícitos **`noexcept`** ou **`throw`** especificadores ou um `__declspec(nothrow)` atributo.

Por padrão, **/Zc: implicitNoexcept** está habilitado. A opção [/permissive-](permissive-standards-conformance.md) não afeta **/Zc: implicitNoexcept**.

Se a opção for desabilitada especificando **/Zc: implicitNoexcept-**, nenhum especificador de exceção implícito será gerado pelo compilador. Esse comportamento é o mesmo que Visual Studio 2013, onde destruidores e desalocadores que não tinham especificadores de exceção podem ter **`throw`** instruções. Por padrão, e quando **/Zc: implicitNoexcept** for especificado, se uma **`throw`** instrução for encontrada em tempo de execução em uma função com um `noexcept(true)` especificador implícito, isso causará uma invocação imediata `std::terminate` e o comportamento normal de desenrolamento para manipuladores de exceção não será garantido. Para ajudar a identificar essa situação, o compilador gera o [aviso do compilador (nível 1) C4297](../../error-messages/compiler-warnings/compiler-warning-level-1-c4297.md). Se o **`throw`** for intencional, recomendamos que você altere sua declaração de função para ter um `noexcept(false)` especificador explícito em vez de usar **/Zc: implicitNoexcept-**.

Este exemplo mostra como um destruidor definido pelo usuário que não tem um especificador de exceção explícito se comporta quando a opção **/Zc: implicitNoexcept** é definida ou desabilitada. Para mostrar o comportamento quando definido, compile usando `cl /EHsc /W4 implicitNoexcept.cpp` . Para mostrar o comportamento quando desabilitado, compile usando `cl /EHsc /W4 /Zc:implicitNoexcept- implicitNoexcept.cpp` .

```cpp
// implicitNoexcept.cpp
// Compile by using: cl /EHsc /W4 implicitNoexcept.cpp
// Compile by using: cl /EHsc /W4 /Zc:implicitNoexcept- implicitNoexcept.cpp

#include <iostream>
#include <cstdlib>      // for std::exit, EXIT_FAILURE, EXIT_SUCCESS
#include <exception>    // for std::set_terminate

void my_terminate()
{
    std::cout << "Unexpected throw caused std::terminate" << std::endl;
    std::cout << "Exit returning EXIT_FAILURE" << std::endl;
    std::exit(EXIT_FAILURE);
}

struct A {
    // Explicit noexcept overrides implicit exception specification
    ~A() noexcept(false) {
        throw 1;
    }
};

struct B : public A {
    // Compiler-generated ~B() definition inherits noexcept(false)
    ~B() = default;
};

struct C {
    // By default, the compiler generates an implicit noexcept(true)
    // specifier for this user-defined destructor. To enable it to
    // throw an exception, use an explicit noexcept(false) specifier,
    // or compile by using /Zc:implicitNoexcept-
    ~C() {
        throw 1; // C4297, calls std::terminate() at run time
    }
};

struct D : public C {
    // This destructor gets the implicit specifier of its base.
    ~D() = default;
};

int main()
{
    std::set_terminate(my_terminate);

    try
    {
        {
            B b;
        }
    }
    catch (...)
    {
        // exception should reach here in all cases
        std::cout << "~B Exception caught" << std::endl;
    }
    try
    {
        {
            D d;
        }
    }
    catch (...)
    {
        // exception should not reach here if /Zc:implicitNoexcept
        std::cout << "~D Exception caught" << std::endl;
    }
    std::cout << "Exit returning EXIT_SUCCESS" << std::endl;
    return EXIT_SUCCESS;
}
```

Quando compilado usando a configuração padrão **/Zc: implicitNoexcept**, o exemplo gera essa saída:

```Output
~B Exception caught
Unexpected throw caused std::terminate
Exit returning EXIT_FAILURE
```

Quando compilado usando a configuração **/Zc: implicitNoexcept-**, o exemplo gera essa saída:

```Output
~B Exception caught
~D Exception caught
Exit returning EXIT_SUCCESS
```

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando**C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções adicionais** para incluir **/Zc: implicitNoexcept** ou **/Zc: implicitNoexcept-** e escolha **OK**.

## <a name="see-also"></a>Confira também

[/Zc (conformidade)](zc-conformance.md)<br/>
[noexcept](../../cpp/noexcept-cpp.md)<br/>
[Especificações de exceção (throw)](../../cpp/exception-specifications-throw-cpp.md)<br/>
[encerrar](../../standard-library/exception-functions.md#terminate)<br/>
