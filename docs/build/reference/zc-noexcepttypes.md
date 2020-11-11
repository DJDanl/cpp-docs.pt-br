---
title: /Zc:noexceptTypes (Regras noexcept C++17)
description: 'Saiba mais sobre a opção de compilador Microsoft C++/Zc: noexceptTypes para conformidade ou reduzida de C++ 17 noexcept de compatibilidade de código-fonte.'
ms.date: 06/04/2020
f1_keywords:
- /Zc:noexceptTypes
helpviewer_keywords:
- /Zc:noexceptTypes
- Zc:noexceptTypes
- -Zc:noexceptTypes
ms.assetid: 1cbf7e3c-0f82-4f91-84dd-612bcf26d2c6
ms.openlocfilehash: c15d4203f343eced7c112757b2665aa71a982c7c
ms.sourcegitcommit: 25f6d52eb9e5d84bd0218c46372db85572af81da
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/10/2020
ms.locfileid: "94448497"
---
# <a name="zcnoexcepttypes-c17-noexcept-rules"></a>/Zc:noexceptTypes (Regras noexcept C++17)

O padrão c++ 17 faz `throw()` um alias para **`noexcept`** , remove `throw(` *`type-list`* `)` e `throw(...)` e permite que determinados tipos sejam incluídos **`noexcept`** . Essa alteração pode causar uma série de problemas de compatibilidade de origem no código que está em conformidade com C++ 14 ou anterior. A **`/Zc:noexceptTypes`** opção especifica conformidade com o padrão c++ 17. **`/Zc:noexceptTypes-`**  permite o comportamento C++ 14 e anterior quando o código é compilado no modo C++ 17.

## <a name="syntax"></a>Syntax

> **`/Zc:noexceptTypes`**\[**`-`** ]

## <a name="remarks"></a>Comentários

Quando a **`/Zc:noexceptTypes`** opção é especificada, o compilador está em conformidade com o padrão c++ 17 e trata [`throw()`](../../cpp/exception-specifications-throw-cpp.md) como um alias para [`noexcept`](../../cpp/noexcept-cpp.md) , remove `throw(` *`type-list`* `)` e `throw(...)` e permite que determinados tipos sejam incluídos **`noexcept`** . A **`/Zc:noexceptTypes`** opção só está disponível quando [`/std:c++17`](std-specify-language-standard-version.md) ou [`/std:c++latest`](std-specify-language-standard-version.md) está habilitada. **`/Zc:noexceptTypes`** é habilitado por padrão para estar em conformidade com o padrão ISO C++ 17. A [`/permissive-`](permissive-standards-conformance.md) opção não afeta **`/Zc:noexceptTypes`** . Desative essa opção especificando **`/Zc:noexceptTypes-`** para reverter para o comportamento de c++ 14 de **`noexcept`** quando **`/std:c++17`** ou **`/std:c++latest`** for especificado.

A partir do Visual Studio 2017 versão 15,5, o compilador C++ diagnostica mais especificações de exceção incompatíveis em declarações no modo C++ 17 ou quando você especifica a [`/permissive-`](permissive-standards-conformance.md) opção.

Este exemplo mostra como as declarações com um especificador de exceção se comportam quando a **`/Zc:noexceptTypes`** opção é definida ou desabilitada. Para mostrar o comportamento quando definido, compile usando `cl /EHsc /W4 noexceptTypes.cpp` . Para mostrar o comportamento quando desabilitado, compile usando `cl /EHsc /W4 /Zc:noexceptTypes- noexceptTypes.cpp` .

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

Quando compilado usando a configuração padrão **`/Zc:noexceptTypes`** , o exemplo gera os avisos listados. Para atualizar seu código, use o seguinte:

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

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a **Configuration Properties**  >  página de propriedade de linha de comando **C/C++** Propriedades de configuração  >  **Command Line** .

1. Modifique a propriedade **Opções adicionais** para incluir *`/Zc:noexceptTypes`* ou *`/Zc:noexceptTypes-`* e, em seguida, escolha **OK**.

## <a name="see-also"></a>Confira também

[`/Zc` Conformidade](zc-conformance.md)\
[noexcept](../../cpp/noexcept-cpp.md)\
[Especificações de exceção (lançar)](../../cpp/exception-specifications-throw-cpp.md)
