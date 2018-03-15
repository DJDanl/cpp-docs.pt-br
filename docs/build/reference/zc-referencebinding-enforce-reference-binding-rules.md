---
title: "/ZC:referenceBinding (Aplicar regras de associação de referência) | Microsoft Docs"
ms.custom: 
ms.date: 03/06/2018
ms.technology:
- cpp-tools
ms.topic: article
f1_keywords:
- referenceBinding
- /Zc:referenceBinding
dev_langs:
- C++
helpviewer_keywords:
- -Zc compiler options (C++)
- referenceBinding
- Enforce reference binding rules
- /Zc compiler options (C++)
- Zc compiler options (C++)
ms.assetid: 0c6cfaac-9c2a-41a3-aa94-64ca8ef261fc
author: corob-msft
ms.author: corob
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: a8e3b10f5b2108a4c0e29d802951015749775a27
ms.sourcegitcommit: eeb2b5ad8d3d22514a7b9bd7d756511b69ae0ccf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/15/2018
---
# <a name="zcreferencebinding-enforce-reference-binding-rules"></a>/ZC:referenceBinding (Aplicar regras de associação de referência)

Quando o **/Zc:referenceBinding** opção for especificada, o compilador não permite uma referência não const lvalue associar a um temporário.

## <a name="syntax"></a>Sintaxe

> **/Zc:referenceBinding**[**-**]

## <a name="remarks"></a>Comentários

Se **/Zc:referenceBinding** for especificado, o compilador seção 8.5.3 do C++ 11 padrão e não permite expressões que associam um tipo definido pelo usuário temporário para uma referência não const lvalue. Por padrão, ou se **/Zc:referenceBinding-** for especificado, o compilador permite tais expressões como uma extensão da Microsoft, mas é emitido um aviso de nível 4. Para segurança de código, portabilidade e conformidade, é recomendável que você use **/Zc:referenceBinding**.

O **/Zc:referenceBinding** opção está desativada por padrão. O [/ permissivo-](permissive-standards-conformance.md) opção de compilador implicitamente define esta opção, mas ele pode ser substituído usando **/Zc:referenceBinding-**.

## <a name="example"></a>Exemplo

Este exemplo mostra a extensão da Microsoft que permite que um temporário de um tipo definido pelo usuário a ser associado a uma referência não const lvalue.

```cpp
// zcreferencebinding.cpp
struct S {
};

void f(S&) {
}

S g() {
    return S{};
}

void main() {
    S& s = g();         // warning C4239 at /W4
    const S& cs = g();  // okay, bound to const ref
    f(g());             // Extension: error C2664 only if /Zc:referenceBinding
}
```

Para obter mais informações sobre problemas de conformidade no Visual C++, consulte [comportamento não padrão](../../cpp/nonstandard-behavior.md).

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, consulte [trabalhar com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Selecione o **propriedades de configuração** > **C/C++** > **linha de comando** página de propriedades.

1. Modificar o **opções adicionais** propriedade incluir **/Zc:referenceBinding** e, em seguida, escolha **Okey**.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[/Zc (conformidade)](../../build/reference/zc-conformance.md)<br/>
