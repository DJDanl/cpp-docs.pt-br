---
title: /Gm (habilitar recompilação manual)
ms.date: 11/12/2018
f1_keywords:
- VC.Project.VCCLCompilerTool.MinimalRebuild
- /Gm
- VC.Project.VCCLWCECompilerTool.MinimalRebuild
helpviewer_keywords:
- /Gm compiler option [C++]
- minimal rebuild
- enable minimal rebuild compiler option [C++]
- Gm compiler option [C++]
- -Gm compiler option [C++]
ms.assetid: d8869ce0-d2ea-40eb-8dae-6d2cdb61dd59
ms.openlocfilehash: 9b928f3add0a2ec10257bf63fe61a824336c19b8
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79439648"
---
# <a name="gm-enable-minimal-rebuild"></a>/Gm (habilitar recompilação manual)

Preterido. Habilita recompilação mínima, que determina se os arquivos de origem C++ que incluem definições de classe C++ alteradas (armazenadas nos arquivos de cabeçalho (.h)) precisam ser recompilados.

## <a name="syntax"></a>Sintaxe

```
/Gm
```

## <a name="remarks"></a>Comentários

**/GM** foi preterido. Ele não pode disparar uma compilação para determinados tipos de alterações de arquivo de cabeçalho. Você pode remover com segurança essa opção de seus projetos. Para melhorar os tempos de compilação, recomendamos que você use cabeçalhos pré-compilados e opções de compilação incrementais e paralelas em vez disso. Para obter uma lista de opções de compilador preteridas, consulte a seção **Opções de compilador preteridas e removidas** em [Opções de compilador listadas por categoria](compiler-options-listed-by-category.md).

O compilador armazena as informações de dependência entre arquivos de origem e definições de classe no arquivo .idb do projeto durante a primeira compilação. (Informações sobre dependência dizem que arquivo de origem depende da definição de classe e em qual arquivo .h a definição está localizada.) Compilações subsequentes usam as informações armazenadas no arquivo .idb para determinar se um arquivo de origem precisa ser compilado, mesmo que inclua um arquivo .h modificado.

> [!NOTE]
> A recompilação mínima conta com definições de classe que não mudem entre os arquivos incluídos. As definições de classe devem ser globais para um projeto (deve haver apenas uma definição de uma determinada classe), pois as informações de dependência no arquivo .idb são criadas para todo o projeto. Se você tiver mais de uma definição para uma classe no seu projeto, desabilite a recompilação mínima.

Como o vinculador incremental não oferece suporte aos metadados do Windows incluídos nos arquivos. obj usando a opção [/zw (compilação de Windows Runtime)](zw-windows-runtime-compilation.md) , a opção **/GM** é incompatível com **/zw**.

### <a name="to-set-this-compiler-option-in-the-visual-studio-development-environment"></a>Para definir esta opção do compilador no ambiente de desenvolvimento do Visual Studio

1. Abra a caixa de diálogo **Páginas de Propriedades** do projeto. Para obter detalhes, confira [Definir as propriedades de build e do compilador do C++ no Visual Studio](../working-with-project-properties.md).

1. Selecione as **Propriedades de configuração** > página de propriedades de **geração de código** **C/C++**  > .

1. Modifique a propriedade **habilitar recompilação mínima** .

### <a name="to-set-this-compiler-option-programmatically"></a>Para definir essa opção do compilador via programação

- Consulte <xref:Microsoft.VisualStudio.VCProjectEngine.VCCLCompilerTool.MinimalRebuild%2A>.

## <a name="see-also"></a>Consulte também

[Opções do compilador MSVC](compiler-options.md)<br/>
[Sintaxe da linha de comando do compilador MSVC](compiler-command-line-syntax.md)
