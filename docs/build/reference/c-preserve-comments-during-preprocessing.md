---
title: -C (preservar comentários durante o pré-processamento) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: reference
f1_keywords:
- VC.Project.VCCLCompilerTool.KeepComments
- /c
- VC.Project.VCCLWCECompilerTool.KeepComments
dev_langs:
- C++
helpviewer_keywords:
- comments, not stripping during preprocessing
- preserve comments during preprocessing
- -c compiler option [C++]
- c compiler option [C++]
- /c compiler option [C++]
ms.assetid: 944567ca-16bc-4728-befe-d414a7787f26
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 20973969385d0b5c61872a12f4d0168420bc2eef
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45713169"
---
# <a name="c-preserve-comments-during-preprocessing"></a>/C (preservar comentários durante o pré-processamento)

Preserva comentários durante o pré-processamento.

## <a name="syntax"></a>Sintaxe

```
/C
```

## <a name="remarks"></a>Comentários

Essa opção do compilador requer o **/E**, **/P**, ou **/EP** opção.

O exemplo de código a seguir exibirá o comentário do código fonte.

```
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

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Trabalhando com propriedades do projeto](../../ide/working-with-project-properties.md).

1. Clique o **C/C++** pasta.

1. Clique o **pré-processador** página de propriedades.

1. Modificar a **manter comentários** propriedade.

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.KeepComments%2A>.

## <a name="see-also"></a>Consulte também

[Opções do Compilador](../../build/reference/compiler-options.md)<br/>
[Definindo opções do compilador](../../build/reference/setting-compiler-options.md)<br/>
[/E (pré-processar em stdout)](../../build/reference/e-preprocess-to-stdout.md)
[/P (pré-processar em um arquivo)](../../build/reference/p-preprocess-to-a-file.md)
[/EP (pré-processar para stdout sem diretivas de #line)](../../build/reference/ep-preprocess-to-stdout-without-hash-line-directives.md)