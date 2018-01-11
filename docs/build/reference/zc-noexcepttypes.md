---
title: '-Zc: noexceptTypes (C++ 17 noexcept regras) | Microsoft Docs'
ms.date: 11/14/2017
ms.technology: cpp-tools
ms.topic: article
f1_keywords: /Zc:noexceptTypes
dev_langs: C++
helpviewer_keywords:
- /Zc:noexceptTypes
- Zc:noexceptTypes
- -Zc:noexceptTypes
ms.assetid: 1cbf7e3c-0f82-4f91-84dd-612bcf26d2c6
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: e1b0e209462295f907f5e518299d34fb18aade4d
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="zcnoexcepttypes-c17-noexcept-rules"></a>/ZC:noexceptTypes (C++ 17 noexcept regras)

Faz com que o padrão C++ 17 `throw()` como um alias para `noexcept`, remove `throw(<type list>)` e `throw(...)`e permite que determinados tipos de incluir `noexcept`. Isso pode causar alguns problemas de compatibilidade de origem no código que está de acordo com a C + + 14 ou anterior. O **/Zc:noexceptTypes** opção pode especificar a conformidade com o padrão C++ 17 ou permitir que o C + + 14 anterior comportamento quando o código é compilado no modo C++ 17.

## <a name="syntax"></a>Sintaxe

> **/ZC:noexceptTypes**[-]

## <a name="remarks"></a>Comentários

Quando o **/Zc:noexceptTypes** opção for especificada, o compilador segue o padrão C++ 17 e trata [throw()](../../cpp/exception-specifications-throw-cpp.md) como um alias para [noexcept](../../cpp/noexcept-cpp.md), remove `throw(<type list>)`e `throw(...)`e permite que determinados tipos de incluir `noexcept`. O **/Zc:noexceptTypes** opção está disponível apenas quando [/std:c + + 17](std-specify-language-standard-version.md) ou [/std:latest](std-specify-language-standard-version.md) está habilitado. **/ZC:noexceptTypes** é habilitado por padrão, de acordo com o ISO padrão C++ 17. Desativar essa opção especificando **/Zc:noexceptTypes-** para reverter para o comportamento de 14 C + + do `noexcept` quando **/std::C + + 17** ou **/std::latest** for especificado.

A partir do Visual Studio 2017 versão 15,5, o compilador do C++ diagnostica mais especificações de exceção incompatível em declarações no modo C + + 17 ou quando o [/ permissivo-](permissive-standards-conformance.md) opção é especificada.

Este exemplo mostra como declarações com um especificador de exceção se comportam quando o **/Zc:noexceptTypes** opção está definida ou desabilitada. Para mostrar o comportamento quando definido, compile usando `cl /EHsc /W4 noexceptTypes.cpp`. Para mostrar o comportamento quando desabilitado, compile usando `cl /EHsc /W4 /Zc:noexceptTypes- noexceptTypes.cpp`.

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

Quando compilado usando a configuração padrão **/Zc:noexceptTypes**, o exemplo gera os avisos listados. Para atualizar seu código, use o seguinte:

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

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **linha de comando** página de propriedades no **C/C++** pasta.

1. Modificar o **opções adicionais** propriedade incluir **/Zc:noexceptTypes** ou **/Zc:noexceptTypes-** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[/ZC (conformidade)](../../build/reference/zc-conformance.md)  
[noexcept](../../cpp/noexcept-cpp.md)  
[Especificações de exceção (lançar)](../../cpp/exception-specifications-throw-cpp.md)  
