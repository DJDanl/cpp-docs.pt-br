---
title: /Qimprecise_fwaits (remover fwaits dentro de blocos Try)
ms.date: 11/04/2016
f1_keywords:
- /Qimprecise_fwaits
helpviewer_keywords:
- -Qimprecise_fwaits compiler option (C++)
- /Qimprecise_fwaits compiler option (C++)
ms.assetid: b1501f21-7e08-4fea-95e8-176ec03a635b
ms.openlocfilehash: 424feda66f6925cb305256249101ea4013e3090f
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87232671"
---
# <a name="qimprecise_fwaits-remove-fwaits-inside-try-blocks"></a>/Qimprecise_fwaits (remover fwaits dentro de blocos Try)

Remove os `fwait` comandos internos para **`try`** blocos quando você usa a opção de compilador [/fp: except](fp-specify-floating-point-behavior.md) .

## <a name="syntax"></a>Sintaxe

```
/Qimprecise_fwaits
```

## <a name="remarks"></a>Comentários

Essa opção não terá efeito se **/fp: except** não for especificado também. Se você especificar a opção **/fp: except** , o compilador irá inserir um `fwait` comando em torno de cada linha de código em um **`try`** bloco. Dessa forma, o compilador pode identificar a linha de código específica que produz uma exceção. **/Qimprecise_fwaits** remove `fwait` instruções internas, deixando apenas as esperas em todo o **`try`** bloco. Isso melhora o desempenho, mas o compilador só poderá dizer qual **`try`** bloco causa uma exceção, e não qual linha.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **C/C++** .

1. Clique na página de propriedades de **linha de comando** .

1. Digite a opção do compilador na caixa **Opções adicionais** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.AdditionalOptions%2A>.

## <a name="see-also"></a>Confira também

[Opções de/q (operações de nível baixo)](q-options-low-level-operations.md)<br/>
[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe de linha de comando do compilador MSVC](compiler-command-line-syntax.md)
