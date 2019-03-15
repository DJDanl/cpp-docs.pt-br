---
title: '/ZC: noexcepttypes (c + + regras noexcept c++17)'
ms.date: 11/14/2017
f1_keywords:
- /Zc:noexceptTypes
helpviewer_keywords:
- /Zc:noexceptTypes
- Zc:noexceptTypes
- -Zc:noexceptTypes
ms.assetid: 1cbf7e3c-0f82-4f91-84dd-612bcf26d2c6
ms.openlocfilehash: 28e06f54049d36262134b6be7eadb0e6e5349a45
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57812103"
---
# <a name="zcnoexcepttypes-c17-noexcept-rules"></a>/ZC: noexcepttypes (c + + regras noexcept c++17)

Torna o padrão c++17 `throw()` como um alias para `noexcept`, remove `throw(<type list>)` e `throw(...)`e permite que certos tipos incluem `noexcept`. Isso pode causar uma série de problemas de compatibilidade de origem no código que está em conformidade com a C + + 14 ou anterior. O **/ZC: noexcepttypes** opção pode especificar a conformidade com o padrão c++17 ou permitir que o C + + 14 e anterior comportamento quando o código é compilado no modo c++17.

## <a name="syntax"></a>Sintaxe

> **/Zc:noexceptTypes**[-]

## <a name="remarks"></a>Comentários

Quando o **/ZC: noexcepttypes** opção for especificada, o compilador esteja de acordo com o padrão C++ 17 e trata [Throw ()](../../cpp/exception-specifications-throw-cpp.md) como um alias para [noexcept](../../cpp/noexcept-cpp.md), remove `throw(<type list>)`e `throw(...)`e permite que certos tipos incluem `noexcept`. O **/ZC: noexcepttypes** opção está disponível apenas quando [/std: c + + 17](std-specify-language-standard-version.md) ou [/std:latest](std-specify-language-standard-version.md) está habilitado. **/ZC: noexcepttypes** é habilitado por padrão em conformidade com ISO C++ 17 standard. O [/permissive--](permissive-standards-conformance.md) opção não afeta **/ZC: noexcepttypes**. Desativar essa opção, especificando **/Zc:noexceptTypes-** para reverter para o comportamento do c++14 do `noexcept` quando **/std::C + + 17** ou **/std::latest** for especificado.

A partir do Visual Studio 2017 versão 15.5, o compilador do C++ diagnostica mais especificações de exceção incompatíveis em declarações no modo c++17 ou quando o [/permissive--](permissive-standards-conformance.md) opção for especificada.

Este exemplo mostra como declarações com um especificador de exceção se comportam quando o **/ZC: noexcepttypes** opção é definida ou desabilitada. Para mostrar o comportamento quando definido, compile usando `cl /EHsc /W4 noexceptTypes.cpp`. Para mostrar o comportamento quando desabilitado, compile usando `cl /EHsc /W4 /Zc:noexceptTypes- noexceptTypes.cpp`.

```cpp
// noexceptTypes.cpp
// Compile by using: cl /EHsc /W4 noexceptTypes.cpp
// Compile by using: cl /EHsc /W4 /Zc:noexceptTypes- noexceptTypes.cpp

void f() throw();    // equivalent to void f() noexcept;
void f() { }         // warning C5043
void g() throw(...); // warning C5040

struct A
{
    virtual void f() throw();
};

struct B : A
{
    virtual void f() { } // error C2694
};
```

Quando compilado usando a configuração padrão **/ZC: noexcepttypes**, o exemplo gera os avisos listados. Para atualizar seu código, use o seguinte:

```cpp
void f() noexcept;
void f() noexcept { }
void g() noexcept(false);

struct A
{
    virtual void f() noexcept;
};

struct B : A
{
    virtual void f() noexcept { }
};
```

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [propriedades de compilador e de build definida C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar a **opções adicionais** propriedade incluir **/ZC: noexcepttypes** ou **/Zc:noexceptTypes-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](zc-conformance.md)<br/>
[noexcept](../../cpp/noexcept-cpp.md)<br/>
[Especificações de exceção (lançar)](../../cpp/exception-specifications-throw-cpp.md)
