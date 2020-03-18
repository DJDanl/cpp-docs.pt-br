---
title: /C (preservar comentários durante o pré-processamento)
ms.date: 11/04/2016
f1_keywords:
- VC.Project.VCCLCompilerTool.KeepComments
- VC.Project.VCCLWCECompilerTool.KeepComments
helpviewer_keywords:
- comments, not stripping during preprocessing
- preserve comments during preprocessing
- -c compiler option [C++]
- c compiler option [C++]
- /c compiler option [C++]
ms.assetid: 944567ca-16bc-4728-befe-d414a7787f26
ms.openlocfilehash: f80ebf45dd396a3f92d9b755c56522d4731bb2d0
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79440280"
---
# <a name="c-preserve-comments-during-preprocessing"></a>/C (preservar comentários durante o pré-processamento)

Preserva comentários durante o pré-processamento.

## <a name="syntax"></a>Sintaxe

```
/C
```

## <a name="remarks"></a>Comentários

Essa opção de compilador requer a opção **/e**, **/p**ou **/EP** .

O exemplo de código a seguir exibirá o comentário do código-fonte.

```cpp
// C_compiler_option.cpp
// compile with: /E /C /c
int i;   // a variable
```

Este exemplo produzirá a saída a seguir.

```
#line 1 "C_compiler_option.cpp"
int i;   // a variable
```

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Clique na pasta **CC++ /** .

1. Clique na página de propriedades do **pré-processador** .

1. Modifique a propriedade **manter comentários** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.KeepComments%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)<br/>
[/E (pré-processar em stdout)](e-preprocess-to-stdout.md)<br/>
[/P (pré-processar em um arquivo)](p-preprocess-to-a-file.md)<br/>
[/EP (pré-processar em stdout sem diretivas #line)](ep-preprocess-to-stdout-without-hash-line-directives.md)
