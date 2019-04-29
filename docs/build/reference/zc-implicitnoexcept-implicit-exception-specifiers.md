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
ms.openlocfilehash: ec2b8c8fb4c7730a78c4403606d6fa61c0ddc374
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62315554"
---
# <a name="zcimplicitnoexcept-implicit-exception-specifiers"></a>/Zc:implicitNoexcept (especificadores de exceção implícitos)

Quando o **/ZC: implicitnoexcept** opção for especificada, o compilador adiciona implícito [noexcept](../../cpp/noexcept-cpp.md) especificador de exceção para funções de membro especial definida pelo compilador e destruidores definidos pelo usuário e deallocators. Por padrão, **/ZC: implicitnoexcept** está habilitado em conformidade com o ISO c++11 standard. Desativação dessa opção desabilita implícita `noexcept` sobre destruidores definidos pelo usuário e dealloacators e funções de membro especial definida pelo compilador.

## <a name="syntax"></a>Sintaxe

> **/Zc:implicitNoexcept**[**-**]

## <a name="remarks"></a>Comentários

**/ZC: implicitnoexcept** informa ao compilador para siga a seção 15.4 da ISO c++11 standard. Ele adiciona implicitamente uma `noexcept` especificador de exceção para cada função de membro especial usadas como padrão explicitamente ou implicitamente declarado — o construtor padrão, copie o construtor, o construtor de movimentação, o destruidor, operador de atribuição de cópia ou atribuição de movimentação operador — e cada função definida pelo usuário o destrutor ou desalocador. Um desalocador definida pelo usuário tem implícito `noexcept(true)` especificador de exceção. Para os destruidores definidos pelo usuário, é o especificador de exceção implícitos `noexcept(true)` , a menos que uma classe de membro contido ou classe base tem um destruidor que não seja `noexcept(true)`. Para funções de membro especial gerado pelo compilador, se qualquer função invocada diretamente por essa função é efetivamente `noexcept(false)`, o especificador de exceção implícita é `noexcept(false)`. Caso contrário, o especificador de exceção implícita é `noexcept(true)`.

O compilador não gera um especificador de exceção implícitos para funções declaradas com o uso explícito `noexcept` ou `throw` especificadores ou um `__declspec(nothrow)` atributo.

Por padrão, **/ZC: implicitnoexcept** está habilitado. O [/permissive--](permissive-standards-conformance.md) opção não afeta **/ZC: implicitnoexcept**.

Se a opção estiver desabilitada, especificando **/Zc:implicitNoexcept-**, sem especificadores de exceção implícitas são geradas pelo compilador. Esse comportamento é o mesmo que o Visual Studio 2013, em que os destruidores e deallocators que não tinham especificadores de exceção poderia ter `throw` instruções. Por padrão e quando **/ZC: implicitnoexcept** for especificado, se um `throw` declaração é encontrada em tempo de execução em uma função com implícito `noexcept(true)` especificador, ele faz com que uma invocação imediata do `std::terminate`, e comportamento normal de desenrolamento para manipuladores de exceção não é garantido. Para ajudar a identificar esta situação, o compilador gera [aviso do compilador (nível 1) C4297](../../error-messages/compiler-warnings/compiler-warning-level-1-c4297.md). Se o `throw` é intencional, é recomendável que você altere sua declaração de função para ter uma explícita `noexcept(false)` especificador em vez de usar **/Zc:implicitNoexcept-**.

Este exemplo mostra como um destruidor definido pelo usuário que não tem nenhum especificador de exceção explícita se comporta quando o **/ZC: implicitnoexcept** opção é definida ou desabilitada. Para mostrar o comportamento quando definido, compile usando `cl /EHsc /W4 implicitNoexcept.cpp`. Para mostrar o comportamento quando desabilitado, compile usando `cl /EHsc /W4 /Zc:implicitNoexcept- implicitNoexcept.cpp`.

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

Quando compilado usando a configuração padrão **/ZC: implicitnoexcept**, o exemplo gera esta saída:

```Output
~B Exception caught
Unexpected throw caused std::terminate
Exit returning EXIT_FAILURE
```

Quando compilado usando a configuração **/Zc:implicitNoexcept-**, o exemplo gera esta saída:

```Output
~B Exception caught
~D Exception caught
Exit returning EXIT_SUCCESS
```

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir **/ZC: implicitnoexcept** ou **/Zc:implicitNoexcept-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](zc-conformance.md)<br/>
[noexcept](../../cpp/noexcept-cpp.md)<br/>
[Especificações de exceção (lançar)](../../cpp/exception-specifications-throw-cpp.md)<br/>
[terminate](../../standard-library/exception-functions.md#terminate)<br/>
