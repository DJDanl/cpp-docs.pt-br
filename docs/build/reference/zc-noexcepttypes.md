---
title: /Zc:noexceptTypes (Regras noexcept C++17)
ms.date: 11/14/2017
f1_keywords:
- /Zc:noexceptTypes
helpviewer_keywords:
- /Zc:noexceptTypes
- Zc:noexceptTypes
- -Zc:noexceptTypes
ms.assetid: 1cbf7e3c-0f82-4f91-84dd-612bcf26d2c6
ms.openlocfilehash: 35bea7c2c629c615c60a6136f289b6b11926c054
ms.sourcegitcommit: 0cfc43f90a6cc8b97b24c42efcf5fb9c18762a42
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/05/2019
ms.locfileid: "73624859"
---
# <a name="zcnoexcepttypes-c17-noexcept-rules"></a>/Zc:noexceptTypes (Regras noexcept C++17)

O padrão C++ 17 faz `throw()` um alias para `noexcept`, remove `throw(<type list>)` e `throw(...)`e permite que determinados tipos incluam `noexcept`. Essa alteração pode causar uma série de problemas de compatibilidade de origem no código que está em conformidade com C++ 14 ou anterior. A opção **/Zc: noexceptTypes** especifica conformidade com o padrão c++ 17. **/Zc: noexceptTypes-** permite o comportamento c++ 14 e anterior quando o código é compilado no modo c++ 17.

## <a name="syntax"></a>Sintaxe

> **/Zc: noexceptTypes**[-]

## <a name="remarks"></a>Comentários

Quando a opção **/Zc: noexceptTypes** é especificada, o compilador está em conformidade com o padrão c++ 17 e trata [throw ()](../../cpp/exception-specifications-throw-cpp.md) como um alias para [noexcept](../../cpp/noexcept-cpp.md), remove `throw(<type list>)` e `throw(...)`e permite que determinados tipos incluam `noexcept`. A opção **/Zc: noexceptTypes** só está disponível quando [/std: c++ 17](std-specify-language-standard-version.md) ou [/std: Latest](std-specify-language-standard-version.md) está habilitado. **/Zc: noexceptTypes** está habilitado por padrão para estar em conformidade com o padrão ISO c++ 17. A opção [/permissive-](permissive-standards-conformance.md) não afeta **/Zc: noexceptTypes**. Desative essa opção especificando **/Zc: noexceptTypes-** para reverter para o comportamento do c++ 14 de `noexcept` quando **/std: c++ 17** ou **/std: Latest** for especificado.

A partir do Visual Studio 2017 versão 15,5, C++ o compilador diagnostica mais especificações de exceção incompatíveis em declarações no modo c++ 17 ou quando você especifica a opção [/permissive-](permissive-standards-conformance.md) .

Este exemplo mostra como as declarações com um especificador de exceção se comportam quando a opção **/Zc: noexceptTypes** é definida ou desabilitada. Para mostrar o comportamento quando definido, compile usando `cl /EHsc /W4 noexceptTypes.cpp`. Para mostrar o comportamento quando desabilitado, compile usando `cl /EHsc /W4 /Zc:noexceptTypes- noexceptTypes.cpp`.

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

Quando compilado usando a configuração padrão **/Zc: noexceptTypes**, o exemplo gera os avisos listados. Para atualizar seu código, use o seguinte:

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

Para obter mais informações sobre problemas de conformidade C++no Visual, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **Propriedades da Configuração** > **C/C++**  > **Linha de Comando**.

1. Modifique a propriedade **Opções adicionais** para incluir **/Zc: noexceptTypes** ou **/Zc: noexceptTypes-** e escolha **OK**.

## <a name="see-also"></a>Consulte também

[/Zc (conformidade)](zc-conformance.md)\
[noexcept](../../cpp/noexcept-cpp.md)\
[Especificações de exceção (throw)](../../cpp/exception-specifications-throw-cpp.md)
