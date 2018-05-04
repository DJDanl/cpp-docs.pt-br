---
title: '/ZC: implicitnoexcept (especificadores de exceção implícitos) | Microsoft Docs'
ms.custom: ''
ms.date: 03/06/2018
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- /Zc:implicitNoexcept
dev_langs:
- C++
helpviewer_keywords:
- /Zc:implicitNoexcept
- Zc:implicitNoexcept
- -Zc:implicitNoexcept
ms.assetid: 71807652-6f9d-436b-899e-f52daa6f500b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 7e420017056d6857a2809ce6eb85fe99b6f3866f
ms.sourcegitcommit: be2a7679c2bd80968204dee03d13ca961eaa31ff
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/03/2018
---
# <a name="zcimplicitnoexcept-implicit-exception-specifiers"></a>/Zc:implicitNoexcept (especificadores de exceção implícitos)

Quando o **/ZC: implicitnoexcept** opção for especificada, o compilador adiciona implícita [noexcept](../../cpp/noexcept-cpp.md) especificador de exceção para funções de membro especiais definidas pelo compilador e destruidores definido pelo usuário e deallocators. Por padrão, **/ZC: implicitnoexcept** está habilitado para estar de acordo com o ISO C++ 11 padrão. Desativação dessa opção desabilita implícita `noexcept` destruidores definido pelo usuário e dealloacators e funções de membro especiais definidas pelo compilador.

## <a name="syntax"></a>Sintaxe

> **/Zc:implicitNoexcept**[**-**]

## <a name="remarks"></a>Comentários

**/ZC: implicitnoexcept** informa ao compilador para seguir seção 15.4 do C++ 11 padrão ISO. Adiciona implicitamente um `noexcept` especificador de exceção para cada função de membro especial declarado implicitamente ou explicitamente definido como padrão, o construtor padrão, copiar construtor, mover construtor, destruidor, operador de atribuição de cópia ou mover atribuição operador — e cada função de destrutor ou desalocador definida pelo usuário. Um desalocador definida pelo usuário tem implícita `noexcept(true)` especificador de exceção. Para destruidores definida pelo usuário, o especificador de exceção implícita é `noexcept(true)` , a menos que uma classe de membro contido ou classe base tem um destruidor que não seja `noexcept(true)`. Para funções de membro especial gerada pelo compilador, se qualquer função invocada diretamente por essa função é efetivamente `noexcept(false)`, o especificador de exceção implícita é `noexcept(false)`. Caso contrário, o especificador de exceção implícita é `noexcept(true)`.

O compilador não gera um especificador de exceção implícita para funções declaradas usando explícita `noexcept` ou `throw` especificadores ou `__declspec(nothrow)` atributo.

Por padrão, **/ZC: implicitnoexcept** está habilitado. O [/ permissivo-](permissive-standards-conformance.md) não afeta a opção **/ZC: implicitnoexcept**.

Se a opção estiver desabilitada, especificando **/Zc:implicitNoexcept-**, nenhum especificadores de exceção implícitas são geradas pelo compilador. Esse comportamento é o mesmo que o Visual Studio 2013, onde destruidores e deallocators que não tinham especificadores de exceção podem ter `throw` instruções. Por padrão e quando **/ZC: implicitnoexcept** for especificado, se um `throw` instrução for encontrada em tempo de execução em uma função com implícita `noexcept(true)` especificador, ele faz com que uma chamada imediata de `std::terminate`, e comportamento de desenrolamento normal para manipuladores de exceção não é garantido. Para ajudar a identificar esta situação, o compilador gera [C4297 de aviso do compilador (nível 1)](../../error-messages/compiler-warnings/compiler-warning-level-1-c4297.md). Se o `throw` é intencional, é recomendável que você altere sua declaração de função para ter uma explícita `noexcept(false)` especificador em vez de usar **/Zc:implicitNoexcept-**.

Este exemplo mostra como um destruidor definido pelo usuário que não tem um especificador nenhuma exceção explícita se comporta quando o **/ZC: implicitnoexcept** opção está definida ou desabilitada. Para mostrar o comportamento quando definido, compile usando `cl /EHsc /W4 implicitNoexcept.cpp`. Para mostrar o comportamento quando desabilitado, compile usando `cl /EHsc /W4 /Zc:implicitNoexcept- implicitNoexcept.cpp`.

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

Quando compilado usando a configuração padrão **/ZC: implicitnoexcept**, o exemplo gera essa saída:

```Output
~B Exception caught
Unexpected throw caused std::terminate
Exit returning EXIT_FAILURE
```

Quando compilado usando a configuração **/Zc:implicitNoexcept-**, o exemplo gera essa saída:

```Output
~B Exception caught
~D Exception caught
Exit returning EXIT_SUCCESS
```

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar o **opções adicionais** propriedade incluir **/ZC: implicitnoexcept** ou **/Zc:implicitNoexcept-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](../../build/reference/zc-conformance.md)<br/>
[noexcept](../../cpp/noexcept-cpp.md)<br/>
[Especificações de exceção (lançar)](../../cpp/exception-specifications-throw-cpp.md)<br/>
[terminate](../../standard-library/exception-functions.md#terminate)<br/>
