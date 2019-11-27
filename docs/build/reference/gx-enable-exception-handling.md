---
title: /GX (habilitar tratamento de exceções)
ms.date: 11/19/2019
f1_keywords:
- /gx
helpviewer_keywords:
- exception handling, enabling
- /GX compiler option [C++]
- -GX compiler option [C++]
- cl.exe compiler, exception handling
- enable exception handling compiler option [C++]
- GX compiler option [C++]
ms.assetid: 933b43ba-de77-4ff8-a48b-7074de90bc1c
ms.openlocfilehash: 171ff0d0dfb1dec41bae5f6be63c941802c402a4
ms.sourcegitcommit: 654aecaeb5d3e3fe6bc926bafd6d5ace0d20a80e
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 11/20/2019
ms.locfileid: "74245082"
---
# <a name="gx-enable-exception-handling"></a>/GX (habilitar tratamento de exceções)

Preterido. Habilita a manipulação de exceção síncrona usando a suposição de que as funções declaradas usando `extern "C"` nunca geram uma exceção.

## <a name="syntax"></a>Sintaxe

```
/GX
```

## <a name="remarks"></a>Comentários

**/GX** foi preterido. Em vez disso, use a opção [/EHsc](eh-exception-handling-model.md) equivalente. Para obter uma lista de opções de compilador preteridas, consulte a seção **Opções de compilador preteridas e removidas** em [Opções de compilador listadas por categoria](compiler-options-listed-by-category.md).

Por padrão, **/EHsc**, o equivalente a **/GX**, está em vigor quando você compila usando o ambiente de desenvolvimento do Visual Studio. Ao usar as ferramentas de linha de comando, nenhuma manipulação de exceção é especificada. Esse é o equivalente de **/GX-** .

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. No painel de navegação, escolha **Propriedades de configuração**, **CC++/** , **linha de comando**.

1. Digite a opção do compilador na caixa **Opções adicionais** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/EH (modelo de tratamento de exceções)](eh-exception-handling-model.md)
