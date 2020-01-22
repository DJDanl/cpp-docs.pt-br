---
title: /Zc:referenceBinding (Impor regras de associação de referência)
ms.date: 03/06/2018
f1_keywords:
- referenceBinding
- /Zc:referenceBinding
helpviewer_keywords:
- -Zc compiler options (C++)
- referenceBinding
- Enforce reference binding rules
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: 0c6cfaac-9c2a-41a3-aa94-64ca8ef261fc
ms.openlocfilehash: b7e297d6fd913ddda4d44a42298a361e314af0b5
ms.sourcegitcommit: a930a9b47bd95599265d6ba83bb87e46ae748949
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 01/22/2020
ms.locfileid: "76518472"
---
# <a name="zcreferencebinding-enforce-reference-binding-rules"></a>/Zc:referenceBinding (Impor regras de associação de referência)

Quando a opção **/Zc: referencebinding** é especificada, o compilador não permite uma referência lvalue não const para associar a um temporário.

## <a name="syntax"></a>Sintaxe

> **/Zc:referenceBinding**[ **-** ]

## <a name="remarks"></a>Comentários

Se **/Zc: referencebinding** for especificado, o compilador seguirá a seção 8.5.3 do padrão c++ 11: ele não permite expressões que associam um tipo definido pelo usuário temporário a uma referência lvalue não const. Por padrão, ou se **/Zc: referencebinding-** for especificado, o compilador permitirá essas expressões como uma extensão da Microsoft, mas um aviso de nível 4 será emitido. Para segurança de código, portabilidade e conformidade, recomendamos que você use **/Zc: referencebinding**.

A opção **/Zc: referencebinding** está desativada por padrão. A opção de compilador [/permissive-](permissive-standards-conformance.md) define implicitamente essa opção, mas pode ser substituída usando **/Zc: referencebinding-** .

## <a name="example"></a>Exemplo

Este exemplo mostra a extensão da Microsoft que permite que um temporário de um tipo definido pelo usuário seja associado a uma referência lvalue não const.

```cpp
// zcreferencebinding.cpp
struct S {
};

void f(S&) {
}

S g() {
    return S{};
}

int main() {
    S& s = g();         // warning C4239 at /W4
    const S& cs = g();  // okay, bound to const ref
    f(g());             // Extension: error C2664 only if /Zc:referenceBinding
}
```

Para obter mais informações sobre problemas de conformidade C++no Visual, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione a página de propriedades **Propriedades de Configuração** > **C/C++**  > **Linha de Comando**.

1. Modifique a propriedade **Opções adicionais** para incluir **/Zc: referencebinding** e escolha **OK**.

## <a name="see-also"></a>Veja também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/Zc (conformidade)](zc-conformance.md)<br/>
